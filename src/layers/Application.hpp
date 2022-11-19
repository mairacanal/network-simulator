#pragma once

#include <bitset>
#include <iostream>
#include <string>
#include <vector>

#include "../Handler.hpp"
#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"
#include "DataLink.hpp"
#include "Layer.hpp"

class Application : public Layer {

public:
    /**
     * @brief Realiza a conversão da mensagem recebida para bits salvando em
     * std::vector<bool>, que é uma especialização do std::vector que permite
     * trabalhar diretamente com bits.
     * @param msg Mensagem a ser convertida
     */
    static void send(const std::string& msg);

    /**
     * @brief Transforma o vetor de bits em uma mensagem ASCII
     * @param bytes Vetor de byte à ser convertido
     */
    static void receive(const std::vector<bool>& bytes);
};
