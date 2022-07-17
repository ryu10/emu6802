*f9dasm: M6800/1/2/3/8/9 / H6309 Binary/OS9/FLEX9 Disassembler V1.80
*Loaded Motorola S file BASPATCH.s19

*;****************************************************
*;* Used Labels                                      *
*;****************************************************

M8018   EQU     $8018
M8019   EQU     $8019

*;****************************************************
*;* Program Code / Data Areas                        *
*;****************************************************

        ORG     $041F

        JSR     Z1F85                    ;041F: BD 1F 85       '...'

        ORG     $0618 

        JSR     Z1F80                    ;0618: BD 1F 80       '...'

        ORG     $08AD 

        JSR     Z1F8D                    ;08AD: BD 1F 8D       '...'

        ORG     $1F80 

Z1F80   LDB     M8018                    ;1F80: F6 80 18       '...'
        ASRB                             ;1F83: 57             'W'
        RTS                              ;1F84: 39             '9'
Z1F85   BSR     Z1F80                    ;1F85: 8D F9          '..'
        BCC     Z1F85                    ;1F87: 24 FC          '$.'
        LDB     M8019                    ;1F89: F6 80 19       '...'
        RTS                              ;1F8C: 39             '9'
Z1F8D   BSR     Z1F80                    ;1F8D: 8D F1          '..'
        ASRB                             ;1F8F: 57             'W'
        BCC     Z1F8D                    ;1F90: 24 FB          '$.'
        ANDA    #$7F                     ;1F92: 84 7F          '..'
        STA     M8019                    ;1F94: B7 80 19       '...'
        RTS                              ;1F97: 39             '9'

        END
