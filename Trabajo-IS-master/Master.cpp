#include<iostream>
#include"UsuarioNoIdentificado.h"
#include"Videojuego.h"
#include"Master.h"
#include"Usuario.h"
#include"Administrador.h"
#include<iomanip>
#include<ctime>
#include<sstream>
#include<fstream>
using namespace std;

struct usuarioConectado {
	Usuario usConectado;
	Administrador adConectado;
};

Usuario* Master::getUsuario() {
	return this->u;
}

Administrador* Master::getAdministrador() {
	return this->a;
}


list<Videojuego> Master::getListaVideojuegos()  {
	return this->lista_Videojuegos;
}
list<Usuario> Master::getListaUsuario() {
	return lista_Usuarios;
}
list<Administrador> Master::getListaAdministrador() {
	return lista_Administradores;
}



void Master::setListaVideojuegos(list<Videojuego> listaVideojuegos) {
	lista_Videojuegos = listaVideojuegos;
}
void Master::setListaUsuarios(const list<Usuario>& lu) {
	lista_Usuarios = lu;
}
void Master::setListaAdministradores(const list<Administrador>& la) {
	lista_Administradores = la;
}

Master::~Master() {
	// TODO Auto-generated destructor stub
}

//Esta funcion devuelve si el hecho de añadir un usuario a tenido exito o no
bool Master::anadirUsuario() {
	bool res;
	string nombre, apellido, email, direccion, contrasena;
	int fecha_nac, telefono, DNI;

	cout << "DNI: " << endl;
	cin >> DNI;
	cout << "Nombre: " << endl;
	cin >> nombre;
	cout << "Apellido: " << endl;
	cin >> apellido;
	cout << "Email: " << endl;
	cin >> email;
	cout << "Fecha de nacimiento (DD/MM/AAAA): " << endl;
	cin >> fecha_nac;
	cout << "Telefono: " << endl;
	cin >> telefono;
	cout << "Dirección: " << endl;
	cin >> direccion;
	cout << "Contraseña: " << endl;
	cin >> contrasena;

	//Comprobamos que si el DNI ya existe
	bool existe = false;
	for (Usuario o : this->lista_Usuarios) {
		if (o.getID() == DNI) {
			existe = true;
			break;
		}
	}

	if (existe == false) {
		Usuario newUs(DNI, fecha_nac, telefono, nombre, apellido, email, direccion, contrasena);
		this->lista_Usuarios.push_back(newUs);
		res = true;
	}
	else {
		res = false;
	}

	return res;
}

//Misma funcion que la funcion anterior solo que añadiendo un administrador
bool Master::anadirAdmin() {
	bool res;
	string nombre, apellido, email, direccion, contrasena;
	int fecha_nac, telefono, DNI;

	cout << "DNI: " << endl;
	cin >> DNI;
	cout << "Nombre: " << endl;
	cin >> nombre;
	cout << "Apellido: " << endl;
	cin >> apellido;
	cout << "Email: " << endl;
	cin >> email;
	cout << "Fecha de nacimiento (DD/MM/AAAA): " << endl;
	cin >> fecha_nac;
	cout << "Telefono: " << endl;
	cin >> telefono;
	cout << "Dirección: " << endl;
	cin >> direccion;
	cout << "Contraseña: " << endl;
	cin >> contrasena;

	//Comprobamos que si el DNI ya existe
	bool existe = false;
	for (Usuario o : this->lista_Usuarios) {
		if (o.getID() == DNI) {
			existe = true;
			cout << "Este usuario ya existe como no administrador" << endl;
		}
	}

	for (Administrador a : this->getListaAdministrador) {
		if (a.getID() == DNI) {
			existe = true;
			cout << "Este usuario ya existe como administrador" << endl;
		}
	}

	if (existe == false) {
		Usuario newUs(DNI, fecha_nac, telefono, nombre, apellido, email, direccion, contrasena);
		Administrador newAd(newUs);
		this->lista_Administradores.push_back(newAd);
		res = true;
	}
	else {
		res = false;
	}

	return res;
}

