package de.dhbw.rahmlab.rtde.api;

import de.dhbw.rahmlab.rtde.impl.std.SharedPtr;
import de.dhbw.rahmlab.rtde.impl.std.VectorString;
import de.dhbw.rahmlab.rtde.impl.ur_rtde.RTDE;
import de.dhbw.rahmlab.rtde.impl.ur_rtde.RTDE.RobotCommand;
import de.dhbw.rahmlab.rtde.impl.ur_rtde.RobotState;

/**
 *
 * @author Oliver Rettig (Oliver.Rettig@orat.de)
 */
public class RTDEClient {
    
    private RTDE client;
    
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

    public void receiveData(RobotState robot_state){
        boolean cMemoryOwn = true; // unklar ob true oder false richtig ist FIXME
        client.receiveData(new SharedPtr(RobotState.getCPtr(robot_state), cMemoryOwn));
    }

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
