#include <stdio.h>
#include <string.h>

void findTwosComplement(char binary[], char twos[]) {
    int len = strlen(binary);
    char ones[100];
    int carry = 1, i;

    printf("Step 1: Find the one's complement of b:\n");
    for (i = 0; i < len; i++) {
        ones[i] = (binary[i] == '0') ? '1' : '0';
    }
    printf("One's complement of b: %s\n", ones);
    
    for (i = len - 1; i >= 0; i--) {
        if (ones[i] == '1' && carry == 1) {
            twos[i] = '0';
        } else if (ones[i] == '0' && carry == 1) {
            twos[i] = '1';
            carry = 0;
        } else {
            twos[i] = ones[i];
        }
    }
    twos[len] = '\0';
    printf("Two's complement of b: %s\n", twos);
}

void binaryAddition(char a[], char b[], char result[]) {
    int lenA = strlen(a), lenB = strlen(b);
    int maxLen = (lenA > lenB) ? lenA : lenB;
    int carry = 0;

    result[maxLen] = '\0';

    int l = lenA - 1, m = lenB - 1, n = maxLen - 1;
    while (n >= 0) {
        int bitA = (l >= 0) ? a[l--] - '0' : 0;
        int bitB = (m >= 0) ? b[m--] - '0' : 0;

        int sum = bitA + bitB + carry;
        result[n--] = (sum % 2) + '0';
    }
}

void twosComplementSubtraction(char a[], char b[], char result[]) {
    char twosB[100];

    findTwosComplement(b, twosB);

    binaryAddition(a, twosB, result);
}

int main() {
    char binary1[100], binary2[100], result[100];

    printf("Enter the first binary number: ");
    scanf("%s", binary1);

    printf("Enter the second binary number: ");
    scanf("%s", binary2);

    twosComplementSubtraction(binary1, binary2, result);

    printf("Result of two's complement subtraction: %s\n", result);

    return 0;
}

