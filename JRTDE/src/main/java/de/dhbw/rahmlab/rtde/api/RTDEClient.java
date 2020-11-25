package de.dhbw.rahmlab.rtde.api;

import de.dhbw.rahmlab.rtde.impl.std.VectorString;
import de.dhbw.rahmlab.rtde.impl.ur_rtde.RTDE;
import de.dhbw.rahmlab.rtde.impl.ur_rtde.RTDE.RobotCommand;

/**
 *
 * @author Oliver Rettig (Oliver.Rettig@orat.de)
 */
public class RTDEClient {
    
    private de.dhbw.rahmlab.rtde.impl.ur_rtde.RTDE client;
    
    public RTDEClient(String hostname, int port, boolean verbose) {
        client = new RTDE(hostname, port, verbose);
    }

    public RTDEClient(String hostname, int port) {
        client = new RTDE(hostname, port);
    }

    public RTDEClient(String hostname) {
        client = new RTDE(hostname);
    }
    
    public synchronized void delete(){
        client.delete();
    }
    
    public void connect() {
        client.connect();
    }

    public void disconnect() {
        client.disconnect();
    }

    public boolean isConnected() {
        return client.isConnected();
    }

    public boolean isStarted() {
        return client.isStarted();
    }

    public boolean negotiateProtocolVersion() {
        return client.negotiateProtocolVersion();
    }

    /*public SWIGTYPE_p_std__tupleT_unsigned_int_unsigned_int_unsigned_int_unsigned_int_t getControllerVersion() {
        return new SWIGTYPE_p_std__tupleT_unsigned_int_unsigned_int_unsigned_int_unsigned_int_t(de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RTDE_getControllerVersion(swigCPtr, this), true);
    }*/

    public void receive() {
        client.receive();
    }

    /*public void receiveData(de.dhbw.rahmlab.rtde.impl.std.SharedPtr robot_state) {
    de.dhbw.rahmlab.rtde.impl.RTDE_MODULEJNI.ur_rtde_RTDE_receiveData(swigCPtr, this, de.dhbw.rahmlab.rtde.impl.std.SharedPtr.getCPtr(robot_state), robot_state);
    }*/

    public void send(RobotCommand robot_cmd) {
        client.send(robot_cmd);
    }

    public void sendAll(short command, String payload) {
        client.sendAll(command, payload);
    }

    public void sendAll(short command) {
        client.sendAll(command);
    }

    public void sendStart() {
        client.sendStart();
    }

    public void sendPause() {
        client.sendPause();
    }

    public boolean sendOutputSetup(VectorString output_names, double frequency) {
        return client.sendOutputSetup(output_names, frequency);
    }

    public boolean sendInputSetup(VectorString input_names) {
        return client.sendInputSetup(input_names);
    }
}
