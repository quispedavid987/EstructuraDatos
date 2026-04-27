#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include "types.h"
#include <string>
using namespace std;

// Defining class as a template
template <typename T>
class Vector
{
private:
    T *m_data;
    // WARNING: size_t is predefined in cstddef
    size_t  m_size;
    size_t  m_capacity;

private:
    void resize();
public:
    // Constructor tih initial parameter
    Vector(size_t capacity = 10);
    virtual ~Vector(); // Destructor

    // Metodos
    void push_back(T value);
    T get(size_t index);
    size_t size();
    string ToString();

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
void Vector<T>::push_back(T value)
{
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
    for (int i = 0; i < m_size; i++)
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
    string result = "[";
    for(size_t i=0; i < m_size-1; i++)
        result += to_string(m_data[i]) + ",";
    if (m_size > 0)
        result += to_string(m_data[m_size - 1]);
    result += "]";
    return result;
}


void DemoVector();

#endif