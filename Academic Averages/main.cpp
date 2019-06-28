#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

int getAverage(ifstream & inFile)
{
    int gradeSum = 0;
    int numberOfGrades = 0;
    double grade = 0;
    while(inFile >> grade)
    {
        numberOfGrades++;
        if(grade < 0)
        {}
        if(grade > 100)
            gradeSum += 100;
        else
            gradeSum += grade;
    }
    return gradeSum/numberOfGrades;
}

void sortInt(int & first, int & second, int & third)
{
    int temp = 0;
    if(second < first)
    {
        temp = second;
        second = first;
        first = temp;
    }
    if(third < second)
    {
        temp = third;
        third = second;
        second = temp;
        if(second < first)
        {
            temp = second;
            second = first;
            first = temp;
        }
    }
}

void writeFile(ofstream & outFile, int & minimum, int & middle, int & maximum)
{
    sortInt(minimum, middle, maximum);
    outFile << minimum << endl << middle << endl << maximum << endl;
}

int main()
{
    ifstream inFile1("A1.txt");
    ifstream inFile2("A2.txt");
    ifstream inFile3("A3.txt");

    if(!inFile1 || !inFile2 || !inFile3)
    {
        cout << "Unable to find a file" << endl;
        return EXIT_FAILURE;
    }
    int lowest = getAverage(inFile1);
    int middle = getAverage(inFile2);
    int highest = getAverage(inFile3);

    ofstream outFile("averages.txt");

    writeFile(outFile, lowest, middle, highest);
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
55
58
70
*/
