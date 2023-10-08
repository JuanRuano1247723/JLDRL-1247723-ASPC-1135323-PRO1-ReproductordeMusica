#include "Canciones.h"

int Canciones::DuracionaSegundos()
{
    size_t pos = duracion.find(':');
    if (pos != std::string::npos) {
        std::string minutosStr = duracion.substr(0, pos);
        std::string segundosStr = duracion.substr(pos + 1);

        int minutos = std::stoi(minutosStr);
        int segundos = std::stoi(segundosStr);

        int totalSegundos = minutos * 60 + segundos;
        return totalSegundos;
    }

    //en caso de un formato incorrecto, devuelve -1
    return -1;
}
