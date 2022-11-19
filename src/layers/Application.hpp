#pragma once

#include <bitset>
#include <iostream>
#include <string>
#include <vector>

#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"
#include "../Handler.hpp"
#include "Layer.hpp"

class Application : public Layer {

    public:

    /**
     * @brief Realiza a conversão da mensagem recebida para bits salvando em um bitset (ao qual utilizamos um vetor de booleano)
     * @param msg Mensagem a ser convertida
    */
    static void send(const std::string& msg);


    /**
     * @brief Decompoẽ o vetor de bits para mensagem
     * @param bytes Vetor de byte à ser convertido
    */
    static void receive(const std::vector<bool>& bytes);

};
