#include <stdio.h>

int main() {
 int eight_ints[8] = {1, 2, 3, 4, 5, 6, 7, 8};
 char *a;
 long *b;
 int i;
 //ASCII of ‘A’ is 65 or 0x41
 a = (char*)eight_ints;
 b = (long*)eight_ints;
 for (i = 4; i <8; i++)
    a[i] = 'A';
 printf("%x\n", b[1]); //0x34
 }
