# waters

Arduino based Analog to Digital converter for Waters 474 fluorometer.
generates two columns of data: Excitation and Emission energies.

Chart recorder (10mV full scale) output is amplified 100X by MCP604
inverting op amp and then translated to 0-1V full scale output for
Arduino INTERNAL (1.1V) analog reference.

Int: Direct integrator output (1V full scale) goes to input A0
Ex: Excitation output (1V full scale) goes to input A1
Ch: Chart Recorder (10mV full scale) amplified before going to A2

