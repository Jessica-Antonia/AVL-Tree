//CS3100 Project 4
//Jessica Venema

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class AVLTree {

private:

    class Node {

    public: 

        Node* parent;
        Node* rightChild;
        Node* leftChild;

        int key;
        string thing;

        


    };

    int size = 0;
    int height = 0;
    Node* root = nullptr;

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