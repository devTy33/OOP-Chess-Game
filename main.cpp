#include <vector>
#include <string>
#include <map>
#include "chess.h"
#include <iostream>
using namespace std;

int main(){
    Board b;
    
    //string cmd;
    int from1, from2, to1, to2;
    int what_player = 1;
    cout << "Welcome To Chess:  <x of piece you want to move> <y of piece you want to move> <x new cell> <y new cell>" << endl;
    cout << endl;
    cout << "Player " << what_player << " turn" << endl << endl;
    b.display();
    while(cin >> from1 >> from2 >> to1 >> to2){
        
        b.move_piece(from1, from2, to1, to2, what_player);
        if(what_player == 1) what_player = 2;
        else{ what_player = 1;}
        cout << "Player " << what_player << " turn" << endl << endl;
        b.display();
    }

}