#ifndef LIST_H
#define LIST_H
#include "includes.h"
#include "node.h"
using namespace std;
class list
{
    public:
        list();

        ~list();
        list& operator=(const list& other);
        void printList(void);
        node* getpFirstNode();
        node* getpLastNode();
       void SetpFirstNode(node* pFirstNode);
       void SetpLastNode(node* pLastNode);
   list(node* pFirstNode,node* pLastNode);
   void printResult();
    protected:

    private:
        node* pFirstNode;
   node*  pLastNode;
};

#endif // LIST_H
