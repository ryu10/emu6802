# EMU6802

[*v0.31*](https://github.com/ryu10/emu6802/releases/tag/v0.31)

([日本語](Readme.md) | EN)

  SBC with PIC16F47Q84 + MC6802, based on the [EMUZ80](https://github.com/vintagechips/emuz80).

  - RAM 12 kbytes
  - Mikbug
  - Basic with 7kB free memory
  
## How to build

Modify an EMUZ80 by adding PIC16F47Q84 and Motorola MC6802. Putting the 6802 on a breadboard is recommended.

![emu6802-breadboard](/img/emu6802bb.jpg)

## Schematics

For the connections between the 6802 and EMUZ80, see the schematic below. The right half of the schematic shows the CLC configuration of the PIC, just for an explanation purpose. No need to wire it.

![schematic](/img/emu6802_sch.png)

## PIC Code

The PIC program is based on the code of the original [EMUZ80](https://github.com/vintagechips/emuz80), and other variants such as [emuz80-hayami](https://github.com/yyhayami/emuz80_hayami).

The project is stored under [emu6802.X](/emu6802.X/). MPLAB X IDE is required to view/edit it.

The PIC18F47Q84 can be programmed with [emu6802.X.production.hex](https://github.com/ryu10/emu6802/releases/download/v0.31/emu6802.X.production.hex).

## Steps to Build

1. Build the EMUZ80 using a PIC18F47Q84.
2. Do not attach the Z80 to EMUZ80. Wire the power/bus signals pins between the CPU socket on EMUZ80 and the MC6800 on a breadboard. For the details please see the schematic above.
3. Program the PIC using [emu6802.X.production.hex](https://github.com/ryu10/emu6802/releases/download/v0.31/emu6802.X.production.hex). An appropriate PIC programmer is needed.
4. Connect an USB-serial interface to the UART port of the EMUZ80 and connect it to a terminal @ 9600 bps.
5. Turn the EMUZ80 on and you will see the Mikbug prompt ('*') on the terminal.
6. Mikbug 'Go' vector is configured at $7F48/$7F49 with the default value $0000. Press 'G' after the system startup to run the Basic.

![startup-mikbug-altair](/img/mikbug-abasic.png)

## Theory of Operation

The PIC16F47Q84 emurates the memory and UART for the MC6802. The 6802 external clock input (EXTAL) is configured at 2.0 MHz. As a memory wait period is inserted to every memory access cycle, the MPU runs below the nominal clock speed 500 kHz. When running the Basic, the avarage clock speed is about 200 kHz.

![timing2](/img/timing2.png)

(EXTAL: yellow, E: cyan, MR: magenta)

## To Do's

- Improve the memory emulation on PIC.
- Run a Basic interpreter. ✅
- Implement the interrupt pins.
- Develop an attachment PCB to the EMUZ80.
- Enable the 6802 internal 128 byte ram.
