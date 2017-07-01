// Copyright 2017 Bevzuk Semen

#include <include/huffman.h>
#include <vector>
#include <string>
#include <list>
#include <map>

Node::Node() {
    left = right = NULL;
}

Node::Node(char symbol, int count) {
    this->symbol = symbol;
    this->count = count;
    left = right = NULL;
}

Node::Node(Node* left, Node* right) {
    this->symbol = 0;
    this->left = left;
    this->right = right;
    this->count = left->count + right->count;
}

bool Node::operator == (Node const& a) const {
    if (a.count != this->count)
        return false;
    if (a.symbol != this->symbol)
        return false;
    return true;
}

bool SortNode(const Node* a, const Node* b) {
    return a->count < b->count;
}

std::string Huffman::Encode(const std::string& string,
                            std::map<char, std::vector<bool>>* table) {
    CheckInputEncode(string, *table);

    input_string_ = string;

    std::list<Node*> trees;
    CreateTree(&trees);

    Node *root = trees.front();
    std::vector<bool> code;
    CreateTable(root, &code, table);

    std::string out = "";
    for (unsigned int i = 0; i < input_string_.length(); i++) {
        for (unsigned int j = 0; j < (*table)[input_string_[i]].size(); j++) {
            out += '0' + (*table)[input_string_[i]][j];
        }
    }

    return out;
}

std::string Huffman::Decode(const std::string& string,
                            const std::map<char, std::vector<bool> >& table) {
    CheckInputDecode(string, table);

    std::map<char, std::vector<bool> > temp_table = table;
    std::map<std::vector<bool>, char> reverse_table;
    std::map<char, std::vector<bool> >::iterator itr_table;
    unsigned int max_code_length = 0;
    for (itr_table = temp_table.begin(); itr_table != temp_table.end();
         ++itr_table) {
        reverse_table[itr_table->second] = itr_table->first;
        if (itr_table->second.size() > max_code_length)
            max_code_length = itr_table->second.size();
    }

    return DecodeReverseTable(string, &reverse_table, max_code_length);
}

void Huffman::CheckInputEncode(const std::string& string,
                               const std::map<char,
                               std::vector<bool>>& table) {
    if (string == "") {
        throw std::string("Empty line");
    }
}

void Huffman::CheckInputDecode(const std::string& string, const std::map<char,
                               std::vector<bool>>& table) {
    if (string == "") {
        throw std::string("Empty line");
    }
    if (table.empty()) {
        throw std::string("Empty table");
    }
}

void Huffman::CreateTree(std::list<Node*>* trees) {
    std::map<char, int> symbols;
    for (unsigned int i = 0; i < input_string_.length(); i++)
        symbols[input_string_[i]]++;

    std::map<char, int>::iterator itr_map;
    for (itr_map = symbols.begin(); itr_map != symbols.end(); ++itr_map) {
        Node *p = new Node(itr_map->first, itr_map->second);
        trees->push_back(p);
    }

    while (trees->size() != 1) {
        trees->sort(SortNode);

        Node *l = trees->front();
        trees->pop_front();
        Node *r = trees->front();
        trees->pop_front();

        Node *parent = new Node(l, r);
        trees->push_back(parent);
    }
}

void Huffman::CreateTable(Node* root, std::vector<bool>* code,
                          std::map<char, std::vector<bool> >* table) {
    if (root->left) {
        code->push_back(0);
        CreateTable(root->left, code, table);
    }

    if (root->right) {
        code->push_back(1);
        CreateTable(root->right, code, table);
    }

    if (root->symbol)
        (*table)[root->symbol] = *code;

    if (code->size())
        code->pop_back();
}

std::string Huffman::DecodeReverseTable(
    const std::string& string,
    std::map<std::vector<bool>, char>* table,
    unsigned int max_code_length) {
    std::string out = "";
    std::vector<bool> code;
    int current_code;
    for (unsigned int i = 0; i < string.length(); i++) {
        if (string[i] == '0')
            current_code = 0;
        else
            current_code = 1;
        code.push_back(current_code);
        if ((*table)[code]) {
            out += (*table)[code];
            code.clear();
        }
        if (code.size() > max_code_length) {
            throw std::string("Incorrect table");
        }
    }
    return out;
}
