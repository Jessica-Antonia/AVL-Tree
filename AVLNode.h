//CS3100 Project 4
//Jessica Venema

#include<string>

using namespace std;

class AVLNode {

public:

    int key = 0;
    int height = 0;
    string thing = "";
    AVLNode* left = nullptr;
    AVLNode* right = nullptr;

    AVLNode();

    AVLNode(int key, string thing);

};