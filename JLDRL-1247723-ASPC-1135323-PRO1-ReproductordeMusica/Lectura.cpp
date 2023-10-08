#include "Lectura.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <filesystem>
#include <utility>

using namespace std;
namespace fs = std::filesystem;

std::pair<list<string>, list<string>> Lectura::LeerCancionesArchivo() {
    if (!fs::is_directory(folderPath)) {
        cerr << "La carpeta especificada no es válida." << endl;
        return std::make_pair(cdnombres, contenidos);
    }
    //auto permite que se adapte a cualquier tipo de variable que entre
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".txt") {
            ifstream file(entry.path());
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    contenidos.push_back(line);
                }
                file.close();
                cdnombres.push_back(entry.path().filename().string());
            }
            else {
                cerr << "No se pudo abrir el archivo: " << entry.path() << endl;
            }
        }
    }

    return make_pair(cdnombres, contenidos);
}
std::list<tuple<string, string, string>> Lectura::IdentificarCanciones() {

    for (const string& line : contenidos) {
        size_t limiteaart = line.find("||");
        size_t limiteadur = line.rfind("||");

        if (limiteaart != string::npos && limiteadur != string::npos && limiteaart != limiteadur) {
            string nombre = line.substr(0, limiteaart);
            string artista = line.substr(limiteaart + 2, limiteadur - limiteaart - 2);
            string duracion = line.substr(limiteadur + 2);

            canciones.push_back(make_tuple(nombre, artista, duracion));
        }
    }

    return canciones;
}

std::string Lectura::EncontrarCancionDuplicada() {
    for (auto it1 = canciones.begin(); it1 != canciones.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != canciones.end(); ++it2) {
            if (*it1 == *it2) {
                string name = get<0>(*it1);
                string artist = get<1>(*it1);
                return "Canción duplicada: " + artist + " - " + name;
            }
        }
    }

    return "No se encontraron canciones duplicadas.";
}

