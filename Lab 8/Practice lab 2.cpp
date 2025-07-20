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
        return l->freq < r->freq; // Max heap for Huffman tree with frequency
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

    priority_queue<Node*, vector<Node*>, compare> maxHeap;

    for (int i = 0; i < size; ++i) {
        maxHeap.push(new Node(data[i], freq[i]));
    }

    // Since we're using a max heap, we need to extract the two nodes with
    // the lowest frequencies for merging. We can achieve this by extracting
    // twice and swapping the order if needed.
    while (maxHeap.size() > 1) {
        left = maxHeap.top();
        maxHeap.pop();

        if (maxHeap.empty()) {
            break; // Only one node left, stop
        }

        right = maxHeap.top();
        if (left->freq > right->freq) {
            swap(left, right); // Ensure left has lower frequency
        }
        maxHeap.pop();

        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        maxHeap.push(top);
    }

    printCodes(maxHeap.top(), "");
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
