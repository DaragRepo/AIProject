#include <iostream>
#include "Link.h"
using namespace std;


Link::Link(char c1 , char c2 , float linkCost){

 this->c1=c1;
    this->c2=c2;
    this->linkCost=linkCost;

}
Link::Link(char c1 , char c2 , float linkCost,float huristic){
this->c1=c1;
    this->c2=c2;
    this->linkCost=linkCost;
    this->huristic=huristic;

}
Link::Link(char c1 , char c2 , int huristic){

this->c1=c1;
    this->c2=c2;
    this->huristic=huristic;

}


int Link::gethuristic(){
return this->huristic;
}
       char Link::getC1(){
    return this->c1;
    }
    char Link::getC2(){
    return this->c2;
    }
     float Link::getlinkCost(){
    return this->linkCost;
    }
    Link::~Link(){
    // do nothing

    }
    Link &Link::operator=(const Link& other){
    // do nothing
    }


