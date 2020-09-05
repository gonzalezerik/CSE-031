#include <stdlib.h>
#include <stdio.h>
int main()
{
int repetitions;
int typoCount;
int count = 1;
printf("Enter the number of repetitions for the punishment phrase: ");
scanf("%d", &repetitions);  /* Takes inputs and assigns it to var*/
if(repetitions < 0){
printf("\n");
printf("You entered an invalid value for the number of repetitions! \n");
exit(0);
}
printf("Enter the repetition count when you wish to introduce a typo: ");
scanf("%d", &typoCount);  /* Takes inputs and assigns it to var*/
if(typoCount < 0){
printf("\n");
printf("You entered an invalid value for the typo placement! \n");
exit(0);
}
printf("\n");

while(count <= repetitions){
    if(count == typoCount){
    printf("C programmming lnguage is the bet! ");
    count++;
    }
    else{
    printf("C programming language is the best! ");
    count++;
    }
}
printf("\n");
return 0;
}
