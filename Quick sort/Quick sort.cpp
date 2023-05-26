#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1; 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;  
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}


void quick_sort(int* arr, int size) {
    quick_sort(arr, 0, size - 1);
}


void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    int arr[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    print_array(arr, size);

    quick_sort(arr, size);

    cout << "Отсортированный массив: ";
    print_array(arr, size);
}