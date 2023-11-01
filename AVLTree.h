//CS3100 Project 4
//Jessica Venema

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class AVLTree {

private:

public:

    AVLTree();

    AVLTree(const AVLTree& t);

    ~AVLTree();

    void insert(int key, string thing);

    int getSize() const;

    int getHeight() const;

    string find(int key, string thing) const;

    vector<string> findRange(int keyStart, int keyEnd) const;

};