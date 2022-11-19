#pragma once

#include <iostream>
#include <string>

#include "utils/ColoredString.hpp"
#include "layers/Application.hpp"

class Handler {

    public:
        /**
         * @brief Gera um loop que mantém-se constantemente enquanto é responsável por receber a mensagem e passar esta adiante
         *
        */
        static void input();

        /**
         * @brief Recebe a mensagem de saída e exibe no console
         * @param msg Mensagem de saída
        */
        static void output(const std::string& msg);
};