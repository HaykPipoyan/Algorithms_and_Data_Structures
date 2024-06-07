#include <iostream>

void insertion_sort(int* arr, int size)	{
	for(int i = 1; i < size; ++i) {
		int result = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > result) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = result;
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
	insertion_sort(arr, size);
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " " ;
	}
	std::cout << std::endl;
}
