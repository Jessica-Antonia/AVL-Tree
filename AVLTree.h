//CS3100 Project 4
//Jessica Venema

#include "AVLNode.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

/// @brief Contains functions to create an AVL Tree
class AVLTree {

private:

    //private AVLTree variables.
    int size = 0;
    int height = 0;
    AVLNode* root = nullptr;

public:

    /// @brief No argument constructor. 
    AVLTree();

    /// @brief Copy constructor.
    /// @param t The tree to be copied.
    AVLTree(const AVLTree& t);

    /// @brief Destructor.
    ~AVLTree();

    /// @brief The destructor's helper function.
    /// @param killMe A pointer to the tree's root.
    void clear(AVLNode* killMe);

    /// @brief The copy constructor's helper function.
    /// @param copyNode A pointer to the root pointer.
    void copyHelper(AVLNode*& copyNode);

    /// @brief Insert's helper function. Recursive. Doesn't work.
    /// @param node A pointer to the root node.
    /// @param current The new node to be inserted.
    /// @return A pointer to the newly inserted node.
    AVLNode* insertHelper(AVLNode*& node, AVLNode*& current);

    /// @brief Inserts a key/value pair into the AVLTree. No dupes.
    /// @param key The key for the new node.
    /// @param thing The value for the new node.
    /// @return Returns false if the node was inserted and false if not. 
    bool insert(int key, string thing);

    /// @brief Calculates the balance of each node.
    /// @param node The node in question.
    /// @return The balance as an integer.
    int getBalance(AVLNode* node);

    /// @brief Calculates and updates the height of a node.
    /// @param node The node to be updated.
    /// @return The height to be returned.
    int AVLTreeUpdateHeight(AVLNode* node);

    /// @brief The total number of nodes in the tree.
    /// @return The integer for the number of nodes.
    int getSize() const;

    /// @brief The height of the tree.
    /// @return The integer for the height of the tree.
    int getHeight() const;

    /// @brief Finds a key if it exists in the tree.
    /// @param key The key for the key/value pair.
    /// @param thing The value for the key/value pair.
    /// @return True if found and false if not.
    bool find(int key, string& thing) const;

    /// @brief Finds all values in the tree within the range given.
    /// @param keyStart The lower limit for searching.
    /// @param keyEnd The upper limit for searching.
    /// @return A vector of all key/value pairs found in the tree.
    vector<string> findRange(int keyStart, int keyEnd) const;

    /// @brief Helper function for printing.
    /// @param printNode Prints the data stored in a node.
    void print(AVLNode* printNode) const;

    /// @brief Helper function for printing. Reverse Order Traversal.
    /// @param currentNode The node to be printed.
    void reverseOrderTraversal(AVLNode* currentNode) const;

    /// @brief The printing function used by overloading the << operator.
    /// @param os The out stream to be used for printing.
    /// @param currentNode A pointer to the root,
    void reverseOrderTraversalPrint(ostream& os, AVLNode* currentNode) const ;

    //Ostream modifer for printing.
    friend ostream& operator<<(ostream& os, const AVLTree& tree);

};