//CS3100 Project 4
//Jessica Venema

#include "AVLNode.h"
#include<string>

/// @brief No argument constructor initialzes all variables to either -1 or 
/// nullptr.
AVLNode::AVLNode():
    key(-1),
    height(-1),
    thing("-1"),
    left(nullptr),
    right(nullptr)    

{ }

/// @brief AVLNode constructor takes in a key and a string. It sets the height
/// to 1 and the right/left pointers to null. 
/// @param aKey The key value.
/// @param aThing The string value.
AVLNode::AVLNode(int aKey, string aThing):
    key(aKey),
    height(0),
    thing(aThing),
    left(nullptr),
    right(nullptr)    

{ }
