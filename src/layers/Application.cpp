#include "Application.hpp"

void Application::send(const std::string& msg)
{
    std::vector<bool> frame {};

    std::cout << ColoredString::magenta("[LAYER] Camada de Aplicação") << std::endl;
    std::cout << ColoredString::cyan("[INFO] ") << "Convertendo para bits:" << std::endl;

    for (auto character : msg)
    {
        std::bitset<8> bits (character);
        for (auto bit : bits.to_string())
            frame.push_back(bit == '1');
    }

    PrintService::printAsBytes(frame);
}

void Application::receive(const std::vector<bool>& bits)
{
    std::string msg {};
    std::bitset<8> bytes {};
    unsigned long character;
    int i = 0;

    std::cout << ColoredString::magenta("[LAYER] Camada de Aplicação") << std::endl;
    std::cout << ColoredString::cyan("[INFO] ") << "Convertendo para ASCII: ";

    for (auto b : bits) {
        bytes[7 - i++ % 8] = b;

        if (i % 8 == 0) {
            character = bytes.to_ulong();
            msg += static_cast<char>(character);
        }
    }

    std::cout << msg << std::endl;
    Handler::output(msg);
}