usuarioConectado Master::iniciarSesion() {
	usuarioConectado usConectado;
	usConectado.usConectado = Usuario();
	usConectado.adConectado = Administrador();
	string email;
	string contrasena;
	cout << "Introduzca sus datos por favor" << endl;
	cout << "email: " << endl;
	cin >> email;
	cout << "contraseña: " << endl;
	cin >> contrasena;

	bool existe = false;

	for (Administrador a : this->lista_Administradores) {
		if (a.getEmail() == email) {
			existe = true;
			if (a.getContrasena() == contrasena) {
				cout << "Bienvenido" << endl;
				//this->setAdministrador(a); //Si eliminamos este atributo del master esta funcion tendra que devolver un usuario o administrador
				//a.menu(master);
				usConectado.adConectado = a;
			}
			else {
				cout << "La contraseña no es correcta" << endl;
			}
			break;
		}
	}

	for (Usuario o : this->lista_Usuarios) {
		if (o.getEmail() == email) {
			existe = true;
			if (o.getContrasena() == contrasena) {
				cout << "Bienvenido" << endl;
				//this->setUsuario(o);
				//o.menu(master);
				usConectado.usConectado = o;
			}
			else {
				cout << "La contraseña no es correcta" << endl;
			}
			break;
		}
	}

	if (existe == false) {
		cout << "El email introducido no existe" << endl;
	}

	return usConectado;
}

void Master::primerInicio() {
	list<Administrador> tempAd = this->getListaAdministrador;
	if (tempAd.empty) {
		cout << "Gracias por elegir GamoGames a continuacion se le pedira que introduzca sus datos como administrador" << endl;
		while (añadirAdmin() == false) {
			cout << "Por favor introduzca un administrador valido" << endl;
		}
		cout << "A continuacion se le mostrara el menu de inicio" << endl;
	}
}

void Master::menuInicio() {
	cout << "-------------------------------- MENÚ INICIO --------------------------------" << endl;
	cout << "\n\n1)Iniciar Sesión" << endl;
	cout << "\n\n2)Registrarse" << endl;
	cout << "\n\n3)Salir" << endl;
	int eleccion;
	cout << "\nIntroduzca un numero con su eleccion" << endl;
	cin >> eleccion;

	switch (eleccion) {
	case 1: 
		//Aqui habria que añadir la funcionalidad para ejecutar el menu del usuario
		this->iniciarSesion();
		break;

	case 2: 
		bool bandera;
		bandera= this->anadirUsuario();
		if (bandera == true) {
			cout << "Usuario registrado con exito, por favor inicie sesión" << endl;
		}
		else {
			cout << "Este usuario ya existe en el sistema" << endl;
		}
		menuInicio();
		break;

	case 3: 
		//Cerrar el programa , reescribir backups default

	default: 
		cout << "La opcion escogida no es valida, por favor vuelva a introducir un numero con su eleccion" << endl;
		cin >> eleccion;
	}

}

void Master::reescribirBackup() {

}

void Master::guardarBackup() {
	auto t = time(NULL);
	auto tm = *std::localtime(&t);
	
	//Aqui establecemos el nombre de los backups
	ostringstream oss1;
	ostringstream oss2;
	oss1 <<"Backup-Usuarios "<< std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
	oss2 <<"Backup-Administradores "<< std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
	string strUsuario = oss1.str();
	string strAdmin = oss2.str();

	ofstream fUs(strUsuario);
	ofstream fAdmin(strAdmin);

	list<Usuario> usuarios= this->getListaUsuario;
	list<Administrador> administradores= this->getListaAdministrador;

	for (Usuario u : usuarios) {
		fUs << u.getNombre() << ",";
		fUs << u.getApellidos() << ",";
		fUs << u.getEmail() << ",";
		fUs << u.getDireccion() << ",";
		fUs << u.getContrasena() << ",";
		fUs << u.getFecha_nac() << ",";
		fUs << u.getTelefono() << ",";
		fUs << u.getID() << endl;
	}

	for (Administrador a : administradores) {
		fAdmin << a.getNombre() << ",";
		fAdmin << a.getApellidos() << ",";
		fAdmin << a.getEmail() << ",";
		fAdmin << a.getDireccion() << ",";
		fAdmin << a.getContrasena() << ",";
		fAdmin << a.getFecha_nac() << ",";
		fAdmin << a.getTelefono() << ",";
		fAdmin << a.getID() << endl;
	}
}

