#include "DataCheck.hpp"

bool DataCheck::errorTest(std::vector<bool>& frame){
    std::cout << ColoredString::cyan("[INFO]") + "Iniciando teste de integridade " << std::endl;
    switch(HANDLING_ROUTINE){
        case 0:
            std::cout << ColoredString::cyan("[INFO]") + "Com paridade par" << std::endl;
            return evenParityTest(frame);
        case 1:
            std::cout << ColoredString::cyan("[INFO]") + "Com paridade impar" << std::endl;
            return oddParityTest(frame);;
        default:
            std::cout << ColoredString::cyan("[INFO]") + "Utilizando polinomios" << std::endl;
            return crc32Test(frame);
    }
}

bool DataCheck::evenTest(std::vector<bool> frame){
    bool even = false;

    for(auto bit : frame){
        even = even ^ bit;
    }

    return !even;
}

bool DataCheck::evenParityTest(std::vector<bool>& frame){
    bool parity = frame[0];
    frame.erase(frame.begin());
    return parity != evenTest(frame);
}

bool DataCheck::oddParityTest(std::vector<bool>& frame){
    bool parity = frame[0];
    frame.erase(frame.begin());
    return parity != !evenTest(frame);
}

bool DataCheck::crc32Test(std::vector<bool>& frame){
        std::vector<bool> polinomio{
        1, 0, 0, 0, 0, 0, 1, 0,
        0, 1, 1, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 1, 1, 1, 0,
        1, 1, 0, 1, 1, 0, 1, 1,
        1};

    std::vector<bool> remaining = frame;
    remaining.resize(remaining.size());

    for (int i = 0; i < remaining.size() - 32; i++) {
        if (remaining[i]) {
            for (int j = 0; j < polinomio.size(); j++) {
                remaining[i + j] = remaining[i + j] ^ polinomio[j];
            }
        }
        remaining[i] = frame[i];
    }

    std::cout << ColoredString::cyan("[INFO]") + "Frame e resto:" << std::endl;
    PrintService::printAsBytes(remaining);

    bool hasError = false;
    for (int i = 0; i < polinomio.size() - 1; i++) {
        frame.erase(frame.end());                   
        if (!hasError) hasError = remaining[remaining.size()];  
        remaining.erase(remaining.end());                        }

    return hasError;
}


