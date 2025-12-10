//CS3100 Project 4
//Jessica Venema

#include "AVLTree.h"

// Private static helpers
// ---------------------------------------------------------
/// @brief Returns the balance of a node (left - right) to balance the tree.
/// @param node
int AVLTree::getBalance(AVLNode* node) {
    // if the node does not exist return o
    if (node == nullptr) return 0;

    // the balance is the height of the left node height minus the balance of
    // the right node height.
    return nodeHeight(node->left) - nodeHeight(node->right);
}

/// @brief Updates the height of a node based on left and right children heights
/// @param node
void AVLTree::updateHeight(AVLNode* node) {
    // if the node does not exist return nothing
    if (node == nullptr) return;

    // get the left and right node heights
    int leftH = nodeHeight(node->left);
    int rightH = nodeHeight(node->right);

    // update the current node height based on the max height plus one.
    node->height = ((leftH > rightH ? leftH : rightH) + 1 );
}

/// @brief Rotates a node to the left by reassigning left and right pointers.
/// @param node
/// @return The new parent or root node.
AVLNode* AVLTree::rotateLeft(AVLNode* node) {
    // new node and temp hook
    AVLNode* newParent = node->right;
    AVLNode* hook = newParent->left;

    // left rotation
    newParent->left = node;
    node->right = hook;

    // update heights
    updateHeight(newParent);
    updateHeight(node);

    return newParent;
}

/// @brief Rotates a node to the right by reassigning left and right pointers.
/// @param node 
/// @return The new parent or root node.
AVLNode* AVLTree::rotateRight(AVLNode* node) {
    // new node and temp hook
    AVLNode* newParent = node->left;
    AVLNode* hook = newParent->right;

    // right rotation
    newParent->right = node;
    node->left = hook;

    // update heights
    updateHeight(node);
    updateHeight(newParent);

    // returns the new subtree root node
    return newParent;
}

/**
 * Recursive insertion, no dupes allowed.
 * @param node The node to be inserted.
 * @param key The key value of the node.
 * @param thing The information stored in the node.
 * @param inserted Boolean
 * @return True if inserted and false if not.
 */
AVLNode* AVLTree::insertRec(AVLNode* node, int key, const string& thing, bool& inserted) {
    // if the node does not exist create it and return it
    if (node == nullptr) {
        inserted = true;
        return new AVLNode(key, thing);
    }

    // using BST rules: if the key is less than the node's key insert it on the left,
    // if the key is greater than the node's key insert it on the right, otherwise
    // set inserted to false. No insertion because the node is a duplicate.
    if (key < node->key) {
        node->left = insertRec(node->left, key, thing, inserted);
    } else if (key > node->key) {
        node->right = insertRec(node->right, key, thing, inserted);
    } else {
        // duplicate key condition
        inserted = false;
        return node;
    }

    // update the height of the inserted node
    updateHeight(node);
    // update the balance of the inserted node
    int balance = getBalance(node);

    // Rotation cases:
    // left-left case
    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }
    // right-right case
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }
    // left-right case
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // right-left case
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    // return the inserted node
    return node;
}

/**
 * Find a node inside a specified range recursively.
 * @param node The node to locate.
 * @param lowkey The low end of the range.
 * @param highkey The high end of the range.
 * @param out The vector which contains the node information.
 */
void AVLTree::findRangeRec(AVLNode* node, int lowkey, int highkey, vector<string>& out) {
    // if the node does not exist return
    if (node == nullptr) return;

    // if the node is greater than the lowkey recurse left
    if (node->key > lowkey) {
        findRangeRec(node->left, lowkey, highkey, out);
    }
    // push the node's information into the vector if both the node's key is greater than or
    // equal to the lowkey AND less than or equal to the highkey
    if (node->key >= lowkey && node->key <= highkey) {
        out.push_back(node->thing);
    }
    // if the node is less than the highkey recurse right
    if (node->key < highkey) {
        findRangeRec(node->right, lowkey, highkey, out);
    }
}

/**
 * Recursive helper for the destructor.
 * @param killMe The node to delete.
 */
void AVLTree::clearRec(AVLNode *killMe) {
    // when there are no more nodes return nothing
    if (killMe == nullptr) return;

    // recursive calls on left and right pointers
    clearRec(killMe->left);
    clearRec(killMe->right);
    // murdering the node
    delete killMe;
}

