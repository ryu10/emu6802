all:
	dump header

header:
	xxd -i -c8 MIKBUG2.bin > MIKBUG2.h

dump:
	xxd MIKBUG2.bin > MIKBUG2.hex

# xxd -i -c8 MIKBUG2.bin > MIKBUG2.h
# srec_cat assist09.s19 -Motorola -o assist09.hex -Intel 
# f9dasm -6800 ma680bas.bin > ma680bas.a
