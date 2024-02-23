#include <iostream>

struct Node {
    Node* next;
    int value;
};

void clean(Node* root) {
    Node* current = root;
    while(current){
        Node *tmp = current;
        current = current->next;
        delete tmp;
    }    
}

void print(Node* root) {
    Node* current = root;
    while(current) {
        std::cout << current -> value << "-";
        current = current -> next;
    }
}

void transverse(Node*& root) {
    Node* pivot = nullptr;
    Node* prior = nullptr;
    while(root) {
        prior = root;
        root = root -> next;
        prior->next = pivot;
        pivot = prior;
    }
    root = pivot;
}

void insert(Node*& root, Node* node, int index) {
    Node* current = root;
    
    if(index == 0) {
        node->next = root;
        root = node;
    } 

    while(index > 1) {
        index--;
        current = current->next;
    }

    node->next = current->next;
    current->next = node;

}