#include <iostream>
using namespace std;

int partition(int arr[], int first, int last) {
    int pivot = arr[last]; // Choose the last element as pivot
    int i = first - 1;

    for (int j = first; j < last; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
}
void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int par = partition(arr, first, last);
        quickSort(arr, first, par - 1);
        quickSort(arr, par + 1, last);
    }
}

int binarySearch(int arr[],int low , int high,int target) {

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {15, 22, 25, 0, -1, -2, -6, -12, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    int target = 25;
    int index = binarySearch(arr,0,n-1, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found" << endl;
    }

    return 0;
}
