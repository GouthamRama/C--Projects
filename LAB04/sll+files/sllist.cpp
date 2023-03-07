// Other than sllist.hpp, you really don't have to include any other files except when testing your code.
#include "sllist.hpp"
// Private functions must be declared and defined in an anonymous namespace!!!

namespace {
    // declaration in anonymous namespace of private function that creates
// a node on heap and initializes it with data and pointer to successor
hlp2::node* create_node(int value, hlp2::node *next = nullptr);
}

namespace hlp2{

struct node 
{
    int value; // data portion
    node *next; // pointer portion
};

struct sllist 
{
    node *head;
};

int data(node const *p)
 { return p->value; }

void data(node *p, int newval)
 { p->value = newval; }

node* next(node *p) 
{ return p->next; }

node const* next(node const *p) 
{ return p->next; }

// return initialized sllist object allocated on free store
sllist* construct() 
{
    return new sllist {nullptr};
}

// add element to front of linked list
void push_front(sllist *ptr_sll, int value) 
{
    ptr_sll->head = create_node(value, ptr_sll->head);
}   

// return number of elements in linked list container
size_t size(sllist const *ptr_sll) 
{
 size_t cnt {};
    for (node *head = ptr_sll->head; head; head = next(head)) 
    {
        ++cnt;
    }
    return cnt;
}

//To avoid memory leaks, the memory allocated to list elements and 
//list object sllist must be deallocated by making a call to destruct()
void destruct(sllist *ptr_sll)
{   
    node*tmp= nullptr;
    for (node *head = ptr_sll->head; head; ) 
    {   
        tmp =next(head);
        delete head;
        head = tmp;
    }

    ptr_sll->head=nullptr;
    delete ptr_sll;
    
}

//This function declared as bool empty(sllist const *ptr_sll); 
//returns true if the list pointed to by ptr_sll has no elements. 
bool empty(sllist const *ptr_sll)
{
  
    return ptr_sll->head == nullptr;;
}

//Function remove_first(sllist *ptr_sll, int val) deletes the 
//first element encountered with the same value as second parameter val .
void remove_first(sllist *ptr_sll, int value)
{
        node* head = ptr_sll->head; 
        node* tmp = nullptr ;

        while(head != nullptr && head->value != value)
        {
            tmp = head; 
            head = head->next;
        }
        
        if(head != nullptr)
        {
            if(tmp != nullptr)
            {
                tmp->next = head->next;
            }
            else 
            {
                ptr_sll -> head = head-> next;
            }
            delete head; 
            
        }
    
}

//Function push_back(sllist *ptr_sll, int val) adds a new element with value val to the
//end of the list container pointed to by ptr_sll , after its head last node
void push_back(sllist *ptr_sll, int value)
{
    node* new_node = create_node(value);
        if(ptr_sll->head == nullptr)
        {
            ptr_sll->head = new_node; 
        }
        else 
        {
            node* head = ptr_sll->head; 
            while(head->next != nullptr)
            {
                head = head->next; 
            }
            head->next = new_node; 
        }
}

//Both these overloads return a pointer to the first 
//element of the list or nullptr if the list has zero elements.
node* front(sllist *ptr_sll)
{
   
    return ptr_sll->head;
}

node const* front(sllist const *ptr_sll)
{
    
    return ptr_sll->head;
}

//Function find declared as node* find(sllist *ptr_sll, int value); returns a pointer to the
//first element in the list pointed to by parameter ptr_sll whose data is equal to the second
///parameter value
node* find(sllist const *ptr_sll, int value)
{
    node *head = ptr_sll->head;
     for (; head != nullptr ; head = next(head)) 
     {
        if (head->value == value)
        {
            return head;
        }
     }  
     return head;
}

//inserts a new element encapsulating data equal to parameter value into the list pointed to by
//parameter ptr_sll at an index specified by parameter position
void insert (sllist *ptr_sll, int value, size_t index)
{
     node* new_node = create_node(value);
        if(index == 0){
            new_node->next = ptr_sll->head; 
            ptr_sll->head = new_node; 
        }
        if(index > size(ptr_sll)){
            node* tmp = nullptr;

            node*head = ptr_sll->head; 

            while(head != nullptr)
            {
                tmp = head;
                head = head->next;
            }
            tmp->next = new_node; 
            return; 
        }
        
        node* previous = ptr_sll->head; 
            for(size_t i = 0; i < index-1; i++)
            {
                previous = previous->next; 
            }

            new_node->next = previous->next;

            previous->next = new_node;
        
}

}




namespace {
    // define this private function in anonymous namespace!!!
hlp2::node* create_node(int value, hlp2::node* next)
{
    return new hlp2::node {value, next};
}

}
// See the spec for structure and interface definitions!!!