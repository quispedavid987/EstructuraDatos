#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <sstream>
#include "types.h"
#include <string>
using namespace std;

// Defining class as a template
template <typename Container>
class vector_foward_iterator{
    using Node     = typename Container::Node;
    using Iterator = vector_foward_iterator<Container>;

    Container *m_pContainer = nullptr;
    Node      *m_pNode      = nullptr;

public:
    vector_foward_iterator(Container *pContainer, Node *pNode):
    m_pContainer(pContainer), m_pNode(pNode) {}

    bool operator!=(const Iterator& other) const {return m_pNode != other.m_pNode;}
    Node& operator*() const {return *m_pNode;}
    Node* operator->() const { return m_pNode;}

    Iterator& operator++() {++m_pNode; return *this;}
};

template <typename T>
struct  VectorNode{
    T   m_data;
    Ref m_ref;
    VectorNode() : m_data(T()), m_ref(Ref()){}
    string ToString(){
        ostringstream oss;
        oss << "(" << m_data << "," << m_ref << ")";
        return oss.str();
    }
    T   GetData() const { return m_data;}
    Ref GetRef() const { return m_ref;}
};



template <typename T>
class Vector
{
private:
    T       *m_data;
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
    void push_back(T value); //Insert element at the tail
    T get(size_t index);     //Get an element by index
    size_t size();           //Get the size of the vector
    string ToString();       //Print the vector class

};

// Defining constructor as template
template <typename T>
Vector<T>::Vector(size_t capacity)
{
    m_data     = nullptr;
    m_size     = 0;
    m_capacity = capacity;
    m_data     = new T[m_capacity]; // Asigning memory
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

template <typename T>
void Vector<T>::push_back(T value){
    if (m_size == m_capacity)
        resize();

    m_data[m_size] = value;
    m_size++;
}

template <typename T>
void Vector<T>::resize()
{
    // New capacity based on old capacity
    m_capacity = m_capacity < 10 ? 10 : m_capacity * 2;
    // New block of memory called newData
    // to storage the new vector
    T *newData = new T[m_capacity];
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
T Vector<T>::get(size_t index) {return m_data[index];}

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