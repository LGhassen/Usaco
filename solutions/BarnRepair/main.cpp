/*
ID: ghassen2
LANG: C++
TASK: barn1
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int maxBoards, totalStalls, cowsInStalls;

    fin>>maxBoards>>totalStalls>>cowsInStalls;

    //create array representation of stalls
    bool stallsArray[totalStalls+10];
    memset(stallsArray,false,totalStalls);


    //mark stalls with cows in them
    int index;
    for (int i=0;i<cowsInStalls;i++)
    {
        fin >> index;
        index--; //bias index by -1 since array starts at 0 and indexes provided start at 1
        stallsArray[index]=true;
    }

    //group adjacent cow stalls and store distances between groups
    bool firstGroupFound=false;
    bool inGroup=false;
    int currentDistance=0;
    int distanceIndex=-1;

    vector<int> distancesBetweenGroups;

    for (int i=0;i<totalStalls;i++)
    {
        if (stallsArray[i])
        {
            if(firstGroupFound && (currentDistance>0))
                distancesBetweenGroups.push_back(currentDistance);

            firstGroupFound=true;
            inGroup=true;
            currentDistance=0;
        }
        else
        {
            if (inGroup)
            {
                inGroup=false;
                currentDistance=0;
                distanceIndex++;
            }

            if (firstGroupFound)
                currentDistance++;
        }
    }

    //sort distances by lowest to highest
    sort(distancesBetweenGroups.begin(),distancesBetweenGroups.end());

    //get number of adjacent cow groups
    int numberOfGroups=distancesBetweenGroups.size()+1;

    //if we have enough boards for every separate stall
    if (maxBoards>=numberOfGroups)
    {
        fout << cowsInStalls <<endl;
        return 0;
    }

    //if not, start grouping the closest groups together
    int totalStallsCovered=cowsInStalls;
    for (int i=0;i<numberOfGroups-maxBoards;i++)
    {
        totalStallsCovered+=distancesBetweenGroups.at(i);
    }

    fout << totalStallsCovered <<endl;

    return 0;
}
