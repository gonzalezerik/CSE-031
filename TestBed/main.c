int main() {
 int i;
 int four_ints[4];
 char* c;

 char str[50];
   int len;

   strcpy(str, "Abc");

   len = strlen(str);
   printf("Length of |%s| is |%d|\n", str, len);

 for(i=0; i<4; i++) four_ints[i] = 2;

 c = (char*)four_ints;
 for(i=0; i<4; i++) c[i] = 1;

 printf("%x\n", four_ints[0]);
 }