#include <iostream>
using namespace std;
#include <vector>

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
                cout << "My name jeff "<< endl;
            }
        }
};

int main(){
    Map a(2,3);
    //a.setSize(2,3);
    return 0;
}