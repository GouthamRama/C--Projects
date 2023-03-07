 /*!************************************************************************
\file ft.hpp
\author Ramalingam Gouthaman
\DP email: gouthaman.r@digipen.edu
\Course: CS1171
\par Lab #07
\date 26-02-2023
\brief
This lab is to implement function templates.

***************************************************************************/
 // make sure to add file-level documentation here!!!

//-------------------------------------------------------------------------
#ifndef FT_H
#define FT_H
//-------------------------------------------------------------------------
#include <iostream>
// Do not add any other header files. Otherwise, your submission
// will not compile!!!

namespace hlp2 {
// DECLARE (not define!!!) and DOCUMENT in ALPHABETIC ORDER the function
// templates you'll be defining. There are *13* function templates to be
// declared and defined.
  
// I'm providing the declaration and documentation for swap here:
/***************************************************************************/
/*!
\brief
 Swaps two objects. There is no return value but the two objects are
 swapped in place.

\param lhs
  Reference to the first object to swap.

\param rhs
 Reference to the second object to swap.
*/
/**************************************************************************/
template <typename T> void swap(T &lhs, T &rhs);

/***************************************************************************/
/*!
\brief
Displays the elements inside the object

\param begin
 beginning of the range.

\param end
 ending of the range
*/
/**************************************************************************/  
template <typename Iter> void display(Iter begin, Iter end);

/***************************************************************************/
/*!
\brief
swap the ranges

\param first1
 beginning of the range.

\param last1
 ending of the range

 \param first2
 beginning of the second range
*/
/**************************************************************************/ 
template<typename ForwardIt1, typename ForwardIt2> void swap_ranges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2);

/***************************************************************************/
/*!
\brief
remove value in the ranges

\param first
 beginning of the range.

\param last
 ending of the range

 \param value
value to remove
*/
/**************************************************************************/ 
template<typename Iterator, typename T> Iterator remove(Iterator first, Iterator last, const T& value) ;

/***************************************************************************/
/*!
\brief
counts the specific elements inside the object

\param first
 beginning of the range.

\param last
 ending of the range

 \param value
value to  count
*/
/**************************************************************************/ 
template<typename InputIt, typename T> typename std::iterator_traits<InputIt>::difference_type count(InputIt first, InputIt last, const T& value);

/***************************************************************************/
/*!
\brief
\brief
finds the specific elements inside the object

\param first
 beginning of the range.

\param last
 ending of the range

 \param value
value to find
*/
/**************************************************************************/ 
template<typename InputIt, typename T> InputIt find(InputIt first, InputIt last, const T& value);

/***************************************************************************/
/*!
\brief
copy the specific elements inside the object

\param first
 beginning of the range.

\param last
 ending of the range

 \param value
value to copy
*/
/**************************************************************************/ 
template<typename InputIt, typename OutputIt> OutputIt copy(InputIt first, InputIt last, OutputIt result);

/***************************************************************************/
/*!
\brief
\brief
fills the specific elements inside the object

\param first1
 beginning of the range.

\param last
 ending of the range

 \param value
value to fill
*/
/**************************************************************************/ 
template<typename Iterator, typename T>
void fill(Iterator first, Iterator last, const T& value);

/***************************************************************************/
/*!
\brief
Replaces the elements inside the object

\param first
 Reference to the beginning of the range to search.

\param last
 Reference to the endinging of the range to search.

 \param old_value
 Reference to the value.
 \param new_value
 Reference to the new value.
*/
/**************************************************************************/ 
template<class Iterator, class T>
void replace(Iterator first, Iterator last, const T& old_value, const T& new_value) ;

/***************************************************************************/
/*!
\brief
Minimum elements inside the object

\param first
  Reference to the beginning of the range to search.

\param last
 Reference to the ending of the range to search.
*/
/**************************************************************************/ 
template<typename Iterator>
Iterator min_element(Iterator first, Iterator last) ;

/***************************************************************************/
/*!
\brief
Maximum elements inside the object

\param first
  Reference to the beginning of the range to search.

\param last
 Reference to the ending of the range to search.
*/
/**************************************************************************/ 
template<typename Iterator>
Iterator max_element(Iterator first, Iterator last);

