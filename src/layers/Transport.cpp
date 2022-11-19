#include "Transport.hpp"

std::vector<bool> _disturbMessageWithRandonmess(std::vector<bool> &message)
{
    std::vector<bool> auxilaryVec;
    for (bool bit : message)
        auxilaryVec.push_back(((std::rand() % 100) <= ERROR_PROB) ? !bit : bit);

    return auxilaryVec;
}

void Transport::send(std::vector<bool> message)
{
    std::cout << std::endl;
    std::cout << ColoredString::magenta("[LAYER] ") << "Camada do meio de comunicação:" << std::endl;
    std::cout << ColoredString::blue("[INFO] ") << "Binário enviado: " << std::endl;

    // Mostra os bits que foram enviados
    PrintService::printAsStream(message);

    std::vector<bool> finalMessage = _disturbMessageWithRandonmess(message);

    std::cout << ColoredString::blue("[INFO] ") << "Recebimento: " << std::endl;
    std::cout << ColoredString::blue("[INFO] ") << "Binário recebido: " << std::endl;

    PrintService::printAsStream(finalMessage);

    std::cout << ColoredString::blue("[INFO] ") << "Diferenças: " << std::endl;

    PrintService::printDifference(message, finalMessage);

    // DataLink::receive(finalMessage);
}