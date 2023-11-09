//CS3100 Project 4
//Jessica Venema

#include "AVLNode.h"
#include<string>

AVLNode::AVLNode():
    key(0),
    thing(""),
    height(1),
    left(nullptr),
    right(nullptr)    

{ }

AVLNode::AVLNode(int key, string thing):
    key(key),
    thing(thing),
    height(1),
    left(nullptr),
    right(nullptr)    

{ }