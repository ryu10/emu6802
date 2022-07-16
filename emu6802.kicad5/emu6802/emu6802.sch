EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L pic18f47qxx:PIC18F47Q84-DIP40 U1
U 1 1 62D3B25B
P 2850 3950
F 0 "U1" H 2500 5350 50  0000 C CNN
F 1 "PIC18F47Q84-DIP40" H 2200 5200 50  0000 C CNN
F 2 "Package_DIP:DIP-40_W15.24mm" H 2700 3900 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/39682E.pdf" H 1700 5150 50  0001 C CNN
	1    2850 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 4550 3900 4550
Text Label 3900 4550 2    50   ~ 0
A15
Wire Wire Line
	3650 4450 3900 4450
Text Label 3900 4450 2    50   ~ 0
A14
Wire Wire Line
	3650 4350 3900 4350
Text Label 3900 4350 2    50   ~ 0
A13
Wire Wire Line
	3650 4250 3900 4250
Text Label 3900 4250 2    50   ~ 0
A12
Wire Wire Line
	3650 4150 3900 4150
Text Label 3900 4150 2    50   ~ 0
A11
Wire Wire Line
	3650 4050 3900 4050
Text Label 3900 4050 2    50   ~ 0
A10
Wire Wire Line
	3650 3950 3900 3950
Text Label 3900 3950 2    50   ~ 0
A9
Wire Wire Line
	3650 3850 3900 3850
Text Label 3900 3850 2    50   ~ 0
A8
Text Label 3900 3650 2    50   ~ 0
D7
Text Label 3900 3550 2    50   ~ 0
D6
Text Label 3900 3450 2    50   ~ 0
D5
Text Label 3900 3350 2    50   ~ 0
D4
Text Label 3900 3250 2    50   ~ 0
D3
Text Label 3900 3150 2    50   ~ 0
D2
Text Label 3900 3050 2    50   ~ 0
D1
Text Label 3900 2950 2    50   ~ 0
D0
Wire Wire Line
	1900 4950 1650 4950
Text Label 1650 4950 0    50   ~ 0
A7
Wire Wire Line
	1900 4850 1650 4850
Text Label 1650 4850 0    50   ~ 0
A6
Wire Wire Line
	1900 4750 1650 4750
Text Label 1650 4750 0    50   ~ 0
A5
Wire Wire Line
	1900 4650 1650 4650
Text Label 1650 4650 0    50   ~ 0
A4
Wire Wire Line
	1900 4550 1650 4550
Text Label 1650 4550 0    50   ~ 0
A3
Wire Wire Line
	1900 4450 1650 4450
Text Label 1650 4450 0    50   ~ 0
A2
Wire Wire Line
	1900 4350 1650 4350
Text Label 1650 4350 0    50   ~ 0
A1
Wire Wire Line
	1900 4250 1650 4250
Text Label 1650 4250 0    50   ~ 0
A0
Wire Wire Line
	1900 3350 1550 3350
Text Label 1550 3350 0    50   ~ 0
MPU_MR
Wire Wire Line
	1900 3250 1550 3250
Text Label 1550 3250 0    50   ~ 0
MPU_VMA
Wire Wire Line
	1900 3150 1550 3150
Text Label 1550 3150 0    50   ~ 0
MPU_E
Wire Wire Line
	1900 3450 1450 3450
Text Label 1450 3450 0    50   ~ 0
MPU_EXTAL
Wire Wire Line
	1900 3650 1550 3650
Text Label 1550 3650 0    50   ~ 0
MPU_R~W~
Wire Wire Line
	1900 3550 1550 3550
Text Label 1550 3550 0    50   ~ 0
MPU_Res
Wire Wire Line
	3650 3650 3900 3650
Wire Wire Line
	3650 3550 3900 3550
Wire Wire Line
	3650 3450 3900 3450
Wire Wire Line
	3650 3350 3900 3350
Wire Wire Line
	3650 3250 3900 3250
Wire Wire Line
	3650 3150 3900 3150
Wire Wire Line
	3650 3050 3900 3050
$Comp
L sbc6802-cache:CPU_NXP_6800_MC6802 U2
U 1 1 62D3D314
P 5250 4150
F 0 "U2" H 4800 5750 50  0000 C CNN
F 1 "MC6802" H 4450 5600 50  0000 C CNN
F 2 "Package_DIP:DIP-40_W15.24mm" H 5250 2650 50  0001 C CNN
F 3 "" H 5250 4150 50  0001 C CNN
	1    5250 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2950 3900 2950
