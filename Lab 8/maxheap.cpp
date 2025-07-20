#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

int left(int i, int heapSize) {
    if (2 * i + 1 < heapSize) {
        return 2 * i + 1;
    } else {
        return -1;
    }
}

int right(int i, int heapSize) {
    if (2 * i + 2 < heapSize) {
        return 2 * i + 2;
    } else {
        return -1;
    }
}

int root(int i) {
    return (i - 1) / 2;
}

// Modified minHeapify function for max-heap
void maxHeapify(Node* arr[], int n, int i) {
    int largest = i;
    int l = left(i, n);
    int r = right(i, n);

    // Find the index of the largest element among root, left child, and right child
    if (l != -1 && arr[l]->data > arr[largest]->data) {
        largest = l;
    }
    if (r != -1 && arr[r]->data > arr[largest]->data) {
        largest = r;
    }

    // If the largest element is not the root, swap it with the root and recursively maxHeapify the subtree
    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(Node* arr[], int n) {
    // Start from the last non-leaf node (parent of the last leaf) and maxHeapify all subtrees
    for (int i = root(n - 1); i >= 0; --i) {
        maxHeapify(arr, n, i);
    }
}

void printMinHeap(Node* arr[], int n) {
    // Print the max-heap (largest elements at the top)
    for (int i = 0; i < n; ++i) {
        cout << arr[i]->data << " ";
    }
    cout << endl;
}

int main() {
    int data[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);

    Node* heap[size];
    for (int i = 0; i < size; ++i) {
        heap[i] = new Node(data[i]);
    }

    buildMaxHeap(heap, size);

    cout << "Max Heap (frequencies):\n";
    printMinHeap(heap, size); // Use same print function, elements will be largest first

    return 0;
}
