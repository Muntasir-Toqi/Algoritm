#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    int data[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);

    Node* root = nullptr;
    for (int i = 0; i < size; ++i) {
        root = insert(root, data[i]);
    }

    cout << "In-order traversal of BST:\n";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
