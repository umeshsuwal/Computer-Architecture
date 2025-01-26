#include <stdio.h>
#include <string.h>

void onesComplementSubtraction(char a[], char b[], char res[]) {
    int lenA = strlen(a), lenB = strlen(b);
    char onesB[100];
    int carry = 0, i;

    for (i = 0; i < lenB; i++) {
        onesB[i] = (b[i] == '0') ? '1' : '0';
    }
    onesB[lenB] = '\0';
    printf("One's complement of b: %s\n", onesB);

    int maxLen = (lenA > lenB) ? lenA : lenB;
    res[maxLen] = '\0';

    int l = lenA - 1, m = lenB - 1, n = maxLen - 1;
    while (n >= 0) {
        int bitA = (l >= 0) ? a[l--] - '0' : 0;
        int bitB = (m >= 0) ? onesB[m--] - '0' : 0;

        int sum = bitA + bitB + carry;
        res[n--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry) {
        char temp[100];
        res[maxLen] = '\0'; 
        for (i = 0; i < maxLen; i++) {
            temp[i] = res[i];
        }
        temp[maxLen] = '\0';
        res[0] = '1';
        for (i = 1; i <= maxLen; i++) {
            res[i] = temp[i - 1];
        }
    }
}

int main() {
    char binary1[100], binary2[100], result[100];

    printf("Enter the first binary number: ");
    scanf("%s", binary1);

    printf("Enter the second binary number: ");
    scanf("%s", binary2);

    onesComplementSubtraction(binary1, binary2, result);

    printf("Result of one's complement subtraction: %s\n", result);

    return 0;
}

