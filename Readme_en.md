# EMU6802

[v0.6]

([日本語](Readme.md) | EN)

 A two-chip computer with PIC16F47Q84 + MC6802, using the [EMUZ80](https://github.com/vintagechips/emuz80).

## TL;DR

 - [Schematic](/img/emu6802_conv_sch.pdf)
 - [Gerber](/data/emu6802r1-gerber.zip)
 - [emu6802.X.production.hex](/data/emu6802.X.production.hex)

## Features

- Adapter PCB for MC6802
- 12KB RAM
- Mikbug
- Basic with 5.5KB free RAM
- Timer with PIC TU16A connected to 6802 IRQ

![emu6802](/img/emu6802pcb.jpg)

## How to build

- Modify the EMUZ80 by adding PIC16F47Q84 and Motorola MC6802.
- Use the converter PCB ([Gerber](/data/emu6802r1-gerber.zip)).
- Attach two 20x1 pin sockets to EMUZ80 (on the sides of Z80 socket). 
- Attach a 40p DIP socket and two 20x1 pin headers to the converter PCB. C1/C2 and J3/J4/J5 are optional. 
- Use 'thin type' pin headers that fit the pin sockets.
- Connect two boards using the pin sockets and headers.

## Schematics

![schematic](/img/emu6802_conv_sch.png)

## PIC Code

Program the PIC16F47Q84 with  [emu6802.X.production.hex](/data/emu6802.X.production.hex). Remove the MC6802 (or the entire adapter PCB) when programming the PIC. The PIC source code is available under [emu6802.X](/emu6802.X/). Open the project with MPLAB X IDE.

## Starting Up

1. Connect a USB-serial interface to the UART port of the EMUZ80 and a terminal @ 9600 bps.
2. Connect a 5V power supply cable to the EMUZ80 and turn EMUZ80 on. You will see the Mikbug prompt ('*') on the terminal.
3. Mikbug 'Go' vector is configured at $2F48/$2F49 with the default value $0000. Press 'G' to start the Basic.

![startup-mikbug-altair](/img/mikbug-abasic.png)

## Theory of Operation

The PIC16F47Q84 emurates the memory, clock and UART for the MC6802. The 6802 external clock input (EXTAL) is configured at 2.3 MHz and a memory wait period is inserted into every memory access cycle. The effective clock cycle (E) is about 387kHz.

![timing2](/img/timing2.png)

(Ch1: EXTAL, Ch2: E, Ch3: MR)

## PIC Timer and 6802 IRQ

PIC Universal Timer TU16A is accessible from the 6802. Access TU16A confugration registers via 6802's mem \$A007 - \$A00F. Accessing \$A01F resets the IRQ interrupt line.

| 6802 Address | PIC Registers  |
|--------------|---------------|
| 0xa007       | TU16ACON0     |
| 0xa008       | TU16ACON1     |
| 0xa009       | TU16AHLT      |
| 0xa00a       | TU16APS       |
| 0xa00b       | TU16ATMRH / TU16ACRH |
| 0xa00c       | TU16ATMRL / TU16ACRL |
| 0xa00d       | TU16APRH      |
| 0xa00e       | TU16APRL      |
| 0xa00f       | TU16ACLK      |
| 0xa01f       | Resets IRQ input |

A clock program using TU16A and IRQ interrupt:  [clock.a](data/irq/clock.a)

![clockapp](/img/clockapp.png)

Also a built-in clock is available at 6802 mem address \$B000 - \$B003. For details see the clock program written in BASIC: [clock.bas](data/pictmr/clock.bas)

## To Do's

- Improve the memory emulation on PIC.✅
- Run a Basic interpreter. ✅
- Implement the interrupt pins.✅
- Develop an adapter PCB.✅
- ~~Enable the 6802 internal 128 byte ram. ✅~~ See [v0.33](https://github.com/ryu10/emu6802/tree/v0.33)
