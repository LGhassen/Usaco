/*
ID: ghassen2
LANG: C++
TASK: friday
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int N;//number of years

    int i,j; //loop iterators

    fin >> N;

    int daysPerMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int daysPerMonthLeapYear[12]={31,29,31,30,31,30,31,31,30,31,30,31};

    int fridaysForYear[7][7]={0}; //first field start day of year, second field number of fridays per day of week
                                  //0-monday 7-sunday

    int fridaysForLeapYear[7][7]={0};

    //precompute number of 13ths for normal year, for each start day of year (monday-sunday)
    for (i=0;i<7;i++)
    {
        int dayOfWeek = i;

        for (int month=0;month<12;month++)
        {
            //find friday 13th
//            (dayOfWeek+12)%7;
            dayOfWeek+=12;
            dayOfWeek%=7;

            //increment day counter
            fridaysForYear[i][dayOfWeek]++;

            //increment dayOfWeek to 1st of next month
            dayOfWeek+=daysPerMonth[month]-13+1;
            dayOfWeek%=7;
        }
    }

    //precompute number of 13ths for leap year, for each start day of year (monday-sunday)
    for (i=0;i<7;i++)
    {
        int dayOfWeek = i;

        for (int month=0;month<12;month++)
        {
            //find friday 13th
//            (dayOfWeek+12)%7;
            dayOfWeek+=12;
            dayOfWeek%=7;

            //increment day counter
            fridaysForLeapYear[i][dayOfWeek]++;

            //increment dayOfWeek to 1st of next month
            dayOfWeek+=daysPerMonthLeapYear [month]-13+1;
            dayOfWeek%=7;
        }
    }

    int results[7]={0};
    //iterate over years and find results

    int yearStartDayOfWeek=0; //1900 starts with a monday
    for (int i=0;i<N;i++)
    {
        int year =1900+i;
        bool leap=false;
        //check if leap year
        if ( ((year % 100 ==0)&&(year % 400 ==0)) || ((year % 4 ==0)&&(year % 100 !=0))  )
            leap = true;

        if (leap)
        {
            for (int j=0;j<7;j++)
            {
                results[j]+= fridaysForLeapYear[yearStartDayOfWeek][j];
            }
            yearStartDayOfWeek+=366;
            yearStartDayOfWeek%=7;
        }
        else
        {
            for (int j=0;j<7;j++)
            {
                results[j]+= fridaysForYear[yearStartDayOfWeek][j];
            }
            yearStartDayOfWeek+=365;
            yearStartDayOfWeek%=7;
        }
    }

    for (int j=5;j<7;j++)
    {
       fout << results[j] << " ";
    }

    for (int j=0;j<4;j++)
    {
       fout << results[j] << " ";
    }

    fout << results[4] << endl;

    return 0;
}
