#include "AVL.h"

int main()
{
    AVLtree<int> Test ;
    Test.AVL_insert(10) ;
    Test.AVL_insert(5) ;
    Test.AVL_insert(11) ;
    Test.AVL_insert(4) ;
    Test.AVL_insert(6) ;
    Test.AVL_remove(11) ;


    std::cout << Test.Root->RNode->value << std::endl ;
    std::cout << Test.Root->LNode->value << std::endl ;



}