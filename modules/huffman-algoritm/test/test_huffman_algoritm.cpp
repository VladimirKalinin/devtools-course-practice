// Copyright 2017 Bevzuk Semen

#include <gtest/gtest.h>

#include <map>
#include <string>
#include <list>
#include <vector>
#include "include/huffman.h"

void AddVector(std::map<char, std::vector<bool> >* table,
               char char_symbol, std::string input) {
    std::vector<bool> vec;
    for (unsigned int i = 0; i < input.length(); i++) {
        vec.push_back(input[i] - '0');
    }
    (*table)[char_symbol] = vec;
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Create_Empty_Node) {
    // Act & Assert
    EXPECT_NO_THROW(Node node);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Compare_Two_Nodes) {
    // Arrang
    Node node_1;
    Node node_2;
    node_1.count = 2;
    node_2.count = 2;
    node_1.symbol = 'a';
    node_2.symbol = 'a';
    bool result;

    // Act
    if (node_1 == node_2)
        result = true;
    else
        result = false;

    // Assert
    EXPECT_EQ(true, result);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Not_Compare_Two_Nodes_Count) {
    // Arrang
    Node node_1;
    Node node_2;
    node_1.count = 2;
    node_2.count = 4;
    node_1.symbol = 'a';
    node_2.symbol = 'a';
    bool result;

    // Act
    if (node_1 == node_2)
        result = true;
    else
        result = false;

    // Assert
    EXPECT_NE(true, result);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Not_Compare_Two_Nodes_Symbol) {
    // Arrang
    Node node_1;
    Node node_2;
    node_1.count = 2;
    node_2.count = 2;
    node_1.symbol = 'a';
    node_2.symbol = 'b';
    bool result;

    // Act
    if (node_1 == node_2)
        result = true;
    else
        result = false;

    // Assert
    EXPECT_NE(true, result);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Create_Node) {
    // Arrang
    Node node('a', 1);
    Node expected_node;
    expected_node.count = 1;
    expected_node.symbol = 'a';

    // Act & Assert
    EXPECT_EQ(expected_node, node);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Create_Node_whith_branchs) {
    // Arrang
    Node node_left('l', 1);
    Node node_right('r', 1);

    // Act
    Node root(&node_left, &node_right);

    // Assert
    EXPECT_EQ(node_left, *root.left);
    EXPECT_EQ(node_right, *root.right);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Sort_List_Nodes_counts) {
    // Arrang
    std::list<Node*> tree;
    Node *node_1 = new Node('a', 1);
    Node *node_2 = new Node('b', 2);
    tree.push_back(node_2);
    tree.push_back(node_1);

    // Act
    tree.sort(SortNode);
    Node *result_node_1 = tree.front();
    tree.pop_front();
    Node *result_node_2 = tree.front();
    tree.pop_front();

    // Assert
    EXPECT_LT(result_node_1->count, result_node_2->count);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Encode_String) {
    // Arrang
    std::string input_string = "aaabbc";
    std::map<char, std::vector<bool> > code_table;
    Huffman ha;
    std::string result_code = "000111110";

    // Act
    std::string out_code = ha.Encode(input_string, &code_table);

    // Assert
    EXPECT_EQ(result_code, out_code);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Encode_String_and_Generate_Table) {
    // Arrang
    std::string input_string = "aab";
    std::map<char, std::vector<bool> > code_table;
    std::map<char, std::vector<bool> > result_table;
    AddVector(&result_table, 'a', "1");
    AddVector(&result_table, 'b', "0");
    Huffman ha;

    // Act
    ha.Encode(input_string, &code_table);

    // Assert
    EXPECT_EQ(result_table, code_table);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Decode_Code) {
    // Arrang
    std::string input_code = "000111110";
    std::map<char, std::vector<bool> > code_table;
    AddVector(&code_table, 'a', "0");
    AddVector(&code_table, 'b', "11");
    AddVector(&code_table, 'c', "10");
    Huffman ha;
    std::string result_string = "aaabbc";

    // Act
    std::string out_string = ha.Decode(input_code, code_table);

    // Assert
    EXPECT_EQ(result_string, out_string);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Not_Decode_Whith_Incorrect_Table) {
    // Arrang
    std::string input_code = "000111110";
    std::map<char, std::vector<bool> > code_table;
    AddVector(&code_table, 'a', "110");
    AddVector(&code_table, 'b', "10");
    AddVector(&code_table, 'c', "11");
    Huffman ha;
    std::string result_string = "aaabbc";

    // Act & Assert
    EXPECT_ANY_THROW(ha.Decode(input_code, code_table));
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Can_Encode_and_Decode) {
    // Arrang
    std::map<char, std::vector<bool> > code_table;
    std::string input_string = "aaabbc";
    std::string result_string = input_string;
    Huffman ha;

    // Act
    std::string out_code = ha.Encode(input_string, &code_table);
    std::string out_string = ha.Decode(out_code, code_table);

    // Assert
    EXPECT_EQ(result_string, out_string);
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Not_Accept_Empty_String_Encode) {
    // Arrang
    std::string input_string = "";
    std::map<char, std::vector<bool> > code_table;
    Huffman ha;

    // Act & Assert
    EXPECT_ANY_THROW(ha.Encode(input_string, &code_table));
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Not_Accept_Empty_Code_Decode) {
    // Arrang
    std::string input_code = "";
    std::map<char, std::vector<bool> > code_table;
    std::vector<bool> vec_1;
    vec_1.push_back(0);
    code_table['a'] = vec_1;
    Huffman ha;

    // Act & Assert
    EXPECT_ANY_THROW(ha.Decode(input_code, code_table));
}

TEST(Bevzuk_Semen_HuffmanAlgoritmTest, Not_Accept_Empty_Table_Decode) {
    // Arrang
    std::string input_code = "000011";
    std::map<char, std::vector<bool> > code_table;
    Huffman ha;

    // Act & Assert
    EXPECT_ANY_THROW(ha.Decode(input_code, code_table));
}
