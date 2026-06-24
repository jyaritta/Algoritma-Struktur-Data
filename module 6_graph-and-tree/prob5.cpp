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

void Preorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode, bool& isFirst) {
    if (node == nilNode || node->isNil) return;
    
    if (!isFirst) cout << " ";
    cout << node->key; 
    isFirst = false;
    
    Preorder(node->left, nilNode, isFirst);
    Preorder(node->right, nilNode, isFirst);
}

void Inorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode, bool& isFirst) {
    if (node == nilNode || node->isNil) return;
    
    Inorder(node->left, nilNode, isFirst);
    
    if (!isFirst) cout << " ";
    cout << node->key;
    isFirst = false;
    
    Inorder(node->right, nilNode, isFirst);
}

void Postorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode, bool& isFirst) {
    if (node == nilNode || node->isNil) return;
    
    Postorder(node->left, nilNode, isFirst);
    Postorder(node->right, nilNode, isFirst);
    
    if (!isFirst) cout << " ";
    cout << node->key;
    isFirst = false;
}

int main() {
    int n;
    cin >> n;

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
        cout << "Tree kosong\n";
        return 0; 
    }
    
    for (int i = 0; i < q; i++) {
        char query[20];
        cin >> query;

        if (isMatch(query, "PREORDER") || isMatch(query, "ALL")) {
            cout << "[Preorder] : ";
            bool isFirst = true;
            Preorder(rbt.root(), rbt.nil(), isFirst);
            cout << "\n";
        }
        if (isMatch(query, "INORDER") || isMatch(query, "ALL")) {
            cout << "[Inorder] : ";
            bool isFirst = true;
            Inorder(rbt.root(), rbt.nil(), isFirst);
            cout << "\n";
        }
        if (isMatch(query, "POSTORDER") || isMatch(query, "ALL")) {
            cout << "[Postorder]: ";
            bool isFirst = true;
            Postorder(rbt.root(), rbt.nil(), isFirst);
            cout << "\n";
        }
    }

    return 0;
}