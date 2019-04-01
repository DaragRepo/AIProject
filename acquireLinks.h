#ifndef ACQUIRELINKS_H
#define ACQUIRELINKS_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "includes.h"
#include <vector>
using namespace std;

class acquireLinks
{
    public:
        acquireLinks();
       void acquireLink(vector<Link> &links);
       void acquireLink_huristic(vector<Link> &links);
       void acquireLink_both(vector<Link> &links);



    protected:

    private:
};

#endif // ACQUIRELINKS_H
