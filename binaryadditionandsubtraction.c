#include <stdio.h>
#include <string.h>

void binaryAddition(char a[], char b[], char result[]) {
    int i, carry = 0, sum;
    int lenA = strlen(a), lenB = strlen(b);
    int maxLen = (lenA > lenB) ? lenA : lenB;
    
    result[maxLen] = '\0';

    for (i = maxLen - 1; i >= 0; i--) {
        int bitA = (lenA > 0) ? a[--lenA] - '0' : 0;
        int bitB = (lenB > 0) ? b[--lenB] - '0' : 0;
        
        sum = bitA + bitB + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;           
    }

    if (carry) {
        printf("Result of binary addition: 1%s\n", result);
    } else {
        printf("Result of binary addition: %s\n", result);
    }
}

void binarySubtraction(char a[], char b[], char result[]) {
    int i, borrow = 0, diff;
    int lenA = strlen(a), lenB = strlen(b);
    int maxLen = (lenA > lenB) ? lenA : lenB;

    result[maxLen] = '\0';

    for (i = maxLen - 1; i >= 0; i--) {
        int bitA = (lenA > 0) ? a[--lenA] - '0' : 0;
        int bitB = (lenB > 0) ? b[--lenB] - '0' : 0;

        diff = bitA - bitB - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff + '0';
    }

    printf("Result of binary subtraction: %s\n", result);
}

int main() {
    char binary1[100], binary2[100], result[101];

    printf("Enter the first binary number: ");
    scanf("%s", binary1);

    printf("Enter the second binary number: ");
    scanf("%s", binary2);

    binaryAddition(binary1, binary2, result);

    binarySubtraction(binary1, binary2, result);

    return 0;
}

