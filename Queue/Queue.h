#include <iostream>

template<typename T>
class  Node
{

public:
  Node():next(nullptr){};
  Node(T A):value(A),next(nullptr){}; 

public:   
   T value ;
   Node<T> *next ;

};

template<typename T>
class Queue :public Node<T>
{

public:

    Queue ()
    {
 
    Top = new Node<T>() ;
    Last = Top ;
    num  = 0 ;

    };
    void Push(T value);
    void Pop() ;
    T QueueTop() ;
    int size() ;

public:
   
   Node<T> *Top ;
   Node<T> *Last ;
   int num ;


};


template<typename T>
void Queue<T>::Push(T value)
{

   Node<T> *P = new Node<T>(value) ;

   Last->next = P ;
   Last = P ;

   num++ ;

}

template<typename T>
void Queue<T>::Pop()
{
    Node<T> *P = Top->next ;
    Top->next =  P->next ;
    delete P ;
    num -- ;

}

template<typename T>
T Queue<T>::QueueTop()
{

    return Top->next->value ;

}

template<typename T>
int Queue<T>::size()
{
   
   return num ;

}



