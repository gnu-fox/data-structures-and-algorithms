#include <iostream>

template<typename T>
struct Node {
    using value_type = T;
    value_type value;
    Node* next;    
};


template<typename T>
class List {
    public:
    using value_type = T;
    using node_type = Node<value_type>

    List() {
        root_ = new node_type{}
    }

    ~List()

    private:
    node_type* root_;
};