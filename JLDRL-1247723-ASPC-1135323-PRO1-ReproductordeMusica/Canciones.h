#pragma once
#include "Lectura.h"
class Canciones : public Lectura {

	private:
		std::string artista;
		std::string nombre;
		std::string duracion;
	public:
	int DuracionaSegundos();
};

