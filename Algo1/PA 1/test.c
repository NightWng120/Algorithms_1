#include <stdio.h>
#include <stdlib.h>

int * copy(int * input, int length){
	int * copy = (int*)malloc(length * sizeof(int));
	int * start = copy;

	while(length - 1 > 0){
		printf("Input is %d, so we cool\n", *input);
		*copy = *input;
		copy++, input++, length--;
	}


	return start;
}

int main(){
	int array[] = {1, 2, 3, 4, 5};
	int length = sizeof(array)/sizeof(int);
	int * A = array;
	int * B = array + (length - 1)/2;
	int * localCopy = copy(array, length);
	for(int i = 0; i < length; i++){
		if(i >= (length - 1)/2){
			printf("\nPointer B: %d, [%p]\n", *B, &B);
			printf("\nPointer Copy: %d, [%p]\n", *localCopy, &localCopy);
			B++, localCopy++;
		}
		else{
			printf("\nPointer A: %d, [%p]\n", *A, &A);
			printf("\nPointer Copy: %d, [%p]\n", *localCopy, &localCopy);
			A++, localCopy++;
		}
	}
	
}
