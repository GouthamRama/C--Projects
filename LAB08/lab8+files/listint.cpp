// File header documentation is required!!!
 /*!************************************************************************
\file listint.cpp
\author Ramalingam Gouthaman
\DP email: gouthaman.r@digipen.edu
\Course: CS1171
\par Lab #08
\date 05-03-2023
\brief
task is to apply C++'s class mechanism and the design principles from lectures to define and
implement a class ListInt that encapsulates a singly-linked list of int values and this file 
contains the definitions of member functions and friend functions.

***************************************************************************/
// Other than listint.hpp, you really don't have to include any other files except when testing your code.
// When you're ready to submit, don't include either of the following two headers: 
#include "listint.hpp"
#include <iomanip>

// Private functions must be declared and defined in an anonymous namespace!!!
namespace hlp2 {

	int ListInt::count = 0;
	// three ctors:
	// 

	/// @brief default ctor
	ListInt::ListInt() : head{ nullptr }, tail{ nullptr }, counter{ 0 }
	{
		count++;
	}

	/// @brief copy constructor
    /// @param other the object to be copied
	ListInt::ListInt(ListInt const& other) : head{ nullptr }, tail{ nullptr }, counter{ 0}
	{
		
		for (size_type i = 0; i < other.size(); i++)
		{
			push_back(other[i]);
		}
		count++;
	}


	
	/// @brief single-argument ctor that takes a std::initializer_list<value_type>
    /// @param other the thing to be copied
	ListInt::ListInt(std::initializer_list<value_type> other) : head{ nullptr }, tail{ nullptr }, counter{ 0 }
	{
		for (int const& elem : other)
		{
			push_back(elem);
		}
		count++;
	}


	/// @brief  destructor [that will call member function clear]
	ListInt::~ListInt()
	{
		clear();
		count--;
	}

	// //  with another ListInt object
	/// @brief copy assignment
    /// @param rhs the object to be copied
	/// @return  reference to ListInt object
	ListInt& ListInt::operator=(const ListInt& rhs)
	{
    	if (this == &rhs) 
		{
        	return *this; 
    	}

	 clear();

		for (Node* node = rhs.head; node != nullptr; node = node->next)
		{
        	push_back(node->data);
    	}

    	return *this;
	}


	
	/// @brief copy assignment
    /// @param other the std::initializer_list<value_type> to be copied
	/// @return  reference to ListInt object
	ListInt& ListInt::operator=(std::initializer_list<value_type> other)
	{
	
    // Clear the current contents of the list
    clear();

		for (int const& elem : other)
		{
			push_back(elem);
		}

		return *this;
	}

	// both copy assignment overloads should use copy-and-swap idiom
	
	
	/// @brief operator += overload: concatenates with nodes of another ListInt container
    /// @param other the object to be copied
	/// @return  reference to ListInt object
	ListInt& ListInt::operator+=(ListInt const& rhs)
	{
		Node * _node = tail;

		for (size_type i = 0 ; i<rhs.counter;i++)
		{
			_node->next=new_node(rhs[i]);
			_node=_node->next;
			counter++;
		}

		return *this;
	}

	
	/// @brief operator += overload: concatenates with std::initializer_list<value_type>
    /// @param other the std::initializer_list<value_type> to be copied
	/// @return  reference to ListInt object
	ListInt& ListInt::operator+=(std::initializer_list<value_type> rhs)
	{
		for (int const& elem : rhs)
		{
			push_back(elem);
		}
		return *this;
	}

	
	/// @brief operator [] overload: returns int data of node at position i in linked list
    /// @param position
	/// @return  reference to int data
	int& ListInt::operator[](int position )
	{
		Node* current = head;
		for (int i = 0; i < position; i++) {
			current = current->next;
		}

		return current->data;
	}

	/// @brief operator [] const overload: returns int data of node at position i in linked list
    /// @param position
	/// @return  reference to int data
	int const& ListInt::operator[](int position) const
	{
		// if (position < 0 || position >= counter)
		// {
		// 	return;
		// }

		Node* current = head;
		for (int i = 0; i < position; i++)
		{
			current = current->next;
		}

		return current->data;
	}

