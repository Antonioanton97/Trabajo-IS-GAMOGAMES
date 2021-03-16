#ifndef VIDEOJUEGO_H_
#define VIDEOJUEGO_H_

#include<iostream>
#include"Master.h"
using namespace std;


class Videojuego {
private:
	string id, plataforma, genero, nombre, descripcion;
	int anio_lanzamiento;
	float precio;
public:
	Videojuego();
	Videojuego(string n, string p, string g, string d, int a, float pr);
	virtual ~Videojuego();
	int getAnioLanzamiento() const;
	void setAnioLanzamiento(int anioLanzamiento);
	const string& getDescripcion() const;
	void setDescripcion(const string& descripcion);
	const string& getGenero() const;
	void setGenero(const string& genero);
	const string& getId() const;
	void setId(const string& id);
	const string& getNombre() const;
	void setNombre(const string& nombre);
	const string& getPlataforma() const;
	void setPlataforma(const string& plataforma);
	float getPrecio() const;
	void setPrecio(float precio);

	//Funciones propias
	bool comprobarID(string id, Master m);
	void mostrar();
	void modificarVideojuego(Master m);
	string generarIdVideojuego(Master m);
};

#endif /* VIDEOJUEGO_H_ */