#include "Handler.hpp"

void Handler::input()
{
    std::string msg {};
    
    while (true) {
        std::cout << ColoredString::blue("[INPUT] ") << "Digite uma mensagem: ";
        std::getline(std::cin, msg);

        if (msg == "exit") {
            std::cout <<  ColoredString::blue("[INPUT] ") << ColoredString::green("O terminal será finalizado...") << std::endl;
            break;
        }

        std::cout << std::string (msg.length() + 30 , '=') << std::endl << std::endl;

        std::cout << ColoredString::cyan("[INFO] ") << "Mensagem Enviada: " << msg  << std::endl<< std::endl;
        
        std::cout << std::string (msg.length() + 30, '=') << std::endl << std::endl;
        
        Application::send(msg);
    }
}

void Handler::output(const std::string& msg)
{
    std::cout << ColoredString::blue("[OUTPUT]") << "Mensagem Recebida: " << msg;
}