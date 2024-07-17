#include <iostream>
using namespace std;

class BSTNode {
public:
    int Key;
    BSTNode* Left;
    BSTNode* Right;
    BSTNode* Parent;
};


BSTNode* Insert(BSTNode* node, int key) {
    if (node == nullptr) {
        node = new BSTNode;
        node->Key = key;
        node->Left = nullptr;
        node->Right = nullptr;
        node->Parent = nullptr;
    } else if (node->Key < key) {
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    } else {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }
    return node;
}


bool Search(BSTNode* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->Key == key) {
        return true;
    } else if (root->Key < key) {
        return Search(root->Right, key);
    } else {
        return Search(root->Left, key);
    }
}


BSTNode* Delete(BSTNode* root, int key) {
    
    return root;
}


void InOrderTraversal(BSTNode* root) {
    if (root == nullptr) {
        return;
    }
    InOrderTraversal(root->Left);
    cout << root->Key << " ";
    InOrderTraversal(root->Right);
}


void PreOrderTraversal(BSTNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->Key << " ";
    PreOrderTraversal(root->Left);
    PreOrderTraversal(root->Right);
}


void PostOrderTraversal(BSTNode* root) {
    if (root == nullptr) {
        return;
    }
    PostOrderTraversal(root->Left);
    PostOrderTraversal(root->Right);
    cout << root->Key << " ";
}

int main() {
    BSTNode* root = nullptr;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
   

    
    int searchKey = 10;
    if (Search(root, searchKey)) {
        cout << "Key " << searchKey << " found in the BST." << endl;
    } else {
        cout << "Key " << searchKey << " not found in the BST." << endl;
    }

    
    cout << "InOrder Traversal: ";
    InOrderTraversal(root);
    cout << endl;

    cout << "PreOrder Traversal: ";
    PreOrderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal: ";
    PostOrderTraversal(root);
    cout << endl;

    return 0;
}

