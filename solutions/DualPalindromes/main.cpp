/*
ID: ghassen2
LANG: C++
TASK: dualpal
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

//reusing my functions from PalindromicSquares
//checks if string is palindrome
bool isPalindrome(string str)
{
    int length = str.size();
    bool palindrome =true;
    int i=0;
    while (palindrome && i<=length/2)
    {
        palindrome = palindrome && (str[i]==str[length-1-i]);
        i++;
    }
    return palindrome;
}

//Reused from PalindromicSquares
string toBaseB(int number, int B)
{
    //convert number to BaseB
    //this method gives the numbers in reverse order
    //so they are inserted at the beginning of the string (line 49)
    string result="";
    string currentCharacter;
    string NUMBERS="0123456789ABCDEFGHIJK"; //String to lookup characters equivalent to each number

    int div=number, remainder=0;

    while (div!=0)
    {
        remainder = div % B;
        div = div / B;

        currentCharacter=NUMBERS[remainder];
        result.insert(0,currentCharacter);
    }
    return result;
}


int main()
{
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int N,S;
    fin>>N>>S;

    int solutionsFound=0;

    int currentNumber=S+1;
    int palindromeCount=0;

    string numberInBaseB;

    while (solutionsFound<N)
    {
        palindromeCount=0;

        for (int i=2;i<11;i++)
        {
           numberInBaseB = toBaseB(currentNumber, i);

           if (isPalindrome(numberInBaseB))
            palindromeCount++;

           if (palindromeCount>1)
           {
                solutionsFound++;
                fout<<currentNumber<<endl;
                break;
           }
        }

        currentNumber++;
    }

    return 0;
}
