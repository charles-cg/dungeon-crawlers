//Carlos Carreon A01665778
//header file where BST methods are implemented
//created on 09.10.25, last modified 20.10.25
#pragma once
#include "BST.h"
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

// constructor of the BST.
template<typename T>
BST<T>::BST(): root(nullptr){}

// destructor of the BST.
template<typename T>
BST<T>::~BST() {
    clear(); // calls clear method
}

// isEmpty checkes if there is data on the BST.
template<typename T>
bool BST<T>::isEmpty() const {
    return root==nullptr;
}

// function to print a tree vertically.
template<typename T>
void BST<T>::print() {
    int treeHeight = height();
    int rows = treeHeight + 1; // number of rows needed for the matrix
    int cols = pow(2, rows) - 1; // number of columns needed from the matrix, formula obtained from leetcode print tree problem https://leetcode.com/problems/print-binary-tree/description/

    // create a dynamic matrix using a pointer to an array of pointers
    std::string** matrix = new std::string*[rows]; // the matrix should be of type string in order to display correctly
    for (unsigned int i = 0; i < rows; i++) {
        matrix[i] = new std::string[cols];
        for (unsigned int j = 0; j < cols; j++) {
            matrix[i][j] = " "; // initializes each matrix element with a space
        }
    }

    print(0, (cols - 1) / 2, treeHeight, matrix, root); // call private method of print for recursion

    // output the matrix to the terminal using two for loops
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";  
        }
        std::cout << "\n";
        delete[] matrix[i];  // delete each row
    }

    delete[] matrix; // delete the matrix pointer
    matrix = nullptr;
}

// private method used for recursion.
template <typename T>
void BST<T>::print(const int& r, const int& c, int& height, std::string** matrix, Node<T>* node) { // r are rows and c are cols
    if (node == nullptr) {
        return; // base case when the node is a nullptr (reaches ends with no node)
    }

    // used to convert numerical types to string, reference obtained from cplusplus.com https://cplusplus.com/reference/sstream/basic_stringstream/str/
    std::stringstream ss;
    ss << node->getData();
    matrix[r][c] = ss.str();

    // obtain where the trees will be inserted in the matrix horizontally
    int leftCol = c - pow(2, height - r - 1); 
    int rightCol = c + pow(2, height - r - 1);
    // formula obtained from leetcode print tree problem https://leetcode.com/problems/print-binary-tree/description/

    // function calls itself with left child and right child, increasing one to the rows of the matrix
    print(r+1, leftCol, height, matrix, node->getLeft());
    print(r+1, rightCol, height, matrix, node->getRight());
}

// method to clear the tree (delete all nodes).
template<typename T>
void BST<T>::clear() {
    if (isEmpty()) {
        std::cout << "Tree is empty!" << std::endl;
        return; // if the tree has no nodes, don't do anything
    }

    clear(root); // calls private clear method
    root = nullptr;
    std::cout << "Tree has been cleared!" << std::endl;
}

// private clear method.
template <typename T>
void BST<T>::clear(Node<T>* node) {
    if (node == nullptr) {
        return; // base case when the node is a nullptr (reaches ends with no node)
    }

    // calls the left and then the right
    // uses post Order to go through the tree
    clear(node->getLeft());
    clear(node->getRight());

    // deletes the node it is at
    delete node;
    node = nullptr;
}

// method to insert a new node
template<typename T>
void BST<T>::insert(const T& v) {
    Node<T>* newNode= new Node<T>(v);
    if (root==nullptr) {
        root = newNode; // when no node, directly insert
        return;
    }
    Node<T>* temp= root;
    Node<T>* parent= nullptr;
    while (temp!=nullptr) {
        parent= temp;
        if (v < temp->getData()) {
            temp= temp->getLeft(); 
        }else if (v > temp->getData()) {
            temp= temp->getRight(); 
        }else {
            delete newNode; // if the node is not valid, delete it
            return;
        }
    }
    if (v < parent->getData()) {
        parent->setLeft(newNode); // insert to the left if the value is smaller
    }else {
        parent->setRight(newNode); // insert to the right if the value is bigger
    }
    delete temp;
}

// private search method
template<typename T>
bool BST<T>::search(Node<T>* root, const T& v) const {
    if (root== nullptr) {
        return false; // case when value is not found
    }
    cout<<"Visitando: "<<root->getData()<<endl;
    if (v==root->getData()) {
        return true; // case when value is found
    }
    // uses binary search to find the value
    if (v < root->getData()) {
        cout<<"Moviendo izquierda"<<endl;
        return search(root->getLeft(), v);
    }
    cout<<"Moviendo derecha"<<endl;
    return search(root->getRight(), v);

}
// method to search a value, return true if it is found
template<typename T>
bool BST<T>::search(const T& v) const {
    return search(root, v); // calls private search function
}

