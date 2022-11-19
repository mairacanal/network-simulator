#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "ColoredString.hpp"

/**
 * @brief Imprime um vetor de bits representando em bytes.
 * 
 * @param bits vector de bits a ser printado
 */
void printAsBytes(std::vector<bool> bits);

/**
 * @brief Imprime um vetor de bits como uma stream
 * 
 * @param bits vector de bits a ser printado
 */
void printAsStream(std::vector<bool> bits);

/**
 * @brief Compara dois vetores de bits e imprime o caractere em vermelho quando os dois forem diferentes.
 * 
 * @param og vector de bits original
 * @param comp vector de bits a ser comparado
 */
void printDifference(std::vector<bool> og, std::vector<bool> comp);