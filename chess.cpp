#include <vector>
#include <string>
#include <map>
#include "chess.h"
#include <iostream>
using namespace std;

Piece* contains(int x, int y, map<Piece*, pair<int, int> > board){
    for(auto it = board.begin(); it != board.end(); ++it){
        pair<int, int> position = it->second;
        if(position.first == x && position.second == y){
            return it->first;
        }
    }
    return NULL;

}

Pawn::Pawn(int player){
        this->type = 6;
        this->player = player;
        this->first_move = 1;
}

bool Pawn::move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) {
        //int from_player, to_player;
        Piece* tmp = contains(fromX, fromY, board);
        if(tmp->player == player){                          // can only move your peices 
            Piece* tmp2 = contains(toX, toY, board);
            if(tmp2 != NULL){
                if(tmp2->player == player) return false;    // you are trying to move to a piece that is yours
            }
            if(first_move == 1){
                if(((fromX+1 == toX && fromY == toY) || (fromX+2 == toX && fromY == toY)) || ((fromX-1 == toX && fromY == toY) || (fromX-2 == toX && fromY == toY))) return true;
                first_move = 0;
            }
            else if((fromX + 1 == toX && fromY == toY) || (fromX - 1 == toX && fromY == toY)){
                tmp = contains(toX, toY, board);
                if(tmp != NULL) return false;
                return true;
            }
            else if((fromX+1 == toX && (fromY-1 == toY || fromY+1 == toY)) || (fromX-1 == toX && (fromY-1 == toY || fromY+1 == toY))){
                Piece* p1 = contains(fromX, fromY, board);
                Piece* p2 = contains(toX, toY, board);
                if(p1 != NULL && p2 != NULL){
                    if(p1->player != p2->player) return true;
                
                }

            }
        }
        return false;

}

bool Rook::move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) {

}

Rook::Rook(int player){
    this->type = 5;
    this->player = player;
    this->first_move = 0;
}

bool Knight::move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) {

}
Knight::Knight(int player){
    this->type = 4;
    this->player = player;
    this->first_move = 0;
}

bool Bishop::move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) {

}
Bishop::Bishop(int player){
    this->type = 3;
    this->player = player;
    this->first_move = 0;
}


bool King::move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) {

}
King::King(int player){
    this->type = 2;
    this->player = player;
    this->first_move = 0;
}

bool Queen::move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) {

}
Queen::Queen(int player){
    this->type = 1;
    this->player = player;
    this->first_move = 0;
}


void Board::move_piece(int fromX, int fromY, int toX, int toY, int player){

    for(auto it = board.begin(); it != board.end(); ++it){
        pair<int, int> position = it->second;
        if(position.first == fromX && position.second == fromY){
            
            if(!it->first->move(fromX,fromY,toX, toY, board, player)){
                cout << "invalid move" << endl << endl;
            }
            else{

                it->second.first = toX;
                it->second.second = toY;

            }
        }
    }

    updateBoard();

}

void Board::display(){
    /*
    for(auto it = board.begin(); it != board.end(); it++){
        cout << it->first->type << " " << it->second.first << " " << it->second.second << endl;
    }
    */

    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            int val = b[i][j];

            if(val == 1) cout << "K ";
            else if(val == 2) cout << "Q ";
            else if(val == 3) cout << "B ";
            else if(val == 4) cout << "Kn ";
            else if(val == 5) cout << "R ";
            else if(val == 6) cout << "P ";
            else{
                cout << "- ";
            }
        }
        cout << endl;

    }
}

void Board::updateBoard(){
    b.assign(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));

    for(auto it = board.begin(); it != board.end(); ++it){
        pair<int, int> position = it->second;
        b[position.first][position.second] = it->first->type;       //update the piece location on the board
    }

}


Board::Board(){
    
    for (int col = 0; col < BOARD_SIZE; ++col) {
        board[new Pawn(1)] = make_pair(1, col); // Player 1's Pawns
        board[new Pawn(2)] = make_pair(6, col); // Player 2's Pawns
    }
    board[new Rook(1)] = make_pair(0, 0); // Player 1's Rook
    board[new Rook(1)] = make_pair(0, 7); // Player 1's Rook
    board[new Rook(2)] = make_pair(7, 0); // Player 2's Rook
    board[new Rook(2)] = make_pair(7, 7); // Player 2's Rook

    board[new Knight(1)] = make_pair(0, 1);
    board[new Bishop(1)] = make_pair(0, 2);
    board[new Queen(1)] = make_pair(0, 3);
    board[new King(1)] = make_pair(0, 4);
    board[new Bishop(1)] = make_pair(0, 5);
    board[new Knight(1)] = make_pair(0, 6);

    board[new Knight(2)] = make_pair(7, 1);
    board[new Bishop(2)] = make_pair(7, 2);
    board[new Queen(2)] = make_pair(7, 3);
    board[new King(2)] = make_pair(7, 4);
    board[new Bishop(2)] = make_pair(7, 5);
    board[new Knight(2)] = make_pair(7, 6);
    updateBoard();

}


