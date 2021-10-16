#include<iostream>
using namespace  std;

template<class T>
struct ChainList
{

    T  data;
    ChainList<T>* next;
    ChainList() = default;
    ChainList(T element) : data(element) {}
    ChainList(const T& element, ChainList<T>* next) {
        this->data = element;
        this->next = next;
    }

};

template<class T>
class chain : public ChainList<T> {

public:

    chain() {

        List = new ChainList<T>();
        List->next = nullptr;
        ListSize = 2;

    }               //构造函数，将链表初始化指向NULL

    chain(chain<T>& L1) {
        List = new ChainList<T>();
        List->next = nullptr;
        this->ListSize = L1.ListSize;
        ChainList<T>* CopyNode = L1.List;
        ChainList<T>* TargetNode = this->List;
        while (CopyNode != nullptr) {
            TargetNode->next = new ChainList<T>();
            TargetNode->data = CopyNode->data;
            TargetNode = TargetNode->next;
            CopyNode = CopyNode->next;
        }
        TargetNode->next = nullptr;

    };    //拷贝构造函数，拷贝一个链表

    ~chain() {
        while (List != nullptr) {

            ChainList<T>* NextNode = List->next;
            delete List;
            List = NextNode;

        }

    }//析构函数，释放内存

    int  empty(){

         if(this->List->next==nullptr)
             return -1;
         else
              return 1;

        }//如果链表不为空返回1，否则返回-1；
    int   size() ;//返回链表中元素个数；  
    ChainList<T> *get(int Index);//返回对应索引的前一个结点；
    void  insert(int Index, const T& data);//在List链表对应结点插入元素
    void   erase(int Index) ;//删除对应结点

protected:
    ChainList<T>* List; //单链表头指针
    int  ListSize;

};

template<class T>
void  chain<T>::insert(int Index, const T& data) {

    if (Index < 1) {
        cout << "索引位置输入错误" << endl;
    }

    else {
        ChainList<T>* Node = List;
        int i = 0;
        while (i < Index - 1 && Node->next != NULL)
        {
            Node = Node->next;
            i++;
        }
        ChainList<T>* p = new  ChainList<T>(data, Node->next);
        Node->next = p;
    }

}

template<class T>
ChainList<T> *chain<T>::get(int Index) {
    int  i = 0;
    ChainList<T>* Node = List;
    while (i < Index-1)
    {
        Node = Node->next;
        i++;
    }
    if (Node == NULL)
    {
        cout << "该结点不存在" << endl;
    }
    else {
        return Node;
    }

}

template<class T>
int chain<T>::size(){
     int i=0;
     auto ptr= this->List->next;
     while(ptr!=nullptr)
     {
         i++;
         ptr=ptr->next;
     }

    return i;
}

template<class T>
void chain<T>::erase(int Index){

    ChainList<T> *Ptr = get(Index);
    ChainList<T> *Ptr2=Ptr->next;
    Ptr->next=Ptr2->next;
    delete Ptr2 ;

}

int main()
{
     int a,b,c,d;
     chain<int> list;
     list.insert(1,1);
     list.insert(2,2);
     list.insert(3,3);
     list.erase(2);
     ChainList<int> *p=list.get(3);
     cout << p->data << endl ;

}