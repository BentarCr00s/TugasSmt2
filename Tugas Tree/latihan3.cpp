#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

class BinaryTree
{
private:
    TreeNode *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    TreeNode *createNode(int value)
    {
        TreeNode *newNode = new TreeNode;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    TreeNode *insertNode(TreeNode *root, int value)
    {
        if (root == nullptr)
        {
            root = createNode(value);
        }
        else if (value <= root->data)
        {
            root->left = insertNode(root->left, value);
        }
        else
        {
            root->right = insertNode(root->right, value);
        }
        return root;
    }

    void preOrderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void inOrderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    void postOrderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }

    TreeNode *searchNode(TreeNode *root, int value)
    {
        if (root == nullptr || root->data == value)
        {
            return root;
        }
        if (value < root->data)
        {
            return searchNode(root->left, value);
        }
        return searchNode(root->right, value);
    }

    TreeNode *deleteNode(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        root->left = deleteNode(root->left);
        root->right = deleteNode(root->right);
        delete root;
        return nullptr;
    }

    TreeNode *getRoot()
    {
        return root;
    }
};

int main()
{
    BinaryTree tree;
    TreeNode *root = nullptr;
    int choice, value;
    TreeNode *searchResult;

    do
    {
        cout << "Menu:\n";
        cout << "1. Input data ke dalam tree\n";
        cout << "2. Penelusuran Preorder\n";
        cout << "3. Penelusuran Inorder\n";
        cout << "4. Penelusuran Postorder\n";
        cout << "5. Cari data di tree\n";
        cout << "6. Hapus seluruh node\n";
        cout << "7. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> value;
            root = tree.insertNode(root, value);
            break;
        case 2:
            cout << "Hasil penelusuran Preorder: ";
            tree.preOrderTraversal(root);
            cout << endl;
            break;
        case 3:
            cout << "Hasil penelusuran Inorder: ";
            tree.inOrderTraversal(root);
            cout << endl;
            break;
        case 4:
            cout << "Hasil penelusuran Postorder: ";
            tree.postOrderTraversal(root);
            cout << endl;
            break;
        case 5:
            cout << "Masukkan data yang ingin dicari: ";
            cin >> value;
            searchResult = tree.searchNode(root, value);
            if (searchResult != nullptr)
            {
                cout << "Data ditemukan di dalam tree." << endl;
            }
            else
            {
                cout << "Data tidak ditemukan di dalam tree." << endl;
            }
            break;
        case 6:
            root = tree.deleteNode(root);
            cout << "Seluruh node telah dihapus." << endl;
            break;
        case 7:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih angka 1-7." << endl;
        }
    } while (choice != 7);

    return 0;
}
