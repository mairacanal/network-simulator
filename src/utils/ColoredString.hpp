#pragma once

#include <string>


/**
 * @brief Esstiliza o texto recebido de maneira a deixa-lo colorido no terminal, a depender do método invocado tem-se uma cor diferente.
 * @param str String a ser recebida para estilização
*/
class ColoredString {

public:
    static std::string red(const std::string& str)
    {
        return std::string { "\033[1m\033[31m" + str + "\033[0m" };
    }
    static std::string green(const std::string& str)
    {
        return std::string { "\033[1m\033[32m" + str + "\033[0m" };
    }

    static std::string blue(const std::string& str)
    {
        return std::string { "\033[1m\033[34m" + str + "\033[0m" };
    }

    static std::string magenta(const std::string& str)
    {
        return std::string { "\033[1m\033[35m" + str + "\033[0m" };
    }

    static std::string cyan(const std::string& str)
    {
        return std::string { "\033[1m\033[36m" + str + "\033[0m" };
    }
};
