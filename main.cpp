#include "vettore.h"
#include <iostream>
using namespace std;

//g++ -std=c++11 main.cpp
int main(int argc, char *argv[])
{   
    int a[7] = {0,1,2,3,4,5,6};
    Vettore<int> v(7,a);
    int c=11;
    auto it=v.begin()+3;
    auto it2(it);
    if(it==it2) cout << "sono uguali " << endl;
    else cout << "sono diversi " << endl;
    cout << v << endl;
    *it=0;
    it2++;
    if(it==it2) cout << "sono uguali " << endl;
    else cout << "sono diversi " << endl;
    *it2=88;
    cout << v << endl;
    cout << "iteratore it al terzo elemento "<<*it << endl;
    cout << "iteratore it2 al terzo elemento++ " << *it2 << endl;
    
    
    
}
