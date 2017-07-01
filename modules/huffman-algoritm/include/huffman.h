// Copyright 2017 Bevzuk Semen

#ifndef MODULES_HUFFMAN_ALGORITM_INCLUDE_HUFFMAN_H_
#define MODULES_HUFFMAN_ALGORITM_INCLUDE_HUFFMAN_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

class Node {
 public:
    int count;
    char symbol;
    Node *left;
    Node *right;

    Node();

    Node(char symbol, int count);

    Node(Node* left, Node* right);

    bool operator == (Node const& a) const;
};

bool SortNode(const Node* a, const Node* b);

class Huffman {
 public:
    std::string Encode(const std::string& string,
                       std::map<char, std::vector<bool> >* table);

    std::string Decode(const std::string& string,
                       const std::map<char, std::vector<bool> >& table);

 private:
    std::string input_string_;

    void CheckInputEncode(const std::string& string,
                          const std::map<char, std::vector<bool> >& table);

    void CheckInputDecode(const std::string& string,
                          const std::map<char, std::vector<bool> >& table);

    void CreateTree(std::list<Node*>* trees);

    void CreateTable(Node* root, std::vector<bool>* code,
                     std::map<char, std::vector<bool> >* table);

    std::string DecodeReverseTable(const std::string& str,
                                     std::map<std::vector<bool>, char>* table,
                                     unsigned int max_code_length);
};

#endif  // MODULES_HUFFMAN_ALGORITM_INCLUDE_HUFFMAN_H_
