#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Direction.hpp"
using namespace std;
using ariel::Direction;

namespace ariel{
    class Board{
    
    public  :
        static std::string read(unsigned int row , unsigned int col ,  Direction dir, unsigned int length);
        static int post(unsigned int row , unsigned int col , Direction dir, std::string const &message);
        static void show();
    };
}
