#pragma once

#include <vector>
#include <iostream>
#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"

#define HANDLING_ROUTINE 2

class DataCheck{
    public:
        static bool errorTest(std::vector<bool>& frame);
        static bool evenTest(std::vector<bool> frame);
    private:
        static bool evenParityTest(std::vector<bool>& frame);
        static bool oddParityTest(std::vector<bool>& frame);
        static bool crc32Test(std::vector<bool>& frame);
};

