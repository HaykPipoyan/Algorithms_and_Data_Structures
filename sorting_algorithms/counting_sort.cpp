#include <iostream>
#include <vector>

void counting_sort(int* arr, int size) 
{
    int max = arr[0];
    for(int i = 1; i < size; ++i) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    std::vector<int> output(size);
    std::vector<int> count(max + 1, 0); 
    for(int i = 0; i < size; ++i) {
        ++count[arr[i]];
    }
    for(int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }
    for(int i = size - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for(int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    counting_sort(arr, size);
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
	std::cout << std::endl;
    return 0;
}