	// 
	/// @brief push_front: adds value_type to front of the list
    /// @param value to add
	/// @return  
	void ListInt::push_front(value_type value) 
	{
		Node* newnode = new_node(value);
		if (head == nullptr)
		{
			head = newnode;
			tail = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
		counter++;
	}


	/// @brief  uses tail data member to efficiently add value_type to back of the list
    /// @param value to add
	/// @return  
	void ListInt::push_back(value_type value) 
	{
		Node* newnode = new_node(value);
		if (tail == nullptr)
		{
			
			head = newnode ;
			tail = newnode ;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}

		++counter;

	}



	/// @brief  returns the value of node at front of the list and then destroys this front node
    /// @param 
	/// @return int
	int ListInt::pop_front()
	{
		if (head == nullptr) {
			// list is empty
			return value_type();
		}
		value_type _data = head->data;
		Node* temp = head->next;
		delete head;
		head = temp;
		counter--;
		if (head == nullptr) {
			// list becomes empty after the first element popped
			tail = nullptr;
		}
		return _data;
	}

	/// @brief allocated new memory
    /// @param data
	/// @return Node pointer
	ListInt::Node* ListInt::new_node(value_type data) const
	{
		return new Node{ data, nullptr };
	}



	/// @brief  clear: erases all nodes in linked list
    /// @param 
	/// @return 
	void ListInt::clear()
	{
		Node* temp = nullptr;
		while(head != nullptr)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
		tail = nullptr;
		counter=0;
	}

	
	/// @brief  // swap: exchanges contents of container with another ListInt container
    /// @param other object to swap
	/// @return 
	void ListInt::swap( ListInt& other)
	{
	if (head==nullptr)
	{
	 Node* node1 = head;
     Node* node2 = other.head;
    for (size_type i = 0; i < other.size(); i++) 
		{
       
        (*node1).data = (*node2).data;
       
        node1 = (*node1).next;
        node2 = (*node2).next;
    	}
	} else 
	{	
		
		ListInt::Node* temp = head;
		head = other.head;
		other.head = temp;
		temp = tail;
		tail = other.tail;
		other.tail = temp;

		
		Node* node1 = head;
    	Node* node2 = other.head;
    	for (size_type i = 0; i < other.size(); i++) 
		{
       
        	(*node1).data = (*node2).data;
       
        	node1 = (*node1).next;
        	node2 = (*node2).next;
		}

	}
	}

	// size: 
	/// @brief  returns number of nodes
    /// @param 
	/// @return size_type number of nodes
	ListInt::size_type ListInt::size() const
	{
		return counter;
	}
	
	/// @brief // empty: returns true if linked list is empty; otherwise false
    /// @param 
	/// @return true or false
	bool ListInt::empty() 
	{
		return head == nullptr;
	}

	
	////////////////////////////////////////////////////////////////////////////////
	// Function: operator<<
	//  Purpose: Output the list into an ostream object
	//   Inputs: os - ostream object
	//           list - the List to output
	//  Outputs: Returns an ostream object.
	////////////////////////////////////////////////////////////////////////////////
	std::ostream& operator<<(std::ostream& os, const ListInt& rhs) {
		// Start at the first node
		ListInt::Node* pnode = rhs.head;

		// Until we reach the end of the list
		while (pnode != 0) {
			os << std::setw(4) << pnode->data; // print the data in this node
			pnode = pnode->next;               // move to the next node
		}

		os << std::endl; // extra newline for readability
		return os;
	}

	// three overloads of operator +:
	// 
	/// @brief  add two ListInt objects
    /// @param rhs listint object
	///@param lhs listint object
	/// @return listint object
	ListInt operator+(ListInt const& lhs, ListInt const& rhs)
	{
		ListInt result(lhs);
		result += rhs;
		return result;
	}

	
		/// @brief  add  std::initializer_list<ListInt::value_tye> and ListInt objects 
    /// @param lhs listint object
	///@param rhs std::initializer_list<ListInt::value_tye>
	/// @return listint object
	ListInt operator+(ListInt const & lhs, std::initializer_list<ListInt::value_type> const &rhs)
	{
		ListInt result(lhs);
	
		for (int const& elem : rhs)
		{
		
			result.push_back(elem);
			
		}
		return result;
	}
	
	/// @brief  add ListInt objects and std::initializer_list<ListInt::value_tye>
    ///@param lhs std::initializer_list<ListInt::value_tye>
	/// @param rhs listint object
	/// @return listint object
	ListInt operator+(std::initializer_list<ListInt::value_type> lhs, ListInt const& rhs)
	{
		ListInt result(lhs);
		result += rhs;
		return result;
	}

	
	/// @brief  number of objects created
    ///@param 
	/// @return int object count
	int ListInt::object_count()
	{
		return count;
	}

	
	

}

