#include <vector>
#include <string>
#include <map>
using namespace std;

class Piece{
    public:
        virtual ~Piece() {};
        int type;
        int player;
        int first_move;
        virtual bool move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) = 0;
};


class Board{

    public:
        Board();
        void display();
        void updateBoard();
        void move_piece(int fromX, int fromY, int toX, int toY, int player);
        map<Piece*, std::pair<int, int> > board;
        
    private:
        static const int BOARD_SIZE = 8;
        vector<vector<int> > b;
        //vector<vector<Piece*>> board;
        
};



class Pawn : public Piece {
    public:
    Pawn(int player);
    bool move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) override;

};



class Rook : public Piece {
    public:
    Rook(int player);
    bool move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) override;

};



class Knight : public Piece {
    public:
    Knight(int player);
    bool move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) override; 
};



class Bishop : public Piece {
    public:
    Bishop(int player);
    bool move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) override;
        
};



class King : public Piece {
    public:
    King(int player);
    bool move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) override;

};



class Queen : public Piece {
    public:
    Queen(int player);
    bool move(int fromX, int fromY, int toX, int toY, map<Piece*, pair<int, int> >& board, int player) override;

};





