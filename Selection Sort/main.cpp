#include <iostream>

using namespace std;

void selectionSort(int testArr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int lowest = testArr[i];
        int replaceIndex = i;

        for(int j = i; j < size; j++)
        {
            if(lowest > testArr[j])
            {
                lowest = testArr[j];
                replaceIndex = j;
                cout << "replaceindex: " << replaceIndex << endl;
            }
        }

        int temp = lowest;
        testArr[replaceIndex] = testArr[i];
        testArr[i] = temp;
    }
}

int main()
{
    int testArr[10];

    for(int count = 9; count >= 0; count--)
    {
        testArr[count] = 10 - count;
    }

    selectionSort(testArr, 10);

    for(int i = 0; i < 10; i++)
    {
        cout << testArr[i] << endl;
    }

    return 0;
}
