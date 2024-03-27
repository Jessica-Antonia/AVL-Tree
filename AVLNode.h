//CS3100 Project 4
//Jessica Venema

#include<string>
#include<iostream>

using namespace std;

/// @brief The class AVLNode is it's own class for code reusability. I have 
/// included print and ostream functions for testing the class. 
class AVLNode {

public: 

    //Public variables for the AVLNode object.
    int key = 0;
    int height = 0;
    int balance = 0;
    string thing = "";
    AVLNode* left = nullptr;
    AVLNode* right = nullptr;

    //No argument constructor.
    AVLNode();

    //Construtor that takes a key and a string for the AVLNode object.
    AVLNode(int key, string thing);

    //Printing function.
    void print(ostream& os) const;

    //Ostream modifer for printing.
    friend ostream& operator<<(ostream& os, const AVLNode& n);

};