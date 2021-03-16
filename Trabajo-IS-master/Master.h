#ifndef MASTER_H_
#define MASTER_H_

#include<iostream>
#include"UsuarioNoIdentificado.h"
#include"Videojuego.h"
#include"Usuario.h"
#include"Administrador.h"
using namespace std;
#include <list>

class Master {
private:
	list<Videojuego> lista_Videojuegos;
	list<Usuario> lista_Usuarios;
	list<Administrador> lista_Administradores;
	//Usuario* u;
	//Administrador* a;
	struct usuarioConectado{
		Usuario usConectado;
		Administrador adConectado;
	};
public:
	inline Master() { this->u = NULL; this->a = NULL; }
	inline Master(Usuario* usu) { this->u = usu; }
	virtual ~Master();
	Usuario* getUsuario();
	Administrador* getAdministrador();
	list<Videojuego> getListaVideojuegos();
	list<Usuario> getListaUsuario();              //Quito los const por ahora
	list<Administrador> getListaAdministrador();
	void setListaVideojuegos(list<Videojuego> listaVideojuegos);
	inline void setUsuario(Usuario us) { this->u = us; };
	inline void setAdministrador(Administrador ad) {this->a = ad};

	void setListaUsuarios(const list<Usuario>& lu);
	void setListaAdministradores(const list<Administrador>& la);

	void primerInicio();
	void reescribirBackup();
	void guardarBackup();
	void cargarBackup();

	void cerrarSesion();
	void cerrarPrograma();

	bool anadirAdmin();
	bool anadirUsuario();
	usuarioConectado iniciarSesion();
	void menuInicio();
};

#endif /* MASTER_H_ */