// Copyright 2017 Doronin Maxim

#include "include/SearchTree.h"

SearchTree::SearchTree() : root_(0) {}

SearchTree::~SearchTree() {
    RecursiveDeletion(&root_);
}

const Node* SearchTree::Search(const double key) const {
    Node* currentNode = root_;
    if (currentNode == 0) {
        throw "Search: Tree is empty!";
    }

    while (currentNode != 0 && currentNode->key != key) {
        if (key < currentNode->key) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    return currentNode;
}

const Node* SearchTree::FindMin() const {
    return FindMin(root_);
}

const Node* SearchTree::FindMax() const {
    return FindMax(root_);
}

const Node* SearchTree::FindMin(const Node* const node) const {
    const Node* currentNode = node;
    if (currentNode == 0) {
        throw "searchMin: Tree is empty!";
    }
    while (currentNode->left != 0) {
        currentNode = currentNode->left;
    }
    return currentNode;
}

const Node* SearchTree::FindMax(const Node* const node) const {
    const Node* currentNode = node;
    if (currentNode == 0) {
        throw "searchMax: Tree is empty!";
    }
    while (currentNode->right != 0) {
        currentNode = currentNode->right;
    }
    return currentNode;
}

const Node* SearchTree::FindPrev(const double key) const {
    const Node* currentNode = Search(key);
    if (currentNode == 0) {
        throw "FindPrev: there is no element with such key!";
    }
    return FindPrev(currentNode);
}

const Node* SearchTree::FindNext(const double key) const {
    const Node* currentNode = Search(key);
    if (currentNode == 0) {
        throw "FindNext: there is no element with such key!";
    }
    return FindNext(currentNode);
}

const Node* SearchTree::FindPrev(const Node* const node) const {
    const Node* result;
    if (node->left != 0) {
        result =  FindMax(node->left);
    } else {
        const Node* currentNode = node;
        const Node* currentParent = node->parent;
        while (currentParent != 0 && currentNode == currentParent->left) {
            currentNode = currentParent;
            currentParent = currentParent->parent;
        }
        result = currentParent;
    }
    return result;
}

const Node* SearchTree::FindNext(const Node* const node) const {
    const Node* result;
    if (node->right != 0) {
        result = FindMin(node->right);
    } else {
        const Node* currentNode = node;
        const Node* currentParent = node->parent;
        while (currentParent != 0 && currentNode == currentParent->right) {
            currentNode = currentParent;
            currentParent = currentParent->parent;
        }
        result = currentParent;
    }
    return result;
}

void SearchTree::Insert(const double key) {
    Node* node = new Node;
    node->key = key;
    node->left = 0;
    node->right = 0;
    node->parent = 0;

    if (root_ == 0) {
        root_ = node;
        return;
    }

    Node* currentNode = root_;
    Node* tmpParentNode;
    while (currentNode != 0) {
        tmpParentNode = currentNode;
        if (currentNode->key < node->key) {
            currentNode = currentNode->right;
        } else if (currentNode->key > node->key) {
            currentNode = currentNode->left;
        } else {
            throw "Insert: Already have such key!";
        }
    }

    node->parent = tmpParentNode;
    if (tmpParentNode->key <= node->key) {
        tmpParentNode->right = node;
    } else {
        tmpParentNode->left = node;
    }
}

void SearchTree::Erase(const double key) {
    Node* dyingNode = const_cast<Node*>(Search(key));
    if (dyingNode == 0) {
        throw "Erase: no such element in the tree";
    }

    Node* parent = dyingNode->parent;
    if (dyingNode->left == 0 && dyingNode->right == 0) {
        if (parent->left == dyingNode) {
            parent->left = 0;
        }
        if (parent->right == dyingNode) {
            parent->right = 0;
        }
        delete dyingNode;
    } else if (dyingNode->left == 0 || dyingNode->right == 0) {
        if (dyingNode->left == 0) {
            if (parent->left == dyingNode) {
                parent->left = dyingNode->right;
            } else {
                parent->right = dyingNode->right;
            }
            dyingNode->right->parent = parent;
        } else {
            if (parent->left == dyingNode) {
                parent->left = dyingNode->left;
            } else {
                parent->right = dyingNode->left;
            }
            dyingNode->left->parent = parent;
        }
        delete dyingNode;
    } else {
        Node* child = const_cast<Node*>(FindNext(dyingNode));
        double newKey = child->key;
        Erase(child->key);
        dyingNode->key = newKey;
    }
}

void SearchTree::Clear() {
    RecursiveDeletion(&root_);
}

bool SearchTree::IsEmpty() const {
    if (root_ != 0) {
        return 0;
    } else {
        return 1;
    }
}

const int SearchTree::Size() const {
    return RecursiveSize(root_);
}

void SearchTree::RecursiveDeletion(Node** const node) {
    if (*node == 0) {
        return;
    }
    RecursiveDeletion(&((*node)->left));
    RecursiveDeletion(&((*node)->left));
    delete *node;
    *node = 0;
}

const int SearchTree::RecursiveSize(const Node* const node) const {
    if (node == 0) {
        return 0;
    }
    int Size;
    Size = RecursiveSize(node->left) + RecursiveSize(node->right);
    return Size + 1;
}
