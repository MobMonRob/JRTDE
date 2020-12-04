package de.dhbw.rahmlab.rtde.test;

import de.dhbw.rahmlab.rtde.impl.std.VectorDouble;
import de.dhbw.rahmlab.rtde.impl.std.VectorString;
import de.dhbw.rahmlab.rtde.impl.ur_rtde.RTDEReceiveInterface;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Oliver Rettig (Oliver.Rettig@orat.de)
 */
public class Test1 {

    /**
     * 
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        // libjrtde.so, librtde.so, librtde.so.1.3 und librtde.so.1.3.6 müssen 
        // nach /usr/java/packages/lib
        System.loadLibrary("jrtde");
        
        int port = 30004; 
        VectorString output_names = new VectorString();
        output_names.add("timestamp");
        output_names.add("actual_q");
        
        RTDEReceiveInterface rtde_receive = new RTDEReceiveInterface("192.168.12.1", output_names, port, true);
        
        //rtde_receive.receiveCallback();
        //-->RTDE synchronization started
        // aber dann passiert nichts mehr
        
        double timestampoffset = rtde_receive.getTimestamp();
        while (true){
            try {
                double timestamp = rtde_receive.getTimestamp()-timestampoffset;
                VectorDouble qv = rtde_receive.getActualQ();
                System.out.println("timestamp = "+String.valueOf(timestamp)+" q="+qv.toString());
                //rtde_receive.receiveCallback();
                // --> damit bleibe ich hängen
                Thread.sleep(10);
            } catch (InterruptedException ex) {
                Logger.getLogger(Test1.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        
        /* The constructor takes the IP address of the robot, by default all variables are
         * transmitted. Optionally only a subset of variables, specified by a vector, are transmitted.
         */
        /*RTDEReceiveInterface rtde_receive = new RTDEReceiveInterface("192.168.12.1");
        while (true){
            VectorDouble joint_positions = rtde_receive.getActualQ();
            double timestamp = rtde_receive.getTimestamp();
            System.out.println(String.valueOf(timestamp)+": ");
            for (int i=0;i<joint_positions.size();i++){
                System.out.print("Angle"+String.valueOf(i)+": "+String.valueOf(joint_positions.get(i).doubleValue())+" ");
            }
            System.out.println();
        }*/
        
        //rtde_receive.
        
    }
    
}
