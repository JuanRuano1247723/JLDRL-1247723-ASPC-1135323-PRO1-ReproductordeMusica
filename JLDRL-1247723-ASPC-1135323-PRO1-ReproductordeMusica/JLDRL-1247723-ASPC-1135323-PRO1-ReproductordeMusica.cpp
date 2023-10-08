// JLDRL-1247723-ASPC-1135323-PRO1-ReproductordeMusica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <filesystem>
#include "Lectura.h"
#include "CD.h"
#include "Canciones.h"

using namespace std;
namespace fs = std::filesystem;


int main() {
        Lectura lector("C:/Users/04dan/Dropbox/Mi PC (LAPTOP-35D3RKBD)/Desktop/Prueba Proyecto"); 

    auto [nombres, contenidos] = lector.LeerCancionesArchivo();

    lector.IdentificarCanciones();

    std::string cancionDuplicada = lector.EncontrarCancionDuplicada();

    std::cout << cancionDuplicada << std::endl;


    return 0;
}

