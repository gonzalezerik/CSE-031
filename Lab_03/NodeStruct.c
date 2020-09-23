
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert extra code here
    printf("Value of head: %d\n", head->iValue);
    printf("Address of head: %p\n", &head);
    printf("Addresses of ivalue: %p\n", &head->iValue);
    printf("Addresses of fvalue: %p\n", &head->fValue);
    printf("Next pointed by head: %p\n", head->next);
	
	
	return 0;
}