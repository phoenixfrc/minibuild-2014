#include "Gamepadf310.h"

Gamepadf310::Gamepadf310(uint32_t port):
Joystick(port){}

Gamepadf310::Gamepadf310(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes):
                    Joystick(port,numAxisTypes,numButtonTypes){
}

Gamepadf310::~Gamepadf310(){
}
