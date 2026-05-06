#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <sstream>
#include <string>

#include "types.h"
#include "foreach.h"
#include "general_iterator.h"

using namespace std;

// Defining class as a template
template <typename Container>
class vector_foward_iterator : public general_iterator<Container, vector_foward_iterator<Container>>{
public:
    using MySelf   = vector_foward_iterator<Container>;
    using Parent   = general_iterator<Container, MySelf>;
    using Parent::Parent;
    MySelf operator++(){this->m_pNode++; return *this;}
};

template <typename Container>
class vector_backward_iterator : public general_iterator<Container, vector_backward_iterator<Container>>{
public:
    using MySelf   = vector_backward_iterator<Container>;
    using Parent   = general_iterator<Container, MySelf>;
    using Parent::Parent;
    MySelf operator++(){this->m_pNode--; return *this;}
};

template <typename T>
struct  VectorNode{
    T   m_data;
    Ref m_ref;
    VectorNode() : m_data(T()), m_ref(Ref()){}
    VectorNode(T data, Ref ref) : m_data(data), m_ref(ref) {}
    string ToString(){
        ostringstream oss;
        oss << "(" << m_data << "," << m_ref << ")";
        return oss.str();
    }
    T   GetData() const { return m_data;}
    Ref GetRef() const { return m_ref;}
    void operator++() {++m_data;}
    void operator+=(const T& value) {m_data += value;}
};

template <typename T>
ostream& operator<<(ostream& os, VectorNode<T>& vn){
    return os << vn.ToString();
}

template <typename T>
class Vector
{
public:
    using Node              = VectorNode<T>;
    using value_type        = T;
    using forward_iterator  = vector_foward_iterator<Vector<T>>;
    using backward_iterator = vector_backward_iterator<Vector<T>>;

private:
    Node   *m_data;
    // WARNING: size_t is predefined in cstddef
    size_t  m_size;
    size_t  m_capacity;

private:
    void resize();
public:
    // Constructor with initial parameters
    Vector(size_t capacity = 10);
    virtual ~Vector(); // Destructor

    // Metodos
    void push_back(T value, Ref ref); //Insert element at the tail
    T get(size_t index);     //Get an element by index
    size_t size();           //Get the size of the vector
    string ToString();       //Print the vector class

    forward_iterator begin() {return forward_iterator(this, m_data);}
    forward_iterator end() {return forward_iterator(this, m_data + m_size);}
    backward_iterator rbegin() {return backward_iterator(this, m_data + m_size - 1);}
    backward_iterator rend() {return backward_iterator(this, m_data - 1);}


    template <typename Func,typename... Args>
    void ForEach(Func func, Args &&... args){
        ::ForEach(begin(), end(), func, forward<Args>(args)...);
    }

    template <typename Func,typename... Args>
    void ReverseForEach(Func func, Args &&... args){
        ::ForEach(rbegin(), rend(), func, forward<Args>(args)...);
    }
};

// Defining constructor as template
template <typename T>
Vector<T>::Vector(size_t capacity)
{
    m_data     = nullptr;
    m_size     = 0;
    m_capacity = capacity;
    m_data     = new Node[m_capacity]; // Asigning memory
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

template <typename T>
void Vector<T>::push_back(T value, Ref ref){
    if (m_size == m_capacity)
        resize();
    m_data[m_size] = Node(value, ref);
    m_size++;
}

template <typename T>
void Vector<T>::resize()
{
    // New capacity based on old capacity
    m_capacity = m_capacity < 10 ? 10 : m_capacity * 2;
    // New block of memory called newData
    // to storage the new vector
    Node *newData = new Node[m_capacity];
    // Copy every each element of old vector
    // to new vector
    for (size_t i = 0; i < m_size; i++)
        newData[i] = m_data[i];
    // Delete old vector
    delete[] m_data;
    // Name the new vector as m_data
    m_data = newData;
    
}

template <typename T>
T Vector<T>::get(size_t index){
    if(index >= m_size)
        throw out_of_range("Index out of bounds");
    return m_data[index].GetData();
}

template <typename T>
size_t Vector<T>::size() {return m_size;}

template <typename T>
string Vector<T>::ToString()
{
    ostringstream oss;
    oss << "[";
    for(size_t i=0; i < m_size-1; i++)
        oss << m_data[i] << ",";
    if (m_size > 0)
        oss << m_data[m_size - 1];
    oss << "]";
    return oss.str();
}

template <typename T>
ostream& operator<<(ostream& os, Vector<T>& v){
    return os << v.ToString();
}


void DemoVector();

#endif