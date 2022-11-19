#pragma once

#include <bitset>
#include <iostream>
#include <string>
#include <vector>

#include "../utils/ColoredString.hpp"
#include "Layer.hpp"

class Application : public Layer {

    public:

    static void send(const std::string& msg);

    static void receive(const std::vector<bool>& bytes);

};
