#include<iostream>
using namespace  std;

template<class T>
struct ChainList
{

T data ;
ChainList<T>* next ;

};
 
template<class T>
class chain : public ChainList<T> {

public:

chain () {
 
 List->next= NULL;
 ListSize=0;

}               //构造函数，将链表初始化指向NULL

chain (chain<T> &);

~chain () {
while (List != NULL){

ChainList<T> *NextNode=List->next ;
delete List ;
List = NextNode ;
}

}//析构函数，释放内存

void  empty() ;//如果链表不为空返回1，否则返回-1；
int   size() ;//返回链表中元素个数；  
T    get(int Index) ;//返回对应结点的数据；
void  insert(int Index,const T& data) ;//在List链表对应结点插入元素
void  erase(int Index,ChainList* List ) ;//删除对应结点

protected:
ChainList<T>* List; //单链表头指针
int  ListSize;

};

template<class T>
void  chain<T>::insert(int Index,const T& data){

if(Index<1){
    cout<<"索引位置输入错误"<<endl ;
}

else{ 
    ChainList<T> *Node=List;
    int i=0;
    while(i < Index-1 && Node->next==NULL)
    {
        Node=Node->next;
        i++;
    }
    ChainList<T> *p=new  T(data);
    p->next=Node->next;
    Node->next=p ;
    
}

}

template<class T>
T  chain<T>::get(int Index){
     int  i=0;
     ChainList<T> *Node=List;
     while(i<Index&&Node->next==NULL)
     {
         Node=Node->next;
         i++
     }
   if(Node==NULL)
   {
       cout<<"该结点不存在"<<endl ;
   }
  else{
      return Node->data;
  }

}


int main()
{
    chain<int> list;
    list.insert(1,1);
    int i=list.get(1);
    cout<<i;

}