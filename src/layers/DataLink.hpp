#pragma once

#include <vector>
#include <iostream>
#include "Layer.hpp"
#include "Transport.hpp"
#include "Application.hpp"
#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"

class DataLink:public Layer{
    public:
        static void send(std::vector<bool> frame);
        static void receive(std::vector<bool> frame);
    private:
        static std::vector<bool> errorHandling(std::vector<bool> frame);
        static std::vector<bool> evenParityControl(std::vector<bool> frame);
        static std::vector<bool> oddParityControl(std::vector<bool> frame);
        static std::vector<bool> crc32Control(std::vector<bool> frame);
};
