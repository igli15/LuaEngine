//
// Created by Igli milaqi on 14/10/2018.
//

#include <cstdlib>
#include <iostream>
#include "Utils.h"


int Engine::Utils::RandomRange(int min, int max)
{
    if(min > max)
    {
        std::cout<<"Your min value is bigger then max!!!"<<std::endl;
        throw;
    }
    int random = rand() % (max - min + 1) + min;
    if(random == 0 ) random = min;
    return random;
}
