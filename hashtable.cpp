#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

class HashTable {
private:
    vector<Node*> table;
    int size;

    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int m) : size(m) {
        table.resize(size, nullptr);
    }

    void insert(int key) {
        int index = hash(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void search(int key) {
        int index = hash(key);
        Node* current = table[index];
        int pos = 0;
        while (current != nullptr) {
            if (current->key == key) {
                cout << key << ":FOUND_AT" << index << "," << pos << ";" << endl;
                return;
            }
            current = current->next;
            pos++;
        }
        cout << key << ":NOT_FOUND;" << endl;
    }

    void remove(int key) {
        int index = hash(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << key << ":DELETED;" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << key << ":DELETE_FAILED;" << endl;
    }

    void output() {
        for (int i = 0; i < size; ++i) {
            cout << i << ":";
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << "->";
                current = current->next;
            }
            cout << ";" << endl;
        }
    }
};

int main() {
    int hashSize;
    cin >> hashSize;

    HashTable hashTable(hashSize);

    char operation;
    int key;
    while (cin >> operation && operation != 'e') {
        switch(operation) {
            case 'i':
                cin >> key;
                hashTable.insert(key);
                break;
            case 's':
                cin >> key;
                hashTable.search(key);
                break;
            case 'd':
                cin >> key;
                hashTable.remove(key);
                break;
            case 'o':
                hashTable.output();
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }

    return 0;
}