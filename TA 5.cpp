#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    Node* left;
    Node* right;
    Node(string k): key(k), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, string key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    return root;
}

bool searchNode(Node* root, string key) {
    if (!root) return false;
    if (root->key == key) return true;
    if (key < root->key) return searchNode(root->left, key);
    return searchNode(root->right, key);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih;
    string x;
    
    do {
        cout << "\n=== Daftar NPM ===\n";
        cout << "1. Masukan NPM\n2. Cari NPM\n3. Urutan NPM\n4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan NPM: "; 
            cin >> x;
            root = insertNode(root, x);
        } else if (pilih == 2) {
            cout << "Cari NPM: "; 
            cin >> x;
            cout << (searchNode(root, x) ? "Ditemukan\n" : "Tidak ditemukan\n");
        } else if (pilih == 3) { 
            inorder(root); 
            cout << "\n";
        }
    } while (pilih != 4);
    
    return 0;
}
