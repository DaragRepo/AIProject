#include "includes.h"
#include "node.h"
#include "acquireLinks.h"
#include <iostream>
#include "acquireLinks.h"
#include <sstream>
#include <vector>
#include "list.h"
using namespace std;
node::node()
{
    //ctor
}
node::node( char name,node* pParent,node* pNext,float cost,bool explored){
         this->name=name;
         this->pParent=pParent;
         this->pNext=pNext;
         this->cost=cost;
         this->explored=explored;
         }
node::~node()
{
    //dtor
}
node& node::operator=(const node& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
char node::getname(){
return this->name;
}
 node* node::getpParent(){
return this->pParent;
}
node* node::getpNext(){
return this->pNext;
}
 float node::getcost(){
return this->cost;
}
 bool node::getexplored(){
return this->explored;
}
void node::Setname(char name){
    this->name=name;

}
        void node::SetpParent(node* pParent){
        this->pParent=pParent;
        }
        void node::SetpNext(node* pNext){
        this->pNext=pNext;

        }
         void node::Setcost(float cost){
         this->cost=cost;

         }
         void node::Setexplored(bool explored){
         this->explored=explored;

         }
 bool node::isGoal(char goalCity){
if (this->getname()==goalCity){
    return true;
} else {
return false ;
}

 }

 void node::expand(vector<Link> &links, list* pFrontier){

 for (int i=0;i<links.size();i++){
    if (this->getname()==links[i].getC1())
        {
        node * n1=new node (links[i].getC2(),this,NULL,this->getcost() + links[i].getlinkCost(),false);
if (n1->visited(pFrontier)||n1->isRepeated(pFrontier)){


}

else {
  n1->pushNodeToList(pFrontier);
}


            }
       if (this->getname()==links[i].getC2())
       {

       node * n1=new node (links[i].getC1(),this,NULL,this->getcost()+ links[i].getlinkCost(),false);
if (n1->visited(pFrontier)||n1->isRepeated(pFrontier)){


} else {

n1->pushNodeToList(pFrontier);
}

           }

 }

 }

 bool node::isQualified(vector<Link> &links,list* pFrontier){
node * n =pFrontier->getpLastNode();
float cost = links[0].getlinkCost();
    for(int i = 0; i<links.size(); i++)
    {
        if (n->getname()==links[i].getC1()||n->getname()==links[i].getC2()){
        if(links[i].getlinkCost() <cost){
        cost =i;
        }
    }
    }
if (links[cost].getC2()==this->getname()||links[cost].getC1()==this->getname()){
return true ;
} else {
return false ;
}
 }

 void node::pushNodeToList(list* pFrontier){
        if (pFrontier->getpFirstNode()==NULL)// list is empty
        {
  pFrontier->SetpFirstNode(this);
  pFrontier->SetpLastNode(this);
        }
 else {
        pFrontier->getpLastNode()->SetpNext(this);
        pFrontier->SetpLastNode(this);
        }
 }
 bool node::visited(list* pFrontier){
 node*  l =pFrontier->getpFirstNode();
 int count = 0 ;
while (l){

       if (this->getname()==l->getname()){
            if (this->getcost()<l->getcost()){
//                    l->Setname(this->getname());
//                   l->Setcost(this->getcost());
//            l->SetpParent(this->getpParent());
//            l->SetpNext(this->getpNext());
//    l->Setexplored(this->getexplored());
l->Setcost(this->getcost());
l->SetpParent(this->getpParent());


        count ++ ;
            }
       }
l=l->getpNext();
}
 if (count>0){
    return true ;
 } else {
 return false ;
 }

 }
 bool node::isRepeated(list* pFrontier){
 node*  l =pFrontier->getpFirstNode();
 int count = 0 ;
while (l){

       if (this->getname()==l->getname()){
            if (this->getcost()>l->getcost()){
        count ++ ;
            }
       }
l=l->getpNext();
}
 if (count>0){
    return true ;
 } else {
 return false ;
 }

 }
list *  node::BFS(char startCity,char goalCity){
  acquireLinks w;
 vector<Link> v ;
 w.acquireLink(v);
node *   n =new node (startCity,NULL,NULL,0,false);
 list * l =new list (NULL,NULL);

 n->pushNodeToList(l);
while (true){

 if (n->getname()==goalCity){
n->Setexplored(true);
    break ;
      }else {
          n->Setexplored(true);
    n->expand(v,l);

    n=n->getpNext();
      }

}
return l;
}
list *  node::Uniform_Cost(char startCity,char goalCity){
 acquireLinks w;
 vector<Link> v ;
 w.acquireLink(v);
node *   n =new node (startCity,NULL,NULL,0,false);
 list * l =new list (NULL,NULL);

 n->pushNodeToList(l);
while (true){

 if (n->getname()==goalCity){
n->Setexplored(true);
    break ;
      }
      else  {
       if (n->isQualified(v,l)){
            n->Setexplored(true);
        n->expand(v,l);
       }

    n=n->getpNext();
      }

}
}
 int node::check(list* pFrontier){
 node*  l =pFrontier->getpFirstNode();
 int count = 0 ;
 int val=0;
while (l){

       if (this->getname()==l->getname()){
          val=count ;
            }

count ++ ;
l=l->getpNext();

}
 return val;

 }
 void node::expand_for_DFS(vector<Link> &links,list* pFrontier){
 int count = 0 ;

 for (int i=0;i<links.size();i++){
    if (this->getname()==links[i].getC1()&&count==0){
       node * n1=new node (links[i].getC2(),this,NULL,links[i].getlinkCost(),false);
       if (n1->visited(pFrontier)||n1->isRepeated(pFrontier)){


} else {

n1->pushNodeToList(pFrontier);
  count ++ ;
}

    }
 else if (this->getname()==links[i].getC2()&&count == 0){
               node * n1=new node (links[i].getC1(),this,NULL,links[i].getlinkCost(),false);
                 if (n1->visited(pFrontier)||n1->isRepeated(pFrontier)){

} else {

n1->pushNodeToList(pFrontier);
  count ++ ;
}
 }

 }



 }
 list * node::DFS(char startCity,char goalCity){
      acquireLinks w;
 vector<Link> v ;
 w.acquireLink(v);
node *   n =new node (startCity,NULL,NULL,0,false);
 list * l =new list (NULL,NULL);
 n->pushNodeToList(l);
 while (true){

 if (n->getname()==goalCity){
n->Setexplored(true);
    break ;
      }else {
n->Setexplored(true);
    n->expand_for_DFS(v,l);

    n=n->getpNext();
      }

}
return l ;
 }
 bool node::A_Cost(vector<Link> &links,list* pFrontier){
node * n =pFrontier->getpLastNode();
float cost = links[0].getlinkCost()+links[0].gethuristic();
    for(int i = 0; i<links.size(); i++)
    {
        if (n->getname()==links[i].getC1()||n->getname()==links[i].getC2()){
        if(links[i].getlinkCost()+links[i].gethuristic() <cost){
        cost =i;
        }
    }
    }
if (links[cost].getC2()==this->getname()||links[cost].getC1()==this->getname()){
return true ;
} else {
return false ;
}
 }
 bool node::huristic_Cost(vector<Link> &links,list* pFrontier){
node * n =pFrontier->getpLastNode();
float cost =links[0].gethuristic();
    for(int i = 0; i<links.size(); i++)
    {
        if (n->getname()==links[i].getC1()||n->getname()==links[i].getC2()){
        if(links[i].gethuristic() <cost){
        cost =i;
        }
    }
    }
if (links[cost].getC2()==this->getname()||links[cost].getC1()==this->getname()){
return true ;
} else {
return false ;
}
 }
 list * node::A(char startCity , char goalCity){
  acquireLinks w;
 vector<Link> v ;
 w.acquireLink_both(v);
node *   n =new node (startCity,NULL,NULL,0,false);
 list * l =new list (NULL,NULL);

 n->pushNodeToList(l);
while (true){

 if (n->getname()==goalCity){
n->Setexplored(true);
    break ;
      }
      else  {
       if (n->A_Cost(v,l)){
            n->Setexplored(true);
        n->expand(v,l);
       }

    n=n->getpNext();
      }

}
return l ;

 }
list *  node::huristic_algorithm(char startCity,char goalCity){
 acquireLinks w;
 vector<Link> v ;
 w.acquireLink_huristic(v);
node *   n =new node (startCity,NULL,NULL,0,false);
 list * l =new list (NULL,NULL);

 n->pushNodeToList(l);
while (true){

 if (n->getname()==goalCity){
n->Setexplored(true);
    break ;
      }
      else  {
       if (n->huristic_Cost(v,l)){
            n->Setexplored(true);
        n->expand(v,l);
       }

    n=n->getpNext();
      }

}
return l ;
}






// bool node::check_priority(vector<Link> &links,list* pFrontier){
//node * n =pFrontier->getpLastNode();
//float cost = this->check(pFrontier);
//while (l);
//        if (n->getname()==links[i].getC1()||n->getname()==links[i].getC2()){
//        if(links[i].getlinkCost() <cost){
//        cost =i;
//        }
//    }
//
//if (links[cost].getC2()==this->getname()||links[cost].getC1()==this->getname()){
//return true ;
//} else {
//return false ;
//}
// }



//   bool node::isQualified(vector<Link> &links,list* pFrontier){
//
//node * n =pFrontier->getpLastNode();
//
//for (int i =0;i<links.size();i++){
//   if (n->getname()==links[i].getC1()||n->getname()==links[i].getC2()){
//
//    if (this->getname()!=links[i].getC1()){
//    if (this->getcost()<links[i].getlinkCost()){
//
//        return true;
//    } else {
//
//    return false ;
//    }
//
//    }
//    else if (this->getname()!=links[i].getC2()){
//        if (this->getcost()<links[i].getlinkCost()){
//           return true;
//        } else {
//        return false ;
//        }
//    }
//
//
//   }
//
//
//
//}
//
//
//
// }
