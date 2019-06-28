#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

int const NUM_COL = 3;
int const NUM_ROW = 36;

// c
void readFile(ifstream & fin1, ifstream & fin2, ifstream & fin3, int arr[NUM_ROW*3][NUM_COL])
{
    for(int row = 0; row < NUM_ROW; row++)
    {
        for(int col = 0; col < NUM_COL; col++)
            fin1 >> arr[row][col];
    }
    for(int row = NUM_ROW; row < NUM_ROW*2; row++)
    {
        for(int col = 0; col < NUM_COL; col++)
            fin2 >> arr[row][col];
    }
    for(int row = NUM_ROW*2; row < NUM_ROW*3; row++)
    {
        for(int col = 0; col < NUM_COL; col++)
            fin3 >> arr[row][col];
    }
}

// d
void outPutTable(int arr[NUM_ROW*3][NUM_COL])
{
    cout << setw(14) << "Temperature" << setw(14) << "Coarseness" << setw(14) << "Ranking" << endl;
    for(int row = 0; row < NUM_ROW*3; row++)
    {
        for(int col = 0; col < NUM_COL; col++)
            cout << setw(14) << arr[row][col];
        cout << endl;
    }
}

// e with 0 as rows and 1 as columns
int sumValues(int arr[NUM_ROW*3][NUM_COL], bool type, int index)
{
    int sum = 0;
    if(type == 0)
    {
        for(int count = 0; count < NUM_COL; count++)
            sum += arr[index][count];
    }
    else
    {
        for(int count = 0; count < NUM_ROW*3; count++)
            sum += arr[count][index];
    }
    return sum;
}

// f
void findBestCoffee(int arr[NUM_ROW*3][NUM_COL], int & temperature, int & coarseness)
{
    int best[NUM_ROW*3][NUM_COL] = {0};
    for(int count = 0; count < NUM_ROW*3; count++)
    {
        if(arr[count][2] >= 8)
        {
            best[count][0] = arr[count][0];
            best[count][1] = arr[count][1];
        }
    }

    int bestTable[10][5] = {0};
    for(int count = 1; count < 10; count++)
    {
        bestTable[count][0] = count + 90;
    }
    for(int count = 1; count < 5; count++)
    {
        bestTable[0][5] = count;
    }



    for(int count1 = 0; count1 < NUM_ROW*3; count1++)
    {
        int colValue = best[count1][1];
        int rowValue = best[count1][0];
        bestTable[rowValue-90][colValue]++;
    }
    int highestOccurance = 0;

    for(int row = 1; row < 10; row++)
    {
        for(int col = 1; col < 5; col++)
        {
            if(highestOccurance < bestTable[row][col])
            {
                highestOccurance = bestTable[row][col];
                temperature = row + 90;
                coarseness = col;
            }
        }
    }
}

int main()
{
    ifstream fin1("coffee1.txt");
    ifstream fin2("coffee2.txt");
    ifstream fin3("coffee3.txt");

    int dataArr[NUM_ROW*3][NUM_COL] = {0};
    readFile(fin1, fin2, fin3, dataArr);

    outPutTable(dataArr);

    int bestTemperature = 0;
    int bestCoarseness = 0;

    int bestTempArr[NUM_ROW*3][NUM_COL] = {0};
    int indexCount = 0;
    for(int count = 0; count < NUM_ROW*3; count++)
    {
        if(dataArr[count][2] == 10)
        {
            bestTempArr[count][0] = dataArr[count][0];
            bestTempArr[count][1] = dataArr[count][1];
            indexCount++;
        }
    }
    cout << "Best Temp: " << sumValues(bestTempArr, 1, 0)/indexCount << endl;
    findBestCoffee(dataArr, bestTemperature, bestCoarseness);
    cout << "The best temperature is " << bestTemperature << " and the coarseness is " << bestCoarseness << endl;
}
/*
   Temperature    Coarseness       Ranking
            94             4             9
            92             3            10
            98             3             3
            98             4             8
            99             3             2
            95             3             1
            93             2             9
            91             3             6
            99             2             3
            98             1             8
            99             1             9
            97             4             4
            91             2             5
            94             2             5
            95             4            10
            98             2             8
            99             4             4
            92             2             2
            92             4             8
            93             3            10
            92             1             5
            94             1             4
            91             1             5
            94             3             3
            93             1            10
            95             2             7
            96             1             5
            96             2             5
            96             3             4
            93             4             1



            96             4             6
            97             1             2
            97             2            10
            91             4            10
            95             1             6
            97             3             7
            91             1             4
            98             4             3
            93             1             6
            98             1             4
            91             3             3
            96             3             6
            99             2             7
            99             3             6
            99             4             9
            96             1             5
            91             2             6
            94             1             3
            93             3             3
            94             3             6
            95             3             9
            96             2             4
            91             4             1
            94             2             1
            97             1             5
            92             1             4
            92             3             3
            95             4             9
            97             2            10
            97             4             5
            93             2             9
            98             2             1
            98             3             9
            94             4             5
            95             1             5
            92             2             4
            95             2             4
            96             4             3
            93             4             8
            92             4             1
            99             1            10
            97             3             4
            95             3             9
            96             2             5
            96             3             4
            93             2             9
            97             1             8
            97             4             9
            98             3             4
            97             2             8
            98             4             8
            92             1             8
            99             1             6
            99             2             4
            93             4             8
            95             4             2
            91             1             1
            92             3             5
            95             2             4
            98             2             7
            99             3             4
            98             1             4
            99             4             5
            91             3             3
            93             1             1
            94             4             1
            96             4             6
            97             3             1
            92             4             2
            96             1             5
            91             4             7
            93             3             6
            92             2             1
            94             2             6
            94             1             6
            91             2            10
            94             3             2
            95             1             2
Best Temp: 94
The best temperature is 93 and the coarseness is 2
*/
