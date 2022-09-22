all: rom16k.h

rom16k.h: rom16k.bin
	xxd -i -c8 rom16k.bin  > rom16k.h

rom16k.bin: rom16k.hex
	hex2bin rom16k.hex 

rom16k.hex: rom16k.s19
	srec_cat rom16k.s19 -Motorola -o rom16k.hex -Intel

rom16k.s19: rom16k.a
	as0 rom16k.a  -l cre s c > rom16k.list

header:
	xxd -i -c8 MIKBUG2.bin > MIKBUG2.h

dump:
	xxd MIKBUG2.bin > MIKBUG2.hex

# 540  as0 rom16k.a  -l cre s c > rom16k.list
# 541  srec_cat rom16k.s19 -Motorola -o rom16k.hex -Intel
# 543  hex2bin rom16k.hex 
# 544  xxd -i -c8 rom16k.bin  > rom16k.h