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
    Node* current = root;
    while(current) {
        prior = current;
        current = current -> next;
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

int main() {
    Node* node5 = new Node{nullptr, 5};
    Node* node4 = new Node{node5, 4};
    Node* node3 = new Node{node4, 3};
    Node* node2 = new Node{node3, 2};
    Node* node1 = new Node{node2, 1};
    Node* root = new Node{node1,0};

    insert(root, new Node{nullptr,33}, 1);
    print(root);
    clean(root);
}