RaspPlc
=======

Rspberry Pi Plc

This software tries to emulate a Mitsubishi Plc (Q-Series) on a Raspberry Pi


config.conf
===========

allowed values:

  raspplc nInputs nOutputs nFlags nDataRegisters nTimers

  The Plc configuration, which defines the amount of needed Inputs, Outputs, etc.

    Example:

    raspplc 512 512 512 512 512
    
    Create 512 Inputs, Outputs, Flags, DataRegisters and Timers




  piface dStartInput dStartOutput Address

  Add a Piface module to the Plc which will be read from and written to every cycle.

    Example:

    piface d0 d1 0

    Add Piface Module at Address 0. Inputs will be mapped to d0, Outputs will be mapped to d1.


program.prg
===========

This holds the program which will be parsed to generate the program.
It is programmed in STL.


Differences to Mitsubishi
=========================

-Timers are in units of 1ms.

  Example:
  
    out t0k100

    Timer t0 is started with a time of 100ms


-There are only DWORD Devices, meaning each Data Register D is 32 Bit wide.

-Bit Devices can be Grouped together with a semicolon.

They don't need to be in units of 4 Bit like Mitsubishi requires you.

  Example:

    Move the Content of D0 to the Output Byte starting at y0

    Mitsubishi:

      ld x0
      mov d0 k2y0

    RaspPlc:

      ld x0
      mov d0 y0;y1;y2;y3;y4;y5;y6;y7

Grouped Bit Devices don't even need to be in order or being neighbours.

  Example:

    ld x0
    mov d0 y4;y8;y15;y16;y23;y42
