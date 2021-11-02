#include <iostream>

template<typename T>
class Node
{

 public:
  Node():next(nullptr),data(0){};
  Node(T value, Node<T> *B): data(value),next(B){};
 

  public:
    T data ;
    Node<T> *next ;

};

template<typename T>
class Stack : public Node<T>
{

  public:
    void StackPush(T value) ;
    void StackPop() ;
    int  StackSize() ;
    T    StackTop() ;
    Stack()
    {
         Top = new Node<T>();
         num = 0 ;

    } ;

private:
    int num ;
    Node<T> *Top ; 
   

};

template<typename T>
void Stack<T>::StackPush(T value)
{
         
     Node<T> *P = new Node<T>(value,Top->next) ;
     Top->next = P ;
     num ++ ;

}

template<typename T>
void Stack<T>::StackPop()
{

    Node<T> *P = Top->next ;
    Top->next = P->next ;
     delete P ;
     num -- ;

}

template<typename T>
 int  Stack<T>::StackSize()
 {
    
    return num ;

 }

 template<typename T>
 T Stack<T>::StackTop()
 {

       return Top->next->data ;

 }
