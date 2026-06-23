#include <iostream>
#include "RedBlackTree.h"

using namespace std;

bool isMatch(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}

void cetakPreorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode, bool& pertama) {
    if (node == nilNode || node->isNil) return;
    
    if (!pertama) cout << " ";
    cout << node->key; 
    pertama = false;
    
    cetakPreorder(node->left, nilNode, pertama);
    cetakPreorder(node->right, nilNode, pertama);
}

void cetakInorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode, bool& pertama) {
    if (node == nilNode || node->isNil) return;
    
    cetakInorder(node->left, nilNode, pertama);
    
    if (!pertama) cout << " ";
    cout << node->key;
    pertama = false;
    
    cetakInorder(node->right, nilNode, pertama);
}

void cetakPostorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode, bool& pertama) {
    if (node == nilNode || node->isNil) return;
    
    cetakPostorder(node->left, nilNode, pertama);
    cetakPostorder(node->right, nilNode, pertama);
    
    if (!pertama) cout << " ";
    cout << node->key;
    pertama = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;

    RedBlackTree rbt;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (!rbt.contains(val)) {
            rbt.insert(val);
        }
    }

    int q;
    cin >> q;

    if (rbt.empty()) {
        cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
        return 0; 
    }
    
    for (int i = 0; i < q; i++) {
        char query[20];
        cin >> query;

        if (isMatch(query, "PREORDER") || isMatch(query, "ALL")) {
            cout << "[Preorder] : ";
            bool pertama = true;
            cetakPreorder(rbt.root(), rbt.nil(), pertama);
            cout << "\n";
        }
        if (isMatch(query, "INORDER") || isMatch(query, "ALL")) {
            cout << "[Inorder] : ";
            bool pertama = true;
            cetakInorder(rbt.root(), rbt.nil(), pertama);
            cout << "\n";
        }
        if (isMatch(query, "POSTORDER") || isMatch(query, "ALL")) {
            cout << "[Postorder]: ";
            bool pertama = true;
            cetakPostorder(rbt.root(), rbt.nil(), pertama);
            cout << "\n";
        }
    }

    return 0;
}