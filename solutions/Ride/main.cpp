/*
ID: ghassen2
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    std::string cometName,groupName;

    int cometSum,groupSum;

//    cin>> cometName;
//    cin>> groupName;

    fin >> cometName;
    fin >> groupName;

    cometSum=1;
    groupSum=1;
    for (int i=0;i<cometName.size();i++)
    {
        cometSum*=cometName[i]-'A'+1;
    }
    for (int i=0;i<groupName.size();i++)
    {
        groupSum*=groupName[i]-'A'+1;
    }


    if ((cometSum % 47) == (groupSum % 47))
//        cout << "GO" << endl;
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;

    return 0;
}
