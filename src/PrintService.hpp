#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "ColoredString.hpp"

class PrintService
{
private:
    static void _compareNBits(int &i, int size) { i = (i % size == 0) ? 1 : i + 1; }
    static void _sendNewLine() { std::cout << std::endl; }
    static void _sendSpace() { std::cout << " "; }

public:
    PrintService();
    ~PrintService();

    /**
     * @brief Imprime um vetor de bits como uma stream
     *
     * @param bits vector de bits a ser printado
     */
    static void printAsStream(std::vector<bool> bits)
    {
        _sendNewLine();
        int i = 1, j = 1;
        for (bool bit : bits)
        {
            std::cout << bit;

            _compareNBits(j, 8);

            if (j == 1)
                _sendSpace();

            _compareNBits(i, 32);
            if (i == 1)
                _sendNewLine();
        }

        _sendNewLine();
        _sendNewLine();
    }

    /**
     * @brief Compara dois vetores de bits e imprime o caractere em vermelho quando os dois forem diferentes.
     *
     * @param og vector de bits original
     * @param comp vector de bits a ser comparado
     */
    static void printDifference(const std::vector<bool> &og, const std::vector<bool> &comp)
    {
        _sendNewLine();

        for (int i = 0, j = 0; i < og.size(); i++, j++)
        {
            std::cout << ((og[i] != comp[i])
                              ? ColoredString::red(std::to_string(og[i]))
                              : std::to_string(og[i]));

            // Um espaco a cada 8 bits
            if ((j + 1) % 8 == 0)
                _sendSpace();

            // Uma nova linha a cada 32 bits
            if ((i + 1) % 32 == 0)
                _sendNewLine();
        }

        _sendNewLine();
        _sendNewLine();
    }
};