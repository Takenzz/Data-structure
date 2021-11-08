#include <iostream>

template<typename T>
class Node
{

public:

    Node() = default ;
    Node(T A): data(A) , LNode(nullptr),RNode(nullptr) {} ;
    Node<T> *LNode ;
    Node<T> *RNode ;
    T  data ;

};

template<typename T>
class BSTree
{
 public:
    Node<T> * root ;

   BSTree(): root(nullptr) {} ;
   void insert(T value) ;
   void remove(T value) ;
   void Preorder(Node<T> *P) ;
   void Inorder(Node<T> *P)  ;
   void Postorder(Node<T> *P) ;

};

template<typename T>
void BSTree<T>::insert(T value)
{

      Node<T> * NewNode = root;
      Node<T> * PrNode = nullptr ;
 
     while(NewNode != nullptr)
     {
         PrNode =  NewNode ;
        if(value > NewNode->data)
        {
            NewNode = NewNode->RNode ;
        }
         else if(value < NewNode->data)
        {
            NewNode = NewNode->LNode ;
        }
        else
        {
            return ;
        }
     }

        NewNode = new Node<T>(value) ;
        if(PrNode == nullptr)
        {
             root = NewNode ;
        }
        else
        {

              if(value > PrNode->data)
              {
                  PrNode->RNode = NewNode ;
              }
             else
             {
                  PrNode->LNode = NewNode ;
             }

        }

}

template<typename T>
void BSTree<T>::remove(T value)
{
     
      Node<T> *GoalNode = root ;
      Node<T> *NewNode ;
      Node<T> *Parent ;
      Parent = GoalNode ;
      while(value != GoalNode->data)
      {
            Parent = GoalNode ;
             if(value > GoalNode->data)
              {
                  GoalNode = GoalNode->RNode ;
              }
              else
              {
                 GoalNode = GoalNode->LNode ;
              }
      }

      NewNode = GoalNode ;

     if(GoalNode->LNode != nullptr && GoalNode->RNode == nullptr)  //只有左子树
     {   
             
         GoalNode = GoalNode->LNode ;
         delete  GoalNode ;

     }
     else if(GoalNode->LNode == nullptr && GoalNode->RNode != nullptr)  //只有右子树
     {   
             
         GoalNode = GoalNode->RNode ;
         delete  GoalNode ;

     }
     else if(GoalNode->LNode != nullptr && GoalNode->RNode != nullptr) //左右都有
     {

        T a ;
        NewNode = GoalNode->LNode ;
        while(NewNode->RNode != nullptr)
        {
            NewNode = NewNode->RNode ;
        }
        a = NewNode->data ;
        remove(a) ; 
        GoalNode->data = a ;

     }
     else if(GoalNode->LNode == nullptr && GoalNode->RNode == nullptr)
     {       
         if(Parent->LNode != nullptr)
         {
            if(GoalNode->data == Parent->LNode->data)
            {
                Parent->LNode = nullptr ;
            }
            else
            {
                Parent->RNode = nullptr ;
            }
            delete GoalNode ;
         }
         else
         {
              Parent->RNode = nullptr ;

         }
             
     }

}

template<typename T>
void BSTree<T>::Preorder(Node<T> *P)
{

   if(P != nullptr)
   {
      std::cout << P->data <<" --> " ;
      Preorder(P->LNode) ;
      Preorder(P->RNode) ;
   }

}

template<typename T>
void BSTree<T>::Postorder(Node<T> *P)
{
    if(P != nullptr)
    {
        Postorder(P->LNode) ;
        Postorder(P->RNode) ;
        std::cout << P->data <<" --> " ;
    }


}

template<typename T>
void BSTree<T>::Inorder(Node<T> *P)
{
    if(P != nullptr)
    {
        Inorder(P->LNode) ;
        std::cout << P->data <<" --> " ;
        Inorder(P->RNode) ;
    }

}