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

std::vector<bool> DataLink::errorHandling(std::vector<bool> frame){
    std::cout << ColoredString::cyan("[INFO]") + "Iniciando tratamento de inconsistencias" << std::endl;
    switch(HANDLING_ROUTINE){
        case 0:
                std::cout << ColoredString::cyan("[INFO]") + "Com paridade par" << std::endl;
                return evenParityControl(frame);
        case 1:
                std::cout << ColoredString::cyan("[INFO]") + "Com paridade impar" << std::endl;
                return oddParityControl(frame);
        default:
                std::cout << ColoredString::cyan("[INFO]") + "Utilizando polinomios" << std::endl;
                return crc32Control(frame);
    }
}


std::vector<bool> DataLink::evenParityControl(std::vector<bool> frame){
    frame.insert(frame.begin(), DataCheck::evenTest(frame));
    return frame;
}

std::vector<bool> DataLink::oddParityControl(std::vector<bool> frame){
    frame.insert(frame.begin(), !DataCheck::evenTest(frame));
    return frame;
}

std::vector<bool> DataLink::crc32Control(std::vector<bool> frame){
        std::cout << ColoredString::cyan("[INFO]") + "Polinômio:" << std::endl;

    std::vector<bool> polinomio{
                                1, 0, 0, 0, 0, 0, 1, 0,
                                0, 1, 1, 0, 0, 0, 0, 0,
                                1, 0, 0, 0, 1, 1, 1, 0,
                                1, 1, 0, 1, 1, 0, 1, 1,
                                1};

    std::cout << std::endl;
    bool firstTerm = true;
    for (int i = 0; i < polinomio.size(); i++) {
        if (polinomio[i]) if (firstTerm) std::cout << "x^" << polinomio.size() - 1 - i << " ";
        else std::cout << "+x^" << polinomio.size() - 1 - i << " ";
    }

    std::cout << std::endl;

    std::vector<bool> remaining = frame;
    remaining.resize(remaining.size() + 32);  
       for (int i = 0; i < remaining.size() - 32; i++) {
        if (remaining[i]) {
            for (int j = 0; j < polinomio.size(); j++) {
                remaining[i + j] = remaining[i + j] ^ polinomio[j];
            }
        }
        remaining[i] = frame[i];      
       }

    frame = remaining;

    std::cout << ColoredString::cyan("[INFO]") + "Frame e resto:" << std::endl;
    PrintService::printAsBytes(frame);

    return frame;
}
