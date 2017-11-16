#include <iostream>
#include <string>
#include <math.h>
#include <memory>

enum class Insertion_method { push_back, push_front };
enum class Prune_method { prune_back, prune_front };

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
        
        void prune_back();

        void prune_front();
        
    public:
    
        List(): head{nullptr}, _size {0} {}

        void insert(const value_type& v, const Insertion_method m);

        void print();

        unsigned int size();

        void reset();

        void prune_node(const Prune_method p);
};

int main() {

    std::cout << "----------FIRST LIST----------" << "\n";

    List<double> list;
    //list.print();
    //std::cout << list.size() << "\n";
    
    double val1 {5.5};
    list.insert( val1, Insertion_method::push_back );
    //list.print();
    
    double val2 {4};
    list.insert( val2, Insertion_method::push_back );
    //list.print();
    
    double val3 {10};
    list.insert( val3, Insertion_method::push_front );
    list.print();
    //std::cout << list.size() << "\n";
    
    std::cout << "----------RESET LIST----------" << "\n";
    
    list.reset();
    list.print();
    //list.prune_node(Prune_method::prune_front);
    //std::cout << list.size() << "\n";
    
    std::cout << "----------SECOND LIST----------" << "\n";
    
    double val21 {6};
    list.insert( val21, Insertion_method::push_back );
    
    double val22 {11};
    list.insert( val22, Insertion_method::push_back );
    
    double val23 {20};
    list.insert( val23, Insertion_method::push_front );
    list.print();
    //std::cout << list.size() << "\n";
    
    std::cout << "----------PRUNE LIST----------" << "\n";    
    
    list.prune_node(Prune_method::prune_front);
    list.print();
    std::cout << "size = " << list.size() << "\n";
    
    return 0;

}

template <typename value_type>
void List<value_type>::push_back(const value_type& v){
    
    node* conductor = head.get(); // The conductor points to the first node. The get() function returns a normal pointer pointing to what the unique one was already pointing
    
    if (conductor) { 
    
        //std::cout << "head already existing" << "\n";
    
        while (conductor->next) { // While next is non zero means that I reach the pointer before the last one and so the last node
            conductor = conductor->next.get(); // This means that conductor is pointing to the following node and so, in a certain way, it is the following node in the sense that by its use I can access the contents of the following node and then the pointer contained in the following node, which, in a certain way, is the the node after the following and so on.
            }
            
        conductor->next.reset(new node{v});  // Creates a node at the end of the list by the use of the last pointer which was nullpointer before
        _size = _size + 1;
    }      
    else{ // If conductor is nullpointer it means there is nothing after the head
    
        //std::cout << "create a new head" << "\n";
    
        head.reset(new node{v});  
        _size = _size + 1;
        }
}

template <typename value_type>
void List<value_type>::push_front(const value_type& v){

    std::unique_ptr<node> new_head{nullptr};
    new_head.reset(new node{v});
    new_head -> next = std::move(head);  
    head = std::move(new_head);
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

template <typename value_type>
void List<value_type>::print(){
    node* conductor = head.get();
    if (conductor) {
        while (conductor) {
            //std::cout << "entered" << "\n";
            std::cout << conductor->data << "\n";
            conductor = conductor->next.get();
        }
    }
    else {
        std::cout << "nullptr" << "\n";
    }
}

template <typename value_type>
unsigned int List<value_type>::size(){
    return _size;
}

template <typename value_type>
void List<value_type>::reset(){
    
    if (head) {
        node* conductor = head.get();
        
        while (conductor->next) {
            head = std::move(conductor->next);
            conductor->next = nullptr;
            conductor = head.get();
        }
        head = nullptr;
        _size = 0;
    }
    
    else {
        std::cout << "nothing to reset" << "\n";
    }    
}

template <typename value_type>
void List<value_type>::prune_front(){

    node* conductor = head.get();
    head = std::move(conductor->next);
    conductor->next = nullptr;
    _size = _size -1;

}

template <typename value_type>
void List<value_type>::prune_back(){
    node* conductor = head.get();
    node* prev_conductor;
    while (conductor->next) {
        prev_conductor = conductor;
        conductor = conductor->next.get();
    }
    prev_conductor->next = nullptr;
    _size = _size-1;

}

template <typename value_type>
void List<value_type>::prune_node(const Prune_method p){
    
    if (head==nullptr) {
    std::cout<<"Empty list.Nothing to prune."<<"\n";
    }
    
    else {
        switch(p){
        
            case Prune_method::prune_back:
                prune_back();
                break;
                
            case Prune_method::prune_front:
                prune_front();      
                break;
        } 
    }   
}





