/**
 * Helper function to copy a subtree.
 * @param node The node which is the subtree's root.
 * @return The new root.
 */
AVLNode* AVLTree::copySubtree(AVLNode *node) {
    // if a node does not exist return a null
    if (node == nullptr) return nullptr;

    // create a new node and update it's members
    AVLNode* newNode = new AVLNode(node->key, node->thing);
    newNode->height = node->height;
    newNode->left = copySubtree(node->left);
    newNode->right = copySubtree(node->right);

    // return the new root
    return newNode;
}

/**
 * Print sideways using recursive calls to visualize the tree.
 * @param os Ostream object.
 * @param node Start at root node and traverse down the branches.
 * @param depth Keeping track of the formatting.
 */
void AVLTree::printSideways(ostream &os, AVLNode *node, int depth) {
    // when we find no more nodes return
    if (node == nullptr) return;

    // print down the right side of the tree first to it will be on top
    printSideways(os, node->right, depth + 1);

    // add in tab spaces to visualize the tree
    for (int i = 0; i < depth; i++) {
        os << "      ";
    }
    // print the node information
    os << node->key << " (H = " << node->height << ") (V = " << node->thing << ")" << endl;

    // print down the left side of the tree so it will be on the bottom of the visualization
    printSideways(os, node->left, depth + 1);
}

// ---------------------------------------------------------

/// @brief No argument constructor. 
AVLTree::AVLTree() : root(nullptr), size(0) {}

/// @brief Copy constructor.
/// @param t The tree to be copied.
AVLTree::AVLTree(const AVLTree& tree) : root(nullptr), size(0) {
    root = copySubtree(tree.root);
    size = tree.size;
}

/**
 * Replaces this tree with a deep copy of a different tree.
 * @param otherTree The tree to copy.
 * @return A reference to this tree.
 */
AVLTree& AVLTree::operator=(const AVLTree &otherTree) {
    // no self assignment
    if (this == &otherTree) return *this;

    // remove all the nodes in this tree
    clearRec(root);
    // copy the nodes in otherTree to this tree
    root = copySubtree(otherTree.root);
    // assign the size of otherTree to this tree
    size = otherTree.size;

    // reference to this tree
    return *this;
}

/// @brief Destructor.
AVLTree::~AVLTree() {
    clearRec(root);
    root = nullptr;
    size = 0;
}

/// @brief Inserts a key/value pair as a node into the AVLTree.
/// @param key The key for the new node.
/// @param thing The value for the new node.
/// @return Returns true if the node was inserted and false if not.
bool AVLTree::insert(int key, string thing) {
    bool inserted = false;

    // starting at root attempt to recursively insert the key/value pair
    root = insertRec(root, key, thing, inserted);
    // increment size
    if (inserted) {
        size++;
    }
    // boolean true if inserted or false if not
    return inserted;
}

/// @brief Finds a key if it exists in the tree.
/// @param key The key for the key/value pair.
/// @param thing The value for the key/value pair.
/// @return True if found and false if not.
bool AVLTree::find(int key, string& thing) const {
    // start at root
    AVLNode* current = root;

    // look for a key which equals an integer value
    while (current != nullptr) {
        if (key == current->key) {
            thing = current->thing;
            return true;
        }
        // if the key is less than go left
        if (key < current->key) {
            current = current->left;
        }
        // if the key is greater than go right
        if (key > current->key) {
            current = current->right;
        }
    }
    // return false if the key was not found.
    return false;
}

/// @brief The total number of nodes in the tree.
/// @return The integer for the number of nodes.
int AVLTree::getSize() const {
    return size;
}

/// @brief The height of the tree.
/// @return The integer for the height of the tree.
int AVLTree::getHeight() const {
    return nodeHeight(root);
}

/// @brief Finds all values in the tree within the range given.
/// @param keyStart The lower limit for searching.
/// @param keyEnd The upper limit for searching.
/// @return A vector of all key/value pairs found in the tree.
vector<string> AVLTree::findRange(int keyStart, int keyEnd) const {
    vector<string> result;
    findRangeRec(root, keyStart, keyEnd, result);
    return result;
}

/// The operator overloading function allows printing for testing.
ostream& operator<<(ostream& os, const AVLTree& tree) {
    // start at root
    if (tree.root == nullptr) {
        os << "Empty Tree" << endl;
    } else {
        // use the recursive sideways printing helper
        AVLTree::printSideways(os, tree.root, 0);
    }
    return os;
}