#pragma once

#include "../utils/ColoredString.hpp"
#include "../utils/PrintService.hpp"
#include <iostream>
#include <vector>

#define HANDLING_ROUTINE 2

class DataCheck {
public:
    /**
     * Rotina principal para detecção de erros, invoca subrotinas
     * para testes especificos
     * @param frame: bitset a ser testado
     **/
    static bool errorTest(std::vector<bool>& frame);
    /**
     * Testa se o frame possui paridade par ou impar
     * @param frame: bitset a ser testado
     **/
    static bool evenTest(std::vector<bool> frame);

private:
    /**
     * Subrotina de teste de integrigade utilizando paridade par
     * @param frame: bitset a ser testado
     **/
    static bool evenParityTest(std::vector<bool>& frame);
    /**
     * Subrotina de teste de integridade utilizando paridade impar
     * @param frame: bitset a ser testado
     **/
    static bool oddParityTest(std::vector<bool>& frame);
    /**
     * Subrotina de teste de integridade utilizando polinomios e o
     * algoritmo crc32
     * @param frame: bitset a ser testado
     **/
    static bool crc32Test(std::vector<bool>& frame);
};

