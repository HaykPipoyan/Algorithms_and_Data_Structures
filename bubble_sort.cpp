#include <iostream>

void bubble_sort(int* arr, int size) {
	bool flag = false;
	for(int i = 0; i < size - 1; ++i) {
		flag = false;
		for(int j = 0; j < size - 1 - i; ++j) {
			if(arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			flag = true;
		}
		if(!flag) {
			break;
		}
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
	bubble_sort(arr, size);
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " " ;
	}
	std::cout << std::endl;
}
