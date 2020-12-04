package de.dhbw.rahmlab.rtde.api;

/**
 *
 * @author Oliver Rettig (Oliver.Rettig@orat.de)
 */
public interface iRobotState {
    
  public double getTimestamp();
  
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getTarget_q();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getTarget_qd();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getTarget_qdd();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getTarget_current();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getTarget_moment();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getActual_q();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getActual_qd();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getActual_current();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getJoint_control_output();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getActual_TCP_pose();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getActual_TCP_speed();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getActual_TCP_force();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getTarget_TCP_pose();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getTarget_TCP_speed();
  public java.math.BigInteger getActual_digital_input_bits();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getJoint_temperatures();
  public double getActual_execution_time();
  public int getRobot_mode();
  public long getRobot_status();
  public long getSafety_status_bits();
  public de.dhbw.rahmlab.rtde.impl.std.VectorInt getJoint_mode();
  public int getSafety_mode();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getActual_tool_accelerometer();
  public double getSpeed_scaling();
  public double getTarget_speed_fraction();
  public double getActual_momentum();
  public double getActual_main_voltage();
  public double getActual_robot_voltage();
  public double getActual_robot_current();
  public de.dhbw.rahmlab.rtde.impl.std.VectorDouble getActual_joint_voltage();
  public java.math.BigInteger getActual_digital_output_bits();
  public long getRuntime_state();
  public double getStandard_analog_input_0() ;
  public double getStandard_analog_input_1();
  public double getStandard_analog_output_0() ;
  public double getStandard_analog_output_1();
  public long getOutput_bit_registers0_to_31();
  public long getOutput_bit_registers32_to_63();
  public int getOutput_int_register_0();
  public int getOutput_int_register_1();
  public int getOutput_int_register_2();
  public int getOutput_int_register_3();
  public int getOutput_int_register_4();
  public int getOutput_int_register_5();
  public int getOutput_int_register_6();
  public int getOutput_int_register_7();
  public int getOutput_int_register_8() ;
  public int getOutput_int_register_9();
  public int getOutput_int_register_10();
  public int getOutput_int_register_11();
  public int getOutput_int_register_12();
  public int getOutput_int_register_13() ;
  public int getOutput_int_register_14();
  public int getOutput_int_register_15();
  public int getOutput_int_register_16();
  public int getOutput_int_register_17();
  public int getOutput_int_register_18();
  public int getOutput_int_register_19();
  public int getOutput_int_register_20();
  public int getOutput_int_register_21();
  public int getOutput_int_register_22();
  public int getOutput_int_register_23();
  public int getOutput_int_register_24();
  
  
  /*
  public int getOutput_int_register_25() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_25(swigCPtr, this);
  }

  public void setOutput_int_register_25(int output_int_register_25) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_25(swigCPtr, this, output_int_register_25);
  }

  public int getOutput_int_register_26() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_26(swigCPtr, this);
  }

  public void setOutput_int_register_26(int output_int_register_26) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_26(swigCPtr, this, output_int_register_26);
  }

  public int getOutput_int_register_27() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_27(swigCPtr, this);
  }

  public void setOutput_int_register_27(int output_int_register_27) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_27(swigCPtr, this, output_int_register_27);
  }

  public int getOutput_int_register_28() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_28(swigCPtr, this);
  }

  public void setOutput_int_register_28(int output_int_register_28) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_28(swigCPtr, this, output_int_register_28);
  }

  public int getOutput_int_register_29() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_29(swigCPtr, this);
  }

  public void setOutput_int_register_29(int output_int_register_29) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_29(swigCPtr, this, output_int_register_29);
  }

  public int getOutput_int_register_30() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_30(swigCPtr, this);
  }

  public void setOutput_int_register_30(int output_int_register_30) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_30(swigCPtr, this, output_int_register_30);
  }

  public int getOutput_int_register_31() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_31(swigCPtr, this);
  }

  public void setOutput_int_register_31(int output_int_register_31) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_31(swigCPtr, this, output_int_register_31);
  }

  public int getOutput_int_register_32() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_32(swigCPtr, this);
  }

  public void setOutput_int_register_32(int output_int_register_32) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_32(swigCPtr, this, output_int_register_32);
  }

  public int getOutput_int_register_33() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_33(swigCPtr, this);
  }

  public void setOutput_int_register_33(int output_int_register_33) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_33(swigCPtr, this, output_int_register_33);
  }

  public int getOutput_int_register_34() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_34(swigCPtr, this);
  }

  public void setOutput_int_register_34(int output_int_register_24) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_34(swigCPtr, this, output_int_register_24);
  }

  public int getOutput_int_register_35() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_35(swigCPtr, this);
  }

  public void setOutput_int_register_35(int output_int_register_35) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_35(swigCPtr, this, output_int_register_35);
  }

  public int getOutput_int_register_36() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_36(swigCPtr, this);
  }

  public void setOutput_int_register_36(int output_int_register_36) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_36(swigCPtr, this, output_int_register_36);
  }

  public int getOutput_int_register_37() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_37(swigCPtr, this);
  }

  public void setOutput_int_register_37(int output_int_register_37) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_37(swigCPtr, this, output_int_register_37);
  }

  public int getOutput_int_register_38() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_38(swigCPtr, this);
  }

  public void setOutput_int_register_38(int output_int_register_38) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_38(swigCPtr, this, output_int_register_38);
  }

  public int getOutput_int_register_39() {
    return de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_getOutput_int_register_39(swigCPtr, this);
  }

  public void setOutput_int_register_39(int output_int_register_39) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RobotState_setOutput_int_register_39(swigCPtr, this, output_int_register_39);
  }*/

