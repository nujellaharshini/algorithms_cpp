#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

/** huffman pseudo: 
    n = |C|
    Q = C
    for i = 1 to n - 1
        give a new node z
        z.left = x = extract-min(Q)
        z.right = y = extract-min(Q)
        z.freq = x.freq + y.freg
        insert(Q,z)
    return extract-min(Q)
**/
    
class Node {
public:
    char data;
    int freq;
    Node* left;
    Node* right;
    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

// compare for priority queue
class Check {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

Node* buildTree(vector<int>& a) {
    priority_queue<Node*, vector<Node*>, Check> pq;
    for (char i = 'A'; i <= 'F'; i++) {
        if (a[i - 'A'] > 0) {
            pq.push(new Node(i, a[i - 'A']));
        }
    }

    while (pq.size() > 1) {
        Node* x = pq.top(); pq.pop();
        Node* y = pq.top(); pq.pop();
        Node* newNode = new Node('$', x->freq + y->freq);
        newNode->left = x;
        newNode->right = y;
        pq.push(newNode);
    }
    return pq.top(); //root of the huffman
}

void assign(Node* root, string code, string huffmanCode[]) {
    if (root == nullptr){
        return;
    }
    if (root->data != '$') {
        huffmanCode[root->data - 'A'] = code;
    }
    assign(root->left, code + "0", huffmanCode);
    assign(root->right, code + "1", huffmanCode);
}

int main() {
    vector<int> num(6);
    for (int i = 0; i < 6; ++i) {
        cin >> num[i];
    }

    Node* root = buildTree(num);

    string huffmanCode[6];
    assign(root, "", huffmanCode);

    for (char i = 'A'; i <= 'F'; i++) {
        if (num[i - 'A'] > 0) {
            cout << i << ":" << huffmanCode[i - 'A'] << endl;
        }
    }
    return 0;
}


