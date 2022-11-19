#pragma once

#include <iostream>
#include <vector>
#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"

#define HANDLING_ROUTINE 2

/**
 * Classe que reúne os algoritmos para a detecção de erros
 */
class DataCheck {
public:
    /**
     * Rotina principal para detecção de erros, invoca subrotinas
     * para métodos de detecção de erros especificos.
     * @param frame bitset a ser testado
     */
    static bool errorTest(std::vector<bool>& frame);

    /**
     * Testa se o frame possui paridade par ou ímpar.
     * @param frame bitset a ser testado
     */
    static bool evenTest(std::vector<bool> frame);

private:
    /**
     * Subrotina de teste de integridade utilizando paridade par.
     * @param frame bitset a ser testado
     */
    static bool evenParityTest(std::vector<bool>& frame);

    /**
     * Subrotina de teste de integridade utilizando paridade ímpar.
     * @param frame bitset a ser testado
     */
    static bool oddParityTest(std::vector<bool>& frame);

    /**
     * Subrotina de teste de integridade utilizando o polinômio CRC-32.
     * @param frame bitset a ser testado
     */
    static bool crc32Test(std::vector<bool>& frame);
};