Text Label 4500 3650 0    50   ~ 0
D7
Text Label 4500 3550 0    50   ~ 0
D6
Text Label 4500 3450 0    50   ~ 0
D5
Text Label 4500 3350 0    50   ~ 0
D4
Text Label 4500 3250 0    50   ~ 0
D3
Text Label 4500 3150 0    50   ~ 0
D2
Text Label 4500 3050 0    50   ~ 0
D1
Text Label 4500 2950 0    50   ~ 0
D0
Wire Wire Line
	4750 3650 4500 3650
Wire Wire Line
	4750 3550 4500 3550
Wire Wire Line
	4750 3450 4500 3450
Wire Wire Line
	4750 3350 4500 3350
Wire Wire Line
	4750 3250 4500 3250
Wire Wire Line
	4750 3150 4500 3150
Wire Wire Line
	4750 3050 4500 3050
Wire Wire Line
	4750 2950 4500 2950
Wire Wire Line
	5750 4450 6000 4450
Text Label 6000 4450 2    50   ~ 0
A15
Wire Wire Line
	5750 4350 6000 4350
Text Label 6000 4350 2    50   ~ 0
A14
Wire Wire Line
	5750 4250 6000 4250
Text Label 6000 4250 2    50   ~ 0
A13
Wire Wire Line
	5750 4150 6000 4150
Text Label 6000 4150 2    50   ~ 0
A12
Wire Wire Line
	5750 4050 6000 4050
Text Label 6000 4050 2    50   ~ 0
A11
Wire Wire Line
	5750 3950 6000 3950
Text Label 6000 3950 2    50   ~ 0
A10
Wire Wire Line
	5750 3850 6000 3850
Text Label 6000 3850 2    50   ~ 0
A9
Wire Wire Line
	5750 3750 6000 3750
Text Label 6000 3750 2    50   ~ 0
A8
Wire Wire Line
	5750 3650 6000 3650
Text Label 6000 3650 2    50   ~ 0
A7
Wire Wire Line
	5750 3550 6000 3550
Text Label 6000 3550 2    50   ~ 0
A6
Wire Wire Line
	5750 3450 6000 3450
Text Label 6000 3450 2    50   ~ 0
A5
Wire Wire Line
	5750 3350 6000 3350
Text Label 6000 3350 2    50   ~ 0
A4
Wire Wire Line
	5750 3250 6000 3250
Text Label 6000 3250 2    50   ~ 0
A3
Wire Wire Line
	5750 3150 6000 3150
Text Label 6000 3150 2    50   ~ 0
A2
Wire Wire Line
	5750 3050 6000 3050
Text Label 6000 3050 2    50   ~ 0
A1
Wire Wire Line
	5750 2950 6000 2950
Text Label 6000 2950 2    50   ~ 0
A0
Wire Wire Line
	4750 3850 4400 3850
Text Label 4400 3850 0    50   ~ 0
MPU_MR
Wire Wire Line
	4750 3950 4400 3950
Text Label 4400 3950 0    50   ~ 0
MPU_E
Wire Wire Line
	4750 4750 4300 4750
Text Label 4300 4750 0    50   ~ 0
MPU_EXTAL
Wire Wire Line
	5750 4850 6100 4850
Text Label 6100 4850 2    50   ~ 0
MPU_R~W~
Wire Wire Line
	4750 4050 4400 4050
Wire Wire Line
	5750 4750 6100 4750
Text Label 6100 4750 2    50   ~ 0
MPU_VMA
Text Label 4400 4050 0    50   ~ 0
MPU_Res
$Comp
L power:GND #PWR08
U 1 1 62D72D70
P 2850 5350
F 0 "#PWR08" H 2850 5100 50  0001 C CNN
F 1 "GND" H 2855 5177 50  0000 C CNN
F 2 "" H 2850 5350 50  0001 C CNN
F 3 "" H 2850 5350 50  0001 C CNN
	1    2850 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 5550 5150 5550
Wire Wire Line
	5100 2750 5250 2750
$Comp
L power:+5V #PWR07
U 1 1 62D77248
P 2850 2500
F 0 "#PWR07" H 2850 2350 50  0001 C CNN
F 1 "+5V" H 2865 2673 50  0000 C CNN
F 2 "" H 2850 2500 50  0001 C CNN
F 3 "" H 2850 2500 50  0001 C CNN
	1    2850 2500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR013