// print when a node is visited
template <typename T>
void BST<T>::visit(Node<T>* node) const {
    std::cout << "Visited: " << node -> getData() << std::endl;
}

// method to print nodes of the tree in order
template <typename T>
void BST<T>::inOrder() const {
    inOrder(root);
}

// private method of inOrder function
template <typename T>
void BST<T>::inOrder(Node<T>* node) const {
    if (node == nullptr) {
        return; // base case
    }
    inOrder(node -> getLeft());
    visit(node);
    inOrder(node -> getRight());
}

// method to print the nodes post order (last to first node)
template <typename T>
void BST<T>::postOrder() const {
    postOrder(root);
}

// private method of postOrder
template <typename T>
void BST<T>::postOrder(Node<T>* node) const {
    if (node == nullptr) {
        return;
    }
    postOrder(node -> getLeft());
    postOrder(node -> getRight());
    visit(node);
}

// method to print nodes in pre order (first to last node)
template <typename T>
void BST<T>::preOrder() const {
    preOrder(root);
}

// private method of preOrder
template <typename T>
void BST<T>::preOrder(Node<T>* node) const {
    if (node == nullptr) {
        return;
    }
    visit(node);
    preOrder(node -> getLeft());
    preOrder(node -> getRight());
}

// private method of remove function
template <typename T>
Node<T>* BST<T>::remove(Node<T>* node, const T& value) {
    if (node == nullptr) return nullptr; // Here we remove the root node if present

    //node is the current subtree root
    if (value < node ->getData()) {
        node->setLeft(remove(node->getLeft(),value));
    } else if (value > node->getData()) {
        node->setRight(remove(node->getRight(),value));
    } else { //If they are the same

        //We found the node we want to delete
        // Handling 3 cases: 0, 1, or 2 children.
        if (node ->getRight()== nullptr && node->getLeft()== nullptr) { // Case 1: leaf node
            delete node;
            return nullptr;

        } else if (node-> getLeft()==nullptr) { // Case 2a: only right child
            Node<T>* temp = node->getRight();
            delete node;
            return temp;

        } else if (node -> getRight() == nullptr) { // Case 2b: only left child
            Node<T>* temp = node->getLeft();
            delete node;
            return temp;

        } else { // Case 3: two children
            Node<T>* maxNode = node -> getLeft();
            while (node && maxNode-> getRight() != nullptr) {
                maxNode = maxNode -> getRight();
            } // Copy predecessor's value into current node, then remove predecessor
            T maxValue = maxNode ->getData();
            node->setData(maxValue);
            node ->setLeft(remove(node->getLeft(), maxNode->getData()));
        }
    }
    return node;
}

// method to remove a node
template <typename T>
void BST<T>::remove(const T& value) {
    root = remove(root, value); // call private method
}

// method to get the height of the tree
template <typename T>
int BST<T>::height() {
    return height(root); // call private method
}

// private method for height used in the recursion
template <typename T>
int BST<T>::height(Node<T>* node) {
    if (node == nullptr) {
        return -1; // base case when the node is a nullptr (reaches the deepest node)
    }

    // calls itself to the right and to the left
    int leftHeight = height(node->getLeft());
    int rightHeight = height(node->getRight());

    // takes the max height of the two sides and returns its value
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

// method to find the ancestors of a given value
template <typename T>
bool BST<T>::ancestors(const T& value) {
    return ancestors(root, value);
}

// private method of ancestors
template <typename T>
bool BST<T>::ancestors(Node<T>* node, const T& value) {
    if (node == nullptr) {
        return false; // case when the value is not found
    }

    if (node->getData() == value) {
        return true; // base case when the value is found
    }

    // if either child has the data it is the ancestor of that child
    if (ancestors(node->getLeft(), value) || ancestors(node->getRight(), value)) {
        std::cout << node->getData() << " is an ancestor of " << value << std::endl;
        return true;
    } else {
        return false;
    }
}

// tells the current height of a value
template <typename T>
int BST<T>::whatLevelAmI(const T& value) {
    int level = whatLevelAmI(root, value);
    return height() - level; // substracts the obtained level to return the height instead of depth
}

// private method of whatLevelAmI for recursion
template <typename T>
int BST<T>::whatLevelAmI(Node<T>* node, const T& value) {
    if (node == nullptr) {
        return -1; // case when value is not found
    }

    if (node->getData() == value) {
        return 0; // case when value is found
    }

    // does binary search to find the data
    if (value < node->getData()) {
        int level = whatLevelAmI(node->getLeft(), value);
        if (level == -1) {
            return -1; // when value is not found
        }
        return level + 1;
    } else {
        int level = whatLevelAmI(node->getRight(), value);
        if (level == -1) {
            return -1; // when value is not found
        }
        return level + 1;
    }
}