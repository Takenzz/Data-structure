#include "Stack.h"

int main()
{

       Stack<int> P ;
       P.StackPush(1) ;
       P.StackPush(2) ;
       P.StackPush(3) ;
       P.StackPush(4) ;
       P.StackPush(5) ;

       std::cout << P.StackTop() << std::endl ;
       P.StackPop();
       std::cout << P.StackTop() << std::endl ;
       std::cout << P.StackSize() << std::endl ;




}