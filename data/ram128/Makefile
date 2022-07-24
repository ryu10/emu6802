all:	ram128.h

clean:
	rm -f ram128.s19 ram128.list ram128.bin ram128.hex ram128.h

ram128.s19:	ram128.a
	as0 ram128.a -l cre s c > ram128.list

ram128.h: ram128.s19
	srec_cat ram128.s19 -Motorola -o ram128.hex -Intel
	hex2bin ram128.hex
	xxd -i -c8 ram128.bin > ram128.h 
	