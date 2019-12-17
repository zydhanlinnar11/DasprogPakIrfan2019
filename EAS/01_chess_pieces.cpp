#include <iostream>
#include <cmath>

using namespace std;

class Piece {
protected:
    int faction; //faction is 1 for white and -1 for black
    int x; int y;
    char * name;
public:
    void getLocation() {
        cout << name << " is at x: " << x << " y: " << y << endl;
    }
    bool moveCondition (int x_dest, int y_dest);
    void move(int x_dest, int y_dest);
};

class Pawn : public Piece {
public:
    Pawn (int f) { //constructor is not inherited
        name = "Pawn";
        faction = f;
        x = 0;
        y = 0;  
    }
    bool moveCondition(int x_dest, int y_dest) {
        return ((x_dest == x) && ((y_dest - y)==faction));
    }
    void move(int x_dest, int y_dest) {
        if (moveCondition (x_dest, y_dest)) {
            x = x_dest;
            y = y_dest;
            getLocation();
        } else {
            cout << "invalid move" << endl;
        }
    }
};

class Rook : public Piece {
public:
    Rook (int f) { //constructor is not inherited
        name = "Rook";
        faction = f;
        x = 0;
        y = 0;  
    }
    bool moveCondition(int x_dest, int y_dest) {
        return ((x_dest != x) ^ (y_dest != y));
    }
    void move(int x_dest, int y_dest) {
        if (moveCondition (x_dest, y_dest)) {
            x = x_dest;
            y = y_dest;
            getLocation();
        } else {
            cout << "invalid move" << endl;
        }
    }
};

class Bishop : public Piece {
public:
    Bishop (int f) { //constructor is not inherited
        name = "Bishop";
        faction = f;
        x = 0;
        y = 0;  
    }
    bool moveCondition(int x_dest, int y_dest) {
        return (((x_dest - x) == (y_dest - y)) && (y_dest - y != 0) && (x_dest - x != 0));
    }
    void move(int x_dest, int y_dest) {
        if (moveCondition (x_dest, y_dest)) {
            x = x_dest;
            y = y_dest;
            getLocation();
        } else {
            cout << "invalid move" << endl;
        }
    }
};

class Knight : public Piece {
public:
    Knight (int f) { //constructor is not inherited
        name = "Knight";
        faction = f;
        x = 0;
        y = 0;  
    }
    bool moveCondition(int x_dest, int y_dest) {
        return ((abs(x_dest - x) == 2) && (abs(y_dest - y) == 1 ) ||
               (abs(x_dest - x) == 1) && (abs(y_dest - y) == 2 ));
    }
    void move(int x_dest, int y_dest) {
        if (moveCondition (x_dest, y_dest)) {
            x = x_dest;
            y = y_dest;
            getLocation();
        } else {
            cout << "invalid move" << endl;
        }
    }
};

class Queen : public Piece {
public:
    Queen (int f) { //constructor is not inherited
        name = "Queen";
        faction = f;
        x = 0;
        y = 0;  
    }
    bool moveCondition(int x_dest, int y_dest) {
        return ((abs(x_dest - x) == abs(y_dest - y)) && ((y_dest - y != 0) &&
               (x_dest - x != 0)) || ((x_dest != x) ^ (y_dest != y)));
    }
    void move(int x_dest, int y_dest) {
        if (moveCondition (x_dest, y_dest)) {
            x = x_dest;
            y = y_dest;
            getLocation();
        } else {
            cout << "invalid move" << endl;
        }
    }
};

int main() {
    Pawn WhitePawn(1), BlackPawn(-1);
    Rook WhiteRook(1), BlackRook(-1);
    Bishop WhiteBishop(1), BlackBishop(-1);
    Knight WhiteKnight(1), BlackKnight(-1);
    Queen WhiteQueen(1), BlackQueen(-1);

    // Get Location of White Pawn and move to valid destination
    cout<<"White ";
    WhitePawn.getLocation();
    cout<<"Attempting to move White Pawn to 0,1"<<endl;
    WhitePawn.move(0,1);
    cout<<"White ";
    WhitePawn.getLocation();
    cout<<endl;
    // Get Location of Black Pawn and move to invalid destination
    cout<<"Black ";
    BlackPawn.getLocation();
    cout<<"Attempting to move Black Pawn to 1,1"<<endl;
    BlackPawn.move(1,1);
    cout<<endl;

    // Get Location of White Rook and move to valid destination
    cout<<"White ";
    WhiteRook.getLocation();
    cout<<"Attempting to move White Rook to 0,6"<<endl;
    WhiteRook.move(0,6);
    cout<<"White ";
    WhiteRook.getLocation();
    cout<<endl;
    // Get Location of Black Rook and move to invalid destination
    cout<<"Black ";
    BlackRook.getLocation();
    cout<<"Attempting to move Black Rook to 1,1"<<endl;
    BlackRook.move(1,1);
    cout<<endl;

    // Get Location of White Bishop and move to valid destination
    cout<<"White ";
    WhiteBishop.getLocation();
    cout<<"Attempting to move White Bishop to 6,6"<<endl;
    WhiteBishop.move(6,6);
    cout<<"White ";
    WhiteBishop.getLocation();
    cout<<endl;
    // Get Location of Black Bishop and move to invalid destination
    cout<<"Black ";
    BlackBishop.getLocation();
    cout<<"Attempting to move Black Bishop to 1,6"<<endl;
    BlackBishop.move(1,6);
    cout<<endl;

    // Get Location of White Knight and move to valid destination
    cout<<"White ";
    WhiteKnight.getLocation();
    cout<<"Attempting to move White Knight to 2,1"<<endl;
    WhiteKnight.move(2,1);
    cout<<"White ";
    WhiteKnight.getLocation();
    cout<<endl;
    // Get Location of Black Knight and move to invalid destination
    cout<<"Black ";
    BlackKnight.getLocation();
    cout<<"Attempting to move Black Knight to 6,6"<<endl;
    BlackKnight.move(6,6);
    cout<<endl;

    // Get Location of White Queen and move to invalid destination
    cout<<"White ";
    WhiteQueen.getLocation();
    cout<<"Attempting to move White Queen to 2,1"<<endl;
    WhiteQueen.move(2,1);
    cout<<endl;
    // Get Location of Black Queen and move to valid destination
    cout<<"Black ";
    BlackQueen.getLocation();
    cout<<"Attempting to move Black Queen to 6,6"<<endl;
    BlackQueen.move(6,6);
    cout<<"Black ";
    WhiteQueen.getLocation();
    cout<<endl;

    return 0;
}