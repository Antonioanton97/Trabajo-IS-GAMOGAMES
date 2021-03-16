#ifndef _USUARIO_H_
#define _USUARIO_H_
#include<iostream>
#include"UsuarioNoIdentificado.h"
#include"Videojuego.h"
#include"Master.h"
#include"Administrador.h"
using namespace std;


class Usuario :public UsuarioNoIdentificado {
private:
	int ID; //DNI
	string nombre;
	string apellidos;
	int fecha_nac;
	int telefono;
	string email;
	string direccion;
	string contrasena;
public:
	//Constructor
	inline Usuario(int id, int f, int t, string n, string a, string e, string d, string c) {
		this->ID = id; this->fecha_nac = f; this->telefono = t;
		this->nombre = n; this->apellidos = a; this->email = e; this->direccion = d; this->contrasena = c;
	}
	inline Usuario(Usuario& u) { *this = u; }
	inline Usuario() { this->nombre = "0"; this->apellidos = "0"; this->email = "0"; this->direccion = "0"; this->contrasena = "0"; this->fecha_nac = 0; this->telefono = 0; this->ID = 0;};
	//Observadores
	inline string getNombre() const { return this->nombre; }
	inline string getApellidos() const { return this->apellidos; }
	inline string getEmail() const { return this->email; }
	inline string getDireccion() const { return this->direccion; }
	inline string getContrasena() const { return this->contrasena; }
	inline int getID() const { return this->ID; }
	inline int getFecha_nac() const { return this->fecha_nac; }
	inline int getTelefono() const { return this->telefono; }
	//Modificadores
	inline void setID(int id) { this->ID = id; }
	inline void setFecha_nac(int f) { this->fecha_nac = f; }
	inline void setTelefono(int t) { this->telefono = t; }
	inline void setNombre(string n) { this->nombre = n; }
	inline void setApellidos(string a) { this->apellidos = a; }
	inline void setEmail(string e) { this->email = e; }
	inline void setDireccion(string d) { this->direccion = d; }
	inline void setContrasena(string c) { this->contrasena = c; }
	//Sobrecarga
	Usuario& operator =(Usuario const& u);

	//Funciones heredadas
	virtual void mostrar();
	virtual void menu(Master m);

	//Funciones propias
	void modificarDatosPersonales(Master m);
	virtual void darseDeBaja(Master m); //Lo hago virtuyal para que admin lo redefina
	void mostrarListaDeVideojuegos(Master m);
	void busquedaPorFiltrado();
	bool comprobarID(int id,Master m);
	Videojuego buscarVideojuego(Master m);


};


#endif // !_USUARIO_H_

