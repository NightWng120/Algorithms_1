#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int * copy(int * input, int length){
	int * copy = (int*)malloc(length * sizeof(int));
	int * start = copy;


	while(length > 0){
		//printf("Length: %d", length);
		*copy = *input;
		copy++, input++, length--;
	}

	return start;
}

int * mergeSort(int * array, int n){
	int * temp = array;
	int * A;
	int * B;
	int lenB = 0;
	int lenA = 0;
	int i = 0;
	int j = 0;
	//printf("\n\n-----------------------\nFirst element of current array: %d\nLength: %d\n-----------------------\n\n", *array, n);

	if(n < 2){
		//printf("\nReturned array\n");
		return array;
	}

	else if(n%2 == 1){
		//printf("\n\n-----------------------\nFirst element of current array: %d\nLength: %d\n-----------------------\n\n", *array, n);
		lenA = (n - 1)/2;
		lenB = (n - 1)/2 + 1;
		A = mergeSort(copy(array, lenA), lenA);
		B = mergeSort(copy(array + lenA, lenB), n);
	}

	else{
		//printf("\n\n-----------------------\nFirst element of current array: %d\nLength: %d\n-----------------------\n\n", *array, n);
		lenA = n/2;
		A = mergeSort(copy(array, lenA), lenA);
		B = mergeSort(copy(array, lenA), n);
	}
	//else if(n%2 == 1){
	//	lenB = (n - 1)/2;
    //    lenA = (n - 1)/2;
	//	A = mergeSort(temp, lenA);
	//	for(int k = 0; k < lenA; k++){
	//		temp++;

	//	}

	//	B = mergeSort(temp, n);
	//	int i = 0;
	//	int j = 0;
	//}

	//else{
	//	lenB = n/2;
	//	lenA = n/2;
	//	printf("\nLength of A: %d\n", lenA);
	//	A = mergeSort(temp, lenA);
	//	for(int k = 0; k < lenA; k++){
	//		printf("\nCurrent temp: %d\n", *temp);
	//		temp++;

	//	}

	//	B = mergeSort(temp, n);
	//	int i = 0;
	//	int j = 0;
	//}

	for(int k = 0; k < n; k++){
		printf("\nCurrent array element: %d\n", *temp);
		if(A == NULL){

			*temp = *B;
			if(j + 1 == lenB) B = NULL;
			else j++, B++;
		}

		else if(B == NULL){

			*temp = *A;
			if(j + 1 == lenA) A = NULL;
			else i++, A++;
		}

		else if(A != NULL && *A < *B){
			*temp = *A;
			if(j + 1 == lenA) A = NULL;
			else i++, A++;

		}

		else if(B != NULL && *B < *A){
			*temp = *B;
			if(j + 1 == lenB) B = NULL;
			else j++, B++;

		}

		else if(*B == *A){
			*temp = *B;
			if(j + 1 == lenB) B = NULL;
			else j++, B++;
		}

		temp++;
	}

	return array;
}
int main(){
	FILE * fp;
	char buff[255];
	//int array[100000];
	int array[] = {8,4,3,2,1};
	int length = sizeof(array)/sizeof(int);
	int i = 0;

	//fp = fopen("IntegerArray.txt", "r");
	//while(fscanf(fp, "%s", buff) == 1){
	//	//printf("%s\n", buff);
	//	int value = atoi(buff);
	//	array[i] = value;
	//	i++;

	//}
	//fclose(fp);
	int * result = mergeSort(array, length);

	for(i = 0; i < length; i++){
		printf("%d\n", result[i]);
	}

}
