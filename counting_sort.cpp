#include <iostream>

void counting_sort(int* arr, int size) {
	int max = arr[0];
	for(int i = 1; i < size; ++i) {
		if(max < arr[i]) {
			max = arr[i];
		}
	}
	int* tmp = new int[max + 1];
	int* res = new int[size];
	for(int i = 0; i < size; ++i) {
		++tmp[arr[i]];
	}
	for(int i = 1; i < max + 1; ++i) {
		tmp[i] += tmp[i - 1];
	}
	for(int i = 0; i < size; ++i) {
		res[tmp[arr[i]] - 1] = arr[i];
		--tmp[arr[i]];
	}
	for(int i = 0; i < size; ++i) {
		arr[i] = res[i];
	}
	delete[] tmp;
	delete[] res;
}


int main(){
	const int size = 8;
	int arr[size] = {2, 3, 1, 3, 2, 1, 0, 0}; 
	counting_sort(arr, size);
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " " ;
	}
	std::cout << std::endl;
}
