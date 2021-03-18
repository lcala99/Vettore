#include "vettore.h"
#include <iostream>
using namespace std;

//g++ -std=c++11 main.cpp
int main(int argc, char *argv[])
{   
    int a[4] = {0,1,2,3};
    Vettore<int> v(4,a);
    v.push_back(5);
    cout << v << endl;
    int b=6;
    v.insert(b);
    cout << "ciao" << endl;
    auto i = new Vettore<int>::Iteratore(5);
    cout << "ho costruito un iteratore";
    //v.insert((v.begin())+1, b);
    
    v.remove(v.end()-1);
    cout << v << endl;


}
