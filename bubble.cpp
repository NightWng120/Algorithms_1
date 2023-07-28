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

int main(){
	int list[] = {2, 7, 4, 1, 5, 3};
	int n = sizeof(list)/sizeof(int);
	int iMin = 0;
	int temp = 0;
	std::cout << "Unsorted array: " + arrToString(list, n)<< std::endl;
	for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(list[j] > list[j + 1] && j + 1 != n){

					temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
				}
			}

	}
	std::cout << "Sorted array: " + arrToString(list, n) << std::endl;


	return 0;
}
