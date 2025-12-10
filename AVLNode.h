//CS3100 Project 4
//Jessica Venema
#pragma once

#include<string>
#include<iostream>

using namespace std;

/// @brief The class AVLNode is its own class for code reusability.
class AVLNode {

private: 

    //Private variables for the AVLNode object.
    int key;
    int height;
    string thing;
    AVLNode* left;
    AVLNode* right;

    // declaring the AVLTree class as a friend allows access to private
    // members
    friend class AVLTree;   

public:

    /**
     * No argument constructor.
     */
    AVLNode();

    /**
     * Constructor that takes a key and a string for the AVLNode object.
     * @param key The key value.
     * @param thing The node content value.
     */
    AVLNode(int key, string thing);
};