#include <iostream>

void swap(int& a, int& b) 
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int* arr, int low, int high)
{
	int pivot = arr[low];
	int i = 0;
	int j = high;
	while(i < j) {
		do{
			++i;
		} while(arr[i] < pivot);
		do{
			--j;
		} while(arr[j] > pivot);
		
		if(i < j) {
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[j], arr[low]);
	return j;
}

void quick_sort(int* arr, int low, int high)
{
	if(low < high) {
		int pi = partition(arr, low, high);
		quick_sort(arr, low, pi);
		quick_sort(arr, pi + 1, high);
	}
}

int main() 
{
	int arr[] = {54, 20, 52, 23, 5, 21};
	const int size = sizeof(arr) / sizeof(arr[0]);

	quick_sort(arr, 0, size);
	
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
