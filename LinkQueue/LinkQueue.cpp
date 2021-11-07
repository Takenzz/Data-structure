#include "LinkQueue.h"

int main()
{

   Queue<int> Que ;
   Que.Push(1) ; 
   Que.Push(2) ; 
   Que.Push(3) ; 
   Que.Push(4) ; 
   int i = Que.QueueTop() ;
   std::cout <<  i  << std::endl ;
   std::cout <<  Que.num  << std::endl ;
   Que.Pop() ;
    i = Que.QueueTop() ;
   std::cout <<  i  << std::endl ;
   std::cout <<  Que.num  << std::endl ;
    Que.Pop() ;
    i = Que.QueueTop() ;
   std::cout <<  i  << std::endl ;
   std::cout <<  Que.num  << std::endl ;
    Que.Pop() ;
    i = Que.QueueTop() ;
   std::cout <<  i  << std::endl ;
   std::cout <<  Que.num  << std::endl ;


}