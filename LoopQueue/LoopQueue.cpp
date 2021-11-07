#include "LoopQueue.h"


int main()
{
    Queue<int> test ; 

   test.Push(1) ;
   test.Push(2) ;
   test.Push(3) ;
   test.Push(4) ;
   test.Push(5) ;
   test.Push(6) ;
   test.Push(7) ;
   test.Push(8) ;
   test.Push(9) ;

  int a,b,c,d,e,f ;
 for(int i = 0 ;i < 10 ; i++)
 {
     a = test.Pop() ;
     std::cout << a << std::endl ;
 }


    if(test.QueueEmpty())
    {
        std::cout << "empty" << std::endl ;
    }

    test.Push(9) ;
    a = test.Pop() ;
    std::cout << a << std::endl ;
      if(test.QueueEmpty())
    {
        std::cout << "empty" << std::endl ;
    }

    test.Pop() ; 
      if(test.QueueEmpty())
    {
        std::cout << "empty" << std::endl ;
    }


}