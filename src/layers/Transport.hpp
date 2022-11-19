#pragma once
#include <vector>
#include <iostream>

#include "Layer.hpp"
#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"

#define ERROR_PROB 10
class Transport : public Layer
{
public:
    static void send(std::vector<bool> message);
};