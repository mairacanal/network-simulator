#pragma once

#include <iostream>
#include <vector>

#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"
#include "Application.hpp"
#include "DataCheck.hpp"
#include "Layer.hpp"
#include "Transport.hpp"

class DataLink : public Layer {
public:
    /**
     * Faz o envio de um quadro para camada de transporte, aplicando
     * algoritmos de controle de erros no quadro
     * @param frame bitset a ser enviado
     */
    static void send(std::vector<bool> frame);

    /**
     * Recebe um quadro e transmite esse frame para a camada de aplicação
     * @param frame bitset recebido
     */
    static void receive(std::vector<bool> frame);

private:
    /**
     * Altera o quadro adicionando bits para controle de erros
     * @param frame bitset a ser manipulado
     */
    static std::vector<bool> errorHandling(std::vector<bool> frame);

    /**
     * Subrotina de manutencao de integridade com controle de erros com paridade par
     * @param frame bitset a ser manipulado
     */
    static std::vector<bool> evenParityControl(std::vector<bool> frame);

    /**
     * Subrotina de manutencao de integridade com controle de erros com paridade impar
     * @param frame bitset a ser manipulado
     */
    static std::vector<bool> oddParityControl(std::vector<bool> frame);

    /**
     * Subrotina de manutencao de integridade com o algoritmo CRC-32
     * @param frame bitset a ser manipulado
     */
    static std::vector<bool> crc32Control(std::vector<bool> frame);
};
