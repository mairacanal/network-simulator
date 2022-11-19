#include "Handler.hpp"

void Handler::input()
{   
    PrintService::welcomeScreen();

    std::string msg {};
    while (true) {
        std::cout << ColoredString::blue("[INPUT] ") << "Digite uma mensagem: ";
        std::getline(std::cin, msg);

        if (msg == "exit") {
            std::cout << ColoredString::green("[EXIT] O terminal será finalizado...") << std::endl;
            break;
        }

        std::cout << std::endl << std::string (120 , '=') << std::endl << std::endl;

        std::cout  << ColoredString::cyan("[INFO] \t\t\t\t\t") << "Mensagem Enviada: " << msg  << std::endl<< std::endl;
        
        std::cout << std::string (120, '=') << std::endl << std::endl;
        
        Application::send(msg);
    }
}

void Handler::output(const std::string& msg)
{
    std::cout << ColoredString::blue("[OUTPUT] ") << "Mensagem Recebida: " << msg << std::endl;
}
