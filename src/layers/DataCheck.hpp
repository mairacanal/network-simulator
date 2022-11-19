#pragma once

#include <vector>
#include <iostream>
#include "Transport.hpp"
#include "Application.hpp"
#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"

#define HANDLING_ROUTINE 2

class DataCheck{
    private:
        static bool errorTest(std::vector<bool>& frame);
        static bool evenTest(std::vector<bool> frame);
        static bool evenParityTest(std::vector<bool>& frame);
        static bool oddParityTest(std::vector<bool>& frame);
        static bool crc32Test(std::vector<bool>& frame);
};

