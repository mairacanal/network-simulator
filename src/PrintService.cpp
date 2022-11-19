#include "PrintService.hpp"

/**
 * @brief Compara se o index do vector do bit atual esta no valor 16,
 *        se estiver ele ira imprimir uma nova linha
 *
 * @param i Index atual do vector
 */
static void _compare16bits(int &i)
{
    i = (i % 16 == 0) ? 1 : i + 1;
}

/**
 * @brief Envia um endl para o cout
 */
static void _sendNewLine()
{
    std::cout << std::endl;
}

/**
 * @brief Imprime um vetor de bits representando em bytes.
 * 
 * @param bits vector de bits a ser printado
 */
void printAsBytes(std::vector<bool> bits)
{
    _sendNewLine();

}


/**
 * @brief Compara dois vetores de bits e imprime o caractere em vermelho quando os dois forem diferentes.
 *
 * @param og vector de bits original
 * @param comp vector de bits a ser comparado
 */
void printDifference(std::vector<bool> og, std::vector<bool> comp)
{
    _sendNewLine();
    for (int i = 0; i < og.size(); i++)
    {
        std::cout << (og[i] != comp[i]) ? ColoredString::red(std::to_string(og[i])) : std::to_string(og[i]);
        if ((i + 1) % 16 == 0)
            _sendNewLine();
    }
    _sendNewLine();
}