  public int getOutput_int_register_40();
  public int getOutput_int_register_41();
  public int getOutput_int_register_42();
  public int getOutput_int_register_43();
  public int getOutput_int_register_44();
  public int getOutput_int_register_45();
  public int getOutput_int_register_46();
  public int getOutput_int_register_47();
  public double getOutput_double_register_0();
  public double getOutput_double_register_1();
  public double getOutput_double_register_2();
  public double getOutput_double_register_3();
  public double getOutput_double_register_4();
  public double getOutput_double_register_5();
  public double getOutput_double_register_6();
  public double getOutput_double_register_7();
  public double getOutput_double_register_8();
  public double getOutput_double_register_9();
  public double getOutput_double_register_10();
  public double getOutput_double_register_11();
  public double getOutput_double_register_12();
  public double getOutput_double_register_13();
  public double getOutput_double_register_14();
  public double getOutput_double_register_15();
  public double getOutput_double_register_16();
  public double getOutput_double_register_17();
  public double getOutput_double_register_18();
  public double getOutput_double_register_19();
  public double getOutput_double_register_20();
  public double getOutput_double_register_21();
  public double getOutput_double_register_22();
  public double getOutput_double_register_23();
  public double getOutput_double_register_24();
  public double getOutput_double_register_25();
  public double getOutput_double_register_26();
  public double getOutput_double_register_27();
  public double getOutput_double_register_28();
  public double getOutput_double_register_29();
  public double getOutput_double_register_30();
  public double getOutput_double_register_31();
  public double getOutput_double_register_32();
  public double getOutput_double_register_33();
  public double getOutput_double_register_34();
  public double getOutput_double_register_35();
  public double getOutput_double_register_36();
  public double getOutput_double_register_37();
  public double getOutput_double_register_38();
  public double getOutput_double_register_39();
  public double getOutput_double_register_40();
  public double getOutput_double_register_41();
  public double getOutput_double_register_42();
  public double getOutput_double_register_43();
  public double getOutput_double_register_44();
  public double getOutput_double_register_45();
  public double getOutput_double_register_46();
  public double getOutput_double_register_47();
}
