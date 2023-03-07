#include "vector.hpp"

namespace hlp2
{

    vector::vector() : sz{ 0 }, space{ 0 }, allocs{ 0 }, data{ new value_type[space]{ } }
    {

    }

    vector::vector(size_type n) :sz{ n }, space{ n  }, allocs{ 1 }, data{ new value_type[space]{} }
    {

    }

    vector::vector(std::initializer_list<int> rhs) : sz{ rhs.size() }, space{ sz }, allocs{ 1 }, data{ nullptr }
    {
        delete[] data;
        data = new value_type[space]{};
        size_type i = 0;
        for (int const& elem : rhs) {
            data[i] = elem;
            ++i;
        }
    }

    vector::vector(vector const& rhs) : sz{ rhs.sz }, space{ sz }, allocs{1 }, data{ nullptr }
    {

        if (rhs.data != nullptr) {
            delete[] data;
            data = new value_type[space]{};
            for (size_type i = 0; i < sz; ++i) {
                data[i] = rhs.data[i];
            }
        }
    }

    vector::~vector() {
        delete[] data;
    }

    vector& vector::operator=(vector const& rhs)
    {
         if (&rhs == this) {
            return *this;
        }
        delete[] data;
        this->sz = rhs.sz;
        this->space = rhs.space;
        this->allocs = rhs.allocs;
        
        data = new value_type[space]{};

        for (size_type i = 0; i < sz; i++)
        {
            data[i] = rhs.data[i];
        }

        return *this;
    }

    vector& vector::operator=(std::initializer_list<int> rhs)
    {
       delete[] data;
        this->sz = rhs.size();
        this->space = sz;
        this->allocs = 1;
        data = new value_type[space]{};

        size_type i = 0;
        for (value_type const& elem : rhs) {
            data[i] = elem;
            ++i;
        }

        return *this;
    }

    vector::reference vector::operator[](size_type index)
    {
        return data[index];
    }

    vector::const_reference vector::operator[](size_type index) const
    {
        return data[index];
    }


    void vector::push_back(value_type value)
    {
        if ( this->space == 0) 
        {
            reserve(1);
            
        }
        else if(this->sz == this->space)
        {
            reserve( 2* (this->space));
        }
        data[this->sz] = value;
        ++this->sz;
    }

   void vector::reserve(size_type newsize)
    {
    
    if (newsize <= this->space) {
        return;
    }

     pointer newdata = new value_type[newsize]{};
    for (size_type i = 0; i < this->sz; ++i) {
        newdata[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newdata;
    this->space = newsize;
    ++this->allocs;
    }

    void vector::resize(size_type newsize)
    {
    if (newsize == this->sz) {
        return; // no change needed
    } else if (newsize < this->sz) {
        this->sz = newsize;
        return; // no need to reallocate memory
    } else { // newsize > this->sz
        if (newsize > this->space) { // need to reallocate memory
            reserve(newsize);
        }
        for (size_type i = this->sz; i < newsize; ++i) {
            data[i] = value_type{}; // value-initialize new elements
        }
        this->sz = newsize;
    }
    }


    bool vector::empty() const
    {
        return this->sz == 0 ? true : false;
    }

    vector::size_type vector::size() const
    {
        return this->sz;
    }

    vector::size_type vector::capacity() const
    {
        return this->space;
    }

    vector::size_type vector::allocations() const
    {
        return this->allocs;
    }

    vector::pointer vector::begin()
    {
        return this->data;
    }

    vector::pointer vector::end()
    {
        return this->data + this->sz;
    }

    vector::const_pointer vector::begin() const
    {
        return this->data;
    }

    vector::const_pointer vector::end() const
    {
        return this->data + this->sz;
    }
    vector::const_pointer vector::cbegin() const
    {
        return this->data;
    }

    vector::const_pointer vector::cend() const
    {
        return this->data + this->sz;
    }
}