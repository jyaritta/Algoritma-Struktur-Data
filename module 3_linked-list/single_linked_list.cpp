#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>

void SingleLinkedList::init(){
    head = new Node;
    head->data = 0;
    head->next = head;
    tail = head;
    size = 0;
}

bool SingleLinkedList::is_empty(){
    return size == 0;
}

void SingleLinkedList::add_front(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = head->next;
    head->next = newNode;

    if(size == 0) {
        tail = newNode;
    }
    size++;
} 

void SingleLinkedList::add_back(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    
    tail->next = newNode;
    tail = newNode;
    size++;
}

void SingleLinkedList::add_idx(int val, int idx){
    if (idx < 0 || idx > size) throw std::out_of_range("Index lebih daripada batu");
    if (idx == 0) {
        add_front(val);
    } else if (idx == size) {
        add_back(val);
    } else {
        Node* prev = head; 
        for (int i = 0; i < idx; i++) {
            prev = prev->next;
        }
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }
}

void SingleLinkedList::delete_front(){
    if (is_empty()) return;
    
    Node* temp = head->next;
    head->next = temp->next;
    
    if (size == 1) {
        tail = head;
    }
    tail->next = head;
    delete temp;
    size--;
}

void SingleLinkedList::delete_back(){
    if (is_empty()) return;
    
    Node* prev = head;
    while (prev->next != tail) {
        prev = prev->next;
    }
    Node* temp = tail;
    prev->next = head;
    tail = prev;
    
    delete temp;
    size--;
}


void SingleLinkedList::delete_idx(int idx){
    if (idx < 0 || idx >= size) throw std::out_of_range("Index tidak valid");
        if (idx == 0) {
        delete_front();
    } else if (idx == size - 1) {
        delete_back();
    } 
    else {
        Node* prev = head;       
        for (int i = 0; i < idx; i++) {
            prev = prev->next;
        }
        
        Node* temp = prev->next;
        prev->next = temp->next;
        
        delete temp;
        size--;
    }
}

void SingleLinkedList::display(){
    if (is_empty()) {
        std::cout << "List kosong\n";
        return;
    }
    Node* curr = head->next;
    while (curr != head) {   
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}

int SingleLinkedList::get(int idx){
    if (idx < 0 || idx >= size) throw std::out_of_range("Index tidak valid");
    Node* curr = head->next;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    return curr->data;
}


void SingleLinkedList::set(int val, int idx){
    if (idx < 0 || idx >= size) throw std::out_of_range("Index kurang atau lebih dari jumlah batu");
    Node* curr = head->next; 
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    curr->data = val;
}

void SingleLinkedList::clear(){
    while (!is_empty())     {
        delete_front();
    }
}