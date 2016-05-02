/*
ID: ghassen2
LANG: C++
TASK: transform
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

//seems pretty tedious
//could have probably been made less tedious and more brute-force-y
//also probably could have made simple transform functions instead of using matrices


//check for transformations
bool isTransformedByMatrix(char originalPattern[10][10], char transformedPattern[10][10],int N, int transformMatrix[2][2])
{
    bool rot=true;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            //god help you understand this
            float a=0.5+ (float)(N-2)/2;
            int rotatedi=(int) ((i-a) * transformMatrix[0][0] + (j-a) * transformMatrix[0][1] +a);
            int rotatedj=(int) ((i-a) * transformMatrix[1][0] + (j-a) * transformMatrix[1][1] +a);

            if (originalPattern[i][j] != transformedPattern[rotatedi][rotatedj])
            {
                rot=false;
                break;
            }
        }

        if (!rot)
        break;
    }

    return rot;
}

bool isTransformedBy2Matrices(char originalPattern[10][10], char transformedPattern[10][10],int N, int transformMatrix1[2][2],
                              int transformMatrix2[2][2])
{
    bool rot=true;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            //god help you understand this
            float a=0.5+ (float)(N-2)/2;
            int rotatedi=(int) ((i-a) * transformMatrix1[0][0] + (j-a) * transformMatrix1[0][1] +a);
            int rotatedj=(int) ((i-a) * transformMatrix1[1][0] + (j-a) * transformMatrix1[1][1] +a);

            int rotatedi2=(int) ((rotatedi-a) * transformMatrix2[0][0] + (rotatedj-a) * transformMatrix2[0][1] +a);
            int rotatedj2=(int) ((rotatedi-a) * transformMatrix2[1][0] + (rotatedj-a) * transformMatrix2[1][1] +a);

            if (originalPattern[i][j] != transformedPattern[rotatedi2][rotatedj2])
            {
                rot=false;
                break;
            }
        }

        if (!rot)
        break;
    }

    return rot;
}


int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    int N;
    fin>>N;

    char originalPattern[10][10];
    char transformedPattern[10][10];

    string temp;
    for (int i=0;i<N;i++)
    {
        fin>>temp;
        for (int j=0;j<N;j++)
        {
            originalPattern[i][j]=temp[j];
        }
    }

    for (int i=0;i<N;i++)
    {
        fin>>temp;
        for (int j=0;j<N;j++)
        {
            transformedPattern[i][j]=temp[j];
        }
    }

    //hand computed rotations
    int rotMatrix90[2][2]={0,1,-1,0};
    int rotMatrix180[2][2]={-1,0,0,-1};
    int rotMatrix270[2][2]={0,-1,1,0};

    //check for 90 degree rotation
    if (isTransformedByMatrix(originalPattern,transformedPattern,N,rotMatrix90))
    {
        fout << "1" << endl;
        return 0;
    }

    //check 180 rotation
    if (isTransformedByMatrix(originalPattern,transformedPattern,N,rotMatrix180))
    {
        fout << "2" << endl;
        return 0;
    }

    //check 270 rotation
    if (isTransformedByMatrix(originalPattern,transformedPattern,N,rotMatrix270))
    {
        fout << "3" << endl;
        return 0;
    }

    bool reflection=true;

    int reflectionMatrix[2][2]={1,0,0,-1};

    //check for reflection
    if (isTransformedByMatrix(originalPattern,transformedPattern,N,reflectionMatrix))
    {
        fout << "4" << endl;
        return 0;
    }

    //check for reflection-rotation combinations
    if (isTransformedBy2Matrices(originalPattern,transformedPattern,N,reflectionMatrix,rotMatrix90))
    {
        fout << "5" << endl;
        return 0;
    }

    if (isTransformedBy2Matrices(originalPattern,transformedPattern,N,reflectionMatrix,rotMatrix180))
    {
        fout << "5" << endl;
        return 0;
    }

    if (isTransformedBy2Matrices(originalPattern,transformedPattern,N,reflectionMatrix,rotMatrix270))
    {
        fout << "5" << endl;
        return 0;
    }

    //check for identical
    int idMatrix[2][2]={1,0,0,1};

    if (isTransformedByMatrix(originalPattern,transformedPattern,N,idMatrix))
    {
        fout << "6" << endl;
        return 0;
    }

    fout << "7" << endl;
    return 0;
}
