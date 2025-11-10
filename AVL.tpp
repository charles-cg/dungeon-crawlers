#pragma once
#include "AVL.h"

#include <sstream>
#include <cmath>

template <typename T>
AVL<T>::~AVL() {
    clear();
}

template <typename T>
void AVL<T>::print() {
    int treeHeight = height(root);
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

template <typename T>
void AVL<T>::print(const int& r, const int& c, int& height, std::string** matrix, Node<T>* node) {
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

template <typename T>
int AVL<T>::height(Node<T>* node) const {
    return node ? node->getHeight():0;
}

template <typename T>
int AVL<T>::balanceFactor(Node<T>* node) const {
    if (node == nullptr) {
        return 0;
    }
    return height(node->getLeft()) - height(node->getRight());
}

template <typename T>
int AVL<T>::maxValue(int a, int b) const {
    return (a > b) ? a : b;
}

template <typename T>
Node<T>* AVL<T>::rotateRight(Node<T>* node) {
    Node<T>* temp = node->getLeft();
    Node<T>* temp2 = temp->getRight();

    temp->setRight(node);
    node->setLeft(temp2);

    node->setHeight(1 + maxValue(height(node->getLeft()), height(node->getRight())));
    temp->setHeight(1 + maxValue(height(temp->getLeft()), height(temp->getRight())));

    return temp;
}

template <typename T>
Node<T>* AVL<T>::rotateLeft(Node<T>* node) {
    Node<T>* temp = node->getRight();
    Node<T>* temp2 = temp->getLeft();

    temp->setLeft(node);
    node->setRight(temp2);

    node->setHeight(1 + maxValue(height(node->getLeft()), height(node->getRight())));
    temp->setHeight(1 + maxValue(height(temp->getLeft()), height(temp->getRight())));

    return temp;
}

template <typename T>
Node<T>* AVL<T>::rotateLeftRight(Node<T>* node) {
    node->setLeft(rotateLeft(node->getLeft()));
    return rotateRight(node);
}

template <typename T>
Node<T>* AVL<T>::rotateRightLeft(Node<T>* node) {
    node->setRight(rotateRight(node->getRight()));
    return rotateLeft(node);
}

template <typename T>
void AVL<T>::insert(const T& value) {
    root = insert(root, value);
}

template <typename T>
Node<T>* AVL<T>::insert(Node<T>* node, const T& value) {
    if (node == nullptr) {
        return new Node<T>(value);
    }
    if (value < node->getData()) {
        node->setLeft(insert(node->getLeft(), value));
    } else if (value > node->getData()) {
        node->setRight(insert(node->getRight(), value));
    } else {
        return node;
    }

    node->setHeight(1 + maxValue(height(node->getLeft()), height(node->getRight())));
    const int bf = balanceFactor(node);

    if (bf > 1 && value < node->getLeft()->getData()) {
        return rotateRight(node);
    }
    if (bf < -1 && value > node->getRight()->getData()) {
        return rotateLeft(node);
    }
    if (bf > 1 && value > node->getLeft()->getData()) {
        return rotateLeftRight(node);
    }
    if (bf < -1 && value < node->getRight()->getData()) {
        return rotateRightLeft(node);
    } 
    return node;
}

template <typename T>
void AVL<T>::remove(const T& value) {
    root = remove(root, value);
}

template <typename T>
Node<T>* AVL<T>::remove(Node<T>* node, const T& value) {
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

    node -> setHeight(1+ maxValue(height(node->getLeft()), height(node->getRight())));
    const int bf = balanceFactor(node);

    if (bf > 1 && value < node ->getLeft()->getData()) { //Rotación simple a la derecha
        return rotateRight(node);
    }

    if (bf < -1 && value > node->getRight()->getData()) {
        return rotateLeft(node);
    }
    if (bf > 1 && value > node ->getLeft()->getData()) { //Rotación simple a la derecha
        return rotateLeftRight(node);
    }

    if (bf < -1 && value < node->getRight()->getData()) {
        return rotateRightLeft(node);
    }
    return node;
}

template <typename T>
void AVL<T>::searchPath(const T& value) {
    searchPath(root, value);
}

template <typename T>
void AVL<T>::searchPath(Node<T>* node, const T& value) {
    if (node == nullptr) {
        std::cout << "->Not Found" << std::endl;
        return;
    }

    std::cout << "->" << node->getData();

    if (value == node->getData()) {
        std::cout << "->Found " << std::endl;
    }

    if (value < node->getData()) {
        searchPath(node->getLeft(), value);
    } else if (value > node->getData()) {
        searchPath(node->getRight(), value);
    }
}

template <typename T>
void AVL<T>::clear() {
    if (root == nullptr) {
        std::cout << "Tree is empty!" << std::endl;
        return; // if the tree has no nodes, don't do anything
    }

    clear(root); // calls private clear method
    root = nullptr;
    std::cout << "Tree has been cleared!" << std::endl;
}

template <typename T>
void AVL<T>::clear(Node<T>* node) {
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

template <typename T>
Node<T>* AVL<T>::search(const T& value) {
    Node<T>* current = root;
    while (current != nullptr) {
        if (value == current->getData()) {
            return current;
        } else if (value < current->getData()) {
            current = current->getLeft();
        } else {
            current = current->getRight();
        }
    }
    return nullptr;
}