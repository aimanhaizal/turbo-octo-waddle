#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //for time() in srand( time(NULL) );
#include <windows.h> //for Sleep()
using namespace std;

class Mars{
    private:
        vector < vector<char> > map;
        int dimX, dimY;

    public:
        Mars(){
            init();
        }
        
        void init();
        void display();
        int getDimX();
        int getDimY();
        char getObject(int x, int y);
        void setObject(int x, int y, char z);
        bool isEmpty(int x, int y);
        bool isInsideMap(int x, int y);
};

void Mars::init(){
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'X', '#', '@', '$'};
    int noOfObjects = 10; //number of objects in the objects array

    dimX = 15;
    dimY = 5;

    //create dynamic 2D array using vector
    map.resize(dimY); //create rows
    for (int i=0; i<dimY; ++i){
        map[i].resize(dimX); //resize each rows
    }
    //put random chars into the vector array
    for (int i=0; i<dimY; ++i){
        for (int j=0; j<dimX; ++j){
            int objNo = rand() % noOfObjects;
            map[i][j] = objects[ objNo ];
        }
    }
}
        
void Mars::display(){
    system("cls");
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " = Curiosity, welcome to Mars! =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    for (int i=0; i<dimY; ++i){
        cout << "  ";
        for (int j=0; j<dimX; ++j){
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(2) << (dimY-i);
        for (int j=0; j<dimX; ++j){
            cout << "|" << map[i][j];
        }
        cout << "|" << endl;
    }

    cout << "  ";
    for (int j=0; j<dimX; ++j) {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << "  ";
    for (int j=0; j<dimX; ++j){
        int digit = (j+1)/10;
        cout << " ";
        if (digit==0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;

    cout << "  ";
    for (int j=0; j<dimX; ++j){
        cout << " " << (j+1)%10;
    }
    cout << endl << endl;
}

void test1(){
    Mars mars;
    mars.display();
}
//---------------------------------------------------------------
int Mars::getDimX(){return dimX;}
int Mars::getDimY(){return dimY;}

void test2()
{
    Mars mars;
    mars.display();
    cout << "Dim X = " << mars.getDimX() << endl;
    cout << "Dim Y = " << mars.getDimY() << endl;
} 
//---------------------------------------------------------------
char Mars::getObject(int x, int y){
    if(y == 1){y = 4;}
    else if(y == 2){y = 3;}
    else if(y == 3){y = 2;}
    else if(y == 4){y = 1;}
    else if(y == 5){y = 0;}
    return map[y][x - 1];
}

void test3()
{
    Mars mars;
    mars.display();
    int x,y;
    char obj;
    x = 1; y = 1;
    obj = mars.getObject(x,y);
    cout << "Object at column " << x << " and row " << y << " is ["
    << obj << "]" << endl;
    x = 15; y = 5;
    obj = mars.getObject(x,y);
    cout << "Object at column " << x << " and row " << y << " is ["
    << obj << "]" << endl;
    x = 5; y = 2;
    obj = mars.getObject(x,y);
    cout << "Object at column " << x << " and row " << y << " is ["
    << obj << "]" << endl;
    x = 10; y = 4;
    obj = mars.getObject(x,y);
    cout << "Object at column " << x << " and row " << y << " is ["
    << obj << "]" << endl;
} 
//---------------------------------------------------------------
void Mars::setObject(int x, int y, char z){
    if(y == 1){y = 4;}
    else if(y == 2){y = 3;}
    else if(y == 3){y = 2;}
    else if(y == 4){y = 1;}
    else if(y == 5){y = 0;}
    map[y][x - 1] = z;
}

void test4(){
    Mars mars;
    mars.setObject( 1, 1, 'A');
    mars.setObject(15, 1, 'B');
    mars.setObject(15, 5, 'C');
    mars.setObject( 1, 5, 'D');
    mars.display();
    cout << "The object A should be at column 1 and row 1" << endl;
    cout << "The object B should be at column 15 and row 1" << endl;
    cout << "The object C should be at column 15 and row 5" << endl;
    cout << "The object D should be at column 1 and row 5" << endl;
}
//---------------------------------------------------------------
bool Mars::isEmpty(int x, int y){
    if(y == 1){y = 4;}
    else if(y == 2){y = 3;}
    else if(y == 3){y = 2;}
    else if(y == 4){y = 1;}
    else if(y == 5){y = 0;}
    if(map[y][x - 1] == ' '){
        return true;
    }
    else{
        return false;
    }
}

bool Mars::isInsideMap(int x, int y){
    if(x > dimX || x < 1 || y > dimY || y < 1){
        return false;
    }
    else{
        return true;
    }
}

void test5(){
    Mars mars;
    mars.setObject( 2, 4, 'Z');
    mars.setObject( 10, 3, ' ');
    mars.display();

    cout << "Coordinate (2,4) is ";
    if ( mars.isEmpty(2,4) )
    cout << "empty.";
    else
    cout << "Not empty.";
    cout << endl;
    cout << "Coordinate (10,3) is ";
    if ( mars.isEmpty(10,3) )
    cout << "empty.";
    else
    cout << "not empty.";
    cout << endl;
    cout << "Coordinate (15,5) is ";
    if ( mars.isInsideMap(15,5) )
    cout << "inside map.";
    else
    cout << "not inside map.";
    cout << endl;
    cout << "Coordinate (0,0) is ";
    if ( mars.isInsideMap(0,0) )
    cout << "inside map.";
    else
    cout << "not inside map.";
    cout << endl;
} 
//---------------------------------------------------------------
class Rover{
    private:
        int x,y;
        char heading;

    public:
        Rover(){}
        void land(Mars& mars);
        void turnLeft(Mars& mars);
        void turnRight(Mars& mars);
        void move(Mars& mars);
};

void Rover::land(Mars& mars){
    char possibleHeading[] = {'^', '>', '<', 'v'};
    x = rand() % mars.getDimX() + 1;
    y = rand() % mars.getDimY() + 1;
    heading = possibleHeading[ rand() % 4 ];
    mars.setObject(x,y,heading);
} 

void test6(){
    Mars mars;
    Rover curiosity;
    curiosity.land(mars);
    mars.display();
}
//-------------------------------------------------
void Rover::turnLeft(Mars& mars){
    if(mars.getObject(x, y) == '>'){
        mars.setObject(x,y,'^');
        heading = '^';
    }
    else if(mars.getObject(x, y) == 'v'){
        mars.setObject(x,y,'>');
        heading = '>';
    }
    else if(mars.getObject(x, y) == '<'){
        mars.setObject(x,y,'v');
        heading = 'v';
    }
    else if(mars.getObject(x, y) == '^'){
        mars.setObject(x,y,'<');
        heading = '<';
    }
}

void Rover::turnRight(Mars& mars){
    if(mars.getObject(x, y) == '>'){
        mars.setObject(x,y,'v');
        heading = 'v';
    }
    else if(mars.getObject(x, y) == 'v'){
        mars.setObject(x,y,'<');
        heading = '<';
    }
    else if(mars.getObject(x, y) == '<'){
        mars.setObject(x,y,'^');
        heading = '^';
    }
    else if(mars.getObject(x, y) == '^'){
        mars.setObject(x,y,'>');
        heading = '>';
    }
}

void Rover::move(Mars& mars){
    mars.setObject(x,y,' ');
    if(heading == '>' && x+1 < mars.getDimX()){
        mars.setObject(x+1,y,heading);
        x++;
    }
    else if(heading == 'v' && y-1 > 0){ 
        mars.setObject(x,y-1,heading);
        y--;
    }
    else if(heading == '<'&& x-1 > 0){
        mars.setObject(x-1,y,heading);
        x--;
    }
    else if(heading == '^'&& y+1 < mars.getDimY()){ 
        mars.setObject(x,y+1,heading);
        y++;
    }
    else
        mars.setObject(x,y,heading);
}

// void test7(){
//     Mars mars;
//     Rover curiosity;
//     curiosity.land(mars);
//     mars.display();
//     system("pause"); 
//     curiosity.turnLeft(mars);
//     mars.display();
//     system("pause");
//     curiosity.move(mars);
//     mars.display(); 
//     system("pause");
//     curiosity.move(mars);
//     mars.display();
//     system("pause");
//     curiosity.turnRight(mars);
//     mars.display();
//     system("pause");
//     curiosity.move(mars);
//     mars.display();
//     system("pause");
// }

void executeInstruction(Mars& mars, Rover& rover) {
    int maxcommand = 10;    
    char command[maxcommand];
    mars.display();
    cout << "Example Sequence: MMLMMMRMMRMRMLLL" << endl
         << "Your command is up to " << maxcommand << endl
         << "Enter command sequence => "; 
    cin >> command;
    cout << endl;
    for (int i=0; i < maxcommand ;i++){
        
        if (command[i] == 'M' || command[i] == 'm'){
            rover.move(mars);
        }
        else if (command[i] == 'L' || command[i] == 'l'){
            rover.turnLeft(mars);
        }
        else if (command[i] == 'R' || command[i] == 'r'){
            rover.turnRight(mars);
        }
        else if (command[i] == 'Q' || command[i] == 'q'){
            cout << "QUITTED!! Mission FAILED!!" << endl;
            exit(EXIT_FAILURE); // stop the program
        }
        mars.display();

    }
}

int main()
{
    srand( time(NULL) );    // is the one which makes it random
    //srand( 1 );           // makes it not random

    Mars mars;
    Rover rover;

    rover.land(mars);

    int count = 0;
    while(count < 3) {
        executeInstruction(mars, rover);
        count++;
    }

    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
}
//  put the randomized map from test 1 into test 7 // step 1 done
//  expand its movement to accept character lines // step 2 done
//  fix the spawn since you can spawn inside items
//  need to add collision to the rover with items that spawn
//  fix the user interface (score and such)
//  add fog to the map