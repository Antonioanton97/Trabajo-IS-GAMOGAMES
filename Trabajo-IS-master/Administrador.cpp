#include<iostream>
#include"Videojuego.h"
#include"Master.h"
#include"Usuario.h"
#include"Administrador.h"
#include<list>
using namespace std;


Usuario Administrador::buscarUsuario(Master m) {
	int id;
	bool enc = false;
	cout << "Introduzca el DNI del usuario: " << endl;
	cin >> id;
	Usuario uenc(0, 0, 0, "0", "0", "0", "0", "0");
	list<Usuario> usuarios = m.getListaUsuario();
	list<Usuario>::iterator it = usuarios.begin();
	while (it != usuarios.end() && enc != true) {
		if (it->getID() == id) {
			enc = true;
			Usuario uenc(*it);
		}
		else if (it == usuarios.end() && enc == false) {
			/*cout << "Lo siento, este usuario no se encuentra en el sistema" << endl;*/
			Usuario uenc(0, 0, 0, "0", "0", "0", "0", "0");
		}
		it++;
	}

	list<Administrador> admins = m.getListaAdministrador();
	list<Administrador>::iterator it2 = admins.begin();
	while (it2 != admins.end() && enc != true) {
		if (it2->getID() == id) {
			enc = true;
			Administrador uenc(*it2);  //Administrador hecho con constructor de usuario
		}
		else if (it2 == admins.end() && enc == false) {
			cout << "Lo siento, este usuario no se encuentra en el sistema" << endl;
			Usuario uenc(0, 0, 0, "0", "0", "0", "0", "0");
		}
		it2++;
	}
	return uenc;
}

void Administrador::darPrivilegiosAdmin(Master m) {
	cout << "Busque el usuario al que desea hacer administrador" << endl;
	Usuario enc = buscarUsuario(m);
	if (enc.getID() != 0) {
		list<Usuario> usuarios = m.getListaUsuario();
		list<Usuario>::iterator it = usuarios.begin();
		bool band = false;
		while (it != usuarios.end() && band==false) {
			if ((*it).getID() == enc.getID()) {
				usuarios.erase(it);
				band = true;
			}
		}
		cout << "Usuario eliminado" << endl;
		Administrador nuevo(enc);                 //Administrador hecho con constructor de usuario //ERRRRRRROR
		m.getListaAdministrador.push_back(nuevo);
		cout << "Nuevo administrador añadido" << endl;
	}
}

void Administrador::eliminarUsuario(Master m) {
	Usuario enc = buscarUsuario(m);
	if (enc.getID() != 0) {
		list<Usuario> usuarios = m.getListaUsuario();
		list<Usuario>::iterator it = usuarios.begin();
		bool band = false;
		while (it != usuarios.end() && band == false) {
			if ((*it).getID() == enc.getID()) {
				usuarios.erase(it);
				band = true;
			}
		}
		cout << "Usuario eliminado" << endl;
	}
	else {
		cout << "El usuario no se encuentra en el sistema, vuelva a intentarlo desde el menu" << endl;
	}
	//¿Que pasa si el usuario encontrado es un administrador o no se encuentra el usuario?
}

void Administrador::mostrarListaDeUsuarios(Master m) {
	list<Usuario> usuarios = m.getListaUsuario();
	list<Usuario>::iterator it = usuarios.begin();
	while (it != usuarios.end()) {
		cout << "Usuario con DNI: " << (*it).getID() << endl;
		it++;
	}
	//¿Y los administradores?
	list<Administrador> admins = m.getListaAdministrador();
	list<Administrador>::iterator it2 = admins.begin();
	while (it2 != admins.end()) {
		cout << "Administrador con DNI: " << (*it2).getID() << endl;
		it2++;
	}
}

void Administrador::mostrar() {
	cout << "\nDNI: " << getID() << endl;
	cout << "Nombre: " << getNombre() << endl;
	cout << "Apellidos: " << getApellidos() << endl;
	cout << "Fecha de naciminento: " << getFecha_nac() << endl;
	cout << "Telefono: " << getTelefono() << endl;
	cout << "E-mail: " << getEmail() << endl;
	cout << "Dirección: " << getDireccion() << endl;
	cout << "Contraseña: " << getContrasena() << endl;
}

//Deberan indicar primero que videojuego añadir para ello creamos un videojuego con el constructor.
void Administrador::añadirVideojuego(Master m) {
	string id, plataforma,genero, nombre, descripcion, null;
	int anio_lanzamiento;
	float precio;
	cout << "Escriba aqui el nombre del videojuego: " << endl;
	cin >> nombre;
	cout << "Plataforma: " << endl;
	cin >> plataforma;
	cout << "Genero: " << endl;
	cin >> genero;
	cout << "Descripcion: " << endl;
	cin >> descripcion;
	cout << "Anio de lanzamiento: " << endl;
	cin >> anio_lanzamiento;
	cout << "Precio: " << endl;
	cin >> precio;

	Videojuego v(nombre, plataforma, genero, descripcion, anio_lanzamiento, precio);
	id=v.generarIdVideojuego(m);
	null = "-1";
	if (id != null) {
		v.setId(id);
		list<Videojuego> videojuegos = m.getListaVideojuegos();
		videojuegos.push_back(v);
		m.setListaVideojuegos(videojuegos);
	}
	else {
		cout << "El juego ya se encuentra en la base de datos" << endl;
	}
}
void Administrador::eliminarVideojuego(Master m) {
	Videojuego v=buscarVideojuego(m);
	if (v.getId() == "-1") {
		cout << "Si desea eliminar otro videojuego vuelva a esta opcion desde el menu" << endl;
	}
	else {
		list<Videojuego> games = m.getListaVideojuegos();
		list<Videojuego>::iterator it = games.begin();
		bool enc = false;
		while (it != games.end() && enc==false) {
			if ((*it).getId() == v.getId()) {
				games.erase(it);
				enc = true;
			}
			it++;
		}		
	}
}

void Administrador::darseDeBaja(Master m) {
	int id = getID();
	bool enc = false;
	list<Administrador> administradores = m.getListaAdministrador();
	list<Administrador>::iterator it = administradores.begin();
	while (it != administradores.end() && enc == false) {
		if ((*it).getID() == id) {
			administradores.erase(it);
			enc = true;
		}
		it++;
	}
	if (enc == false) {
		cout << "Usted no se encuentra registrado en la base de datos, por favor vuelva a iniciar sesion" << endl;
		//Salir()
	}
	else {
		cout << "Administrador eliminado" << endl;
		m.setListaAdministradores(administradores);
	}
}