/***************************************************************************/
/*!
\brief
check if the ranges are equal

\param first1
 beginning of the range.

\param last1
 ending of the range

 \param first2
 beginning of the second range
*/
/**************************************************************************/ 
template <typename ForwardIt1, typename ForwardIt2>
bool equal(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2) ;

/***************************************************************************/
/*!
\brief
sum of the elements inside the object


\param first1
 beginning of the range.

\param last
 ending of the range


*/
/**************************************************************************/ 
template<typename InputIt>
typename std::iterator_traits<InputIt>::value_type sum(InputIt first, InputIt last) ;
// Provide DEFINITIONS for each function template declared above ...                                                      
template <typename T>
void swap(T& lhs, T& rhs) 
{
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

template <typename Iter>
void display(Iter begin, Iter end)
{
    if (begin == end) 
    {
std::cout << "\n" ;
        return;
   }
    
    std::cout << *begin;
    ++begin;
    
    while (begin != end) 
    {
        std::cout << ", " << *begin;
        ++begin;
    }

    std::cout << "\n" ;
}

template<typename ForwardIt1, typename ForwardIt2>
void swap_ranges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2) 
{
    for (; first1 != last1; ++first1, ++first2)
     {
        std::iter_swap(first1, first2);
    }
}


template<typename Iterator, typename T>
Iterator remove(Iterator first, Iterator last, const T& value) 
{
    for (; first != last; ++first) 
    {
        if (*first == value)
        {
            for (Iterator i = first; ++i != last;)
            {
                if (!(*i == value))
                {
                    *first++ = std::move(*i);
                }
            }
            break;
        }
    }
    return first;
}


template<typename InputIt, typename T>
typename std::iterator_traits<InputIt>::difference_type count(InputIt first, InputIt last, const T& value) 
{
    typename std::iterator_traits<InputIt>::difference_type count = 0;
    for (; first != last; ++first)
     {
        if (*first == value) 
        {
            ++count;
        }
    }
    return count;
}

template<typename InputIt, typename T>
InputIt find(InputIt first, InputIt last, const T& value) 
{
    for (; first != last; ++first) 
    {
        if (*first == value)
         {
            return first;
        }
    }
    return last;
}

template<typename InputIt, typename OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt result) 
{
    while (first != last) 
    {
        *result = *first;
        ++result;
        ++first;
    }
    return result;
}

template<typename Iterator, typename T>
void fill(Iterator first, Iterator last, const T& value)
 {
    for (auto it = first; it != last; ++it) 
    {
        *it = value;
    }
}

template<class Iterator, class T>
void replace(Iterator first, Iterator last, const T& old_value, const T& new_value) 
{
    for (auto it = first; it != last; ++it) 
    {
        if (*it == old_value) 
        {
            *it = new_value;
        }
    }
}

template<typename Iterator>
Iterator min_element(Iterator first, Iterator last) 
{
    if (first == last) 
    {
        return last;
    }
    Iterator smallest = first;
    ++first;
    while (first != last) 
    {
        if (*first < *smallest) 
        {
            smallest = first;
        }
        ++first;
    }
    return smallest;
}

template<typename Iterator>
Iterator max_element(Iterator first, Iterator last) {
   int pos=0;
    int maxpos=0;
Iterator temp= first;

while(first != last)
{
if( *(temp+maxpos)< *first)
maxpos=pos;
++pos;
++first;
   
}
 return temp+maxpos;
}


template <typename ForwardIt1, typename ForwardIt2>
bool equal(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2) 
{
    for (; first1 != last1; ++first1, ++first2) 
    {
        if (*first1 != *first2) 
        {
            return false;
        }
    }
    return true;
}

template<typename InputIt>
typename std::iterator_traits<InputIt>::value_type sum(InputIt first, InputIt last) 
{
    typename std::iterator_traits<InputIt>::value_type result = typename std::iterator_traits<InputIt>::value_type();
    while (first != last) 
    {
        result += *first;
        ++first;
    }
    return result;
}

}
#endif
//-------------------------------------------------------------------------
