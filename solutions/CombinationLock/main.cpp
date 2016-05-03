/*
ID: ghassen2
LANG: C++
TASK: combo
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

//Looking back maybe I could have brute-forced this
//At a maximum N=100, we would have 1 million combinations to try
//For each combination we have to check every number is at +-2 of a combination number
//This is more or less at the threshold of what is bruteforceable
//
//The solution here is analytical
//Compute number of all possible combinations and substract overlapping numbers between combinations
//Overlap is checked separately for each digit by the simple method of marking a bool array
//Probably this could be replace by some if/else checks
//But at N=100 this shouldn't be any different in speed and this is simpler

int main()
{
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");

    int N;

    fin>>N;

    int farmerCombination[3],masterCombination[3];

    fin>> farmerCombination[0] >> farmerCombination[1] >> farmerCombination[2];
    fin>> masterCombination[0] >> masterCombination[1] >> masterCombination[2];

    int acceptedNumbersPerDigit=min(N,5);

    //total combinations including duplicates
    int totalCombinations= acceptedNumbersPerDigit * acceptedNumbersPerDigit * acceptedNumbersPerDigit * 2;

    //determine overlap of digits per key
    //to do this I map all possible combinations of a digit in an array for one key
    //and then have the second key do the same but reading and checking for existing digits instead
    int overlapPerDigit[3]={0};

    bool mapDigits[N];
    for (int i=0;i<3;i++)
    {
        memset(mapDigits,false,N);
        int combinationDigit=farmerCombination[i];
        for (int j=0;j<5;j++)
        {
            int index= combinationDigit-2+j;
            while (index<0)
                index+=N;
            index%=N;
            mapDigits[index]=true;
        }

        combinationDigit=masterCombination[i];
        for (int j=0;j<5;j++)
        {
            int index= combinationDigit-2+j;
            while (index<0)
                index+=N;
            index%=N;

            if (mapDigits[index])
                overlapPerDigit[i]++;
        }
        overlapPerDigit[i]=min(overlapPerDigit[i],N);
//        cout << overlapPerDigit[i] << endl;
    }


    int result=totalCombinations-(overlapPerDigit[0]*overlapPerDigit[1]*overlapPerDigit[2]);

    fout << result << endl;

    return 0;
}
