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
        void replace(int x, int y, int newitem){map[x][y]=newitem;}
        void setSize(int x,int y){      // this one assigns the map to sizes x by y
            map.resize(y);
            for(int i=0;i<y;i++){
                map[i].resize(x);
            }
        }
        void Map::fillMap(){            // this one just fills the map with the number 0
            for (int i=0; i<dimX; i++){
                for(int j=0; j<dimY;j++){
                    map[i][j] = 0; // new comment!
                }
            }
        }   
};
// next to do; make the map spawn items, make the items randomized

void start(Map& call){                                  // trying to push map with 111111
    int objects[] = {1 , 1 , 1, 1, 1, 1, 1, 1, 1};
    int amount = 10;

    for (int i=0;i<call.dimY();i++){             // problem calling
        for(int j=0;j<call.dimX();j++){          // problem calling
            int newObj = rand()% amount;
            call.replace(j,i,objects[amount]);
        }
    }
}

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

    cout << "Let's explore Mars......" << endl;
    int x,y;
    cout << "Mars dimension X => " << endl;
    cin >> x;
    cout << "Mars dimension Y => " << endl;
    cin >> y;
    Map a(x,y);
    //a.setSize(2,3);
    return 0;
}