U 1 1 62D778D7
P 4450 4350
F 0 "#PWR013" H 4450 4200 50  0001 C CNN
F 1 "+5V" H 4465 4523 50  0000 C CNN
F 2 "" H 4450 4350 50  0001 C CNN
F 3 "" H 4450 4350 50  0001 C CNN
	1    4450 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4150 4750 4250
Connection ~ 4750 4250
Wire Wire Line
	4750 4250 4750 4350
Wire Wire Line
	4450 4350 4750 4350
Connection ~ 4750 4350
$Comp
L power:GND #PWR014
U 1 1 62D80B10
P 4450 4450
F 0 "#PWR014" H 4450 4200 50  0001 C CNN
F 1 "GND" H 4455 4277 50  0000 C CNN
F 2 "" H 4450 4450 50  0001 C CNN
F 3 "" H 4450 4450 50  0001 C CNN
	1    4450 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4450 4450 4450
Wire Wire Line
	4600 4550 4750 4550
Wire Wire Line
	4600 4450 4600 4550
NoConn ~ 5750 4650
NoConn ~ 3650 4750
NoConn ~ 3650 4850
NoConn ~ 3650 4950
Wire Wire Line
	1900 3850 1550 3850
$Comp
L Device:C C3
U 1 1 62D9C627
P 1950 6800
F 0 "C3" H 1900 7200 50  0000 L CNN
F 1 "0.1u" H 1900 7100 50  0000 L CNN
F 2 "" H 1988 6650 50  0001 C CNN
F 3 "~" H 1950 6800 50  0001 C CNN
	1    1950 6800
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 62D9CE82
P 1700 6800
F 0 "C2" H 1650 7200 50  0000 L CNN
F 1 "10u" H 1650 7100 50  0000 L CNN
F 2 "" H 1738 6650 50  0001 C CNN
F 3 "~" H 1700 6800 50  0001 C CNN
	1    1700 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 2500 2850 2650
Wire Wire Line
	2850 5350 2850 5250
Wire Wire Line
	2850 2650 2750 2650
Connection ~ 2850 2650
Wire Wire Line
	2850 5250 2750 5250
Connection ~ 2850 5250
$Comp
L power:GND #PWR017
U 1 1 62DAE438
P 5350 5650
F 0 "#PWR017" H 5350 5400 50  0001 C CNN
F 1 "GND" H 5355 5477 50  0000 C CNN
F 2 "" H 5350 5650 50  0001 C CNN
F 3 "" H 5350 5650 50  0001 C CNN
	1    5350 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 5650 5350 5550
Connection ~ 5350 5550
$Comp
L power:GND #PWR015
U 1 1 62DB17FD
P 4450 4900
F 0 "#PWR015" H 4450 4650 50  0001 C CNN
F 1 "GND" H 4455 4727 50  0000 C CNN
F 2 "" H 4450 4900 50  0001 C CNN
F 3 "" H 4450 4900 50  0001 C CNN
	1    4450 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4900 4450 4900
$Comp
L Switch:SW_Push S2
U 1 1 62DB5007
P 1250 3150
F 0 "S2" V 1296 3298 50  0000 L CNN
F 1 "Reest" V 1205 3298 50  0000 L CNN
F 2 "" H 1250 3350 50  0001 C CNN
F 3 "~" H 1250 3350 50  0001 C CNN
	1    1250 3150
	0    1    -1   0   
$EndComp
$Comp
L Device:D_ALT D1
U 1 1 62DB5793
P 3500 1600
F 0 "D1" H 3500 1817 50  0000 C CNN
F 1 "1N4148" H 3500 1726 50  0000 C CNN
F 2 "" H 3500 1600 50  0001 C CNN
F 3 "~" H 3500 1600 50  0001 C CNN
	1    3500 1600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 CON2
U 1 1 62DB7187
P 3000 1500
F 0 "CON2" H 2918 1917 50  0000 C CNN
F 1 "Conn_01x06" H 2918 1826 50  0000 C CNN
F 2 "" H 3000 1500 50  0001 C CNN
F 3 "~" H 3000 1500 50  0001 C CNN
	1    3000 1500
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 CON1
U 1 1 62DB7D0E
P 1500 1600
F 0 "CON1" H 1418 2117 50  0000 C CNN
F 1 "Conn_01x08" H 1418 2026 50  0000 C CNN
F 2 "" H 1500 1600 50  0001 C CNN
F 3 "~" H 1500 1600 50  0001 C CNN
	1    1500 1600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1550 3750 1900 3750
