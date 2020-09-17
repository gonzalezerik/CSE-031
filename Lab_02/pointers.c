#include <stdio.h>
int main()
{
int x =0, y=0, *px = &x, *py=&y;

printf("%p\n", &x);

printf("%p\n",px);
printf("%p\n",py);


printf("%p\n",&px);
printf("%p\n",&py);


int arr[10];
for(int i = 0; i++; i <10){
    arr[i] = i; 
}
for(int i = 0; i++; i <10){
   printf("content of %d element is %d arr+i is %p \n", i, *(arr+i), arr+i);
}
printf("\n");
printf("arr %p, address of arr[0] %p", arr, &arr[0]);
printf("\n");

printf("arr address is %p", &arr);
printf("\n");
printf("%d\n",arr[0]);

return 0;
}
