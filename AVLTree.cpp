//CS3100 Project 4
//Jessica Venema

#include "AVLTree.h"

AVLTree::AVLTree() {

};

AVLTree::AVLTree(const AVLTree& t) {

    AVLNode* copyMe = t.root;

    copyHelper(copyMe);
};

AVLTree::~AVLTree() {

    clear(root);
};

void AVLTree::clear(AVLNode* killMe) {

    if (killMe == nullptr)
    {
        root = nullptr;
        size = 0;
        height = 0;
        return;
    }
    
    clear(killMe->right);
    clear(killMe->left);
    delete killMe;
};

void AVLTree::copyHelper(AVLNode*& copyMe) {

    if (copyMe == nullptr)
    {
        return;
    }
    
    copyHelper(copyMe->right);
    copyHelper(copyMe->left);
    insert(copyMe->key, copyMe->thing);
};

AVLNode* AVLTree::insertHelper(AVLNode*& node, AVLNode*& newestNode) {
    
    int balanceFactor = 0;

    if (node == nullptr)
    {
        node = newestNode;
        return node;

    } else if (newestNode->key < node->key) {
        node->left = insertHelper(node->left, newestNode);
    } else if (newestNode->key > node->key)
    {
        node->right = insertHelper(node->right, newestNode);
    } else {
        cout << "No dupes!" << endl;
        return node;
    }

    AVLTreeUpdateHeight(node);
    balanceFactor = getBalance(node);
    
    return node;
};

bool AVLTree::insert(int key, string thing) {

    bool existingKey = find(key, thing);

    if (existingKey == true)
    {
        return false;
    } else {
        
        AVLNode* newestNode = new AVLNode(key, thing);
        insertHelper(root, newestNode);
    }

    
    return true;
};

int AVLTree::getBalance(AVLNode* current) {

    if (current == nullptr)
    {
        return 0;
    } else if (current->left != nullptr && current->right != nullptr)
    {
        return (AVLTreeUpdateHeight(current->left) - 
                AVLTreeUpdateHeight(current->right));
    }

    return 0;    
}

int AVLTree::AVLTreeUpdateHeight(AVLNode* current) {

    int leftHeight = -1;
    if ((current != nullptr) && (current->left != nullptr))
    {
        leftHeight = current->left->height;
    }
    int rightHeight = -1;
    if ((current != nullptr) && (current->right != nullptr)) {
        rightHeight = current->right->height;
    }
    
    return current->height = max(leftHeight, rightHeight) + 1;  
};

int AVLTree::getSize() const {

    return size;
};

int AVLTree::getHeight() const {

    return height;
};

bool AVLTree::find(int key, string& thing) const {

    AVLNode* current = root;
    
    while (current != nullptr)
    {
        if (current->key == key) {
            thing = current->thing;
            return true;
        } else if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        }
    }
    return false;
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