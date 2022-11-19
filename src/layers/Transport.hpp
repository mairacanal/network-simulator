#pragma once

#include <iostream>
#include <vector>

#include "DataLink.hpp"
#include "Layer.hpp"
#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"

class Transport : public Layer {
private:
    static constexpr int ERROR_PROB = 10;
    static std::vector<bool> _disturbMessageWithRandonmess(const std::vector<bool>& message);

public:
    static void send(std::vector<bool> message);
};
