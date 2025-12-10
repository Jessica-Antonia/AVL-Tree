//CS3100 Project 4
//Jessica Venema
#pragma once

#include "AVLNode.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

/// @brief Contains functions to create an AVL Tree
class AVLTree {

private:

    //private AVLTree variables.
    int size;
    AVLNode* root;

    // -------------Private Helper Functions---------------

    /**
     * Finds the height of a node.
     * @param node
     * @return Returns the node height if it exists, else -1 if it does not exist.
     */
    static int nodeHeight(AVLNode* node) {
        return (node == nullptr) ? -1 : node->height;  
    }

    /**
     * Balance factor = height(left) - height(right)
     * @param node
     * @return The balance factor as an integer.
     */
    static int getBalance(AVLNode* node);

    /**
     * Update the height of this node from its children
     * @param node
     */
    static void updateHeight(AVLNode* node);

    /**
     * Rotates a node left for balance.
     * @param node Node to be rotated left.
     * @return The new node.
     */
    static AVLNode* rotateLeft(AVLNode* node);

    /**
     * Rotates a node right for balance.
     * @param node Node to be rotated right.
     * @return The new node.
     */
    static AVLNode* rotateRight(AVLNode* node);

    /**
     * Recursive insert, returns new subtree root.
     * @param node The node to be inserted into the tree.
     * @param key Key value for sorting nodes.
     * @param thing Information value the node contains.
     * @param inserted Boolean
     * @return Returns true if the node was inserted or false if not.
     */
    static AVLNode* insertRec(AVLNode* node, int key, const string& thing, bool& inserted);

    /**
     * Recursive range search.
     * @param node The node we are searching for in the range.
     * @param lowkey Low ley value in the range.
     * @param highkey High key value in the range.
     * @param out Vector with node values.
     */
    static void findRangeRec(AVLNode* node, int lowkey, int highkey, vector<string>& out);

    /**
     * Helper function for recursive destructor.
     * @param killMe Node to be deleted.
     */
    static void clearRec(AVLNode* killMe);

    /**
     * Recursive deep copy of subtree.
     * @param node The root of the subtree.
     * @return The new subtree root.
     */
    static AVLNode* copySubtree(AVLNode* node);

    /**
     * Recursive sideways print.
     * @param os Ostream for printing.
     * @param node The node to be printed.
     * @param depth The depth of node to print.
     */
    static void printSideways(ostream& os, AVLNode* node, int depth);

public:

    /// @brief No argument constructor.
    AVLTree();

    /// @brief Copy constructor.
    /// @param t The tree to be copied.
    AVLTree(const AVLTree& t);

    /// @brief Assignment operator
    AVLTree& operator=(const AVLTree& otherTree);

    /// @brief Destructor.
    ~AVLTree();

    /// @brief Inserts a key/value pair into the AVLTree. No dupes.
    /// @param key The key for the new node.
    /// @param thing The value for the new node.
    /// @return Returns true if the node was inserted and false if not.
    bool insert(int key, string thing);

    /// @brief Finds a key if it exists in the tree.
    /// @param key The key for the key/value pair.
    /// @param thing The value for the key/value pair.
    /// @return True if found and false if not.
    bool find(int key, string& thing) const;

    /// @brief The total number of nodes in the tree.
    /// @return The integer for the number of nodes.
    int getSize() const;

    /// @brief The height of the tree.
    /// @return The integer for the height of the tree.
    int getHeight() const;

    /// @brief Finds all values in the tree within the range given.
    /// @param keyStart The lower limit for searching.
    /// @param keyEnd The upper limit for searching.
    /// @return A vector of all key/value pairs found in the tree.
    vector<string> findRange(int keyStart, int keyEnd) const;

    /**
     * Ostream overloaded for printing.
     * @param os Ostream object.
     * @param tree The tree to be printed
     * @return The ostream.
     */
    friend ostream& operator<<(ostream& os, const AVLTree& tree);

};