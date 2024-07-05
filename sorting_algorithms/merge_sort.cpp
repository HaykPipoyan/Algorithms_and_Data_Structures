#include <iostream>

void merge(int* arr, int left, int mid, int right)
{
	int i = 0;
	int j = 0;

	int size1 = mid - left + 1;
	int size2 = right - mid;

	int* leftArr = new int[size1];
	int* rightArr = new int[size2];

	for( ; i < size1; ++i) {
		leftArr[i] = arr[i + left];
	}
	for( ; j < size2; ++j) {
		rightArr[j] = arr[mid + j + 1];
	}
	i = 0;
	j = 0;
	int k = left;
	
	while(i < size1 && j < size2) {
		if(leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			++i;
		} else {
			arr[k] = rightArr[j];
			++j;
		}
		++k;
	}
	while(i < size1) {
		arr[k] = leftArr[i];
		++i;
		++k;
	}
	while(j < size2) {
		arr[k] = rightArr[j];
		++j;
		++k;
	}
	delete[] leftArr;
	delete[] rightArr;
}

void merge_sort(int* arr, int left, int right)
{
	if(left < right) 
	{
		int mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main()
{
	int arr[] = {54, 20, 52, 23, 5, 21};
	const int size = sizeof(arr) / sizeof(arr[0]);
	merge_sort(arr, 0, size - 1);
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
