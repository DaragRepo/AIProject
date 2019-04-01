#include "includes.h"
#include "list.h"
#include <iostream>
using namespace std;
list::list()
{
    //ctor
}

list::~list()
{
    //dtor
}
list::list(node* pFirstNode,node* pLastNode){
this->pFirstNode=pFirstNode;
this->pLastNode=pLastNode;
}
list& list::operator=(const list& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
node* list::getpFirstNode(){
return this->pFirstNode;
}
node* list::getpLastNode(){
return this->pLastNode;
}
  void list::SetpFirstNode(node* pFirstNode){
  this->pFirstNode=pFirstNode;

  }
       void list::SetpLastNode(node* pLastNode){
       this->pLastNode=pLastNode;
       }
void list::printList(){
 node*  l =list::getpFirstNode();
while (l){
        if (l==list::getpFirstNode()){
            cout<<" Name : "<< l->getname()<<"   Parent : no parent"<<" Next : " <<l->getpNext()->getname()<<"  Cost :  "<<l->getcost()<<endl ;
        }
        else if (l==list::getpLastNode()){
        cout<<" Name : "<< l->getname()<<"   Parent : "<<l->getpParent()->getname()<<" Next : No Next " <<"  Cost :  "<<l->getcost()<<endl ;
        }

         else {

 cout<<" Name : "<< l->getname()<<"   Parent : "<<l->getpParent()->getname()<< " Next : " <<l->getpNext()->getname()<<   "  Cost :  "<<l->getcost()<<endl ;
        }
l=l->getpNext();
}

}
//void list::printResult(list * l) {
//
// node * p=l->getpFirstNode();
//int counter = 0 ;
//while (p){
//   if (p->getexplored()==true){
//       cout << p->getname();
//       counter ++ ;
//    }
//    p=p->getpNext();
//}
//cout << counter-1 ;
//}
//
//
//}



