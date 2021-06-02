//
// Created by bueck on 02.06.2021.
//
#include <stdexcept>
#include "error.h"
void error(std::string message){
    throw std::invalid_argument( message );
}
