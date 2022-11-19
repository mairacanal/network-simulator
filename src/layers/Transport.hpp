#pragma once

#include <iostream>
#include <vector>

#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"
#include "DataLink.hpp"
#include "Layer.hpp"

class Transport : public Layer {
private:
    static constexpr int ERROR_PROB = 8;

    /**
     * Introduz erros aleatórios a mensagem simulando um meio físico de transmissão
     * @param message Mensagem, em bits, que será enviada no meio físico
     * @return Mensagem com erros aleatórios
     */
    static std::vector<bool> _disturbMessageWithRandonmess(const std::vector<bool>& message);

public:
    /**
     * Transmite a mensagem para a aplicação receptora simulando um meio de
     * transmissão, aplicando erros aleatoriamente em cada bit com uma
     * probabilidade de 8%.
     * @param message Mensagem, em bits, que será enviada no meio físico
     */
    static void send(const std::vector<bool>& message);
};
