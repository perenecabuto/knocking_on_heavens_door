#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

char *byte_to_binary(int n) {
    #define BITS 10

    char *buf;
    static char static_buf[BITS + 1];
    int i;

    if (buf == NULL)
        buf = static_buf;

    for (i = BITS - 1; i >= 0; --i) {
        buf[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }

    buf[BITS] = '\0';
    return buf;

    #undef BITS
}


int main() {
    uint16_t
        SHORT = 1,
        MEDIUM = 2,
        LONG = 3,
        combination = 0;

    char * secret = "LSMSL";
    int secretSize = strlen(secret);
    int i;

    for (i = 0; i < secretSize; i++) {
        combination <<= 2;

        switch(secret[i]) {
            case 'L':
                combination |= LONG;
                break;
            case 'M':
                combination |= MEDIUM;
                break;
            case 'S':
                combination |= SHORT;
                break;
        }
    }

    printf("SHORT      : %s\n", byte_to_binary(SHORT));
    printf("MEDIUM     : %s\n", byte_to_binary(MEDIUM));
    printf("LONG       : %s\n", byte_to_binary(LONG));
    printf("COMBINATION: %s\n", byte_to_binary(combination));
    printf("EXPECTED   : %s\n", "1101100111");

    return 0;
}

