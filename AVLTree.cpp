//CS3100 Project 4
//Jessica Venema

#include "AVLTree.h"

/// @brief No argument constructor. 
AVLTree::AVLTree() {

};

/// @brief Copy constructor.
/// @param t The tree to be copied.
AVLTree::AVLTree(const AVLTree& t) {

    AVLNode* copyMe = t.root;

    copyHelper(copyMe);
};

/// @brief Destructor.
AVLTree::~AVLTree() {

    clear(root);
};

/// @brief The destructor's helper function.
/// @param killMe A pointer to the tree's root.
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

/// @brief The copy constructor's helper function.
/// @param copyNode A pointer to the root pointer.
void AVLTree::copyHelper(AVLNode*& copyMe) {

    if (copyMe == nullptr)
    {
        return;
    }
    
    copyHelper(copyMe->right);
    copyHelper(copyMe->left);
    insert(copyMe->key, copyMe->thing);
};

/// @brief Insert's helper function. Recursive. Doesn't work.
/// @param node A pointer to the root node.
/// @param current The new node to be inserted.
/// @return A pointer to the newly inserted node.
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

    cout << node->key << endl;
    balanceFactor = AVLTreeUpdateHeight(node);
    cout << "Height: " << balanceFactor << endl;
    balanceFactor = getBalance(node);
    cout << "BF: " << balanceFactor << endl;
    
    return node;
};

/// @brief Inserts a key/value pair into the AVLTree. No dupes.
/// @param key The key for the new node.
/// @param thing The value for the new node.
/// @return Returns false if the node was inserted and false if not. 
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

/// @brief Calculates the balance of each node.
/// @param node The node in question.
/// @return The balance as an integer.
int AVLTree::getBalance(AVLNode*& current) {

    int balanceFactor = 0;
    int noLeftNode = -1;
    int noRightNode = -1;

    if (current == nullptr)
    {
        return current->balance = balanceFactor;
    } else if (current->left != nullptr && current->right == nullptr)
    {
        return current->balance = (AVLTreeUpdateHeight(current->left) - noRightNode);
    } else if (current->left == nullptr && current->right != nullptr)
    {
        return current->balance = (noLeftNode - AVLTreeUpdateHeight(current->right));
    } else if (current->left != nullptr && current->right != nullptr)
    {
        return current->balance = (AVLTreeUpdateHeight(current->left) - 
                AVLTreeUpdateHeight(current->right));
    }
    
    return balanceFactor;    
}

/// @brief Calculates and updates the height of a node.
/// @param current The node to be updated.
/// @return The height to be returned.
int AVLTree::AVLTreeUpdateHeight(AVLNode*& current) {

    int leftHeight = -1;
    if ((current != nullptr) && (current->left != nullptr)){

        leftHeight = current->left->height;
    }
    int rightHeight = -1;
    if ((current != nullptr) && (current->right != nullptr)) {

        rightHeight = current->right->height;
    }
    
    return current->height = max(leftHeight, rightHeight) + 1;  
};

/// @brief The total number of nodes in the tree.
/// @return The integer for the number of nodes.
int AVLTree::getSize() const {

    return size;
};

/// @brief The height of the tree.
/// @return The integer for the height of the tree.
int AVLTree::getHeight() const {

    return height;
};

/// @brief Finds a key if it exists in the tree.
/// @param key The key for the key/value pair.
/// @param thing The value for the key/value pair.
/// @return True if found and false if not.
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

/// @brief Finds all values in the tree within the range given.
/// @param keyStart The lower limit for searching.
/// @param keyEnd The upper limit for searching.
/// @return A vector of all key/value pairs found in the tree.
vector<string> AVLTree::findRange(int keyStart, int keyEnd) const {


};

/// @brief Helper function for printing.
/// @param printNode Prints the data stored in a node.
void AVLTree::print(AVLNode* printNode) const {

    cout << *printNode << endl;
}

/// @brief Helper function for printing. Reverse Order Traversal.
/// @param currentNode The node to be printed.
void AVLTree::reverseOrderTraversal(AVLNode* currentNode) const {
    if (currentNode == nullptr)
    {
        return;
    }

    reverseOrderTraversal(currentNode->right);
    print(currentNode);
    reverseOrderTraversal(currentNode->left);
};

/// @brief The printing function used by overloading the << operator.
/// @param os The out stream to be used for printing.
/// @param currentNode A pointer to the root,
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