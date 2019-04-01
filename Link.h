#ifndef LINK_H
#define LINK_H

#include <iostream>
using namespace std;
class Link
{
    private:
     char c1 , c2 ;
    float linkCost;
    int  huristic ;
    public:

          Link();
    Link(char c1,char c2 , float linkCost);
     Link(char c1,char c2 , int huristic);
    Link (char c1 , char c2 , float linkCost,float huristic);
  ~Link();

 Link& operator=(const Link& other);
         char getC1();
char getC2();
    float getlinkCost();
int gethuristic();


};


#endif // LINK_H
