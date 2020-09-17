/*
Pseudocode:

 input integer
 size = size + 1

 while number != 0:
     input integer
     size = size + 1

 for i less than size of array:
     if arr value > 0:
     	negative average += arr value
	
     if arr value < 0:
         positive average += arr value

 if positive average = 0:
     print negative average
 else if negative average = 0:
     print positive average
 else:
	print positive average
	print negative average
*/

#include <stdlib.h>
#include <stdio.h>
int main(){
    int avg_pos = 0;
    int avg_neg = 0;
    int neg_count = 0;
    int pos_count = 0;

    int size = 0;
    int nums[size]; //create number array 
    int input;

    do{
        printf("Please enter an integer: ");
        scanf("%d", &input);
        nums[size] = input;
        size++;
    }while(input!= 0);

    for(int i = 0; i < size; i++){//iterate through our input
        if(nums[i] > 0){            //if pos
            avg_pos = avg_pos + nums[i];
            pos_count++;
    }
    else if(nums[i] < 0){//if neg
        avg_neg = avg_neg + nums[i];
        neg_count++;
    }

    }
    printf("\n");
    if(pos_count == 0){//no pos numbers
        avg_neg = avg_neg/neg_count;
        printf("Negative average: %d \n", avg_neg);
    }
    else if(neg_count == 0){
        avg_pos = avg_pos/pos_count;
        printf("Positive average: %d \n", avg_pos);

    }
    else{
        avg_neg = avg_neg/neg_count;
        avg_pos = avg_pos/pos_count;

        printf("Positive average: %d \n", avg_pos);
        printf("Negative average: %d \n", avg_neg);

    }

    

    return 0;
}