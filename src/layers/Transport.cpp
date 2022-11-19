#include "Transport.hpp"

/**
 * @brief Perturba a mensagem e cria um novo vetor.
 * 
 * @param message mensagem original.
 * @return std::vector<bool> mensagem com erros.
 */
std::vector<bool> _disturbMessageWithRandonmess(std::vector<bool> &message)
{
    std::vector<bool> auxilaryVec;
    for (bool bit : message)
        auxilaryVec.push_back(((std::rand() % 100) <= ERROR_PROB) ? !bit : bit);

    return auxilaryVec;
}

/**
 * @brief Perturba uma mensagem antes de enviar ela.
 * 
 * @param message Mensagem que vai ser enviada.
 */
void Transport::send(std::vector<bool> message)
{
    std::cout << std::endl;
    std::cout << ColoredString::magenta("[LAYER] ") << "Camada do meio de comunicação:" << std::endl;
    std::cout << ColoredString::blue("[INFO] ") << "Binário enviado: " << std::endl;

    // Mostra os bits que foram enviados
    PrintService::printAsStream(message);

    // Perturba a mensagem
    std::vector<bool> finalMessage = _disturbMessageWithRandonmess(message);

    std::cout << ColoredString::blue("[INFO] ") << "Recebimento: " << std::endl;
    std::cout << ColoredString::blue("[INFO] ") << "Binário recebido: " << std::endl;

    // Mensagem recebida com erros
    PrintService::printAsStream(finalMessage);

    // Mostra a diferença 
    std::cout << ColoredString::blue("[INFO] ") << "Diferenças: " << std::endl;

    PrintService::printDifference(message, finalMessage);

    DataLink::receive(finalMessage);
}