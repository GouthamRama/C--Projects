// File header documentation is required!!!
 /*!************************************************************************
\file listint.hpp
\author Ramalingam Gouthaman
\DP email: gouthaman.r@digipen.edu
\Course: CS1171
\par Lab #08
\date 05-03-2023
\brief
task is to apply C++'s class mechanism and the design principles from lectures to define and
implement a class ListInt that encapsulates a singly-linked list of int values and this file 
contains the declarations of member functions and friend fucntions as well as the class data
members. 

***************************************************************************/
// Provide include guards
// Don't include either of the following two headers: 
// You may need to include <cstddef> for size_t [which is the largest unsigned type from the C standard library]
#include <cstddef>
#include <initializer_list>
#include <iostream>


namespace hlp2 {

    class ListInt {
    public:
        // type aliases
        using size_type = size_t;
        using value_type = int;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;

        // three ctors:
        // default ctor
        ListInt();

        // copy ctor
        ListInt(ListInt const& other);

        // single-argument ctor that takes a std::initializer_list<value_type>
        ListInt(std::initializer_list<value_type> other);

        // destructor [that will call member function clear]
        ~ListInt();

        // copy assignment with another ListInt object
        ListInt& operator=(ListInt const& other);

        // copy assignment with std::initializer_list<value_type>
        ListInt& operator=(std::initializer_list<value_type> other);

        // both copy assignment overloads should use copy-and-swap idiom
        // operator += overload: concatenates with nodes of another ListInt container
        ListInt& operator+=(ListInt const& rhs);

        // operator += overload: concatenates with std::initializer_list<value_type>
        ListInt& operator+=(std::initializer_list<value_type> rhs);

        // operator [] overload: returns int data of node at position i in linked list
        int& operator[](int position);

        // operator [] overload: const overload of above function
        int const& operator[](int position) const;

        // push_front: adds value_type to front of the list
        void push_front(value_type value) ;

        // push_back: uses tail data member to efficiently add
        // value_type to back of the list
        void push_back(value_type value);

        // pop_front: returns the value of node at front of the list
        // and then destroys this front node
        value_type pop_front();

        // clear: erases all nodes in linked list
        void clear();

        // swap: exchanges contents of container with another ListInt container
        void swap(ListInt& other);

        // size: returns number of nodes
        size_type size() const ;

        // empty: returns true if linked list is empty; otherwise false
        bool empty() ;

        static int object_count() ;
        // Declare this as a friend function in class ListInt:
        friend std::ostream& operator<<(std::ostream& os, const ListInt& rhs);

        // three overloads of operator +:
        // add two ListInt objects
        friend ListInt operator+(ListInt const& lhs, ListInt const& rhs);

        // add ListInt and std::initializer_list<ListInt::value_tye>
        friend ListInt operator+(ListInt const & lhs, std::initializer_list<ListInt::value_type> const &rhs);

        // add std::initializer_list<ListInt::value_tye> and ListInt
        friend ListInt operator+(std::initializer_list<ListInt::value_type> lhs, ListInt const& rhs);

    private:
        // data encapsulated here ...
        struct Node {
            int data; // the actual data in the node
            Node* next; // pointer to the next Node
        };

        Node* head; // pointer to the head of the list
        Node* tail; // pointer to the last node
        size_type counter; // number of nodes on the list
        Node* new_node(value_type data) const;
        static int count;
    };

}
// All names from here on must be in namespace hlp2.
// Don't add any names that are private to the implementation source file listint.cpp in this file.
// Necessary declarations are described in the spec.

// Ensure every member function declared in class ListInt has a header!!!

