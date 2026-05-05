#include <iostream>
#include <fstream>

#include "vector.h"

using namespace std;

// Defining demo


void DemoVector()
{
    // Defining with a special type in template
    Vector<TI> v1;
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(19);
    v1.push_back(1);

    cout << v1.ToString() << endl;
    cout << "Size of vector: " << v1.size() << endl;
    // Printing values
    //for(auto i = 0; i < v1.size(); ++i)
    //    cout << v1.get(i) << " ";
    //cout << endl;
    //cout << "Size of vector: " << v1.size() << endl;

    Vector<TD> v2;
    v2.push_back(1.5);
    v2.push_back(2.6);
    v2.push_back(2.8);
    v2.push_back(3.9);
    v2.push_back(4.2);
    v2.push_back(1.6);
    v2.push_back(2.1);
    cout << v2.ToString() << endl;
    cout << "Size of vector: " << v2.size() << endl;


    
    Vector<TS> v3;
    v3.push_back("Hello");
    v3.push_back("World");
    v3.push_back("Maestria");

    cout << v3.ToString() << endl;
    cout << "Size of vector: " << v3.size() << endl;
    
    cout << "===== Implementando cout a los vectores =====" << endl;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;

    cout << "=== Exportando en un outfilestream.txt" << endl;
    ofstream ofs("output.txt");
    ofs << v3;


}