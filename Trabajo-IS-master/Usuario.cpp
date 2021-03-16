#include<iostream>
#include"UsuarioNoIdentificado.h"
#include"Videojuego.h"
#include"Master.h"
#include"Administrador.h"
using namespace std;


//Sobrecarga de operadores
Usuario& Usuario::operator =(Usuario const& u) {
	setApellidos(u.getApellidos());
	setNombre(u.getNombre());
	setContrasena(u.getContrasena());
	setDireccion(u.getDireccion());
	setEmail(u.getEmail());
	setFecha_nac(u.getFecha_nac());
	setID(u.getID());
	setTelefono(u.getTelefono());
	return *this;
}

//FUnciones propias
void Usuario::mostrar() {
	cout << "\nDNI: " << getID() << endl;
	cout << "Nombre: " << getNombre() << endl;
	cout << "Apellidos: " << getApellidos() << endl;
	cout << "Fecha de naciminento: " << getFecha_nac() << endl;
	cout << "Telefono: " << getTelefono() << endl;
	cout << "E-mail: " << getEmail() << endl;
	cout << "Dirección: " << getDireccion() << endl;
	cout << "Contraseña: " << getContrasena() << endl;
}

bool Usuario::comprobarID(int id,Master m) {
	list<Usuario> usuarios = m.getListaUsuario();
	list<Usuario>::iterator it = usuarios.begin();
	bool enc = false;
	while (it != usuarios.end() && enc == false) {
		if ((*it).getID() == id) {
			enc = true;
		}
		it++;
	}
	return enc;
}

void Usuario::modificarDatosPersonales(Master m) {
	cout << "Sus datos actuales son: " << endl;
	mostrar();	

	int id, f, t;
	string n, a, d, e, c;
	
	cout << "Introduzca campo a campo sus nuevos datos" << endl;
	cout << "DNI:" << endl;
	cin >> id;	
	bool revisado = comprobarID(id,m);
	while (revisado == true) {
		cout << "Lo siento, este DNI ya esta registrado. Por favor intropduzca su DNI:" << endl;
		cin >> id;
		revisado = comprobarID(id,m);
	}
	setID(id);
	cout << "Nombre:" << endl;
	cin >> n;
	setNombre(n);
	cout << "Apellidos:" << endl;
	cin >> a;
	setApellidos(a);
	cout << "Fecha de nacimiento:" << endl;
	cin >> f;
	setFecha_nac(f);
	cout << "Telefono:" << endl;
	cin >> t;
	 setTelefono(t);
	cout << "E-mail:" << endl;
	cin >> e;
	setEmail(e);
	cout << "Dirección:" << endl;
	cin >> d;
	setDireccion(d);
	cout << "Contraseña:" << endl;
	cin >> c;
	setContrasena(c);
}

Videojuego Usuario::buscarVideojuego(Master m) {
	string nom, plat, nom2;
	cout << "Introduzca el nombre del videojueo: " << endl;
	cin >> nom;
	cout << "Introduzca la plataforma del videojueo: " << endl;
	cin >> plat;
	string a = "_";
	nom2 = nom.substr(0, 3);
	string id = nom + a + plat;
	list<Videojuego> videojuegos = m.getListaVideojuegos();
	list<Videojuego>::iterator it = videojuegos.begin();
	bool enc = false;
	while (it != videojuegos.end() && enc == false) {
		if ((*it).getId() == id) {
			enc = true;
			return *it;
		}
		it++;
	}
	if (enc == false) {
		id = nom2 + a + plat;
		bool enc1 = false;
		list<Videojuego>::iterator it2 = videojuegos.begin();
		while (it2 != videojuegos.end() && enc1 == false) {
			if ((*it2).getId() == id) {
				enc1 = true;
				return *it2;
			}
			it++;
		}
		if (enc1 == false) {
			cout << "Este videojuego no se encuentra en la base de datos en esta plataforma" << endl;
			Videojuego null;
			null.setId("-1");
			return null;
		}
	}
}

void Usuario::mostrarListaDeVideojuegos(Master m) {
	list<Videojuego> games = m.getListaVideojuegos();
	list<Videojuego>::iterator it = games.begin();
	cout << "---------LISTA DE VIDEOJUEGOS---------" << endl;
	while (it != games.end()) {
		cout << (*it).getNombre() << " - " << (*it).getPlataforma() << endl;
		it++;
	}
}

void Usuario::darseDeBaja(Master m) {
	int id = getID();
	bool enc = false;
	list<Usuario> usuarios = m.getListaUsuario();
	list<Usuario>::iterator it = usuarios.begin();
	while (it != usuarios.end() && enc==false) {
		if ((*it).getID() == id) {
			usuarios.erase(it);
			enc = true;
		}
		it++;
	}
	if (enc == false) {
		cout << "Usted no se encuentra registrado en la base de datos, por favor vuelva a iniciar sesion" << endl;
		//Salir()
	}
	else {
		cout << "Usuario eliminado" << endl;
		m.setListaUsuarios(usuarios);
	}
}

void Usuario::menu(Master m) {

	cout << "-------------------------------- MENÚ --------------------------------" << endl;
	cout << "\n\n1)Mi perfil" << endl;
	cout << "\n\n2)Mostrar lista de videojuegos" << endl;
	cout << "\n\n3)Buscar un videojuego" << endl;
	cout << "\n\n4)Cerrar sesion" << endl;
	cout << "\n\n5)Darse de baja" << endl;
	int eleccion;
	cout << "\nIntroduzca un numero con su eleccion" << endl;
	cin >> eleccion;

	switch (eleccion) {  //Error con *1

	case 1: int elec;
		cout << "\n\n1)Ver datos personales" << endl;
		cout << "\n\n2)Modificar datos personales" << endl;
		cout << "\n\n3)Volver atras" << endl;
		cout << "\nIntroduzca un numero con su eleccion: " << endl;
		cin >> elec;
		while (elec != 1 || elec != 2 || elec != 3) {
			cout << "La opcion escogida no es valida, por favor vuelva a introducir un numero con su eleccion" << endl;
			cin >> elec;
		}
		if (elec == 1) {
			cout << "Sus datos personales son: " << endl;
			mostrar();
		}
		else if (elec == 2) {
			modificarDatosPersonales(m);
		}
		else {
			menu(m);
		}
		break;
	case 2:
		mostrarListaDeVideojuegos(m);
		menu(m);
		break;
	case 3:
		Videojuego v=buscarVideojuego(m);  //*1 no puedo inicializar este Videojuego
		if (v.getId() == "-1") { 
			cout << "Para buscar otro juego, vuelva a intentarlo desde el menú" << endl;
			menu(m);
		}
		else {
			cout << "El videojuego contiene los siguientes campos: " << endl;
			v.mostrar();
		}
		break;
	case 4:break;
	case 5:break;
	default:
		cout << "La opcion escogida no es valida, por favor vuelva a introducir un numero con su eleccion" << endl;
		cin >> eleccion;
		break;
	}

}
