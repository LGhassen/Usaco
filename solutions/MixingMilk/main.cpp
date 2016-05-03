/*
ID: ghassen2
LANG: C++
TASK: milk
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


struct farmer{
    int unitPrice;
    int totalUnits;
};

bool compareByUnitPrice(const farmer &a, const farmer &b)
{
    return a.unitPrice < b.unitPrice;
}

int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int milkWanted, totalFarmers;
    fin >> milkWanted >> totalFarmers;

    vector<farmer> farmers;

    //read farmers prices and amount of milk
    for (int i=0;i<totalFarmers;i++)
    {
        farmer temp;
        fin>>temp.unitPrice>>temp.totalUnits;
        farmers.push_back(temp);
    }

    //sort farmers by price
    sort(farmers.begin(), farmers.end(), compareByUnitPrice);


    //buy milk starting from cheapest farmer
    int unitsLeft= milkWanted;
    int totalPrice=0;
    int currentFarmer=0;
    farmer _cur;

    while (unitsLeft>0)
    {
        _cur=farmers.at(currentFarmer);

        if(_cur.totalUnits<unitsLeft)
        {
            unitsLeft-=_cur.totalUnits;
            totalPrice+=_cur.totalUnits*_cur.unitPrice;
        }
        else
        {
            totalPrice+=unitsLeft*_cur.unitPrice;
            unitsLeft=0;
        }

        currentFarmer++;
    }

    fout << totalPrice << endl;
    return 0;
}