Text Label 1550 3750 0    50   ~ 0
TX
Text Label 1550 3850 0    50   ~ 0
RX
Text Label 4100 1600 2    50   ~ 0
RX
Text Label 4100 1700 2    50   ~ 0
TX
$Comp
L power:GND #PWR010
U 1 1 62DD62B1
P 3300 1800
F 0 "#PWR010" H 3300 1550 50  0001 C CNN
F 1 "GND" H 3305 1627 50  0000 C CNN
F 2 "" H 3300 1800 50  0001 C CNN
F 3 "" H 3300 1800 50  0001 C CNN
	1    3300 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 1800 3300 1800
Wire Wire Line
	1700 1300 1850 1300
Text Label 1850 1300 2    50   ~ 0
RE3
$Comp
L power:+5V #PWR04
U 1 1 62DE6741
P 2050 1400
F 0 "#PWR04" H 2050 1250 50  0001 C CNN
F 1 "+5V" H 2065 1573 50  0000 C CNN
F 2 "" H 2050 1400 50  0001 C CNN
F 3 "" H 2050 1400 50  0001 C CNN
	1    2050 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1400 2050 1400
$Comp
L power:GND #PWR05
U 1 1 62DEA3A1
P 2050 1500
F 0 "#PWR05" H 2050 1250 50  0001 C CNN
F 1 "GND" H 2055 1327 50  0000 C CNN
F 2 "" H 2050 1500 50  0001 C CNN
F 3 "" H 2050 1500 50  0001 C CNN
	1    2050 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 1500 1700 1500
Text Label 1550 2950 0    50   ~ 0
RE3
Wire Wire Line
	1700 1600 1850 1600
Text Label 1850 1600 2    50   ~ 0
RB7
Wire Wire Line
	1700 1700 1850 1700
Text Label 1850 1700 2    50   ~ 0
RB6
NoConn ~ 1700 1800
NoConn ~ 1700 1900
NoConn ~ 1700 2000
NoConn ~ 3200 1400
NoConn ~ 3200 1500
$Comp
L Device:R R1
U 1 1 62E31575
P 3850 1400
F 0 "R1" H 3920 1446 50  0000 L CNN
F 1 "10k" H 3920 1355 50  0000 L CNN
F 2 "" V 3780 1400 50  0001 C CNN
F 3 "~" H 3850 1400 50  0001 C CNN
	1    3850 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1550 3850 1600
Wire Wire Line
	3850 1600 3650 1600
Wire Wire Line
	3850 1600 4100 1600
Connection ~ 3850 1600
$Comp
L power:+5V #PWR012
U 1 1 62E40936
P 3850 1250
F 0 "#PWR012" H 3850 1100 50  0001 C CNN
F 1 "+5V" H 3865 1423 50  0000 C CNN
F 2 "" H 3850 1250 50  0001 C CNN
F 3 "" H 3850 1250 50  0001 C CNN
	1    3850 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 1600 3200 1600
Wire Wire Line
	3200 1700 4100 1700
NoConn ~ 3200 1300
$Comp
L power:GND #PWR03
U 1 1 62E661DD
P 1250 3350
F 0 "#PWR03" H 1250 3100 50  0001 C CNN
F 1 "GND" H 1255 3177 50  0000 C CNN
F 2 "" H 1250 3350 50  0001 C CNN
F 3 "" H 1250 3350 50  0001 C CNN
	1    1250 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 62E669BA
P 1250 2700
F 0 "R2" H 1320 2746 50  0000 L CNN
F 1 "10k" H 1320 2655 50  0000 L CNN
F 2 "" V 1180 2700 50  0001 C CNN
F 3 "~" H 1250 2700 50  0001 C CNN
	1    1250 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 62E669C4
P 1250 2550
F 0 "#PWR02" H 1250 2400 50  0001 C CNN
F 1 "+5V" H 1265 2723 50  0000 C CNN
F 2 "" H 1250 2550 50  0001 C CNN
F 3 "" H 1250 2550 50  0001 C CNN
	1    1250 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 2850 1250 2950
Wire Wire Line
	1250 2950 1900 2950
Connection ~ 1250 2950
$Comp
L Device:C C4
U 1 1 62E80AB3
P 2200 6800
F 0 "C4" H 2150 7200 50  0000 L CNN
F 1 "0.1u" H 2150 7100 50  0000 L CNN
F 2 "" H 2238 6650 50  0001 C CNN
F 3 "~" H 2200 6800 50  0001 C CNN
	1    2200 6800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 62E80D77
