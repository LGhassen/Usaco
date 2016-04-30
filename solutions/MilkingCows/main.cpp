/*
ID: ghassen2
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int N;
    fin >> N;

    //I simply made a huge "timetable" array
    //since it's only booleans the whole thing sits in 5 megs of memrory
    //I later walk through the timetable and find the longest milk/noMilk times
    //easy peasy

    bool seconds[1000000]={false}; //0 not milked 1 milked

    int milkStart, milkEnd, globalMilkEnd=0;
    for (int i=0;i<N;i++)
    {
        fin>>milkStart>>milkEnd;
        globalMilkEnd=max(globalMilkEnd,milkEnd);
        memset(seconds+milkStart,true,milkEnd-milkStart);
    }

    int longestMilk =0;
    int longestNoMilk=0;

    int currentMilk =0;
    int currentNoMilk=0;

    bool milkStarted=false;

    int i=0;
    while (i<globalMilkEnd)
    {
        if (!milkStarted)
            milkStarted= milkStarted || seconds[i];

        if (seconds[i])
        {
            currentMilk++;
            currentNoMilk=0;
        }
        else
        {
            currentMilk=0;
            if (milkStarted && (i<globalMilkEnd))
                currentNoMilk++;
        }

        longestMilk=max(longestMilk,currentMilk);
        longestNoMilk=max(longestNoMilk,currentNoMilk);

        i++;
    }

    fout << longestMilk<<" "<<longestNoMilk<<endl;


    return 0;
}
