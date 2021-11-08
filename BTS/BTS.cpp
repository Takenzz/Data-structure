#include "BTS.h"



int main()
{
 
    BSTree<int> test ;  
    test.insert(6) ;
    test.insert(3) ;
    test.insert(11) ;
    test.insert(15) ;
    test.insert(9) ;
    test.insert(7) ;
    test.insert(10) ;
    test.insert(1) ;
    test.insert(4) ;
    test.Preorder(test.root) ;
    std::cout << '\n' ; 
    test.Inorder(test.root) ;
    std::cout << '\n' ; 
    test.Postorder(test.root) ;
}