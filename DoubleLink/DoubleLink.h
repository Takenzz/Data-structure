#include<iostream>

template <typename T>
class Node
{
public:
    T value ;
    Node<T> *Pre_Node ;
    Node<T> *Next_Node ;

public:
    Node() = default ;
    Node(T a,Node<T> * b,Node<T> *c):
    value(a),Pre_Node(b),Next_Node(c){};
};

template <typename T>
class DoubleLink : public Node<T>
{
private:
    Node<T> *Pointer ;
    Node<T> *Head ;
    int count ;

public:
    DoubleLink()
    {
        Head = new Node<T>(0,nullptr,nullptr) ;
        Head->Next_Node = nullptr ;
        Head->Pre_Node  = nullptr ;
        Pointer = nullptr ;
        count = 0 ;
    }
    Node<T> *GetNode(int index) ;
    void    insert(T value,int index) ;
    void    erase(int index) ;
    void    push_back(T value) ;
    void    erase_back();
    int     GetCount();
    void    push_front(T value);
    void    erase_front();


};

template <typename T>
Node<T> *DoubleLink<T>::GetNode(int index)
{
    Node<T> * P = Head;
     if(index>count)
     {
        std::cout << "ERROR" ;
        return 0 ;
     }
  if(index <= count/2)
  {

     for(int i = 0 ; i < index ; i++)
     {
        P = P->Next_Node ;
     }

  }

    if(index > count/2)
  {

     for(int i = count + 1; i > index ; i--)
     {
        P = P->Pre_Node ;
     }

  }

  return P;

}   

template <typename T>
void DoubleLink<T>::insert(T value,int index)
{
     if(index<1||index>count+1)
     {
          std::cout << "ERROR" ;
          return ;
     }
    
   Node<T> * P = GetNode(index-1) ;
   Node<T> * P2 = new Node<T>(value , P ,P->Next_Node);

   if(P->Next_Node != nullptr)
   {

   P->Next_Node->Pre_Node = P2 ;
   P->Next_Node = P2 ;
  
   }
   else
   {
 
   P->Next_Node = P2 ;
   P->Pre_Node  = P2 ;
   P2->Next_Node = P ;
    
   }
   count ++ ;
}

template <typename T>
void DoubleLink<T>::erase(int index)
{
    Node<T> *P =  GetNode(index - 1) ;
    Node<T> *P2 = GetNode(index) ;

    P->Next_Node=P2->Next_Node ;
    P2->Next_Node->Pre_Node = P ;
    count --;

}

template <typename T>
void DoubleLink<T>::push_back(T value)
{
    Node<T> *P = GetNode(count) ;
    Node<T> *P2 ;
    P2 = new Node<T>(value,P,P->Next_Node) ;

    if(P->Next_Node != nullptr)
    {

    P->Next_Node->Pre_Node = P2 ;
    P->Next_Node = P2 ;

    }

    else
    {

       P->Next_Node = P2 ;
       P2->Next_Node = P ;
       P->Pre_Node = P2 ;
       P2->Pre_Node = P ;

    }
    count ++ ;

}

template <typename T>
void DoubleLink<T>::erase_back()
{
    Node<T> *P = GetNode(count) ;
       if(count == 0)
       {
          std::cout <<" ERROR" ;
          return ;
       }

    P->Pre_Node->Next_Node = P->Next_Node ;
    P->Next_Node->Pre_Node = P->Pre_Node  ; 
     delete P ;
     count --;

}

template <typename T>
int DoubleLink<T>::GetCount()
{

   return count  ;

}

template <typename T>
void  DoubleLink<T>::push_front(T value)
{

     Node<T> *P = new Node<T>(value,Head,Head->Next_Node);
     if(Head->Next_Node == nullptr)
     {
        Head->Next_Node = P;
        Head->Pre_Node = P;
        P->Next_Node = Head ; 
     }
    else
    {
       Head->Next_Node = P ;
       Head->Next_Node->Pre_Node = P ;
    }
    count ++ ;

}

template <typename T>
void DoubleLink<T>::erase_front()
{

    Node<T> *P = Head->Next_Node ;
     if(count == 0)
       {
          std::cout <<" ERROR" ;
          return ;
       }
     
     Head->Next_Node = P->Next_Node ;
     P->Next_Node->Pre_Node = Head  ;

}



