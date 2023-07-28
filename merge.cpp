#include <stdio.h>
#include <iostream>
#include <string>

std::string arrToString(int array[], int n){
	std::string stringArr = "[";

	for(int i = 0; i < n; i++){
		if(i + 1 == n){
			stringArr += std::to_string(array[i]);
			stringArr += "]";
			break;
		}
		stringArr += std::to_string(array[i]);
		stringArr += ", ";
	}
	return stringArr;

}

int * mergeSort(int array[], int n){
	if(n < 2)){
		return *array[0];
	}
}



int main(){
	int list[] = {2, 7, 4, 1, 5, 3};
	int n = sizeof(list)/sizeof(int);
	std::cout << "Unsorted array: " + arrToString(list, n)<< std::endl;
	mergeSort(list, n);
	std::cout << "Sorted array: " + arrToString(list, n) << std::endl;


	return 0;
}
