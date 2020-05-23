//
// Created by Kadir Gönül on 2020-04-19.
//

#include <set>
#include "huffman.h"

huffman::huffman(map<unsigned char, int> data) {
    int t = 0, size = data.size();
    unsigned char* arr = new unsigned char[size];
    int* freq = new int[size];

    map<unsigned char, int>::iterator i;
    for(i = data.begin(); i != data.end(); i++) {
        arr[t] = i->first;
        freq[t] = i->second;
        t++;
    }

    huffmanCodes(arr, freq, size);
    delete[] arr;
    delete[] freq;
}

//Build Huffman Tree and generate codes by traversing the built Huffman Tree
void huffman::huffmanCodes(unsigned char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;

    for (int i = 0; i < size; ++i) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1) {

        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node
        top = new MinHeapNode(left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes using
    // the Huffman tree built above
    cout<<"Generated huffman codes:"<<endl;
    generateHuffmanCodes(minHeap.top(), "");

    std::cout<<endl<<"Generated canonical huffman codes:"<<std::endl;
    generateCanonicalHuffmanCodes();
    cout<<endl;
}

// Prints huffman codes from
// the root of Huffman Tree. In-Order traversal. LNR.
void huffman::generateHuffmanCodes(struct MinHeapNode* root, string str) {
    if (!root)
        return;

    if (root->internalNode == false) {
        cout << hex << (int) root->data << ": " << str << "\n";
        code[root->data] = str.empty() ? "0" : str;
    }

    generateHuffmanCodes(root->left, str + "0");
    generateHuffmanCodes(root->right, str + "1");
}

//Returns generated code for the symbol
string huffman::operator[] (unsigned char p) {
    auto search = code.find(p);
    if (search != code.end()) {
        return search->second;
    }
    else {
        cout << "Array index out of bound" << p << " not found, exiting";
        exit(0);
    }
}

/**
 * Returns encoded bit string for the data provided for each color channel
 * @param str symbol sequence provided by each color channel
 * @param size size of data provided by each color channel
 * @return encoded bit string
 */
string huffman::getEncodedData(unsigned char *str, int size) {
    string encodedStr = "";
    for (int i = 0; i < size; i++) {
        encodedStr += code[*(str+i)];
    }
    return encodedStr;
}

/**
 * Generates header data ordered by code length increasing.
 * Number of symbols + each [symbol + length]
 * @return header data for each color channel
 */
string huffman::generateHeader() {
    //Declaring the type of Predicate that accepts 2 pairs and return a bool
    typedef std::function<bool(std::pair<unsigned char, string>, std::pair<unsigned char, string>)> Comparator;

    //Defining a lambda function to compare two pairs. It will compare two pairs using second field
    Comparator compFunctor =
            [](std::pair<unsigned char, string> elem1 ,std::pair<unsigned char, string> elem2)
            {
                if (elem1.second.size() != elem2.second.size())
                    return elem1.second.size() < elem2.second.size();
                else
                    return elem1.first <elem2.first;
            };

    //Declaring a set that will store the pairs using above comparision logic
    std::set<std::pair<unsigned char, string>, Comparator> setOfWords(
            code.begin(), code.end(), compFunctor);

    //This is the advantage of canonical huffman
    //We don't need to store the codes. Of course we still need to pass to the decoder the lengths and symbols
    string header = "";

    //Number of symbols + each [symbol + length]
    header += (unsigned char)(code.size()-1);
    for (std::pair<unsigned char, string> element : setOfWords) {
        header += element.first;
        header += element.second.size();
    }

    return header;
}

//Increment bit string by adding 1
string incrementBitString(string str) {
    bool carry = true;
    for (int i = (str.size() - 1); i >= 0; i--) {
        if (carry) {
            if (str[i] == '0') {
                str[i] = '1';
                carry = false;
            }
            else {
                str[i] = '0';
                carry = true;
            }
        }
    }
    if (carry) {
        str.insert(0, "1");
    }
    return str;
}

/**
 * Canonical increment
 * @param previous code that set by zeros
 * @param current Code that follows previous code. Code length ordered. So length should be same or longer
 * @return new code for canonical huffman
 */
string canonicalIncrement(string previous, string current) {
    string res = incrementBitString(previous);
    if (previous.size() != current.size()) {
        int diff = current.size() - res.size();
        res.append(diff, '0');
    }
    return res;
}

string canonicalIncrement(string previous, int current) {
    string res = incrementBitString(previous);
    if (previous.size() != current) {
        int diff = current - res.size();
        res.append(diff, '0');
    }
    return res;
}

void huffman::generateCanonicalHuffmanCodes() {
    typedef std::pair<unsigned char, string> pair;

    // create an empty vector of pairs
    std::vector<pair> vec;

    // copy key-value pairs from the map to the vector
    std::copy(code.begin(),
              code.end(),
              std::back_inserter<std::vector<pair>>(vec));

    // sort the vector by increasing order of its pair's second value
    // if second value are equal, order by the pair's first value
    std::sort(vec.begin(), vec.end(),
              [](const pair& l, const pair& r) {
                  return l.second.size() < r.second.size();
              });

    pair previous = vec.front();
    previous.second.assign(previous.second.size(), '0'); //Assign zeros for shortest code
    code[previous.first] = previous.second;

    std::vector<pair>::iterator it = vec.begin();
    std::advance(it, 1);

    while (it != vec.end()) {
        it->second = canonicalIncrement(previous.second, it->second);
        code[it->first] = it->second;
        previous = *it;
        ++it;
    }

    for(auto elem : code) {
        std::cout << hex << (int) elem.first << ": " << elem.second << " " << "\n";
    }
}

/**
 * Regenerates canonical huffman codes after code length for each symbol read from compressed file
 * @param symbols each symbol and its code length
 */
void huffman::regenerateCanonicalCodes(std::map<unsigned char, int> symbols) {
    canonicalCode.clear();
    typedef std::pair<unsigned char, int> pair;

    //Declaring the type of Predicate that accepts 2 pairs and return a bool
    typedef std::function<bool(std::pair<unsigned char, int>, std::pair<unsigned char, int>)> Comparator;

    //Defining a lambda function to compare two pairs. It will compare two pairs using second field
    Comparator compFunctor =
            [](std::pair<unsigned char, int> elem1 ,std::pair<unsigned char, int> elem2)
            {
                if (elem1.second != elem2.second)
                    return elem1.second < elem2.second;
                else
                    return elem1.first <elem2.first;
            };

    //Declaring a set that will store the pairs using above comparision logic
    std::set<std::pair<unsigned char, int>, Comparator> setOfWords(
            symbols.begin(), symbols.end(), compFunctor);

    std::set<std::pair<unsigned char, int>>::iterator it = setOfWords.begin();
    string previousCode = std::string(it->second, '0');
    canonicalCode[previousCode] = it->first;
    std::advance(it, 1);

    while (it != setOfWords.end()) {
        previousCode = canonicalIncrement(previousCode, it->second);
        canonicalCode[previousCode] = it->first;
        ++it;
    }
}

/**
 * Encoded byte array is decoded using regenerated huffman codes
 * @param encodedText encoded binary data stream
 * @return decoded data stream - sequence of symbols
 */
string huffman::decodeData(string encodedText) {
    int start, length;
    string decodedText = "";
    start = 0;
    length = 1;

    while(start + length <= encodedText.size()) {
        string current = encodedText.substr(start, length);
        if(canonicalCode.find(current) != canonicalCode.end()) {
            decodedText += canonicalCode[current];
            start += length;
            length = 1;
            continue;
        }

        ++length;
    }
    return decodedText;
}


