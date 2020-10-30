/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package de.dhbw.rahmlab.RTDE.impl;

public final class RobotMode {
  public final static RobotMode NO_CONTROLLER = new RobotMode("NO_CONTROLLER");
  public final static RobotMode DISCONNECTED = new RobotMode("DISCONNECTED");
  public final static RobotMode CONFIRM_SAFETY = new RobotMode("CONFIRM_SAFETY");
  public final static RobotMode BOOTING = new RobotMode("BOOTING");
  public final static RobotMode POWER_OFF = new RobotMode("POWER_OFF");
  public final static RobotMode POWER_ON = new RobotMode("POWER_ON");
  public final static RobotMode IDLE = new RobotMode("IDLE");
  public final static RobotMode BACKDRIVE = new RobotMode("BACKDRIVE");
  public final static RobotMode RUNNING = new RobotMode("RUNNING");

  public final int swigValue() {
    return swigValue;
  }

  public String toString() {
    return swigName;
  }

  public static RobotMode swigToEnum(int swigValue) {
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (int i = 0; i < swigValues.length; i++)
      if (swigValues[i].swigValue == swigValue)
        return swigValues[i];
    throw new IllegalArgumentException("No enum " + RobotMode.class + " with value " + swigValue);
  }

  private RobotMode(String swigName) {
    this.swigName = swigName;
    this.swigValue = swigNext++;
  }

  private RobotMode(String swigName, int swigValue) {
    this.swigName = swigName;
    this.swigValue = swigValue;
    swigNext = swigValue+1;
  }

  private RobotMode(String swigName, RobotMode swigEnum) {
    this.swigName = swigName;
    this.swigValue = swigEnum.swigValue;
    swigNext = this.swigValue+1;
  }

  private static RobotMode[] swigValues = { NO_CONTROLLER, DISCONNECTED, CONFIRM_SAFETY, BOOTING, POWER_OFF, POWER_ON, IDLE, BACKDRIVE, RUNNING };
  private static int swigNext = 0;
  private final int swigValue;
  private final String swigName;
}
