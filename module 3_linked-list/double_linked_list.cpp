#include "double_linked_list.h"
#include <iostream>
#include <stdexcept>

void DoubleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {
    return size == 0;
}

void DoubleLinkedList::add_front(int val) {
    Node* newNode = new Node;
    newNode->data = val;

    if (is_empty()) {
        head = tail = newNode;
        newNode->next = head; 
        newNode->prev = tail;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
    size++;
}

void DoubleLinkedList::add_back(int val) {
    Node* newNode = new Node;
    newNode->data = val;

    if (is_empty()) {
        head = tail = newNode;
        newNode->next = head;
        newNode->prev = tail;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
    size++;
}

void DoubleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) throw std::out_of_range("Index tidak valid");
    if (idx == 0) {
        add_front(val);
    } else if (idx == size) {
        add_back(val);
    } else {
        Node* curr = head;
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
        
        Node* newNode = new Node;
        newNode->data = val;

        newNode->prev = curr->prev;
        newNode->next = curr;

        curr->prev->next = newNode;
        curr->prev = newNode;
        size++;
    }
}

void DoubleLinkedList::delete_front() {
    if (is_empty()) return;
    
    if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next; 
        head->prev = tail; 
        tail->next = head;
        delete temp;
    }
    size--;
}

void DoubleLinkedList::delete_back() {
    if (is_empty()) return;
    
    if (size == 1) {
        delete tail;
        head = tail = nullptr;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }
    size--;
}

void DoubleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Index tidak valid");
    if (idx == 0) {
        delete_front();
    } else if (idx == size - 1) {
        delete_back();
    } else {
        Node* curr = head;
        // Jalan ke target
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        
        delete curr;
        size--;
    }
}

void DoubleLinkedList::display() {
    if (is_empty()) {
        std::cout << "EMPTY\n";
        return;
    }
    Node* curr = head;
    do {
        std::cout << curr->data;
        curr = curr->next;
    } while (curr != head);
    std::cout << "\n";
}

char DoubleLinkedList::get(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Index tidak valid");
    Node* curr = head;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    return curr->data;
}

void DoubleLinkedList::set(char val, int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Index tidak valid");
    Node* curr = head;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    curr->data = val;
}

void DoubleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}