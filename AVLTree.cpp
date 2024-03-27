//CS3100 Project 4
//Jessica Venema

#include "AVLTree.h"

AVLTree::AVLTree() {


};

AVLTree::AVLTree(const AVLTree& t) {


};

AVLTree::~AVLTree() {



};

void AVLTree::insert(int key, string thing) {

    if (root == nullptr)
    {
        AVLNode* aNode = new AVLNode(key, thing);
        root = aNode;
        size++;
    }

    AVLNode* current = root;
    AVLNode* aNode = new AVLNode(key, thing);
    if (current.key > aNode.key)
    {
        
        current->left = aNode;
    }
    

};

int AVLTree::getSize() const {

    return size;
};

int AVLTree::getHeight() const {



};

string AVLTree::find(int key, string thing) const {



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