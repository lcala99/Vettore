
#include <iostream>
#ifndef VETTORE_H
#define VETTORE_H

using namespace std;

typedef unsigned int u_int;

template <class T> class Vettore;

template <class T>
std::ostream& operator<<(std::ostream& os,const Vettore<T>& vec);

class Iteratore;

template<class T>
class Vettore{

    friend std::ostream& operator<< <T>(std::ostream& os,const Vettore<T>& vec);

    friend class Iteratore;

    private:
        T* info;
        u_int size;
        u_int capacity;

    public:
        class Iteratore{
            friend class Vettore<T>;
            private:
                const Vettore<T>* punt;
                u_int index;

            public:
                // iteratore CONSTUCTOR
                Iteratore(const Vettore<T>& v, u_int ind=0);
                // Iteratore(T* p, u_int s, u_int c);
                Iteratore clone() const;
                Iteratore(const Iteratore& it);
                //~Iteratore(); -----> potrebbe no nservire visto che utilizziamo un puntatore
                //                      quando cancelliamo iteratore non vogliamo cancellate anche il vettore
                //                      quindi ci basta cancellare il puntatore e non ciò a cui punta
                Iteratore(u_int ind);
                // overloading OPERATOR
                Iteratore& operator++();
                Iteratore& operator--();
                Iteratore operator+(u_int const ind) const;
                Iteratore operator-(u_int const ind) const;
                T& operator*() const;
                T& operator->()const;
                T& operator[](u_int ind)const;
                bool operator!=(const Iteratore& it) const;
                bool operator==(const Iteratore& it) const;
        };

        // vettore CONSTUCTOR
        Vettore();
        Vettore(T t);
        Vettore(u_int n, T t);
        Vettore(u_int n, T* t);
        Vettore( typename Vettore<T>::Iteratore first, typename  Vettore<T>::Iteratore second );
        Vettore(const Vettore& vec);

        // Vettore OPERATOR overloading
        T& operator[](u_int ind)const;
        bool operator==(Vettore& vec);

        // Vettore METHOD
        Iteratore begin() const;
        Iteratore end() const;
        u_int Size() const;
        void push_back(const T val);
        void insert(Iteratore it, T val);
        void insert(T& val);
        void remove(Iteratore& it); //rimuove l'elemento in posizione it
        void remove(T& value); //rimuove elemento con valore value
        T& pop_back(); //rimuove ultimo elemento
        bool empty(); //true se il vettore è vuoto
        Vettore& merge(Vettore& vec);

};

template <class T>
std::ostream& operator<<(std::ostream& os,const Vettore<T>& vec);


#endif



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
Vettore<T>::Iteratore::Iteratore(const Vettore<T>& v , u_int ind){
    punt = &v;
    index = ind;
    cout << "costruito con index = " << index << endl;
}

template <class T>
Vettore<T>::Iteratore::Iteratore(u_int ind){
    punt = nullptr;
    index = ind;
    cout << "creato iteratore con indice: " << index << endl;
}

//Iteratore(T* p, u_int s, u_int c);

template <class T>
typename Vettore<T>::Iteratore Vettore<T>::Iteratore::clone()const{
    return new Vettore<T>::Iteratore(this);
}

template <class T>
Vettore<T>::Iteratore::Iteratore (const Iteratore& it): punt(it.punt), index(it.index) {}


//overloading operatori

// operator iteratore
template <class T>
typename Vettore<T>::Iteratore& Vettore<T>::Iteratore::operator++(){
      if(punt != nullptr) {
        if(index < punt.Size()) {
            if(index++ != punt->Size()) index++;
            else {index++; }
        }
      }
      return *this;
}

// operator iteratore
template <class T>
typename Vettore<T>::Iteratore& Vettore<T>::Iteratore::operator--(){
      if(punt != nullptr) {
             index--;
      }else{ 
          index=(*punt).Size()--; 
      }
      return *this;
}

// operator iteratore

template <class T>
T& Vettore<T>::Iteratore::operator*() const{
    return (*punt)[index];
}

// operator iteratore

template <class T>
T& Vettore<T>::Iteratore::operator->() const {
    return index == punt->Size() ? new T() : (*punt)[index];
}

// operator iteratore
template <class T>
T& Vettore<T>::Iteratore::operator[](u_int ind) const {
    return (*punt)[ind];
}

template <class T>
typename Vettore<T>::Iteratore Vettore<T>::Iteratore::operator+(u_int const ind) const{
    int index = index+ind > punt->Size() ? punt->Size() : index+ind;
    return Iteratore(index);
}

