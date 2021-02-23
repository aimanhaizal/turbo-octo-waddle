#include <iostream> 
#include <iomanip> 
#include <cstdlib> 
#include <string> 
#include <vector> 
#include <ctime> 
#include <windows.h>
using namespace std;

class Map {
    private:
        vector < vector<char> > map;
        int dimX, dimY;
    public:
        Map(int x, int y){
            dimX = x;
            dimY = y;
            setSize(dimX,dimY);
        }
        void setSize(int x,int y){
            map.resize(y);
            for(int i=0;i<y;i++){
                map[i].resize(x);
                //cout << "My name jeff "<< endl;
                cout << "Its workin" << endl;
            }
        }
};

void Mars::init()
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ',
    'X', '#', '@', '$' };
    int noOfObjects = 10;	//number of objects in the objects array

    dimX = 15;
    dimY = 5;

    //create dynamic 2D array using vector 
    map.resize(dimY);	//create rows 
    for (int i=0; i<dimY; ++i)
    {
    map[i].resize(dimX);	//resize each rows
    }

    //put random chars into the vector array 
    for (int i=0; i<dimY; ++i)
    {
    for (int j=0; j<dimX; ++j)
        {
        int objNo = rand() % noOfObjects; map[i][j] =	objects[ objNo ];
        }
    }
}


int main(){
    Map a(2,3);
    //a.setSize(2,3);
    return 0;
}
