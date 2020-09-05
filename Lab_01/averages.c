/*
Pseudocode:
1. Create two variables to keep track of postive/negative averages, another two to keep count of pos and neg numbers seperately, an array to store all of the user input
2. Ask user to enter a number 
3. Keep asking the user to enter a number, store it in the array, increase the index for the array, stop when the number is 0
4. Once program stops taking in input, iterate through the array, if the number is pos increase the pos count and add the number to the pos average variable, if it is negative, increase the negative count variable and add it to the negative average variable
5. If there are no negative numbers, divide the postive average value with the total positive numbers and output it. 5. If there are no postive numbers, divide the negative average value with the total negative numbers and output it. If both of the conditions are false, output both the postive and negative averages.
6. Once the averages are outputted, exit program.
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