template <class T>
typename Vettore<T>::Iteratore Vettore<T>::Iteratore::operator-(u_int const ind) const{
    cout << "index = " << index << endl;
    int aux = 0;
    aux = index-ind > 0 ? index-ind : 0;
    cout << "aux = " << aux << endl;
    cout << "index = " << index << endl;
    return Iteratore(aux);
} 

// operator iteratore
template <class T>
bool Vettore<T>::Iteratore::operator!=(const Iteratore& it) const{
    return this!=it;
}

// operator iteratore
template <class T>
bool Vettore<T>::Iteratore::operator==(const Iteratore& it) const{
    return *(this)==it || (punt == it.punt && index == it.index);
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
//costruttore di copia
template <class T> //ok
Vettore<T>::Vettore(const Vettore& vec): size(vec.size){
    delete[] info;
    info = new T[size];
    for(int i=0; i<size; i++){
        info[i]=vec.info[i];
    }
}

template <class T> //ok
Vettore<T>::Vettore():info(nullptr), size(0), capacity(0){}

template <class T> //ok
Vettore<T>::Vettore(T t): info(new T(t)), size(1),capacity(1){}

template <class T> //ok
Vettore<T>::Vettore(u_int n, T t): info(new T[n]){
    for(int i=1; i<n; i++){
        push_back(t);
    }
}

template <class T> //ok
Vettore<T>::Vettore(u_int n, T* t): info(new T[n]), size(n){
    for(int i =0; i<n; i++){
        info[i]=t[i];
    }
}

template <class T>
typename Vettore<T>::Iteratore Vettore<T>::begin() const{
    return Iteratore(*this);
}

template <class T>
typename Vettore<T>::Iteratore Vettore<T>::end() const{
    return Iteratore(*this, size);
}


template <class T> //ok
u_int Vettore<T>::Size() const{
    return size;
}

template <class T> //ok
void Vettore<T>::push_back(const T val){
    if(info){ //l'array non è vuoto
        if(size == capacity){ //l'array è pieno
            T* aux  = new T[capacity*2]; //raddoppio capacity
            capacity *= 2;
            for(int i=0; i<size; i++){
                aux[i]=info[i];
            }
            delete[] info;
            info = aux;
            info[size]=val; //metto in coda l'elemento da aggiungere
        } else info[size]= val;
    }
    else{
        info = new T(val);
        capacity++;
    }
    size++;
}

template <class T>
void Vettore<T>::insert(Iteratore it, T val){
    //if( end() == it ) return;
    size++;
    for(int i=size-1; i!=it.index; i--){
        info[i]=info[i-1];
    }
    info[it.index]=val;
    
}

template <class T>
void Vettore<T>::insert(T& val){
    bool ctr = true;
    for( int i = 0; ctr && i < size; i++){
        if(val == info[i]){
            info[i]+val;
            ctr = false;
        }
    }
    if(ctr)push_back(val);
}
template <class T>
void Vettore<T>::remove(T& value){
    for( int i = 0; i<Size(); i++){
        if(this[i]==value){
            if(i+1!=Size()){
                for(int j = i+1; j < Size(); j++){
                    info[j-1] = info[j];
                }
            }size--;
            
        }
    }
}

template <class T> //ok
T& Vettore<T>::pop_back(){
    T* ret = info+(size-1);
    size--; //perchè tolgo un valore
    delete info[size];
    return ret;
}

template <class T> //ok
bool Vettore<T>::empty(){ //true se il vettore è vuoto
    if( size == 0 ) return true;
}

template <class T> //ok
typename Vettore<T>::Vettore& Vettore<T>::merge(Vettore<T>& vec){
    Vettore aux= new Vettore;
    for(int i = 0; i< size; i++) {aux.push_back(this[i]);}
    for(int i=0; i<vec.size; i++) {aux.push_back(vec[i]);}
    return aux; //ho definito un costruttore che prende un T* e una size
}

template <class T> //ok
bool Vettore<T>::operator==(Vettore& vec){
    if(size != vec.Size()) return false;
    bool control = true;
    for( auto cont = begin(); cont != end() && control; cont++ ){
        if( cont->info != vec->info ) control = false;
    }
    return control;
}

template <class T>
void Vettore<T>::remove(Iteratore& iter){
    if( iter.index < size ){
        if(iter.index+1<size){
            for(int i = iter.index; i < size; i++){
                info[i]=info[i+1];
            }
        }else{
            size--;
        }
        
    }
}

template <class T>
T& Vettore<T>::operator[](u_int ind) const {
    return *(info+ind);
}

template <class T>
std::ostream& operator<<(std::ostream& os,const Vettore<T>& vec){
    for(int i =0; i< vec.size; i++){
        os << vec[i] << " ";
    }
    return os;
}

