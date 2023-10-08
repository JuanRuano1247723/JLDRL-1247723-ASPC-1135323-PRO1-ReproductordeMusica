#pragma once
#include "Lectura.h"
#include <string>
class CD : public Lectura{
private:
	std::string nombre;
	int cantidad;
	int indice;
public:
	
	//constructor
	CD(std::string _string, int cant, int index) {
		nombre = _string;
		cantidad = cant;
		indice = index;
	}
	CD() {

	}
};

