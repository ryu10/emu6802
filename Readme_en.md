# EMU6802

[*v0.33a*](https://github.com/ryu10/emu6802/releases/tag/v0.33a)

([日本語](Readme.md) | EN)

  An SBC with PIC16F47Q84 + MC6802, built on the [EMUZ80](https://github.com/vintagechips/emuz80).

  - 12KB RAM
  - Mikbug
  - Basic with 7KB free RAM
## How to build

Modify an EMUZ80 by adding PIC16F47Q84 and Motorola MC6802. For easy wiring work, it is recommended to put the 6802 on a breadboard.

![emu6802-breadboard](/img/emu6802bb.jpg)

## Schematics

For the connections between the 6802 and EMUZ80, see the schematic below. The right half of the schematic describes the configuration of the CLCs on PIC and is just an informational purpose only, you do not need to wire it.

![schematic](/img/emu6802_sch.png)

## PIC Code

The EMU6802 PIC program is based on the code of the original [EMUZ80](https://github.com/vintagechips/emuz80), and other variants such as [emuz80-hayami](https://github.com/yyhayami/emuz80_hayami).

The PIC project is stored under [emu6802.X](/emu6802.X/) of this repository. Open it with MPLAB X IDE.

You can use the pre-built hex file [emu6802.X.production.hex](https://github.com/ryu10/emu6802/releases/download/v0.31/emu6802.X.production.hex) to progam a PIC18F47Q84. An appropriate PIC programmer is required.

## Steps to Build

1. Build the EMUZ80 using a PIC18F47Q84.
2. Do not install the Z80 to EMUZ80. Wire the power/bus signals pins between the CPU socket on EMUZ80 and the MC6802 on a breadboard. For the details please see the schematic above.
3. Program the PIC using [emu6802.X.production.hex](https://github.com/ryu10/emu6802/releases/download/v0.31/emu6802.X.production.hex). An appropriate PIC programmer is needed.
4. Connect a USB-serial interface to the UART port of the EMUZ80 and a terminal @ 9600 bps.
5. Connect a 5V power supply cable to the EMUZ80 and turn EMUZ80 on. You will see the Mikbug prompt ('*') on the terminal.
6. Mikbug 'Go' vector is configured at $7F48/$7F49 with the default value $0000. Press 'G' to run the Basic.

![startup-mikbug-altair](/img/mikbug-abasic.png)

## Theory of Operation

The PIC16F47Q84 emurates the memory and UART for the MC6802. The 6802 external clock input (EXTAL) is configured at 2.0 MHz. As a memory wait period is inserted to every memory access cycle, the MPU runs below the nominal clock rate 500 kHz. When running the Basic, the avarage clock rate is about 200 kHz.

![timing2](/img/timing2.png)

(Ch1: EXTAL, Ch1: E, Ch3: MR)

## Enabling MC6802 inernal RAM

MC6802 contains a 128-byte internal RAM area from $0000-$007F. This internal RAM is enabled by setting RE (pin36) to High. Basic available ram is increased from 6106 bytes to 6234 bytes.

As the internal RAM is a physical device, i.e. it si not emulated by the PIC, you need to implment the following:

- When accessing $0000-$007F, do not stretch the mem. acc. cycle.
- Make the default MPU_DDIR to 0xff = MPU write (PIC read), so that there will not be data bus conflict.

## To Do's

- Improve the memory emulation on PIC.
- Run a Basic interpreter. ✅
- Implement the interrupt pins.
- Develop an attachment PCB to the EMUZ80.
- Enable the 6802 internal 128 byte ram. (branch 'ram128') ✅
