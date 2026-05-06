#include <iostream>
#include <fstream>

#include "vector.h"

using namespace std;

// Creating method for ForEach
template <typename T>
void Print(VectorNode<T> &value, ostream& os){
    os << value << ",";
}

template <typename T>
void AddOne(VectorNode<T> &node){
    ++node;
}


template <typename T>
void AddX(VectorNode<T> &node, T x){
    node += x;
}

// Defining demo
void DemoVector()
{
    // Defining with a special type in template
    Vector<TI> v1;
    v1.push_back(7, 14);
    v1.push_back(8, 12);
    v1.push_back(19, 12);
    v1.push_back(1, 15);
    cout << "=== Imprimiendo v1:" << endl;
    cout << v1.ToString() << endl;
    cout << "Size of vector: " << v1.size() << endl;
    cout << "=== Imprimiendo con el iterador:" << endl;
    cout << "[";
    for (auto it = v1.begin(); it != v1.end(); ++it){
        cout << *it << ",";
    }
    cout << "]" << endl;
    cout << "======================" << endl;

    cout << "==== Imprimiendo con ForEach" << endl;
    v1.ForEach(Print<TI>, cout);
    cout << endl;
    cout << "======================" << endl;

    cout << "==== Agregando AddOne" << endl;
    v1.ForEach(AddOne<TI>);
    v1.ForEach(Print<TI>, cout);
    cout << endl;
    cout << "======================" << endl;
    cout << "==== Agregando AddX (2)" << endl;
    v1.ForEach(AddX<TI>, 2);
    v1.ForEach(Print<TI>, cout);
    cout << endl;
    cout << "======================" << endl;
    cout << "==== Implementando Lambda" << endl;
    int a = 3;
    v1.ForEach([a](VectorNode<TI>& node){ node.GetDataRef() *= a;});
    v1.ForEach(Print<TI>, cout);
    cout << endl;
    cout << "======================" << endl;

    cout << v1.get(0) << endl;
    cout << "======================" << endl;
    

/*
    // Printing values
    //for(auto i = 0; i < v1.size(); ++i)
    //    cout << v1.get(i) << " ";
    //cout << endl;
    //cout << "Size of vector: " << v1.size() << endl;

    Vector<TD> v2;
    v2.push_back(1.5, 13);
    v2.push_back(2.6, 12);
    v2.push_back(2.8, 10);
    v2.push_back(3.9, 12);
    v2.push_back(4.2, 16);
    v2.push_back(1.6, 19);
    v2.push_back(2.1, 20);
    cout << v2.ToString() << endl;
    cout << "Size of vector: " << v2.size() << endl;


    
    Vector<TS> v3;
    v3.push_back("Hello", 1);
    v3.push_back("World", 2);
    v3.push_back("Maestria",3 );

    cout << v3.ToString() << endl;
    cout << "Size of vector: " << v3.size() << endl;
    
    cout << "===== Implementando cout a los vectores =====" << endl;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;

    cout << "=== Exportando en un outfilestream.txt" << endl;
    ofstream ofs("output.txt");
    ofs << v3;
*/

}