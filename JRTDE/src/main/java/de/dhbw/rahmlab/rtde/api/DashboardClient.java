package de.dhbw.rahmlab.rtde.api;

/**
 * @author Oliver Rettig (Oliver.Rettig@orat.de)
 */
public class DashboardClient extends de.dhbw.rahmlab.rtde.impl.DashboardClient {
    
    public DashboardClient(String hostname, int port, boolean verbose) {
        super(hostname, port, verbose);
    }
    public DashboardClient(String hostname, int port) {
        super(hostname, port);
    }
    public DashboardClient(String hostname) {
        super(hostname);
    }
}
