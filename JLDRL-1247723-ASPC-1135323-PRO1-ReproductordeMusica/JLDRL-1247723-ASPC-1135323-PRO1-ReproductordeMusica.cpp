// JLDRL-1247723-ASPC-1135323-PRO1-ReproductordeMusica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main() {

    list<string> fileContents;  // Lista para almacenar los contenidos de las líneas
    string folderPath = "C:/Users/04dan/Dropbox/Mi PC (LAPTOP-35D3RKBD)/Desktop/Prueba Proyecto";


    // Comprueba si la ruta es válida
    if (!fs::is_directory(folderPath)) {
        std::cerr << "La carpeta especificada no es válida." << std::endl;
        return 1;
    }

    // Itera a través de los archivos .txt en la carpeta
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".txt") {
            // Abre el archivo
            std::ifstream file(entry.path());
            if (file.is_open()) {
                std::string line;
                // Lee y almacena las líneas del archivo en la lista
                while (std::getline(file, line)) {
                    fileContents.push_back(line);
                }
                file.close();
            }
            else {
                std::cerr << "No se pudo abrir el archivo: " << entry.path() << std::endl;
            }
        }
    }

    // Imprime el contenido de la lista
    for (const std::string& line : fileContents) {
        std::cout << line << std::endl;
    }

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
