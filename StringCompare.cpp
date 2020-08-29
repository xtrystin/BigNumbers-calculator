#include "StringCompare.h"
//#include <iostream>
//using namespace std;



bool CompareGreaterThan(string a, string b)     // a > b ?
{
    int nullPositionA = a.size();
    int nullPositionB = b.size();

    if (nullPositionA > nullPositionB)
        return true;
    else if (nullPositionA < nullPositionB)
        return false;
    else if (nullPositionA == nullPositionB)
    {
        for (int i = 0; i < nullPositionA; i++)
        {
            if (a[i] > b[i])
                return true;
            else if (a[i] < b[i])
                return false;
            else if (a[i] == b[i])
                continue;
        }
        return false;
    }

}

bool CompareEqual(string a, string b)      // a == b ?
{
    int nullPositionA = a.size();
    int nullPositionB = b.size();

    if (nullPositionA > nullPositionB)
        return true;
    else if (nullPositionA < nullPositionB)
        return false;
    else if (nullPositionA == nullPositionB)
    {
        for (int i = 0; i < nullPositionA; i++)
        {
            if (a[i] > b[i])
                return true;
            else if (a[i] < b[i])
                return false;
            else if (a[i] == b[i])
                continue;
        }
        return true;
    }

}


