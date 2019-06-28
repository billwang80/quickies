#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

int const NUM_ROW = 60;
int const NUM_COL = 8;

class Song
{
    private:
        string name;
        int minute;
        int second;
    public:
        Song()
        {
            name = "";
            minute = 0;
            second = 0;
        }

        Song(string name0, int minute0, int second0)
        {
            name = name0;
            minute = minute0;
            second = second0;
        }

        string getSong()
        {
            return name;
        }

        int getTime()
        {
            return minute*60 + second;
        }

        void input(ifstream & fin)
        {
            while(fin >> name)
                fin >> minute >> second;
        }
};

int readArray(ifstream & fin, int day[NUM_COL], char usage[NUM_ROW][NUM_COL])
{
    for(int row = 0; row < NUM_ROW; row++)
    {
        fin << day[NUM_ROW];
        for{int col = 0; col < NUM_COL; col++}
    }
}

int main()
{

}