P 2450 6800
F 0 "C5" H 2400 7200 50  0000 L CNN
F 1 "0.1u" H 2400 7100 50  0000 L CNN
F 2 "" H 2488 6650 50  0001 C CNN
F 3 "~" H 2450 6800 50  0001 C CNN
	1    2450 6800
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 62E81174
P 1450 6800
F 0 "C1" H 1400 7200 50  0000 L CNN
F 1 "10u" H 1400 7100 50  0000 L CNN
F 2 "" H 1488 6650 50  0001 C CNN
F 3 "~" H 1450 6800 50  0001 C CNN
	1    1450 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 6950 1700 6950
Connection ~ 1700 6950
Wire Wire Line
	1700 6950 1950 6950
Connection ~ 1950 6950
Wire Wire Line
	1950 6950 2200 6950
Connection ~ 2200 6950
Wire Wire Line
	2200 6950 2450 6950
Wire Wire Line
	2450 6650 2200 6650
Connection ~ 1450 6650
Wire Wire Line
	1450 6650 1150 6650
Connection ~ 1700 6650
Wire Wire Line
	1700 6650 1450 6650
Connection ~ 1950 6650
Wire Wire Line
	1950 6650 1700 6650
Connection ~ 2200 6650
Wire Wire Line
	2200 6650 1950 6650
$Comp
L power:+5V #PWR01
U 1 1 62E932FA
P 1150 6650
F 0 "#PWR01" H 1150 6500 50  0001 C CNN
F 1 "+5V" H 1165 6823 50  0000 C CNN
F 2 "" H 1150 6650 50  0001 C CNN
F 3 "" H 1150 6650 50  0001 C CNN
	1    1150 6650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 62E9371A
P 2450 6950
F 0 "#PWR06" H 2450 6700 50  0001 C CNN
F 1 "GND" H 2455 6777 50  0000 C CNN
F 2 "" H 2450 6950 50  0001 C CNN
F 3 "" H 2450 6950 50  0001 C CNN
	1    2450 6950
	1    0    0    -1  
$EndComp
Connection ~ 2450 6950
$Comp
L power:+5V #PWR016
U 1 1 62EE3E88
P 5250 2750
F 0 "#PWR016" H 5250 2600 50  0001 C CNN
F 1 "+5V" H 5265 2923 50  0000 C CNN
F 2 "" H 5250 2750 50  0001 C CNN
F 3 "" H 5250 2750 50  0001 C CNN
	1    5250 2750
	1    0    0    -1  
$EndComp
Connection ~ 5250 2750
$Comp
L Connector:Barrel_Jack_Switch J3
U 1 1 62EE5066
P 3850 6700
F 0 "J3" H 3620 6742 50  0000 R CNN
F 1 "Barrel_Jack_Switch" H 3620 6651 50  0000 R CNN
F 2 "" H 3900 6660 50  0001 C CNN
F 3 "~" H 3900 6660 50  0001 C CNN
	1    3850 6700
	-1   0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST S1
U 1 1 62EE6849
P 3200 6600
F 0 "S1" H 3200 6835 50  0000 C CNN
F 1 "SW_SPST" H 3200 6744 50  0000 C CNN
F 2 "" H 3200 6600 50  0001 C CNN
F 3 "~" H 3200 6600 50  0001 C CNN
	1    3200 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 6600 3400 6600
$Comp
L power:+5V #PWR09
U 1 1 62EEC768
P 2850 6500
F 0 "#PWR09" H 2850 6350 50  0001 C CNN
F 1 "+5V" H 2865 6673 50  0000 C CNN
F 2 "" H 2850 6500 50  0001 C CNN
F 3 "" H 2850 6500 50  0001 C CNN
	1    2850 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 6500 2850 6600
Wire Wire Line
	2850 6600 3000 6600
$Comp
L power:GND #PWR011
U 1 1 62EF1AA3
P 3350 6800
F 0 "#PWR011" H 3350 6550 50  0001 C CNN
F 1 "GND" H 3355 6627 50  0000 C CNN
F 2 "" H 3350 6800 50  0001 C CNN
F 3 "" H 3350 6800 50  0001 C CNN
	1    3350 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 6800 3550 6800
