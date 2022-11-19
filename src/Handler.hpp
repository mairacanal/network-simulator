#pragma once

#include <iostream>
#include <string>

#include "ColoredString.hpp"
#include "layers/Application.hpp"

class Handler {

    public:

        static void input();

        static void output(const std::string& msg);
};