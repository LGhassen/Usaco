/*
ID: ghassen2
LANG: C++
TASK: namenum
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
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict ("dict.txt");

    //load dictionary
    vector<string> dictionary;
    string tempString;
    for (int i=0;i<5000;i++)
    {
        dict >> tempString;
        dictionary.push_back(tempString);
    }

    //map numbers to letters
    map <char,string> numbersToLettersMap;
    numbersToLettersMap['2']="ABC";  numbersToLettersMap['3']="DEF";  numbersToLettersMap['4']="GHI";
    numbersToLettersMap['5']="JKL";  numbersToLettersMap['6']="MNO";  numbersToLettersMap['7']="PRS";
    numbersToLettersMap['8']="TUV";  numbersToLettersMap['9']="WXY";

    //read input number
    string input;
    fin>>input;

    int inputSize=input.size();

    string name;
    int nameNumber=0;

    bool foundSolution=false;

    //generate names
    for (int i=0;i<(int)pow(3,inputSize);i++)
    {
        name="";
        for (int j=0;j<inputSize;j++)
        {
            int index= ((int) (i/pow(3,inputSize-1-j))  )%3;
            name+= numbersToLettersMap[input[j]][index];
        }

        //find and display name if in dictionary
        //use std::binary_search since dictionary vector is already sorted
        if (binary_search (dictionary.begin(), dictionary.end(), name))
        {
            foundSolution=true;
            fout << name << endl;
        }
    }

    if (!foundSolution)
        fout << "NONE" << endl;

    return 0;
}
