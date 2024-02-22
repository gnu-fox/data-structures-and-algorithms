#include <iostream>

enum class Kind {Forward};
template<typename T, Kind...> class Node;


template<typename T>
struct Node<T, Kind::Forward> {
    Node<T, Kind::Forward>* next;    
    T value;
};

enum class Sentinel {True, False};
template<typename T, Kind, Sentinel> class List;

template<typename T>
void clean(Node<T, Kind::Forward>* root) {
    Node<T, Kind::Forward>* current = root;
    while (current) {
        Node<T, Kind::Forward>* temporary = current;
        current = current -> next;
        std::cout << "delete temporary: " << temporary -> value << "\n";
        delete temporary;
    }
}

template <typename T>
class List<T, Kind::Forward, Sentinel::True> {
    public:
    using node_type = Node<T, Kind::Forward>;

    List() {sentinel_ = new node_type{nullptr}}
    ~List() {clean(sentinel_);}

    private:
    node_type* sentinel_;
};


int main() {
    Node<float, Kind::Forward>* node4 = new Node<float, Kind::Forward>{nullptr, 4};
    Node<float, Kind::Forward>* node3 = new Node<float, Kind::Forward>{node4, 3};
    Node<float, Kind::Forward>* node2 = new Node<float, Kind::Forward>{node3, 2};
    Node<float, Kind::Forward>* sentinel = new Node<float, Kind::Forward>{node2};
    clean(sentinel);   
}