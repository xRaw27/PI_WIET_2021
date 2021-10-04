#include <stdio.h>

int value(char r) {
    if (r == 'I') return 1;
    if (r == 'V') return 5;
    if (r == 'X') return 10;
    if (r == 'L') return 50;
    if (r == 'C') return 100;
    if (r == 'D') return 500;
    if (r == 'M') return 1000;
    return -1;
}

void print_roman(int d) {
    if (d == 1) printf("I");
    if (d == 4) printf("IV");
    if (d == 5) printf("V");
    if (d == 9) printf("IX");
    if (d == 10) printf("X");
    if (d == 40) printf("XL");
    if (d == 50) printf("L");
    if (d == 90) printf("XC");
    if (d == 100) printf("C");
    if (d == 400) printf("CD");
    if (d == 500) printf("D");
    if (d == 900) printf("CM");
    if (d == 1000) printf("M");
}

void decimal_to_roman(int decimal) {
    int d[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    int i = 0;
    while (decimal > 0) {
        if (decimal >= d[i]) {
            print_roman(d[i]);
            decimal -= d[i];
        } else {
            i += 1;
        }
    }
}

int roman_to_decimal(char *roman) {
    int decimal = 0;
    int t[16];

    for (int i = 0; i < 16; ++i) {
        t[i] = value(roman[i]);
    }

    for (int i = 0; i < 15; ++i) {
        if (t[i] < 0) {
            break;
        }
        if (t[i] >= t[i + 1]) {
            decimal += t[i];
        } else {
            decimal -= t[i];
        }
    }

    return decimal;
}

int main() {
    // liczba o maksymalnej długości to MMMDCCCLXXXVIII czyli 15 znaków, alkokujemy tablicę o 1 większą
    // aby przy odwoływaniu się do i + 1 indeksu nie było błędu
    char roman1[16], roman2[16];
    int decimal1, decimal2;

    for (int i = 0; i < 16; ++i) {
        roman1[i] = 0;
        roman2[i] = 0;
    }
    scanf("%s %s", roman1, roman2);

    decimal1 = roman_to_decimal(roman1);
    decimal2 = roman_to_decimal(roman2);
    decimal_to_roman(decimal1 + decimal2);

    return 0;
}

