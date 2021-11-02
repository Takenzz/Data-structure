#include "DoubleLink.h"

int main()
{
   DoubleLink<int> test ;
   test.insert(1,1) ;
   test.push_back(2) ;
   test.erase_back() ;
   test.push_front(3) ;
   test.erase_front() ;
   int i = test.GetNode(1)->value ;
   std::cout << i ;



     return 0 ;
}