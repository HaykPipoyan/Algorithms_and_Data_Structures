#include <iostream>

void selection_sort(int* arr, int size) {
	int min_index = 0;
	for(int i = 0; i < size - 1; ++i) {
		min_index = i;
		for(int j = i + 1; j < size; ++j) {
			if(arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		std::swap(arr[i], arr[min_index]);
	}
}


int main(){
	const int size = 8;
	int arr[size] = {}; 
	std::cout << "please enter 8 numbers: "; 
	for(int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}
	std::cout << "your sorted array: ";
	selection_sort(arr, size);
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " " ;
	}
	std::cout << std::endl;
}
