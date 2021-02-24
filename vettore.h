#ifndef VETTORE_H
#define VETTORE_H
#include <iostream>

typedef unsigned int u_int;

template <class T>
class Vettore;

template <class T>
std::ostream& operator<<(std::ostream& os,const Vettore<T>& vec);

class Iteratore;

template<class T>
class Vettore{
    // Vettore FRIEND DECLARATION 
    template<class T>
    friend std::ostream& operator<<(std::ostream& os,const Vettore<T>& vec);
   
    friend class Iteratore;

    private:
        T* info;
        u_int Size;
        u_int capacity;

    public:
        class Iteratore{
            friend class Vettore<T>;
            friend Vettore<T>::Iteratore Vettore<T>::Iteratore(const Iteratore& it);
            private:
                Vettore<T>* const punt; 
                u_int index;
                
            public:
                // iteratore CONSTUCTOR
                Iteratore(Vettore<T>* v, u_int ind=0);
                // Iteratore(T* p, u_int s, u_int c);
                static Iteratore clone(const Iteratore& it);
                Iteratore(const Iteratore& it);
                //~Iteratore(); -----> potrebbe no nservire visto che utilizziamo un puntatore 
                //                      quando cancelliamo iteratore non vogliamo cancellate anche il vettore
                //                      quindi ci basta cancellare il puntatore e non ciò a cui punta

                // overloading OPERATOR
                Iteratore& operator++();
                Iteratore& operator--();
                T& operator*() const;
                T& operator->()const;
                T& operator[](u_int ind)const;
                bool operator!=(const Iteratore& it) const;
                bool operator==(const Iteratore& it) const;
        };

        // vettore CONSTUCTOR
        Vettore();
        Vettore(u_int n, T& t);
        Vettore( typename Vettore<T>::Iteratore first, typename  Vettore<T>::Iteratore second );
        Vettore(Vettore& vec);
        
        // Vettore OPERATOR overloading
        T& operator[](u_int ind)const;
        bool operator==(Vettore& vec);

        // Vettore METHOD
        Iteratore& begin() const;
        Iteratore& end() const;
        u_int size() const;
        void push_back(T& val);
        void insert(Iteratore& it, T& val);
        T& remove(Iteratore& it); //rimuove l'elemento in posizione it
        T& remove(T& value); //rimuove elemento con valore value
        T& pop_back(); //rimuove ultimo elemento
        bool empty(); //true se il vettore è vuoto
        Vettore& merge(Vettore& vec);
        
};

template <class T>
std::ostream& operator<<(std::ostream& os,const Vettore<T>& vec);


#endif VETTORE_H
