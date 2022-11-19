#pragma once

#include <iostream>
#include <vector>

#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"
#include "Application.hpp"
#include "Layer.hpp"
#include "Transport.hpp"

#define HANDLING_ROUTINE 2

class DataLink : public Layer {
public:
    /**
     * Faz o envio de um frame(bitset), utilizando algoritmos de alteracao
     * para manutencao da consistencia nele
     * @param frame bitset a ser enviado
     */
    static void send(std::vector<bool> frame);

    /**
     * Recebe um frame(bitset e utiliza algoritmos para checar a consistência dele
     * @param frame bitset recebido
     */
    static void receive(std::vector<bool> frame);

private:
    /**
     * Altera o frame(bitset) para que haja manuntencao de integridade de dados
     * @param frame bitset a ser manipulado
     */
    static std::vector<bool> errorHandling(std::vector<bool> frame);

    /**
     * Subrotina de manutencao de integridade com paridade par
     * @param frame bitset a ser manipulado
     */
    static std::vector<bool> evenParityControl(std::vector<bool> frame);

    /**
     * Subrotina de manutencao de integridade com paridade impar
     * @param frame bitset a ser manipulado
     */
    static std::vector<bool> oddParityControl(std::vector<bool> frame);

    /**
     * Subrotina de manutencao de integridade utilizando polinomios e o
     * algoritmo crc32
     * @param frame bitset a ser manipulado
     */
    static std::vector<bool> crc32Control(std::vector<bool> frame);
};
