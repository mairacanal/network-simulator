#pragma once
#include "Layer.hpp"
#include "iostream"
#include "../ColoredString.hpp"
#include <vector>


#define ERROR_PROB 5

class Transport : public Layer{
    public:
        static void send(std::vector<bool> msgFrame);
};