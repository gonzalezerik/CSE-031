#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArr(int *a, int size, char *name){
	//Your code here
        printf("\n");

    printf("%s array contents: ", name);
    for(int i = 0; i < size; i++){
        printf("%d ", *(a+i));
    }
    
}

int* arrCopy(int *a, int size){
	//Your code here ---> malloc returns a pointer to the allocated memory
    int *copy = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        *(copy + i) = *(a+i);
    }
    return copy;
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    //Dynamically create an int array of n items
    arr = (int*) malloc(n * sizeof(int));
    //Your code here

    //Ask user to input content of array
    for(i = 0; i < n; i++){
        printf("Enter array element #%d: ", i+1);
        scanf("%d", (arr+i));
    }
	//Your code here
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n, "Original");

	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n, "Copied");

    printf("\n");

    return 0;
}