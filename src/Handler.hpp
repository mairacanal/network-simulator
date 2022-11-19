#pragma once

#include <iostream>
#include <string>

#include "utils/ColoredString.hpp"
#include "layers/Application.hpp"

class Handler {

    public:

        static void input();

        static void output(const std::string& msg);
};