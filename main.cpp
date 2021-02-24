#include "vettore.h"

int main(int argc, char *argv[])
{   
    double c = 8;
    Vettore<double> v(c);
    
    v.push_back(c);
    
    //Vettore<int> v1(2,c);
    return 0;
}
