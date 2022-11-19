#include "Transport.hpp"

/**
 * @brief Perturba a mensagem e cria um novo vetor.
 *
 * @param message mensagem original.
 * @return std::vector<bool> mensagem com erros.
 */
std::vector<bool> Transport::_disturbMessageWithRandonmess(const std::vector<bool>& message)
{
    std::vector<bool> auxilaryVec {};

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
    std::vector<bool> finalMessage {};

    std::cout << ColoredString::magenta("[LAYER] \t\t\t\tCamada Física de Transmissão") << std::endl;
    std::cout << ColoredString::blue("[INFO] ") << "\t\t\t\t\tBinário enviado: " << std::endl;

    // Mostra os bits que foram enviados
    PrintService::printAsStream(message);

    finalMessage = _disturbMessageWithRandonmess(message);

    std::cout << ColoredString::blue("[INFO] \t\t\t\t\t") << "Binário recebido: " << std::endl;

    // Mensagem recebida com erros
    PrintService::printAsStream(finalMessage);

    // Mostra a diferença
    std::cout << ColoredString::blue("[INFO] \t\t\t\t\t") << "Diferenças: " << std::endl;

    PrintService::printDifference(message, finalMessage);

    DataLink::receive(finalMessage);
    std::cout << std::string(120, '=') << std::endl
              << std::endl;
}
