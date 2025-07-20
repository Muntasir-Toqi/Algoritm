#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Node {
    char data;
    unsigned int freq;
    Node* left;
    Node* right;

    Node(char d, unsigned int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root) {
        return;
    }

    if (root->data != '$') {
        cout << root->data << ": " << str << endl;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size) {
    Node* left, *right, *top;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < size; ++i) {
        minHeap.push(new Node(data[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
