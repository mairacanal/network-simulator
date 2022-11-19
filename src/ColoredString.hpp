#pragma once

#include <string>

class ColoredString {

    static std::string red(const std::string& str)
    {
        return std::string { "\033[1m\033[31m" + str + "\033[0m" };
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
