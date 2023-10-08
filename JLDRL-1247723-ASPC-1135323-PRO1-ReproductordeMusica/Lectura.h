#pragma once
#include <string>
#include <list>
#include <utility>

class Lectura
{
private:
	//caracteristicas
    std::string artista;
    std::string nombre;
    std::string duracion;
	std::list<std::tuple<std::string, std::string, std::string>> canciones;	
	std::string folderPath;
	std::list<std::string> contenidos;
	std::list<std::string> cdnombres;
public:
	//DUNCIONES
	std::pair<std::list<std::string>, std::list<std::string>> LeerCancionesArchivo();
	std::list<std::tuple<std::string, std::string, std::string>> IdentificarCanciones();
	std::string EncontrarCancionDuplicada();

	//constructor
	Lectura(std::string _folderPath) {
		folderPath = _folderPath;
	}
	Lectura() {

	}
};


