#ifndef __OTA_HPP__
#define __OTA_HPP__               // Declaração da biblioteca .hpp do OTA

#include "Arduino.h"

class OTA {
    private:
        char* usuario;
        char* senha;

    public:
    
        OTA(char* usuario, char* senha);

        void setup_wifi(); // Inicializa o Wi-Fi
        void setup_ota();  // Inicializa o OTA
}