#include <stdio.h>
#include <string.h>

void onesComplement(char binary[], char ones[]) {
	int i;
    for (i = 0; binary[i] != '\0'; i++) {
        ones[i] = (binary[i] == '0') ? '1' : '0';
    }
    ones[strlen(binary)] = '\0';
}

void twosComplement(char ones[], char twos[]) {
    int carry = 1, i, length = strlen(ones);
    for (i = length - 1; i >= 0; i--) {
        if (ones[i] == '1' && carry == 1) {
            twos[i] = '0';
        } else if (ones[i] == '0' && carry == 1) {
            twos[i] = '1';
            carry = 0;
        } else {
            twos[i] = ones[i];
        }
    }
    twos[length] = '\0';
}

int main() {
    char binary[100], ones[100], twos[100];

    printf("Enter a binary number: ");
    scanf("%s", binary);

    onesComplement(binary, ones);

    twosComplement(ones, twos);

    printf("Original Binary Number:   %s\n", binary);
    printf("One's complement:  %s\n", ones);
    printf("Two's complement:  %s\n", twos);

    return 0;
}

