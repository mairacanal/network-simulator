#include "DataLink.hpp"
#include "DataCheck.hpp"

void DataLink::send(std::vector<bool> frame){
    std::cout << ColoredString::magenta("[LAYER]") + "Camada de Enlace:" << std::endl;
    frame = errorHandling(frame);
    Transport::send(frame);
}

void DataLink::receive(std::vector<bool> frame){
    std::cout << ColoredString::magenta("[LAYER]") + "Camada de Enlace:" << std::endl;
    if(DataCheck::errorTest(frame)) std::cout << ColoredString::red("[ERROR]") + "Erro nos dados recebidos" << std::endl;
    std::cout << ColoredString::cyan("[INFO]") + "Binário recebido:" << std::endl;
    PrintService::printAsBytes(frame);
    Application::receive(frame);
}

    
