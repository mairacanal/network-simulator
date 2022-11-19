#include "DataLink.hpp"

void DataLink::send(vector<bool> frame){
    std::cout << ColoredString::magenta([LAYER]) + Camada de Enlace:<< std::endl;
    frame = errorHandling(frame);
    Transport::send(frame);
}

void DataLink::receive(vector<bool> frame){
    std::
