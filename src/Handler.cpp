#include "Handler.hpp"

void Handler::input()
{   
    char const *linew = "______________________________________________________________________________________________________\n";
    char const *welcome = "████████╗░█████╗░██████╗░  ░██████╗██╗███╗░░░███╗██╗░░░██╗██╗░░░░░░█████╗░████████╗░█████╗░██████╗░\n╚══██╔══╝██╔══██╗██╔══██╗  ██╔════╝██║████╗░████║██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗\n░░░██║░░░██║░░╚═╝██████╔╝  ╚█████╗░██║██╔████╔██║██║░░░██║██║░░░░░███████║░░░██║░░░██║░░██║██████╔╝\n░░░██║░░░██║░░██╗██╔═══╝░  ░╚═══██╗██║██║╚██╔╝██║██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║░░██║██╔══██╗\n░░░██║░░░╚█████╔╝██║░░░░░  ██████╔╝██║██║░╚═╝░██║╚██████╔╝███████╗██║░░██║░░░██║░░░╚█████╔╝██║░░██║\n░░░╚═╝░░░░╚════╝░╚═╝░░░░░  ╚═════╝░╚═╝╚═╝░░░░░╚═╝░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝";
    std::cout << linew << std::endl << ColoredString::green(welcome) << std::endl << linew << std::endl;
    std::string msg {};
    while (true) {
        std::cout << ColoredString::blue("[INPUT] ") << "Digite uma mensagem: ";
        std::getline(std::cin, msg);

        if (msg == "exit") {
            std::cout << ColoredString::green("[EXIT] O terminal será finalizado...") << std::endl;
            break;
        }

        std::cout << std::endl << std::string (msg.length() + 90 , '=') << std::endl << std::endl;

        std::cout  << ColoredString::cyan("[INFO] \t\t\t\t\t") << "Mensagem Enviada: " << msg  << std::endl<< std::endl;
        
        std::cout << std::string (msg.length() + 90, '=') << std::endl << std::endl;
        
        Application::send(msg);
    }
}

void Handler::output(const std::string& msg)
{
    std::cout << ColoredString::blue("[OUTPUT]") << "Mensagem Recebida: \t\t\t\t\t" << msg;
}
