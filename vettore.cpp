#include "vettore.h"
#include <math.h>
#include <iostream>
typedef unsigned int u_int;

/*
template <class T>
Vettore<T>::Iteratore::Iteratore(T* p, u_int s, u_int c): size(s), cap(c),past_the_end(false) {
    T* arr = new T[c];
    for(int i=0; i<size; i++){
        arr[i]=p[i];
    }
    punt=arr;
}

template <class T>
typename Vettore<T>::Iteratore Vettore<T>::Iteratore::clone(const Iteratore& it){
    return new Iteratore(it.punt, it.size, it.cap);
}

template<class T>
Vettore<T>::Iteratore::Iteratore(Iteratore& it,bool pte=false):past_the_end(pte){
    this=clone(it);
}
template <class T>
Vettore<T>::Iteratore::~Iteratore(){
    delete punt;
}

template <class T>
Vettore<T>::Vettore(): v_size(0),capacity(0) {
    info = nullptr;
}

template <class T>
Vettore<T>::Vettore(u_int n, T& t):
    info( n == 0 ? nullptr : new T[n]), v_size(n), capacity(n){

    for(int i = 0; i < v_size; i++)info[i]=t;
}

/*
 * template <class T>
 * Vettore<T>::Vettore(Iteratore& i);


template <class T>
u_int Vettore<T>::size()const{return v_size;}

template <class T>
typename Vettore<T>::Iteratore& Vettore<T>::end() const{return new typename Vettore<T>::Iteratore(info[v_size()], true);}

template <class T>
Vettore<T>::Iteratore& begin() const{
    Vettore<T>::Iteratore it.punt = info;
    return it;
}

template <class T>
void add(Iteratore& t);


*/

//              CONSTRUCTOR ITERATORE
template <class T>
Vettore<T>::Iteratore::Iteratore(Vettore<T>* v, u_int ind=0): punt(v), index(ind){}

//Iteratore(T* p, u_int s, u_int c);

template <class T>
Vettore<T>::Iteratore Vettore<T>::Iteratore::clone(){
    return new Vettore<T>::Iteratore(this);
}

template <class T>
Vettore<T>::Iteratore::Iteratore (const Iteratore& it): punt(it.punt), index(it.index) {}


//overloading operatori

// operator iteratore
template <class T>
typename Vettore<T>::Iteratore& Vettore<T>::Iteratore::operator++(){
      if(punt!= nullptr) {
        if(!past_the_end) {
            if(index++ != punt->Size()) index++;
            else {index++ ; past_the_end = true;}
        }
      }
      return *this;
}

// operator iteratore
template <class T>
typename Vettore<T>::Iteratore& Vettore<T>::Iteratore::operator--(){
      if(punt!= nullptr) {
        if(!past_the_end) {
            if(index-- != 0) index--;
            else index=(*punt).Size();
        }
        else{
            index--;
            past_the_end=false;
        }
      }
      return *this;
}

// operator iteratore

template <class T>
T& Vettore<T>::Iteratore::operator*() const{
    return (punt*)[index];
}

// operator iteratore
template <class T>
T& Vettore<T>::Iteratore::operator->() const {
    return past_the_end ? new T() : (punt*)[index];
}

// operator iteratore
template <class T>
T& Vettore<T>::Iteratore::operator[](u_int ind) const {
    return (punt*)[ind];
}

// operator iteratore
template <class T>
bool Vettore<T>::Iteratore::operator!=(const Iteratore& it) const{
    return this!=it;
}

// operator iteratore
template <class T>
bool Vettore<T>::Iteratore::operator==(const Iteratore& it) const{
    return this==it;
}



//      METODI VETTORE


// CONSTRUCTOR Vettore
// --------------------------------> RICONTROLLARE <-------------------------------
template <class T>
Vettore<T>::Vettore( typename Vettore<T>::Iteratore first, typename  Vettore<T>::Iteratore second) { //non passati per riferimento costante perchè dobiamo fare ++ allinterno della funzione
    
    if(first && second){
        if( first == second ) push_back(first->info);
        else{
            while(first != second){
                push_back(first->info);
                first++;
            }
        }
    }
    
    
}

// CONSTRUCTOR Vettore
template <class T>
Vettore<T>::Vettore(Vettore& vec){

}

template <class T>
Vettore<T>::Vettore():info(nullptr),size(0), capacity(0){}

template <class T>
Vettore<T>::Vettore(T& t):Vettore(1,&t) {}

template <class T>
Vettore<T>::Vettore(u_int n, T& t):Vettore(){
    for(int i = 1; i < n; i++)push_back(&t);
}

template <class T>
Vettore<T>::Iteratore& Vettore<T>::begin() const{
    return new Iteratore(this*);

}

template <class T>
Vettore<T>::Iteratore& Vettore<T>::end()const{
    return new Iteratore(this*, size);
}


// Vettore METHOD
template <class T>
u_int Vettore<T>::Size() const{
    return size;
}

template <class T>
void Vettore<T>::push_back(const T& val){
    if(info){
        if(size == capacity){
            T* aux  = info;
            delete info;
            info = new T[capacity*2];
            capacity *= 2;
            info = aux;
            info[size]=T;
            size++;
        }else{
            info + size = val; 
            size++;
        }
    }else{
        info = new T(val);
        size++;
        capacity++;
    }
    
}

template <class T>
void Vettore<T>::insert(Iteratore& it, T& val){

}



template <class T>
T& Vettore<T>::remove(T& value){

}

template <class T>
T& Vettore<T>::pop_back(){
    
    T* ret = info + (size-1);
    size--; //perchè tolgo un valore
    delete info + (size);

    return ret;

}

template <class T>
bool Vettore<T>::empty(){ //true se il vettore è vuoto
    if( size == 0 ) return true;
}

template <class T>
typename Vettore<T>::Vettore& merge(Vettore<T>& vec){
    T* aux= new T[size+vec.size];
    for(int i = 0; i< size; i++) aux[i]=punt[i];
    for(i=0; i<vec.size; i++) aux[size+i]=vec.punt[i];
    delete [] punt;
    punt=aux;
    return new Vettore(aux); //ha costruito sto aux, lo assegna ad un vettore, che ritorna
}

template <class T>
bool Vettore<T>::operator==(Vettore& vec){
    if(size != vec.Size())return false;
    bool control = true;
    for( auto cont = begin(); cont != end() && control; cont++ ){
        if( cont->info != vec->info ) control = false;
    }
    return control;
}

template <class T>
T& Vettore<T>::remove(Iteratore& iter){
    Vettore<T>::Iteratore it = begin();
    Vettore<T> aux();
    while(it != iter) it++;
    
    Vettore<T>::Iteratore aux=it++;
    size--; //perchè tolgo un valore
    return it->info; //ritorno quello che ho tolto
}

template <class T>
std::ostream& operator<<(std::ostream& os,const Vettore<T>& vec);