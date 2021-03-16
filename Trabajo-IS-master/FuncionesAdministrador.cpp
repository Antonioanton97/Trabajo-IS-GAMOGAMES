#include<iostream>
#include<list>
using namespace std;


Usuario Administrador::buscarUsuario(Master m) {
	int id;
	bool enc = false;
	cout << "Introduzca el DNI del usuario: " << endl;
	cin >> id;
	list<Usuario> usuarios = m.getListaUsuario();
	list<Usuario> it = usuarios.begin();
	while(it!=usuarios.end() && enc!=true){
		if (*it->getID() == id) {
			enc = true;
			Usuario uenc(*it);
		}
		it++;
	}
	list<Administrador> admins = m.getListaAdministrador();
	list<Administrador>::it2 = admis.begin();
	while (it2 != admins.end() && enc != true) {
		if (*it->getID() == id) {
			enc = true;
			Administrador uenc(*it);  //Administrador hecho con constructor de usuario
		}
		it2++;
	}
	if (enc == false) {
		cout << "Lo siento, este usuario no se encuentra en el sistema" << endl;
		Usuario a(0, 0, 0, "0", "0", "0", "0", "0");  //Solucion para sacar un usuario como salida de la funcion;
		return a;
	}
	else {
		return uenc;
	}
}

void Administrador::darPrivilegiosAdmin(Master m) {
	Usuario enc = buscarUsuario(m);
	if (enc.getID() != 0){
		m.getListaUsuario().erase(enc);
		cout << "Usuario eliminado" << endl;
		Administrador nuevo(enc);                 //Administrador hecho con constructor de usuario
		m.getListaAdministrador.push_back(nuevo);
		cout << "Nuevo administrador añadido" << endl;
	}
}

void Administrador::eliminarUsuario(Master m){
	Usuario enc = buscarUsuario(m);
	m.getListaUsuario().erase(enc);  //¿Que pasa si el usuario encontrado es un administrador o no se encuentra el usuario?
}

void Administrador::verListaUsuarios(Master m) {
	list<Usuario> usuarios = m.getListaUsuario();
	list<Usuario>::iterator it = usuarios.begin();
	while (it != usuarios.end()) {
		cout << "Usuario con DNI: " << *it->getID() << endl;
		it++;
	}
	//¿Y los administradores?
	list<Administrador> admins = m.getListaAdministrador();
	list<Administrador>::iterator it2 = admins.begin();
	while (it != admins.end()) {
		cout << "Administrador con DNI: " << *it2->getID() << endl;
		it2++;
	}
}