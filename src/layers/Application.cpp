#include "Application.hpp"

void Application::send(const std::string& msg)
{
    std::vector<bool> frame {};

    std::cout << ColoredString::magenta("[LAYER] Camada de Aplicação") << std::endl;
    std::cout << ColoredString::cyan("[INFO]") << "Convertendo para bits:" << std::endl;

    for (auto character : msg)
    {
        std::bitset<8> bit (character);
        std::cout << bit.to_string() << std::endl;
    }
}

void Application::receive(const std::vector<bool>& bits)
{

}