void Master::cargarBackup() {
	list<Usuario> lUsuarios;
	list<Administrador> lAdmin;
	string fUsuario = "Backup-Usuarios ", fAdmin= "Backup-Administradores ";
	int DNI; //DNI
	string nombre;
	string apellido;
	int fecha_nac;
	int telefono;
	string email;
	string direccion;
	string contrasena;
	char temp[128];

	cout << "Introduzca la fecha del backup que desea cargar" << endl;
	string backup;
	cin >> backup;

	fUsuario.insert(16, backup);
	fAdmin.insert(23, backup);

	ifstream fbackupUs;
	ifstream fbackupAdmin;

	fbackupUs.open(fUsuario, ofstream::out);
	fbackupAdmin.open(fbackupAdmin, ofstream::out);

	if (fbackupUs.is_open() && fbackupAdmin.is_open()) {
		while (fbackupUs.eof()) {
			//Conseguir nombre
			fbackupUs.getline(temp, 128, ',');
			string nombre(temp);

			//Conseguir apellido
			fbackupUs.getline(temp, 128, ',');
			string apellido(temp);

			//Conseguir email
			fbackupUs.getline(temp, 128, ',');
			string email(temp);

			//Conseguir direccion
			fbackupUs.getline(temp, 128, ',');
			string direccion(temp);

			//Conseguir contraseña
			fbackupUs.getline(temp, 128, ',');
			string contrasena(temp);

			//Conseguir fecha nacimiento
			fbackupUs.getline(temp, 128, ',');
			fecha_nac = atoi(temp);

			//Conseguir telefono
			fbackupUs.getline(temp, 128, ',');
			telefono = atoi(temp);

			//Conseguir DNI
			fbackupUs.getline(temp, 128, '\n');
			DNI = atoi(temp);

			Usuario newUs(DNI, fecha_nac, telefono, nombre, apellido, email, direccion, contrasena);
			lUsuarios.push_back(newUs);
		}

		while (fbackupAdmin.eof) {
			//Conseguir nombre
			fbackupAdmin.getline(temp, 128, ',');
			string nombre(temp);

			//Conseguir apellido
			fbackupAdmin.getline(temp, 128, ',');
			string apellido(temp);

			//Conseguir email
			fbackupAdmin.getline(temp, 128, ',');
			string email(temp);

			//Conseguir direccion
			fbackupAdmin.getline(temp, 128, ',');
			string direccion(temp);

			//Conseguir contraseña
			fbackupAdmin.getline(temp, 128, ',');
			string contrasena(temp);

			//Conseguir fecha nacimiento
			fbackupAdmin.getline(temp, 128, ',');
			fecha_nac = atoi(temp);

			//Conseguir telefono
			fbackupAdmin.getline(temp, 128, ',');
			telefono = atoi(temp);

			//Conseguir DNI
			fbackupAdmin.getline(temp, 128, '\n');
			DNI = atoi(temp);

			Administrador newAdmin(DNI, fecha_nac, telefono, nombre, apellido, email, direccion, contrasena);
			lUsuarios.push_back(newAdmin);
		}
	}
	else {
		cout << "Ha ocurrido un error al abrir los ficheros" << endl;
	}
}