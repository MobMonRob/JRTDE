const std::string NEW_LINE= "\n"; const std::string QUOTATION = "\""; std::string UR_SCRIPT = "def rtde_control():" + NEW_LINE  + 
"    global force_mode_type = 2" + NEW_LINE  + 
"    global selection_vector = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"    global task_frame = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"    global wrench = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"    global limits = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"    global is_servoing = 0" + NEW_LINE  + 
"    global is_speeding = 0" + NEW_LINE  + 
"    global is_in_forcemode = 0" + NEW_LINE  + 
"" + NEW_LINE  + 
"    global servo_target = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"    global servo_time = 0.002" + NEW_LINE  + 
"    global servo_lookahead_time = 0.1" + NEW_LINE  + 
"    global servo_gain = 300" + NEW_LINE  + 
"" + NEW_LINE  + 
"    global servoc_target = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"    global servoc_acceleration = 1.2" + NEW_LINE  + 
"    global servoc_velocity = 0.25" + NEW_LINE  + 
"    global servoc_blend = 0" + NEW_LINE  + 
"" + NEW_LINE  + 
"    global speed_type = 0" + NEW_LINE  + 
"    global speed_target = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"    global speed_acceleration = 0.5" + NEW_LINE  + 
"    global speed_time = 0.5" + NEW_LINE  + 
"" + NEW_LINE  + 
"    global servo_thrd = 0" + NEW_LINE  + 
"    global servoc_thrd = 0" + NEW_LINE  + 
"    global speed_thrd = 0" + NEW_LINE  + 
"    global force_thrd = 0" + NEW_LINE  + 
"" + NEW_LINE  + 
"    thread force_thread():" + NEW_LINE  + 
"        while (True):" + NEW_LINE  + 
"            force_mode(task_frame, selection_vector, wrench, force_mode_type, limits)" + NEW_LINE  + 
"            sync()" + NEW_LINE  + 
"        end" + NEW_LINE  + 
"    end" + NEW_LINE  + 
"" + NEW_LINE  + 
"    thread speed_thread():" + NEW_LINE  + 
"        while (True):" + NEW_LINE  + 
"            if speed_type == 0:" + NEW_LINE  + 
"                if speed_time > 0:" + NEW_LINE  + 
"                    speedl(speed_target, a=speed_acceleration, t=speed_time)" + NEW_LINE  + 
"                else:" + NEW_LINE  + 
"                    speedl(speed_target, a=speed_acceleration)" + NEW_LINE  + 
"                end" + NEW_LINE  + 
"            else:" + NEW_LINE  + 
"                if speed_time > 0:" + NEW_LINE  + 
"                    speedj(speed_target, a=speed_acceleration, t=speed_time)" + NEW_LINE  + 
"                else:" + NEW_LINE  + 
"                    speedj(speed_target, a=speed_acceleration)" + NEW_LINE  + 
"                end" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"        end" + NEW_LINE  + 
"    end" + NEW_LINE  + 
"" + NEW_LINE  + 
"    thread servo_thread():" + NEW_LINE  + 
"      while (True):" + NEW_LINE  + 
"          enter_critical" + NEW_LINE  + 
"          q = servo_target" + NEW_LINE  + 
"          dt = servo_time" + NEW_LINE  + 
"          lh_time = servo_lookahead_time" + NEW_LINE  + 
"          g = servo_gain" + NEW_LINE  + 
"          exit_critical" + NEW_LINE  + 
"          servoj(q, t=dt, lookahead_time=lh_time, gain=g)" + NEW_LINE  + 
"      end" + NEW_LINE  + 
"  end" + NEW_LINE  + 
"" + NEW_LINE  + 
"    thread servoc_thread():" + NEW_LINE  + 
"        while (True):" + NEW_LINE  + 
"            servoc(servoc_target, a=servoc_acceleration, v=servoc_velocity, r=servoc_blend)" + NEW_LINE  + 
"        end" + NEW_LINE  + 
"    end" + NEW_LINE  + 
"" + NEW_LINE  + 
"    def signal_ready():" + NEW_LINE  + 
"        write_output_integer_register(0, 1)" + NEW_LINE  + 
"    end" + NEW_LINE  + 
"" + NEW_LINE  + 
"    def signal_done_with_cmd():" + NEW_LINE  + 
"        write_output_integer_register(0, 2)" + NEW_LINE  + 
"    end" + NEW_LINE  + 
"" + NEW_LINE  + 
"    def rtde_cmd():" + NEW_LINE  + 
"        return read_input_integer_register(0)" + NEW_LINE  + 
"    end" + NEW_LINE  + 
"" + NEW_LINE  + 
"    def process_cmd():" + NEW_LINE  + 
"        cmd = read_input_integer_register(0)" + NEW_LINE  + 
"" + NEW_LINE  + 
"        if cmd == 1:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movej"+QUOTATION+")" + NEW_LINE  + 
"            q = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            q[0] = read_input_float_register(0)" + NEW_LINE  + 
"            q[1] = read_input_float_register(1)" + NEW_LINE  + 
"            q[2] = read_input_float_register(2)" + NEW_LINE  + 
"            q[3] = read_input_float_register(3)" + NEW_LINE  + 
"            q[4] = read_input_float_register(4)" + NEW_LINE  + 
"            q[5] = read_input_float_register(5)" + NEW_LINE  + 
"            velocity = read_input_float_register(6)" + NEW_LINE  + 
"            acceleration = read_input_float_register(7)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"Target q:"+QUOTATION+")" + NEW_LINE  + 
"            textmsg(q)" + NEW_LINE  + 
"            movej(q, a=acceleration, v=velocity)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movej done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 2:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movej_ik"+QUOTATION+")" + NEW_LINE  + 
"            pose = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            pose[0] = read_input_float_register(0)" + NEW_LINE  + 
"            pose[1] = read_input_float_register(1)" + NEW_LINE  + 
"            pose[2] = read_input_float_register(2)" + NEW_LINE  + 
"            pose[3] = read_input_float_register(3)" + NEW_LINE  + 
"            pose[4] = read_input_float_register(4)" + NEW_LINE  + 
"            pose[5] = read_input_float_register(5)" + NEW_LINE  + 
"            velocity = read_input_float_register(6)" + NEW_LINE  + 
"            acceleration = read_input_float_register(7)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"Target pose:"+QUOTATION+")" + NEW_LINE  + 
"            textmsg(pose)" + NEW_LINE  + 
"            q = get_inverse_kin(pose)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"Target q:"+QUOTATION+")" + NEW_LINE  + 
"            textmsg(q)" + NEW_LINE  + 
"            movej(q, a=acceleration, v=velocity)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movej_ik done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 3:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movel"+QUOTATION+")" + NEW_LINE  + 
"            pose = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            pose[0] = read_input_float_register(0)" + NEW_LINE  + 
"            pose[1] = read_input_float_register(1)" + NEW_LINE  + 
"            pose[2] = read_input_float_register(2)" + NEW_LINE  + 
"            pose[3] = read_input_float_register(3)" + NEW_LINE  + 
"            pose[4] = read_input_float_register(4)" + NEW_LINE  + 
"            pose[5] = read_input_float_register(5)" + NEW_LINE  + 
"            velocity = read_input_float_register(6)" + NEW_LINE  + 
"            acceleration = read_input_float_register(7)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"Target pose:"+QUOTATION+")" + NEW_LINE  + 
"            textmsg(pose)" + NEW_LINE  + 
"            movel(pose, a=acceleration, v=velocity)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movel done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 4:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movel_fk"+QUOTATION+")" + NEW_LINE  + 
"            q = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            q[0] = read_input_float_register(0)" + NEW_LINE  + 
"            q[1] = read_input_float_register(1)" + NEW_LINE  + 
"            q[2] = read_input_float_register(2)" + NEW_LINE  + 
"            q[3] = read_input_float_register(3)" + NEW_LINE  + 
"            q[4] = read_input_float_register(4)" + NEW_LINE  + 
"            q[5] = read_input_float_register(5)" + NEW_LINE  + 
"            velocity = read_input_float_register(6)" + NEW_LINE  + 
"            acceleration = read_input_float_register(7)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"Target q:"+QUOTATION+")" + NEW_LINE  + 
"            textmsg(q)" + NEW_LINE  + 
"            movel(q, a=acceleration, v=velocity)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movel_fk done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 5:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movec"+QUOTATION+")" + NEW_LINE  + 
"            pose_via = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            pose_via[0] = read_input_float_register(0)" + NEW_LINE  + 
"            pose_via[1] = read_input_float_register(1)" + NEW_LINE  + 
"            pose_via[2] = read_input_float_register(2)" + NEW_LINE  + 
"            pose_via[3] = read_input_float_register(3)" + NEW_LINE  + 
"            pose_via[4] = read_input_float_register(4)" + NEW_LINE  + 
"            pose_via[5] = read_input_float_register(5)" + NEW_LINE  + 
"            pose_to = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            pose_to[0] = read_input_float_register(6)" + NEW_LINE  + 
"            pose_to[1] = read_input_float_register(7)" + NEW_LINE  + 
"            pose_to[2] = read_input_float_register(8)" + NEW_LINE  + 
"            pose_to[3] = read_input_float_register(9)" + NEW_LINE  + 
"            pose_to[4] = read_input_float_register(10)" + NEW_LINE  + 
"            pose_to[5] = read_input_float_register(11)" + NEW_LINE  + 
"            velocity = read_input_float_register(12)" + NEW_LINE  + 
"            acceleration = read_input_float_register(13)" + NEW_LINE  + 
"            blend = read_input_float_register(14)" + NEW_LINE  + 
"            movec_mode = read_input_integer_register(1)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"pose_via:"+QUOTATION+")" + NEW_LINE  + 
"            textmsg(pose_via)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"pose_to:"+QUOTATION+")" + NEW_LINE  + 
"            textmsg(pose_to)" + NEW_LINE  + 
"            movec(pose_via, pose_to, a=acceleration, v=velocity, r=blend, mode=movec_mode)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movec done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 6:" + NEW_LINE  + 
"            # force_mode" + NEW_LINE  + 
"            enter_critical" + NEW_LINE  + 
"            force_mode_type = read_input_integer_register(1)" + NEW_LINE  + 
"            selection_vector[0] = read_input_integer_register(2)" + NEW_LINE  + 
"            selection_vector[1] = read_input_integer_register(3)" + NEW_LINE  + 
"            selection_vector[2] = read_input_integer_register(4)" + NEW_LINE  + 
"            selection_vector[3] = read_input_integer_register(5)" + NEW_LINE  + 
"            selection_vector[4] = read_input_integer_register(6)" + NEW_LINE  + 
"            selection_vector[5] = read_input_integer_register(7)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            task_frame[0] = read_input_float_register(0)" + NEW_LINE  + 
"            task_frame[1] = read_input_float_register(1)" + NEW_LINE  + 
"            task_frame[2] = read_input_float_register(2)" + NEW_LINE  + 
"            task_frame[3] = read_input_float_register(3)" + NEW_LINE  + 
"            task_frame[4] = read_input_float_register(4)" + NEW_LINE  + 
"            task_frame[5] = read_input_float_register(5)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            wrench[0] = read_input_float_register(6)" + NEW_LINE  + 
"            wrench[1] = read_input_float_register(7)" + NEW_LINE  + 
"            wrench[2] = read_input_float_register(8)" + NEW_LINE  + 
"            wrench[3] = read_input_float_register(9)" + NEW_LINE  + 
"            wrench[4] = read_input_float_register(10)" + NEW_LINE  + 
"            wrench[5] = read_input_float_register(11)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            limits[0] = read_input_float_register(12)" + NEW_LINE  + 
"            limits[1] = read_input_float_register(13)" + NEW_LINE  + 
"            limits[2] = read_input_float_register(14)" + NEW_LINE  + 
"            limits[3] = read_input_float_register(15)" + NEW_LINE  + 
"            limits[4] = read_input_float_register(16)" + NEW_LINE  + 
"            limits[5] = read_input_float_register(17)" + NEW_LINE  + 
"            exit_critical" + NEW_LINE  + 
"" + NEW_LINE  + 
"            if is_in_forcemode == 0:" + NEW_LINE  + 
"                is_in_forcemode = 1" + NEW_LINE  + 
"                if force_thrd == 0:" + NEW_LINE  + 
"                    global force_thrd = run force_thread()" + NEW_LINE  + 
"                end" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"        elif cmd == 7:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"force_mode_stop"+QUOTATION+")" + NEW_LINE  + 
"            enter_critical" + NEW_LINE  + 
"            is_in_forcemode = 0" + NEW_LINE  + 
"            kill force_thrd" + NEW_LINE  + 
"            force_thrd = 0" + NEW_LINE  + 
"            end_force_mode()" + NEW_LINE  + 
"            stopl(10)" + NEW_LINE  + 
"            exit_critical" + NEW_LINE  + 
"            textmsg("+QUOTATION+"force_mode stopped"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 8:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"zero_ftsensor"+QUOTATION+")" + NEW_LINE  + 
"            zero_ftsensor()" + NEW_LINE  + 
"            textmsg("+QUOTATION+"ftsensor zeroed"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 9:" + NEW_LINE  + 
"            # speedJ" + NEW_LINE  + 
"            qd = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            qd[0] = read_input_float_register(0)" + NEW_LINE  + 
"            qd[1] = read_input_float_register(1)" + NEW_LINE  + 
"            qd[2] = read_input_float_register(2)" + NEW_LINE  + 
"            qd[3] = read_input_float_register(3)" + NEW_LINE  + 
"            qd[4] = read_input_float_register(4)" + NEW_LINE  + 
"            qd[5] = read_input_float_register(5)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            enter_critical" + NEW_LINE  + 
"            speed_type = 1" + NEW_LINE  + 
"            speed_acceleration = read_input_float_register(6)" + NEW_LINE  + 
"            speed_time = read_input_float_register(7)" + NEW_LINE  + 
"            speed_target = qd" + NEW_LINE  + 
"            exit_critical" + NEW_LINE  + 
"" + NEW_LINE  + 
"            if is_speeding == 0:" + NEW_LINE  + 
"                is_speeding = 1" + NEW_LINE  + 
"                if speed_thrd == 0:" + NEW_LINE  + 
"                    global speed_thrd = run speed_thread()" + NEW_LINE  + 
"                end" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"        elif cmd == 10:" + NEW_LINE  + 
"            # speedL" + NEW_LINE  + 
"            xd = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            xd[0] = read_input_float_register(0)" + NEW_LINE  + 
"            xd[1] = read_input_float_register(1)" + NEW_LINE  + 
"            xd[2] = read_input_float_register(2)" + NEW_LINE  + 
"            xd[3] = read_input_float_register(3)" + NEW_LINE  + 
"            xd[4] = read_input_float_register(4)" + NEW_LINE  + 
"            xd[5] = read_input_float_register(5)" + NEW_LINE  + 
"            enter_critical" + NEW_LINE  + 
"            speed_type = 0" + NEW_LINE  + 
"            speed_acceleration = read_input_float_register(6)" + NEW_LINE  + 
"            speed_time = read_input_float_register(7)" + NEW_LINE  + 
"            speed_target = xd" + NEW_LINE  + 
"            exit_critical" + NEW_LINE  + 
"" + NEW_LINE  + 
"            if is_speeding == 0:" + NEW_LINE  + 
"                is_speeding = 1" + NEW_LINE  + 
"                if speed_thrd == 0:" + NEW_LINE  + 
"                    global speed_thrd = run speed_thread()" + NEW_LINE  + 
"                end" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"        elif cmd == 11:" + NEW_LINE  + 
"            # servoJ" + NEW_LINE  + 
"            q = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            q[0] = read_input_float_register(0)" + NEW_LINE  + 
"            q[1] = read_input_float_register(1)" + NEW_LINE  + 
"            q[2] = read_input_float_register(2)" + NEW_LINE  + 
"            q[3] = read_input_float_register(3)" + NEW_LINE  + 
"            q[4] = read_input_float_register(4)" + NEW_LINE  + 
"            q[5] = read_input_float_register(5)" + NEW_LINE  + 
"            velocity = read_input_float_register(6)" + NEW_LINE  + 
"            acceleration = read_input_float_register(7)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            enter_critical" + NEW_LINE  + 
"            servo_target = q" + NEW_LINE  + 
"            servo_time = read_input_float_register(8)" + NEW_LINE  + 
"            servo_lookahead_time = read_input_float_register(9)" + NEW_LINE  + 
"            servo_gain = read_input_float_register(10)" + NEW_LINE  + 
"            exit_critical" + NEW_LINE  + 
"" + NEW_LINE  + 
"            if is_servoing == 0:" + NEW_LINE  + 
"                is_servoing = 1" + NEW_LINE  + 
"                if servo_thrd == 0:" + NEW_LINE  + 
"                    global servo_thrd = run servo_thread()" + NEW_LINE  + 
"                end" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"            " + NEW_LINE  + 
"        elif cmd == 12:" + NEW_LINE  + 
"            # servoC" + NEW_LINE  + 
"            pose = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            pose[0] = read_input_float_register(0)" + NEW_LINE  + 
"            pose[1] = read_input_float_register(1)" + NEW_LINE  + 
"            pose[2] = read_input_float_register(2)" + NEW_LINE  + 
"            pose[3] = read_input_float_register(3)" + NEW_LINE  + 
"            pose[4] = read_input_float_register(4)" + NEW_LINE  + 
"            pose[5] = read_input_float_register(5)" + NEW_LINE  + 
"            velocity = read_input_float_register(6)" + NEW_LINE  + 
"            acceleration = read_input_float_register(7)" + NEW_LINE  + 
"            blend = read_input_float_register(8)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            enter_critical" + NEW_LINE  + 
"            servoc_target = pose" + NEW_LINE  + 
"            servoc_acceleration = acceleration" + NEW_LINE  + 
"            servoc_velocity = velocity" + NEW_LINE  + 
"            servoc_blend = blend" + NEW_LINE  + 
"            exit_critical" + NEW_LINE  + 
"" + NEW_LINE  + 
"            if is_servoing == 0:" + NEW_LINE  + 
"                is_servoing = 1" + NEW_LINE  + 
"                if servoc_thrd == 0:" + NEW_LINE  + 
"                    global servo_thrd = run servoc_thread()" + NEW_LINE  + 
"                end" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"" + NEW_LINE  + 
"        elif cmd == 15:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"speed_stop"+QUOTATION+")" + NEW_LINE  + 
"            enter_critical" + NEW_LINE  + 
"            is_speeding = 0" + NEW_LINE  + 
"            kill speed_thrd" + NEW_LINE  + 
"            speed_thrd = 0" + NEW_LINE  + 
"            if speed_type == 0:" + NEW_LINE  + 
"                stopl(10)" + NEW_LINE  + 
"            else:" + NEW_LINE  + 
"                stopj(10)" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"            exit_critical" + NEW_LINE  + 
"            textmsg("+QUOTATION+"speed_stop done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 16:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"servo_stop"+QUOTATION+")" + NEW_LINE  + 
"            enter_critical" + NEW_LINE  + 
"            is_servoing = 0" + NEW_LINE  + 
"            kill servo_thrd" + NEW_LINE  + 
"            kill servoc_thrd" + NEW_LINE  + 
"            servo_thrd = 0" + NEW_LINE  + 
"            servoc_thrd = 0" + NEW_LINE  + 
"            exit_critical" + NEW_LINE  + 
"            stopl(20)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"servo_stop done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 17:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"set_payload"+QUOTATION+")" + NEW_LINE  + 
"            mass = read_input_float_register(0)" + NEW_LINE  + 
"            cog_x = read_input_float_register(1)" + NEW_LINE  + 
"            cog_y = read_input_float_register(2)" + NEW_LINE  + 
"            cog_z = read_input_float_register(3)" + NEW_LINE  + 
"            cog = [cog_x, cog_y, cog_z]" + NEW_LINE  + 
"$V50        if cog_x == 0 and cog_y == 0 and cog_z == 0:" + NEW_LINE  + 
"$V50            set_payload(mass, get_target_payload_cog())" + NEW_LINE  + 
"$V50        else:" + NEW_LINE  + 
"                set_payload(mass, cog)" + NEW_LINE  + 
"$V50        end" + NEW_LINE  + 
"$V50        textmsg("+QUOTATION+"active payload:"+QUOTATION+")" + NEW_LINE  + 
"$V50        textmsg(get_target_payload())" + NEW_LINE  + 
"            textmsg("+QUOTATION+"set_payload done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 18:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"teach_mode"+QUOTATION+")" + NEW_LINE  + 
"            teach_mode()" + NEW_LINE  + 
"            textmsg("+QUOTATION+"teach_mode done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 19:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"end_teach_mode"+QUOTATION+")" + NEW_LINE  + 
"            end_teach_mode()" + NEW_LINE  + 
"            textmsg("+QUOTATION+"end_teach_mode done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 20:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"force_mode_set_damping"+QUOTATION+")" + NEW_LINE  + 
"            damping = read_input_float_register(0)" + NEW_LINE  + 
"$V35        force_mode_set_damping(damping)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"force_mode_set_damping done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 21:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"force_mode_set_gain_scaling"+QUOTATION+")" + NEW_LINE  + 
"            scaling = read_input_float_register(0)" + NEW_LINE  + 
"$V50        force_mode_set_gain_scaling(scaling)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"force_mode_set_gain_scaling done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 24:" + NEW_LINE  + 
"            pose = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            pose[0] = read_input_float_register(0)" + NEW_LINE  + 
"            pose[1] = read_input_float_register(1)" + NEW_LINE  + 
"            pose[2] = read_input_float_register(2)" + NEW_LINE  + 
"            pose[3] = read_input_float_register(3)" + NEW_LINE  + 
"            pose[4] = read_input_float_register(4)" + NEW_LINE  + 
"            pose[5] = read_input_float_register(5)" + NEW_LINE  + 
"            velocity = read_input_float_register(6)" + NEW_LINE  + 
"            acceleration = read_input_float_register(7)" + NEW_LINE  + 
"            q = get_inverse_kin(pose)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            enter_critical" + NEW_LINE  + 
"            servo_target = q" + NEW_LINE  + 
"            servo_time = read_input_float_register(8)" + NEW_LINE  + 
"            servo_lookahead_time = read_input_float_register(9)" + NEW_LINE  + 
"            servo_gain = read_input_float_register(10)" + NEW_LINE  + 
"            exit_critical" + NEW_LINE  + 
"" + NEW_LINE  + 
"            if is_servoing == 0:" + NEW_LINE  + 
"                is_servoing = 1" + NEW_LINE  + 
"                if servo_thrd == 0:" + NEW_LINE  + 
"                    global servo_thrd = run servo_thread()" + NEW_LINE  + 
"                end" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"        elif cmd == 25:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"tool_contact"+QUOTATION+")" + NEW_LINE  + 
"            direction = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            direction[0] = read_input_float_register(0)" + NEW_LINE  + 
"            direction[1] = read_input_float_register(1)" + NEW_LINE  + 
"            direction[2] = read_input_float_register(2)" + NEW_LINE  + 
"            direction[3] = read_input_float_register(3)" + NEW_LINE  + 
"            direction[4] = read_input_float_register(4)" + NEW_LINE  + 
"            direction[5] = read_input_float_register(5)" + NEW_LINE  + 
"$V54        time_steps = tool_contact(direction)" + NEW_LINE  + 
"$V54        write_output_integer_register(1, time_steps)" + NEW_LINE  + 
"$V54        textmsg("+QUOTATION+"tool_contact timesteps:"+QUOTATION+")" + NEW_LINE  + 
"$V54        textmsg(time_steps)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"tool_contact done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 26:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"get_steptime"+QUOTATION+")" + NEW_LINE  + 
"$V54        step_time = get_steptime()" + NEW_LINE  + 
"$V54        write_output_float_register(0, step_time)" + NEW_LINE  + 
"$V54        textmsg("+QUOTATION+"get_steptime step_time:"+QUOTATION+")" + NEW_LINE  + 
"$V54        textmsg(step_time)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"get_steptime done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 27:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"get_actual_joint_positions_history"+QUOTATION+")" + NEW_LINE  + 
"            steps = read_input_integer_register(1)" + NEW_LINE  + 
"$V54        textmsg(steps)" + NEW_LINE  + 
"$V54        joint_positions_history = get_actual_joint_positions_history(steps)" + NEW_LINE  + 
"$V54        textmsg(joint_positions_history)" + NEW_LINE  + 
"$V54        write_output_float_register(0, joint_positions_history[0])" + NEW_LINE  + 
"$V54        write_output_float_register(1, joint_positions_history[1])" + NEW_LINE  + 
"$V54        write_output_float_register(2, joint_positions_history[2])" + NEW_LINE  + 
"$V54        write_output_float_register(3, joint_positions_history[3])" + NEW_LINE  + 
"$V54        write_output_float_register(4, joint_positions_history[4])" + NEW_LINE  + 
"$V54        write_output_float_register(5, joint_positions_history[5])" + NEW_LINE  + 
"            textmsg("+QUOTATION+"get_actual_joint_positions_history done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 28:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"get_target_waypoint"+QUOTATION+")" + NEW_LINE  + 
"$V53        target_waypoint = get_target_waypoint()" + NEW_LINE  + 
"$V53        write_output_float_register(0, target_waypoint[0])" + NEW_LINE  + 
"$V53        write_output_float_register(1, target_waypoint[1])" + NEW_LINE  + 
"$V53        write_output_float_register(2, target_waypoint[2])" + NEW_LINE  + 
"$V53        write_output_float_register(3, target_waypoint[3])" + NEW_LINE  + 
"$V53        write_output_float_register(4, target_waypoint[4])" + NEW_LINE  + 
"$V53        write_output_float_register(5, target_waypoint[5])" + NEW_LINE  + 
"            textmsg("+QUOTATION+"get_target_waypoint done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 29:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"set_tcp"+QUOTATION+")" + NEW_LINE  + 
"            pose = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            pose[0] = read_input_float_register(0)" + NEW_LINE  + 
"            pose[1] = read_input_float_register(1)" + NEW_LINE  + 
"            pose[2] = read_input_float_register(2)" + NEW_LINE  + 
"            pose[3] = read_input_float_register(3)" + NEW_LINE  + 
"            pose[4] = read_input_float_register(4)" + NEW_LINE  + 
"            pose[5] = read_input_float_register(5)" + NEW_LINE  + 
"            set_tcp(pose)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"set_tcp done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 30:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"get_inverse_kin"+QUOTATION+")" + NEW_LINE  + 
"            x = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            x[0] = read_input_float_register(0)" + NEW_LINE  + 
"            x[1] = read_input_float_register(1)" + NEW_LINE  + 
"            x[2] = read_input_float_register(2)" + NEW_LINE  + 
"            x[3] = read_input_float_register(3)" + NEW_LINE  + 
"            x[4] = read_input_float_register(4)" + NEW_LINE  + 
"            x[5] = read_input_float_register(5)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            qnear = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            qnear[0] = read_input_float_register(6)" + NEW_LINE  + 
"            qnear[1] = read_input_float_register(7)" + NEW_LINE  + 
"            qnear[2] = read_input_float_register(8)" + NEW_LINE  + 
"            qnear[3] = read_input_float_register(9)" + NEW_LINE  + 
"            qnear[4] = read_input_float_register(10)" + NEW_LINE  + 
"            qnear[5] = read_input_float_register(11)" + NEW_LINE  + 
"            maxPositionError = read_input_float_register(12)" + NEW_LINE  + 
"            maxOrientationError = read_input_float_register(13)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            q = get_inverse_kin(x, qnear, maxPositionError, maxOrientationError)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            write_output_float_register(0, q[0])" + NEW_LINE  + 
"            write_output_float_register(1, q[1])" + NEW_LINE  + 
"            write_output_float_register(2, q[2])" + NEW_LINE  + 
"            write_output_float_register(3, q[3])" + NEW_LINE  + 
"            write_output_float_register(4, q[4])" + NEW_LINE  + 
"            write_output_float_register(5, q[5])" + NEW_LINE  + 
"            textmsg("+QUOTATION+"get_inverse_kin done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 31:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"protective_stop"+QUOTATION+")" + NEW_LINE  + 
"$V38        protective_stop()" + NEW_LINE  + 
"            textmsg("+QUOTATION+"protective_stop done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 32:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movep"+QUOTATION+")" + NEW_LINE  + 
"            pose = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            pose[0] = read_input_float_register(0)" + NEW_LINE  + 
"            pose[1] = read_input_float_register(1)" + NEW_LINE  + 
"            pose[2] = read_input_float_register(2)" + NEW_LINE  + 
"            pose[3] = read_input_float_register(3)" + NEW_LINE  + 
"            pose[4] = read_input_float_register(4)" + NEW_LINE  + 
"            pose[5] = read_input_float_register(5)" + NEW_LINE  + 
"            velocity = read_input_float_register(6)" + NEW_LINE  + 
"            acceleration = read_input_float_register(7)" + NEW_LINE  + 
"            blend = read_input_float_register(8)" + NEW_LINE  + 
"            movep(pose, a=acceleration, v=velocity, r=blend)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"movep done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 33:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"stopl"+QUOTATION+")" + NEW_LINE  + 
"            deceleration_rate = read_input_float_register(0)" + NEW_LINE  + 
"            stopl(deceleration_rate)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"stopl done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 34:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"stopj"+QUOTATION+")" + NEW_LINE  + 
"            deceleration_rate = read_input_float_register(0)" + NEW_LINE  + 
"            stopj(deceleration_rate)" + NEW_LINE  + 
"            textmsg("+QUOTATION+"stopj done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 35:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"set_watchdog"+QUOTATION+")" + NEW_LINE  + 
"            # Setup watchdog for the RTDE communication" + NEW_LINE  + 
"            watchdog_min_frequency = read_input_float_register(0)" + NEW_LINE  + 
"            rtde_set_watchdog("+QUOTATION+"input_int_register_23"+QUOTATION+", watchdog_min_frequency, "+QUOTATION+"stop"+QUOTATION+")" + NEW_LINE  + 
"            textmsg("+QUOTATION+"set_watchdog done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 36:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"is_pose_within_safety_limits"+QUOTATION+")" + NEW_LINE  + 
"            pose = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            pose[0] = read_input_float_register(0)" + NEW_LINE  + 
"            pose[1] = read_input_float_register(1)" + NEW_LINE  + 
"            pose[2] = read_input_float_register(2)" + NEW_LINE  + 
"            pose[3] = read_input_float_register(3)" + NEW_LINE  + 
"            pose[4] = read_input_float_register(4)" + NEW_LINE  + 
"            pose[5] = read_input_float_register(5)" + NEW_LINE  + 
"            safe_pose = is_within_safety_limits(pose)" + NEW_LINE  + 
"            if safe_pose == True:" + NEW_LINE  + 
"               write_output_integer_register(1, 1)" + NEW_LINE  + 
"            else:" + NEW_LINE  + 
"               write_output_integer_register(1, 0)" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"            textmsg("+QUOTATION+"is_pose_within_safety_limits done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 37:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"is_joints_within_safety_limits"+QUOTATION+")" + NEW_LINE  + 
"            q = [0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            q[0] = read_input_float_register(0)" + NEW_LINE  + 
"            q[1] = read_input_float_register(1)" + NEW_LINE  + 
"            q[2] = read_input_float_register(2)" + NEW_LINE  + 
"            q[3] = read_input_float_register(3)" + NEW_LINE  + 
"            q[4] = read_input_float_register(4)" + NEW_LINE  + 
"            q[5] = read_input_float_register(5)" + NEW_LINE  + 
"            safe_q = is_within_safety_limits(q)" + NEW_LINE  + 
"            if safe_q == True:" + NEW_LINE  + 
"               write_output_integer_register(1, 1)" + NEW_LINE  + 
"            else:" + NEW_LINE  + 
"               write_output_integer_register(1, 0)" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"            textmsg("+QUOTATION+"is_joints_within_safety_limits done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 38:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"get_joint_torques"+QUOTATION+")" + NEW_LINE  + 
"            torques = get_joint_torques()" + NEW_LINE  + 
"            write_output_float_register(0, torques[0])" + NEW_LINE  + 
"            write_output_float_register(1, torques[1])" + NEW_LINE  + 
"            write_output_float_register(2, torques[2])" + NEW_LINE  + 
"            write_output_float_register(3, torques[3])" + NEW_LINE  + 
"            write_output_float_register(4, torques[4])" + NEW_LINE  + 
"            write_output_float_register(5, torques[5])" + NEW_LINE  + 
"            textmsg("+QUOTATION+"get_joint_torques done"+QUOTATION+")" + NEW_LINE  + 
"        elif cmd == 39:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"pose_trans"+QUOTATION+")" + NEW_LINE  + 
"            p_from = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            p_from[0] = read_input_float_register(0)" + NEW_LINE  + 
"            p_from[1] = read_input_float_register(1)" + NEW_LINE  + 
"            p_from[2] = read_input_float_register(2)" + NEW_LINE  + 
"            p_from[3] = read_input_float_register(3)" + NEW_LINE  + 
"            p_from[4] = read_input_float_register(4)" + NEW_LINE  + 
"            p_from[5] = read_input_float_register(5)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            p_from_to = p[0, 0, 0, 0, 0, 0]" + NEW_LINE  + 
"            p_from_to[0] = read_input_float_register(6)" + NEW_LINE  + 
"            p_from_to[1] = read_input_float_register(7)" + NEW_LINE  + 
"            p_from_to[2] = read_input_float_register(8)" + NEW_LINE  + 
"            p_from_to[3] = read_input_float_register(9)" + NEW_LINE  + 
"            p_from_to[4] = read_input_float_register(10)" + NEW_LINE  + 
"            p_from_to[5] = read_input_float_register(11)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            p = pose_trans(p_from, p_from_to)" + NEW_LINE  + 
"" + NEW_LINE  + 
"            write_output_float_register(0, p[0])" + NEW_LINE  + 
"            write_output_float_register(1, p[1])" + NEW_LINE  + 
"            write_output_float_register(2, p[2])" + NEW_LINE  + 
"            write_output_float_register(3, p[3])" + NEW_LINE  + 
"            write_output_float_register(4, p[4])" + NEW_LINE  + 
"            write_output_float_register(5, p[5])" + NEW_LINE  + 
"            textmsg("+QUOTATION+"pose_trans done"+QUOTATION+")   " + NEW_LINE  + 
"        elif cmd == 255:" + NEW_LINE  + 
"            textmsg("+QUOTATION+"Received stop script!"+QUOTATION+")" + NEW_LINE  + 
"        end" + NEW_LINE  + 
"" + NEW_LINE  + 
"        if cmd != 255:" + NEW_LINE  + 
"            signal_done_with_cmd()" + NEW_LINE  + 
"        end" + NEW_LINE  + 
"" + NEW_LINE  + 
"        return cmd != 255" + NEW_LINE  + 
"    end" + NEW_LINE  + 
"" + NEW_LINE  + 
"    #" + NEW_LINE  + 
"    # RTDE Control script - Main loop" + NEW_LINE  + 
"    #" + NEW_LINE  + 
"" + NEW_LINE  + 
"    textmsg("+QUOTATION+"RTDE Control Script Loaded"+QUOTATION+")" + NEW_LINE  + 
"" + NEW_LINE  + 
"    # Initialize gain and damping for force mode to a more stable default" + NEW_LINE  + 
"$V50force_mode_set_gain_scaling(0.5)" + NEW_LINE  + 
"$V35force_mode_set_damping(0.025)" + NEW_LINE  + 
"" + NEW_LINE  + 
"    keep_running = True" + NEW_LINE  + 
"    executing_cmd = False" + NEW_LINE  + 
"    signal_ready()" + NEW_LINE  + 
"" + NEW_LINE  + 
"    while keep_running:" + NEW_LINE  + 
"        cmd = rtde_cmd()" + NEW_LINE  + 
"        if cmd == 24 or cmd == 11 or cmd == 9 or cmd == 10 or cmd == 6:" + NEW_LINE  + 
"            # servo or speed or force mode, simply process and signal ready." + NEW_LINE  + 
"            keep_running = process_cmd()" + NEW_LINE  + 
"            signal_ready()" + NEW_LINE  + 
"        else:" + NEW_LINE  + 
"            # regular mode" + NEW_LINE  + 
"            if cmd == 0:" + NEW_LINE  + 
"                executing_cmd = False" + NEW_LINE  + 
"                signal_ready()" + NEW_LINE  + 
"            else:" + NEW_LINE  + 
"                if not executing_cmd:" + NEW_LINE  + 
"                    keep_running = process_cmd()" + NEW_LINE  + 
"                end" + NEW_LINE  + 
"                executing_cmd = True" + NEW_LINE  + 
"            end" + NEW_LINE  + 
"        end" + NEW_LINE  + 
"        " + NEW_LINE  + 
"        sync()" + NEW_LINE  + 
"    end" + NEW_LINE  + 
"    textmsg("+QUOTATION+"RTDE Control Script Terminated"+QUOTATION+")" + NEW_LINE  + 
"end" + NEW_LINE  + 
"run program" + NEW_LINE  + 
"";