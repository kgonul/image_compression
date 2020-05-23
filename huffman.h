//
// Created by Kadir Gönül on 2020-04-19.
//

#ifndef UNTITLED1_HUFFMAN_H
#define UNTITLED1_HUFFMAN_H

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

// A Huffman tree node
struct MinHeapNode {
    // One of the input characters
    unsigned char data;

    // Frequency of the character
    unsigned freq;

    // Left and right child
    MinHeapNode *left, *right;

    bool internalNode;

    MinHeapNode(unsigned char data, unsigned freq) :internalNode(false) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }

    MinHeapNode(unsigned freq) :internalNode(true) {
        left = right = nullptr;
        this->freq = freq;
    }

    MinHeapNode() {
        left = right = nullptr;
    }
};

// For comparison of
// two heap nodes (needed in min heap)
struct compare {
    bool operator() (MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

class huffman {
public:
    huffman(map<unsigned char, int> data);
    string operator[] (unsigned char p);
    string getEncodedData(unsigned char *str, int size);
    string decodeData(string s);
    string generateHeader();
    void regenerateCanonicalCodes(std::map<unsigned char, int> symbols);

private:
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    map<unsigned char, string> code;
    map<string, unsigned char> canonicalCode;
private:
    void generateHuffmanCodes(struct MinHeapNode* root, string str);
    void generateCanonicalHuffmanCodes();
    void huffmanCodes(unsigned char data[], int freq[], int size);
};


#endif //UNTITLED1_HUFFMAN_H
