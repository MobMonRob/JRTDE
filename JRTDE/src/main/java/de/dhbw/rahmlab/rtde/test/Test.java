package de.dhbw.rahmlab.rtde.test;

import de.dhbw.rahmlab.rtde.api.RTDEClient;
import de.dhbw.rahmlab.rtde.impl.std.VectorDouble;
import de.dhbw.rahmlab.rtde.impl.std.VectorString;
import de.dhbw.rahmlab.rtde.impl.ur_rtde.RTDEReceiveInterface;
import de.dhbw.rahmlab.rtde.impl.ur_rtde.RobotState;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Oliver Rettig (Oliver.Rettig@orat.de)
 */
public class Test {

    /**
     * https://github.com/UniversalRobots/Universal_Robots_Client_Library
     * --> vermutlich am besten selber bauen
     * 
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        try {
            // https://www.osetc.com/en/how-to-install-boost-on-ubuntu-16-04-18-04-linux.html
            
            // dpkg -s libboost-dev | grep Version
            // --> Versionsnummer
            
            // sudo apt-get upgrade libboost-dev
            // libboost-dev ist schon die neueste Version (1.58.0.1ubuntu1)
            
            // warum wir das lib-path def in den run-properties nicht berücksichtigt?
            //  /usr/java/packages/lib:/usr/lib64:/lib64:/lib:/usr/lib
            //System.out.println("library path: "+System.getProperty("java.library.path"));
            
            
            // ldd librtde.so
            // ./librtde.so: /lib/x86_64-linux-gnu/libm.so.6: version `GLIBC_2.29' not found (required by ./librtde.so)
            // ./librtde.so: /usr/lib/x86_64-linux-gnu/libstdc++.so.6: version `GLIBCXX_3.4.26' not found (required by ./librtde.so)
            // linux-vdso.so.1 =>  (0x00007fff1c385000)
            // libboost_thread.so.1.71.0 => not found
            // libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f534935f000)
            // libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f5348fdd000)
            // libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f5348cd4000)
            // libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f5348abe000)
            // libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f53486f4000)
            // /lib64/ld-linux-x86-64.so.2 (0x00007f5349788000)
            
            // Exception in thread "main" java.lang.UnsatisfiedLinkError: /usr/java/packages/lib/libjrtde.so: libboost_thread.so.1.71.0:
            // Kann die Shared-Object-Datei nicht öffnen: Datei oder Verzeichnis nicht gefunden
            
            System.loadLibrary("jrtde");
            
            // hierher zu verschieben hat auch nichts gebracht
            //RobotState robotState = new RobotState();
            
            int port = 30004;
            RTDEClient client = new RTDEClient("192.168.12.1", port, true);
            VectorString output_names = new VectorString();
            output_names.add("actual_q");
            output_names.add("timestamp");
            VectorString input_names = new VectorString();
            
            System.out.println("Try to connect ...");
            client.connect();
            System.out.println("is connected ="+client.isConnected());
            
            // crashed die VM wenn vorher nicht connected wurde
            client.sendOutputSetup(output_names, 500);
            client.sendInputSetup(input_names);
            
            RobotState robotState = new RobotState();
            
            // testweise
            Thread.sleep(10);

            // Right after calling my_client.start(), it should be made sure to read
            // the buffer from the RTDEClient by calling getDataPackage() frequently.
            // The Client's queue can only contain 1 item at a time, so a Pipeline
            // producer overflowed! error will be raised if the buffer isn't read
            // before the next package arrives.
            client.sendStart();
            // --> // Unable to start synchronization
            System.out.println("sendStart() invoked!");
            System.out.println("is Started = "+client.isConnected());
            
            // im c++ code wird der robotstate erst nach dem start erzeugt
            // möglicherweise muss ich diesen aber bereits vor dem Initialisieren
            // des clients erzeugen?
            // an dieser Stelle hats jedefalls nicht funktioniert.
            //RobotState robotState = new RobotState();
            
            Thread.sleep(10);
            
            //TODO vielleicht muss ich das in einen eigenen thread auslagern?
            long counter = 100;
            boolean running = true;
            while (counter > 0 && running){
                counter--;
                try {
                    System.out.println("before receive...");
                    client.receiveData(robotState); // sollte exception feuern können, dann prüfen ob noch connected und wenn ja aktiv disconnecten und die schleife beenden, d.h. running auf false setzen
                    //robotState.lockUpdateStateMutex();
                    double timestamp = robotState.getTimestamp();
                    //robotState.unlockUpdateStateMutex();
                    System.out.println("timestamp = "+String.valueOf(timestamp));
                    Thread.sleep(2); // 100us sollten reichen
                } catch (InterruptedException ex) {
                    Logger.getLogger(Test.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            
            client.disconnect();
           
        } catch (InterruptedException ex) {
            Logger.getLogger(Test.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
