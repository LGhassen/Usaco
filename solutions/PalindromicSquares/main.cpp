/*
ID: ghassen2
LANG: C++
TASK: palsquare
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

//itoa doesn't seem to work on the USACO compiler, and probably C++11
//so I made a quick base conversion function
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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    //read Base number
    int B;
    fin>>B;

    //generate squares 1 to 300
    int squares[310];

    for (int i=1;i<301;i++)
    {
        squares[i]=i*i;
    }

    //iterate through squares and convert to base B
    string numberInBaseB;
    for (int i=1;i<301;i++)
    {
        string numberInBaseB= toBaseB(squares[i],B);

        //check and return palindromes
        if (isPalindrome(numberInBaseB))
        {
            //convert original number to base B for display
            string iBaseB= toBaseB(i, B);
            fout << iBaseB+" "+numberInBaseB << endl;
        }
    }

    return 0;
}
