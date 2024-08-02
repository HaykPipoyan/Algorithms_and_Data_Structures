#include <iostream>

int binary_search(int* arr, int size, int target) {
	int start = 0;
	int end = size -1;
	while(start <= end) {
		int mid = start + (end - start)/2;
		if(arr[mid] == target) {
			return mid;
		} else if(arr[mid] < target) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return -1;
}

int main() {
	const int size = 8;
	int arr[size] = {11, 22, 33, 44, 55, 66, 77, 88};
	int target = 0;
	std::cout << "Please enter target: ";
	std::cin >> target;
	std::cout << "your target is: " << binary_search(arr, size, target) << " simbol" << std::endl;
}
