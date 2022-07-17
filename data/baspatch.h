/*

        ORG     $7F80
Z7F80   LDB     M8018                    ;7F80: F6 80 18       '...'
        ASRB                             ;7F83: 57             'W'
        RTS                              ;7F84: 39             '9'
Z7F85   BSR     Z7F80                    ;7F85: 8D F9          '..'
        BCC     Z7F85                    ;7F87: 24 FC          '$.'
        LDB     M8019                    ;7F89: F6 80 19       '...'
        RTS                              ;7F8C: 39             '9'
Z7F8D   BSR     Z7F80                    ;7F8D: 8D F1          '..'
        ASRB                             ;7F8F: 57             'W'
        BCC     Z7F8D                    ;7F90: 24 FB          '$.'
        ANDA    #$7F                     ;7F92: 84 7F          '..'
        STA     M8019                    ;7F94: B7 80 19       '...'
        RTS                              ;7F97: 39             '9'

*/

uin8_t baspatch[] = {
  0xf6, 0x80, 0x18, 0x57, 0x39, 0x8d, 0xf9, 0x24,
  0xfc, 0xf6, 0x80, 0x19, 0x39, 0x8d, 0xf1, 0x57,
  0x24, 0xfb, 0x84, 0x7f, 0xb7, 0x80, 0x19, 0x39
};

