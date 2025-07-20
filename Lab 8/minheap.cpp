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

void minHeapify(Node* arr[], int n, int i) {
    int smallest = i;
    int l = left(i, n);
    int r = right(i, n);

    if (l != -1 && arr[l]->data < arr[smallest]->data) {
        smallest = l;
    }
    if (r != -1 && arr[r]->data < arr[smallest]->data) {
        smallest = r;
    }

    if (smallest != i) {
        swap(&arr[smallest], &arr[i]);
        minHeapify(arr, n, smallest);
    }
}

void builtMinHeap(Node* arr[],int n){
    for(int i = root(n-1); i>=0; --i){
        minHeapify(arr,n,i);
    }

}

void printMinHeap(Node* arr[], int n) {

    for (int i = 0; i < n; ++i) {
        cout << arr[i]->data << " ";
    }
    cout << endl;
}

int main() {
    int data[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);

    Node* heap[size];
    for(int i = 0; i < size; ++i){
         heap[i] = new Node(data[i]);
    }

   builtMinHeap(heap, size);

    cout << "Max Heap (frequencies):\n";
    printMinHeap(heap, size);

    return 0;
}
