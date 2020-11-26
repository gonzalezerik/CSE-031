#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);

// Main function, DO NOT MODIFY!!!	
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
	char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

	// Read puzzle block into 2D arrays
    for(i=0; i<bSize; i++){
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
	
	// Save words into arrays
	for(i=0; i<50; i++){
		*(words+i) = (char*)malloc(20 * sizeof(char));
		fgets(*(words+i), 20, fptr);		
	}
	
	// Remove newline characters from each word (except for the last word)
	for(i=0; i<49; i++){
		*(*(words+i) + strlen(*(words+i))-2) = '\0';	
	}
	
	// Print out word list
	printf("Printing list of words:\n");
	for(i=0; i<50; i++){
		printf("%s\n", *(words + i));		
	}
	printf("\n");
	
	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");

	// Call searchPuzzle to find all words in the puzzle
	searchPuzzle(block, bSize, words, 50);
	printf("\n");
	
	// Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
	printf("\n");
	
    return 0;
}

void printPuzzle(char** arr, int n){
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
	for(int i = 0; i< n; i++){
		for(int j=0; j<n; j++){
			printf("%c ", *(*(arr+i)+j));
		}
		printf("\n");
	}


}

void searchPuzzle(char** arr, int n, char** list, int listSize){
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here
	char* ptr;
	bool isFound = false;
	int searchCase = 0;
	//loop through states
	for(int k = 0; k < listSize; k++){
		int word=0;
		//ptr to the state
		ptr = *(list + k);
		while(*(*(list + k)+word) != NULL){
			word++;
		}
		//loop through the rows of the wordsearch
		for(int i = 0; i<n; i++){
			isFound = false;;
			//loop through the cols of the wordsearch
			for(int j=0; j<n; j++){
				//check first letter of the state with the letter in the spot in the wordsearch
				if(*(ptr) == *(*(arr + i)+ j) || (*(ptr)+32) == *(*(arr + i)+ j) ){

					// search check left to right
					if( ((((i) < n) && (j+1)<n)) ){
						for(int h=1; ((((i) < n) && ((j+h)<n)) && h<word); h++){

							if((*(ptr +h)-32) == *(*(arr + i)+ j+h))
								isFound = true;
							else if((*(ptr +h)) == *(*(arr + i)+ j+h))
								isFound = true;
							else{
								isFound = false;
								break;
							}
							if(h != (word-1))
								isFound = false;
						}
					}
					if(isFound == true){
						searchCase = 1;
						goto printWord;
					}
					// search right to left
					if( (((i) < n) && ((j-1)<n))  ){
						for(int h=1; ((((i) < n) && ((j-h)<n)) && h<word); h++){
							if((*(ptr +h)-32) == *(*(arr + i)+ j-h))
								isFound = true;
							else if((*(ptr +h)) == *(*(arr + i)+ j-h))
								isFound = true;
							else{
								isFound = false;
								break;
							}
							if(h != (word-1))
								isFound = false;
						}
					}
					if(isFound == true){
						searchCase = 2;
						goto printWord;
					}
					// search check up to down
					if( ((i+1) < n) && ((j)<n) ){
						for(int h=1; (((i+h) < n) && ((j)<n) && h<word); h++){
							if((*(ptr +h)-32) == *(*(arr + i+h)+ j))
								isFound = true;
							else if((*(ptr +h)) == *(*(arr + i+h)+ j))
								isFound = true;
							else{
								isFound = false;
								break;
							}
							if(h != (word-1))
								isFound = false;
						}
					}
					if(isFound == true){
						searchCase = 3;
						goto printWord;
					}

					// search top left to bottom right
					if(  ((i+1) < n) && ((j+1)<n)  ){
						for(int h=1; ( (((i+h) < n) && ((j+h)<n)) && h<word ); h++){
							if((*(ptr +h)-32) == *(*(arr + i+h)+ j+h)){
								isFound = true;
							}
							else if((*(ptr +h)) == *(*(arr + i+h)+ j+h)){
								isFound = true;
							}
							else{
								isFound = false;
								break;
							}
							if(h != (word-1))
								isFound = false;
						}
					}
					if(isFound == true){
						searchCase = 4;
						goto printWord;
					}
					// search diagonal top right to bottom left
					if(  (((i-1) < n) && ((j-1)<n)) && ((i-1) > 0)  ){
						for(int h=1; (((i-h) < n) && ((j-h)<n) && h<word); h++){
							if((*(ptr +h)-32) == *(*(arr + i-h)+ j-h))
								isFound = true;
							else if((*(ptr +h)) == *(*(arr + i-h)+ j-h)){
								isFound = true;
							}
							else{
								isFound = false;
								break;
							}
							if(h != (word-1))
								isFound = false;
						}
						searchCase = 5;
					}

					//lower case the letters in the found word and print "found word"
					printWord:
					if(isFound == true){
						printf("Word found: %s \n", *(list + k));
						switch(searchCase){
							case 1: 
								for(int h=0; ((((i) < n) && ((j+h)<n)) && h<word); h++){
								if(*(*(arr + i)+ j+h)  >= 'A' && *(*(arr + i)+ j+h)  <= 'Z')
									*(*(arr + i)+ j+h) += 32;
								}
								break;

							case 2:
								for(int h=0; ((((i) < n) && ((j-h)<n)) && h<word); h++){
								if(*(*(arr + i)+ j-h)  >= 'A' && *(*(arr + i)+ j-h)  <= 'Z')
									*(*(arr + i)+ j-h) += 32;
								} 
								break;

							case 3: 
								for(int h=0; (((i+h) < n) && ((j)<n) && h<word); h++){
								if(*(*(arr + i+h)+ j)  >= 'A' && *(*(arr + i+h)+ j)  <= 'Z')
									*(*(arr + i+h)+ j) += 32;
								}
								break;

							case 4: 
								for(int h=0; ( (((i+h) < n) && ((j+h)<n)) && h<word ); h++){
								if(*(*(arr + i+h)+ j+h) >= 'A' && *(*(arr + i+h)+ j+h)  <= 'Z')
									*(*(arr + i+h)+ j+h) += 32;
								}
								break;

							case 5: 
								for(int h=0; (((i-h) < n) && ((j-h)<n) && h<word); h++){
								if(*(*(arr + i-h)+ j-h) >= 'A' && *(*(arr + i-h)+ j-h) <= 'Z')
									*(*(arr + i-h)+ j-h) += 32;
								}
								break;
							
						}

					break; 
					}

				}
			}
		}
	}
	

}