$Comp
L 4xxx:4013 UX4
U 1 1 62EFFDB6
P 9700 4400
F 0 "UX4" H 9850 4750 50  0000 C CNN
F 1 "CLC2" H 9700 4400 50  0000 C CNN
F 2 "" H 9700 4400 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 9700 4400 50  0001 C CNN
	1    9700 4400
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4081 UX3
U 1 1 62F00D8C
P 9550 2800
F 0 "UX3" H 9550 3125 50  0000 C CNN
F 1 "CLC1" H 9550 3034 50  0000 C CNN
F 2 "" H 9550 2800 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4073bms-81bms-82bms.pdf" H 9550 2800 50  0001 C CNN
	1    9550 2800
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 UX1
U 1 1 62F0464B
P 8850 2700
F 0 "UX1" H 8850 3017 50  0000 C CNN
F 1 "CLC1" H 8850 2926 50  0000 C CNN
F 2 "" H 8850 2700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 8850 2700 50  0001 C CNN
	1    8850 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 2700 9150 2700
Wire Wire Line
	10000 4300 10150 4300
Text GLabel 10150 4300 2    50   Input ~ 0
RA2
$Comp
L 74xx:74LS04 UX2
U 1 1 62F26A3E
P 9000 4550
F 0 "UX2" H 8950 4400 50  0000 C CNN
F 1 "CLC1" H 8950 4550 50  0000 C CNN
F 2 "" H 9000 4550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 9000 4550 50  0001 C CNN
	1    9000 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 4400 9300 4400
Wire Wire Line
	9300 4400 9300 4550
Text GLabel 8650 4550 0    50   Input ~ 0
NCO1_OUT
Text GLabel 8400 2700 0    50   Input ~ 0
RA0
Text GLabel 8400 2900 0    50   Input ~ 0
RA1
Wire Wire Line
	8550 2700 8400 2700
Wire Wire Line
	8400 2900 9250 2900
Text GLabel 9950 2800 2    50   Input ~ 0
CLC1_INTP
Wire Wire Line
	9850 2800 9950 2800
Text GLabel 8750 4300 0    50   Input ~ 0
CLC2_G2POL
Wire Wire Line
	8750 4300 9400 4300
Text GLabel 8750 4000 0    50   Input ~ 0
CLC2_G3POL
Wire Wire Line
	9700 4100 9700 4000
Wire Wire Line
	9700 4000 8750 4000
$Comp
L power:GND #PWR018
U 1 1 62F727F3
P 9700 4700
F 0 "#PWR018" H 9700 4450 50  0001 C CNN
F 1 "GND" H 9705 4527 50  0000 C CNN
F 2 "" H 9700 4700 50  0001 C CNN
F 3 "" H 9700 4700 50  0001 C CNN
	1    9700 4700
	1    0    0    -1  
$EndComp
NoConn ~ 10000 4500
Text Notes 7800 4350 0    50   ~ 0
MPU_MRDY
Text Notes 7750 4600 0    50   ~ 0
MPU_EXTAL
Text Notes 7700 4050 0    50   ~ 0
MRDY_FF_RES
Text Notes 7500 2200 0    94   ~ 0
CLC1
Text Notes 7500 3650 0    94   ~ 0
CLC2
Text Notes 7500 5150 0    94   ~ 0
NCO1
Text Notes 10400 4350 0    50   ~ 0
MPU_MR
Text Notes 7900 2750 0    50   ~ 0
MPU_E
Text Notes 7800 2950 0    50   ~ 0
MPU_VMA
$Comp
L Oscillator:ACO-xxxMHz XA1
U 1 1 62FA4C08
P 8550 5550
F 0 "XA1" H 8206 5596 50  0000 R CNN
F 1 "2MHz" H 8206 5505 50  0000 R CNN
F 2 "Oscillator:Oscillator_DIP-14" H 9000 5200 50  0001 C CNN
F 3 "http://www.conwin.com/datasheets/cx/cx030.pdf" H 8450 5550 50  0001 C CNN
	1    8550 5550
	1    0    0    -1  
$EndComp
NoConn ~ 8550 5250
NoConn ~ 8550 5850
Text GLabel 9000 5550 2    50   Input ~ 0
RA3\NCO1_OUT
Wire Wire Line
	9000 5550 8850 5550
Wire Wire Line
	8700 4550 8650 4550
Text Notes 9650 5550 0    50   ~ 0
MPU_EXTAL
Text Notes 7550 7500 0    50   ~ 0
EMU6802, derived from EMUZ80
$EndSCHEMATC
