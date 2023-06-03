#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Tidak dapat mengalokasikan memori!" << endl;
        exit(0);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}

void printLeafNodes(Node* root) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return;
    }
    if (root->left)
        printLeafNodes(root->left);
    if (root->right)
        printLeafNodes(root->right);
}
void printInternalNodes(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    cout << root->data << " ";
    if (root->left)
        printInternalNodes(root->left);
    if (root->right)
        printInternalNodes(root->right);
}

void printSibling(Node* root, int data) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->left && root->left->data == data) {
        if (root->right)
            cout << root->right->data << " ";
        else
            cout << "Tidak ada sibling";
        return;
    }
    if (root->right && root->right->data == data) {
        if (root->left)
            cout << root->left->data << " ";
        else
            cout << "Tidak ada sibling";
        return;
    }
    printSibling(root->left, data);
    printSibling(root->right, data);
}

void preOrderTraversal(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    int data[] = {50, 17, 12, 23, 9, 14, 19, 72, 54, 70, 67};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++)
        root = insertNode(root, data[i]);

    cout << "Leaf Nodes: ";
    printLeafNodes(root);
    cout << endl;

    cout << "Internal Nodes: ";
    printInternalNodes(root);
    cout << endl;

    int nodeData = 17;
    cout << "Sibling of Node " << nodeData << ": ";
    printSibling(root, nodeData);
    cout << endl;

    cout << "PreOrder Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "InOrder Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
