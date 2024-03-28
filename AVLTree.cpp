//CS3100 Project 4
//Jessica Venema

#include "AVLTree.h"

AVLTree::AVLTree() {

};

AVLTree::AVLTree(const AVLTree& t) {


};

AVLTree::~AVLTree() {



};

bool AVLTree::insertHelper(AVLNode*& current, int key, string thing) {
    
    if (current == nullptr)
    {
        AVLNode* aNode = new AVLNode(key, thing);
        current = aNode;
        size++;
        
        return true;
                
    } else if (key < current->key) {
        
        return insertHelper(current->left, key, thing);
    } else if (key > current->key) {
        
        return insertHelper(current->right, key, thing);
    } else {
        return false;
    }

    current->height = AVLTreeUpdateHeight(current);
};

bool AVLTree::insert(int key, string thing) {

    return insertHelper(root, key, thing);
};

int AVLTree::AVLTreeUpdateHeight(AVLNode*& node) {

    int leftHeight = -1;
    if (node->left != nullptr)
    {
        leftHeight = node->left->height;
    }
    int rightHeight = -1;
    if (node->right != nullptr) {
        rightHeight = node->right->height;
    }
    
    return node->height = max(leftHeight, rightHeight) + 1;  
};

int AVLTree::getSize() const {

    return size;
};

int AVLTree::getHeight() const {

    return height;
};

bool AVLTree::find(int key, string thing) const {



};

vector<string> AVLTree::findRange(int keyStart, int keyEnd) const {



};

void AVLTree::print(AVLNode* printNode) const {

    cout << *printNode << endl;
}

void AVLTree::reverseOrderTraversal(AVLNode* currentNode) const {
    if (currentNode == nullptr)
    {
        return;
    }

    reverseOrderTraversal(currentNode->right);
    reverseOrderTraversal(currentNode->left);
    print(currentNode);
};

void AVLTree::reverseOrderTraversalPrint(ostream& os, AVLNode* currentNode) const {
    if (currentNode == nullptr)
    {
        os << "The tree is empty." << endl;
        return;
    }
    
    reverseOrderTraversal(currentNode);    
};

/// The operator overloading function allows printing for testing.
ostream& operator<<(ostream& os, const AVLTree& tree) {

    AVLNode* current = tree.root;
    tree.reverseOrderTraversalPrint(os, current);
    return os;
};