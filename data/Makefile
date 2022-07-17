all:
	dump head

head:
	xxd -i -c8 MIKBUG2.bin > MIKBUG2.h

dump:
	xxd MIKBUG2.bin > MIKBUG2.hex

# srec_cat assist09.s19 -Motorola -o assist09.hex -Intel 