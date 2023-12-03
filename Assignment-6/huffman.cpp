#include <iostream>
#include <queue>
#include <map>
using namespace std;

// A Huffman tree node
struct Node 
{
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// Comparison object to be used to order the heap
struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

// Traverses the Huffman tree and stores the codes in a map
void encode(Node* root, string code, map<char, string> &huffmanCode) {
    if (root == nullptr) {
        return;
    }
    if (!root->left && !root->right) {
        huffmanCode[root->data] = code;
    }
    encode(root->left, code + "0", huffmanCode);
    encode(root->right, code + "1", huffmanCode);
}

// Builds the Huffman tree and returns the root
Node* buildHuffmanTree(string s, int freq[], int n) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < n; ++i) {
        minHeap.push(new Node(s[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();
        Node* top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    return minHeap.top();
}

// Prints the codes
void printHuffmanCodes(map<char, string> &huffmanCode) {
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

// Driver program to test the above functions
int main() {
    string s;
    cout << "Enter characters: ";
    cin >> s;

    int n = s.length();
    int freq[n];

    cout << "Enter frequencies for each character: ";
    for (int i = 0; i < n; ++i) {
        cin >> freq[i];
    }

    Node* root = buildHuffmanTree(s, freq, n);

    map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    printHuffmanCodes(huffmanCode);

    return 0;
}
