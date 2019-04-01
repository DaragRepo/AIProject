#ifndef NODE_H
#define NODE_H
#include "includes.h"
#include "list.h"
class list ;
using namespace std;
class node
{

       private:
         char name;
         node* pParent;
         node* pNext;
         float cost;
         bool explored;
    public:
        node();
        ~node();

         node( char name,node* pParent,node* pNext,float cost,bool explored);
        node& operator=(const node& other);
bool isGoal(char goalCity);

void Setname(char name);
        void SetpParent(node* pParent);
        void SetpNext(node* pNext);
         void Setcost(float cost);
         void Setexplored(bool explored);
         char getname();
 node* getpParent();
node* getpNext();
 float getcost();
 bool getexplored();
 bool isQualified(vector<Link> &links,list* pFrontier);
void expand(vector<Link> &links, list* pFrontier);
void pushNodeToList(list* pFrontier);
bool visited(list* pFrontier);
bool isRepeated(list* pFrontier);
list * BFS(char startCity,char goalCity);
list *  Uniform_Cost(char startCity,char goalCity);

int check (list * pFrontier);
 bool check_priority(vector<Link> &links,list* pFrontier);
 void expand_for_DFS(vector<Link> &links,list* pFrontier);
 list *  DFS(char startCity,char goalCity);
  bool A_Cost(vector<Link> &links,list* pFrontier);
bool huristic_Cost(vector<Link> &links,list* pFrontier);
 list * A (char startCity , char goalCity);
 list *  huristic_algorithm(char startCity,char goalCity);






























    protected:






#endif // NODE_H
