// Copyright 2017 Doronin Maxim

#ifndef MODULES_SEARCH_TREE_INCLUDE_SEARCHTREE_H_
#define MODULES_SEARCH_TREE_INCLUDE_SEARCHTREE_H_


class Node {
 public:
     double key;
     Node* left;
     Node* right;
     Node* parent;
};

class SearchTree {
 public:
     SearchTree();
     ~SearchTree();

     const Node* Search(const double key) const;
     const Node* FindMin() const;
     const Node* FindMax() const;
     const Node* FindMin(const Node* const node) const;
     const Node* FindMax(const Node* const node) const;
     const Node* FindPrev(const double key) const;
     const Node* FindNext(const double key) const;

     void Insert(const double key);
     void Erase(const double key);
     void Clear();

     bool IsEmpty() const;
     const int Size() const;

 protected:
     Node* root_;

     const Node* FindPrev(const Node* const node) const;
     const Node* FindNext(const Node* const node) const;

     void RecursiveDeletion(Node** const node);  // for destructor
     const int RecursiveSize(const Node* const node) const;
};

#endif  // MODULES_SEARCH_TREE_INCLUDE_SEARCHTREE_H_
