#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using ariel::Direction;
using namespace std;
using namespace ariel;


ariel::Board board;


TEST_CASE("good case"){

    unsigned int row = std::rand()%500;
    unsigned int col = std::rand()%500;
    unsigned int x = std::rand()%30;
    Direction dir = Direction::Vertical;
    
    CHECK(board.post(row,col,dir,"Vertical check")==1); // Check post in Vertical Direction
    CHECK(board.read(row,col,dir,x).compare("example string\n") == 0); // Check String after post in Vertical direction

    dir = Direction::Horizontal;

    CHECK(board.post(row,col,dir,"Horizontal check")==1); // Check post in Horizntal Direction
    CHECK(board.read(row,col,dir,x).compare("example string\n") == 0); // Check String after post in Horizontal direction

    CHECK(board.post(row,col,dir,"nottry") == 1);
    CHECK(board.read(row,col,dir,6).compare("tryout")==-1); // Check if string is not the same.
    CHECK(board.read(row,col,dir,6).compare("nottry")==-1); // Check if string the same.
    CHECK(board.post(row,col,dir,"tryout") == 1); //posting on another msg.
    CHECK(board.read(row,col,dir,6).compare("tryout")==-1); // Checks String after posting on another msg.

    dir = Direction::Vertical; // same tests on vertical direction 

    CHECK(board.post(row,col,dir,"nottry2") == 1);
    CHECK(board.read(row,col,dir,7).compare("tryout2")==-1); // Check if string is not the same.
    CHECK(board.read(row,col,dir,7).compare("nottry2")==-1); // Check if string the same.
    CHECK(board.post(row,col,dir,"tryout2") == 1); //posting on another msg.
    CHECK(board.read(row,col,dir,7).compare("tryout2")==-1); // Checks String after posting on another msg.

    CHECK(board.read(row,col,dir,230).compare("tryout2")==-1); // trying to read a string longer than possible
    CHECK(board.read(300,400,dir,10).compare("tryout2")==-1); // trying to read string outside of current messageboard frame

    CHECK(board.post(300,400,dir,"230") == 1);// trying to post string outside of current messageboard frame
    CHECK(board.post(row,col,dir,"230") == 1);// trying to post a string 

    dir = Direction::Vertical; // same tests on vertical direction 

     CHECK(board.read(row,col,dir,230).compare("tryout2")==-1); // trying to read a string longer than possible
    CHECK(board.read(300,400,dir,10).compare("tryout2")==-1); // trying to read string outside of current messageboard frame
}