#include <iostream>
#include <algorithm> 

template<typename T>
class Node
{  
public:
     Node(T a,Node<T> * b,Node<T> * c) : value(a),LNode(b),RNode(c) ,height(0){} ;
   
    T value ;
    int  height = 0 ;
    Node<T> *LNode ; 
    Node<T> *RNode ; 

};

template<typename T>
class AVLtree
{
 public:
     Node<T> *Root ;


AVLtree():Root(nullptr) {} ;
Node<T> *search(T value) ;
void AVL_insert(T value) ;
void AVL_remove(T value) ;

private:
void insert(Node<T> *&GoalNode,T value) ;
void remove(Node<T> *&GoalNode,T value) ;

int  Height(Node<T> * GoalNode) ;
Node<T> *R_Revolve(Node<T> * GoalNode) ;
Node<T> *L_Revolve(Node<T> * GoalNode) ;
Node<T> *Min_Node(Node<T> * GoalNode) ;
Node<T> *Max_Node(Node<T> * GoalNode) ;


};

template<typename T>
int AVLtree<T>::Height(Node<T> * GoalNode)
{
    if(GoalNode != nullptr)
    {
        return GoalNode->height ;
    }
    return 0;
}



template<typename T>
Node<T> *AVLtree<T>::search(T value)
{
     Node<T> *GoalNode = Root ;
     while(GoalNode->valuer == value )
     {
         if(GoalNode->value > value)
         {
             GoalNode = GoalNode->LNode ;
         }
         else if (GoalNode->value < value)
         {
             GoalNode = GoalNode->RNode ;
         }
         else
         {
             return GoalNode ;
         }
     }
         return GoalNode  ;

}

template<typename T>
void AVLtree<T>::insert(Node<T> *&GoalNode,T value)
{
     if(GoalNode == nullptr)
     {
         GoalNode = new Node<T>(value,nullptr,nullptr) ;
     }    
     else if( GoalNode->value > value )
     {
         insert(GoalNode->LNode,value) ;
         if(Height(GoalNode->LNode)-Height(GoalNode->RNode) == 2)
         {
             if(GoalNode->LNode->value > value)
             {
             GoalNode = R_Revolve(GoalNode) ;
             }
             else
             {
               GoalNode->LNode = L_Revolve(GoalNode->LNode) ;
               GoalNode = R_Revolve(GoalNode) ;

             }
         }
     }
     else if(GoalNode->value < value)
     {
         insert(GoalNode->RNode,value) ;
         if(Height(GoalNode->RNode)-Height(GoalNode->LNode) == 2)
         {

             if(value < GoalNode->RNode->value)
             {
                GoalNode->RNode = R_Revolve(GoalNode->RNode) ;
                GoalNode = L_Revolve(GoalNode) ;
             }
             else
             {
                   GoalNode = L_Revolve(GoalNode) ;
             }
             
         }

     }

     GoalNode->height = std::max(Height(GoalNode->LNode),Height(GoalNode->RNode))+1 ;
     
}

template<typename T>
Node<T> *AVLtree<T>::R_Revolve(Node<T> * GoalNode)
{
      Node<T> *NewNode = GoalNode->LNode;
      GoalNode->LNode = GoalNode->LNode->RNode ;
      NewNode->RNode = GoalNode ;

     GoalNode->height = std::max(Height(GoalNode->LNode),Height(GoalNode->RNode))+1 ;
     NewNode->height = std::max(Height(NewNode->LNode),Height(NewNode->RNode))+1 ;

      return NewNode ;

}


template<typename T>
Node<T> *AVLtree<T>::L_Revolve(Node<T> * GoalNode)
{
    Node<T> *NewNode = GoalNode->RNode ;
    GoalNode->LNode = GoalNode->LNode->RNode ;
    NewNode->LNode = GoalNode ;
      
    GoalNode->height = std::max(Height(GoalNode->LNode),Height(GoalNode->RNode))+1 ;
    NewNode->height = std::max(Height(NewNode->LNode),Height(NewNode->RNode))+1 ;

   return NewNode ;
}

template<typename T>
void AVLtree<T>::remove(Node<T> *&GoalNode,T value)
{
   if(GoalNode != nullptr)
 {
     if(GoalNode->value == value)
     {
        if(GoalNode->LNode == nullptr || GoalNode->RNode == nullptr )
        {
             Node<T> *PrNode = GoalNode ;
              if(GoalNode->RNode != nullptr)
              {
                  GoalNode = GoalNode->RNode ;
              }
              else if(GoalNode ->LNode != nullptr )
              {
                 GoalNode = GoalNode->LNode ;
              }
              else 
              {
                  GoalNode = nullptr;
              }
              delete PrNode ;
              return ;
        }
        else
        {
           if (Height(GoalNode->LNode)>Height(GoalNode->RNode))
           {
                Node<T> *TargetNode ; 
                TargetNode = Max_Node(GoalNode->LNode) ;
                GoalNode->value = TargetNode->value ;
                remove(GoalNode->LNode,TargetNode->value) ;
           }
           else
           {
                 Node<T> *TargetNode ;    
                 TargetNode = Min_Node(GoalNode->RNode) ;
                 GoalNode->value = TargetNode->value ;
                 remove(GoalNode->RNode,TargetNode->value) ;
           }       
        }
     }    
     else if(value > GoalNode->value)
     {
                 remove(GoalNode->RNode,value) ;
            if(Height(GoalNode->LNode) - Height(GoalNode->RNode) == 2)
            {
                 if(GoalNode->LNode->LNode->height > GoalNode->LNode->RNode->height)
                 {
                     GoalNode->LNode = L_Revolve(GoalNode->LNode) ;
                     GoalNode = R_Revolve(GoalNode) ;        
                 }  
                 else
                 {
                     GoalNode = R_Revolve(GoalNode) ;  
                 }
            }
    
     }
     else if(value < GoalNode->value)
     {
     
             remove(GoalNode->LNode,value) ;           
          if(value > GoalNode->value)
                if(GoalNode->RNode->RNode->height > GoalNode->RNode->LNode->height)
                 {
                     GoalNode->RNode = R_Revolve(GoalNode->RNode) ;        
                     GoalNode = L_Revolve(GoalNode) ;
                 }  
                 else
                 {
                     GoalNode = L_Revolve(GoalNode) ;
                 }
     }
 }
    
}

template<typename T>
Node<T> *AVLtree<T>::Max_Node(Node<T> *GoalNode)
{
      if(GoalNode != nullptr)
      {
          GoalNode = GoalNode->LNode ;
      }

      return  GoalNode ;
}

template<typename T>
Node<T> *AVLtree<T>::Min_Node(Node<T> *GoalNode)
{
     if(GoalNode != nullptr)
      {
          GoalNode = GoalNode->RNode ;
      }

      return  GoalNode ;

}

template<typename T>
void AVLtree<T>::AVL_insert(T value)
{  
    insert(Root,value) ;
}

template<typename T>
void AVLtree<T>::AVL_remove(T value)
{  
    remove(Root,value) ;
}