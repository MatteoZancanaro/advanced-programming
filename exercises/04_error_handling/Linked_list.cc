#include <iostream>
#include <string>
#include <math.h>
#include <memory>

enum class Insertion_method { push_back, push_front };

template <typename value_type>
class List {

    private:
 
        struct node {
            value_type data;
            std::unique_ptr<node> next;

            node(value_type value): data{value}, next{nullptr} {}
        };
        

        std::unique_ptr<node> head;
        unsigned int _size;
        
        void push_back(const value_type& v);

        void push_front(const value_type& v);
        
    public:
    
        List(): head{nullptr}, _size {0} {}

        void insert(const value_type& v, const Insertion_method m);

        //void print();

        //unsigned int size();

        //void reset();

        //void prune_node(const value_type; v);
};

int main() {

    List<double> list;
    
    double val {5.5};
    list.insert( val, Insertion_method::push_back );
    
    return 0;

}

template <typename value_type>
void List<value_type>::push_back(const value_type& v){
    
    std::unique_ptr<node> conductor{nullptr};
    
    //conductor = head; // The conductor points to the first node
    
    if (!conductor) { // If conductor is nullpointer it means there is nothing after the head
        while (!conductor->next) // While next is non zero means that I reach the pointer before the last one and so the last node
          conductor = conductor->next; // This means that conductor is pointing to the following node and so, in a certain way, it is the following node in the sense that by its use I can access the contents of the following node and then the pointer contained in the following node, which, in a certain way, is the the node after the following and so on.
    }      
    else{
        conductor->next = new node;  
        conductor = conductor->next;
        conductor->next = nullptr;
        conductor->data = v;
        head=conductor;
        _size = _size + 1;
        }
        
    conductor->next = new node;  // Creates a node at the end of the list by the use of the last pointer which was nullpointer before
    conductor = conductor->next; // Conductor is moved from the second to last to the last node just created
    conductor->next = nullptr;   // The pointer of the last node is changed to prevent it from going any further
    conductor->data = v;
    _size = _size + 1;
    
}

template <typename value_type>
void List<value_type>::push_front(const value_type& v){

    node new_head = new node;
    new_head->next = head;   
    new_head->data = v;
    head = &new_head;
    _size = _size + 1;

}

template <typename value_type>
void List<value_type>::insert(const value_type& v, const Insertion_method m){
    
    switch(m){
    
        case Insertion_method::push_back:
            push_back(v);
            break;
            
        case Insertion_method::push_front:
            push_front(v);      
            break;
    }
}





















