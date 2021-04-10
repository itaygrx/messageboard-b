#include <iostream>
#include "Board.hpp"
#include "Direction.hpp"
#include <vector>
#include <stdexcept>
using ariel::Direction;

namespace ariel{

std::string Board::read(unsigned int row , unsigned int col , Direction dir, unsigned int length)
{if (length == 0)
{
    return "" ;
}

    std::cout << "this is read func\n" << std::endl;
std::string s = "example string\n";
return s;}

int Board::post(unsigned int row , unsigned int col , Direction dir, std::string const &message){
    std::cout << "this is post func\n" << std::endl;
return 1;}

void Board::show(){std::cout << "this is the show func\n" << std::endl;}
}

