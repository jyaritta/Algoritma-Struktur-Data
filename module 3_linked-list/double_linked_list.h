#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

struct Node {
    char data;
    Node * next;
    Node * prev;
};

struct DoubleLinkedList {
    Node *head = nullptr, *tail = nullptr;
    int size = 0;

    void init();
    bool is_empty();
    
    void add_front(int val);
    void add_back(int val);
    void add_idx(int val, int idx);

    void delete_front();
    void delete_back();
    void delete_idx(int idx);

    void display();
    char get(int idx);
    void set(char val, int idx);

    void clear();
};


#endif