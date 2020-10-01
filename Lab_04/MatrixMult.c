#include <stdio.h>
#include <malloc.h>


void allocater(int **arr, int n, int val){ //it seems that we aren't able to allocate things into memory (used from a previous lab)
	for(int i = 0; i < n; i++){

		*(arr + i) = (int*)malloc(n * sizeof(int));
		for(int j = 0; j < n; j++){
			*(*(arr + i) + j) = val;
		}
	}
}

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int** c = (int**)malloc(size * sizeof(int*));
	allocater(c, size, 0);

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			*(*(c + i) + j) = 0;
			for(int k = 0; k < size; k++)
			{
				*(*(c + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
			}

				*(*(c+ i)+ j)= *(*(c + i) + j);
		}
	}
	return c;


}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d", *(*(arr + i) + j));
			
		}
		printf("\n");
	}
	printf("\n");
}




int main() {
	int n = 2;
	int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices). 
	matA = (int**)malloc(n * sizeof(int*));
	allocater(matA, n, 1);
	matB = (int**)malloc(n * sizeof(int*));
	allocater(matB, n, 10);

	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printArray(matB, n);
	//(5) Call matMult to multiply the 2 arrays here.
	matC = (int**)malloc(n * sizeof(int*));
	allocater(matC, n, 0);
	matC = matMult(matA, matB, n);

	//(6) Call printArray to print out resulting array here.
	printArray(matC, n);



    return 0;
}