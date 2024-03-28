//CS3100 Project 4
//Jessica Venema

#include "AVLNode.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class AVLTree {

private:

    int size = 0;
    int height = 0;
    AVLNode* root = nullptr;

public:

    AVLTree();

    AVLTree(const AVLTree& t);

    ~AVLTree();

    bool insertHelper(AVLNode*& current, int key, string thing);

    bool insert(int key, string thing);

    int AVLTreeUpdateHeight(AVLNode*& node);

    int getSize() const;

    int getHeight() const;

    bool find(int key, string thing) const;

    vector<string> findRange(int keyStart, int keyEnd) const;

    void print(AVLNode* printNode) const;

    void reverseOrderTraversal(AVLNode* currentNode) const;

    void reverseOrderTraversalPrint(ostream& os, AVLNode* currentNode) const ;

    //Ostream modifer for printing.
    friend ostream& operator<<(ostream& os, const AVLTree& tree);

};