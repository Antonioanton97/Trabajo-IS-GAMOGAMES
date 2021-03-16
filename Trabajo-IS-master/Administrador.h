#ifndef _ADMINISTRADOR_H_
#define _ADMINISTRADOR_H_
#include<iostream>
#include"Usuario.h"
#include"Videojuego.h"
#include"Master.h"
using namespace std;


class Administrador : public Usuario {
public:
	//Faltan constructores
	inline Administrador(){}
	inline Administrador(Administrador& a) { *this = a; }
	//inline Administrador(Usuario& u); //Crear un admin a partir de un usuario
	//Funciones heredadas
	void mostrar();
	void menu(Master m);
	//Funciones propias
	//Videojuego modificarVideojuego(Master m); Por ahora esta funcion pertence a videojuego
	void añadirVideojuego(Master m);
	void eliminarVideojuego(Master m);
	void eliminarUsuario(Master m);
	void mostrarListaDeUsuarios(Master m);
	void darPrivilegiosAdmin(Master m);
	Usuario buscarUsuario(Master m);
	void darseDeBaja(Master m);




};
#endif // !_ADMINISTRADOR_H_

