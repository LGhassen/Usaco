/*
ID: ghassen2
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int NP;
    fin >> NP;
    //names table
    std::string tableName[NP];

    //moneyMap
    std::map <std::string,int> nameTofinalMoneyMap;
    std::map <std::string,int> nameToInitialMoneyMap;

    //get all names in map
    std::string tempName;

    for (int i=0;i<NP;i++)
    {
        fin>>tempName;
        tableName[i]=tempName;
        nameTofinalMoneyMap[tempName]=0;
        nameToInitialMoneyMap[tempName]=0;
    }

    std::string gifterName, giftRecipientName;
    //for each person giving money
    int startMoney, numberOfGifts;
    for (int i=0;i<NP;i++)
    {
        //read person name
        fin>>gifterName;
        //read initial money amount and number of given gifts
        fin>>startMoney>>numberOfGifts;

        //remember start money
        nameToInitialMoneyMap[gifterName]=startMoney;

        //for every gift given
        for (int j=0;j<numberOfGifts;j++)
        {
            //read gift recipient
            fin >> giftRecipientName;
            //give him money
            nameTofinalMoneyMap[giftRecipientName]+=startMoney / numberOfGifts;
        }

        //left over money stays in giver's account
        if (numberOfGifts != 0)
            nameTofinalMoneyMap[gifterName]+=startMoney % numberOfGifts;
        else
            nameTofinalMoneyMap[gifterName]+=startMoney;
    }


    //print start money, final money and delta
    for (int i=0;i<NP;i++)
    {
        fout << tableName[i] << " " << nameTofinalMoneyMap[tableName[i]]-nameToInitialMoneyMap[tableName[i]]<<endl;
    }

    return 0;
}
