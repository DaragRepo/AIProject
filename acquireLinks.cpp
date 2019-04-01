#include "acquireLinks.h"
#include "acquire.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "includes.h"
#include <vector>
using namespace std ;
acquireLinks::acquireLinks()
{
    //ctor
}



void acquireLinks::acquireLink(vector<Link> &links)
{
    string line;
    char c1 ,c2 ;
    float linkCost ;
    ifstream myfile ("file.txt");
    if (myfile.is_open())
        {
            while ( myfile>>c1>>c2>>linkCost )
            {
                links.push_back(Link(c1,c2,linkCost));
            }
            myfile.close();
        }
        else
            cout << "Unable to open file";
}

void acquireLinks::acquireLink_huristic(vector<Link> &links)
{
     string line;
    char c1 ,c2 ;
    int huristic ;
    ifstream myfile ("huristic.txt");
    if (myfile.is_open())
        {
            while ( myfile>>c1>>c2>>huristic )
            {
                links.push_back(Link(c1,c2,huristic));
            }
            myfile.close();
        }
        else
            cout << "Unable to open file";



}
void acquireLinks::acquireLink_both(vector<Link> &links){
  string line;
    char c1 ,c2 ;
    int  huristic ;
    float linkCost ;
    ifstream myfile ("huristic+real.txt");
    if (myfile.is_open())
        {
            while ( myfile>>c1>>c2>>linkCost>>huristic )
            {
                links.push_back(Link(c1,c2,linkCost,huristic));
            }
            myfile.close();
        }
        else
            cout << "Unable to open file";

}






}








