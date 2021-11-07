#include <iostream>



template<typename T>
class Queue  
{    
   public :
   T value[10] ;
   int  front ; 
   int  rear ;     
   
   Queue(): front(0) , rear(0) {} ;
   bool QueueEmpty();
   void Push(T data);
   T Pop();
   

};

template<typename T>
bool Queue<T>::QueueEmpty()
{
  
   if(front == rear)
   {
        return true ;
   }
   else
   {
       return false ;
   }

}

template<typename T>
void Queue<T>::Push(T data)
{

    if((rear+1)%10 == front)
    {
        return ;
    }
    value[rear] = data ;
    rear = (rear+1) % 10 ;

}

template<typename T>
T Queue<T>::Pop()
{
  if(rear == front)
  {
      return 0;
  }
    int x ; 
    x = value[front] ;
    front = (front + 1) % 10 ;
    return x ;

}



