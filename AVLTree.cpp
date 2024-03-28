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
        
        // if (key < lastKey) {
        //     current->left = aNode;
        //     return true;
        // } else if (key > lastKey) {
        //     current->right = aNode;
        //     return true;
        // } else {
        //     return false;
        // }
        
    } else if (key < current->key) {
        insertHelper(current->left, key, thing);
        //return true;
    } else if (key > current->key) {
        insertHelper(current->right, key, thing);
        //return true;
    } else {
        return false;
    }
};

bool AVLTree::insert(int key, string thing) {

    bool didItWork;
    didItWork = insertHelper(root, key, thing);
    return didItWork;
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