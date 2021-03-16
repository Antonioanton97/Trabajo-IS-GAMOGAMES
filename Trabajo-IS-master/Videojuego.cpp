#include<iostream>
#include"Videojuego.h"
#include"Master.h"
using namespace std;
#include<iostream>
using namespace std;

Videojuego::Videojuego() {
	// TODO Auto-generated constructor stub

}
Videojuego::Videojuego(string n, string p, string g, string d, int a, float pr){
	this->nombre = n;
	this->descripcion = d;
	this->genero = g;
	this->descripcion = d;
	this->anio_lanzamiento = a;
	this->plataforma = p;
	this->precio = pr;
}


int Videojuego::getAnioLanzamiento() const {
	return anio_lanzamiento;
}

void Videojuego::setAnioLanzamiento(int anioLanzamiento) {
	anio_lanzamiento = anioLanzamiento;
}

const string& Videojuego::getDescripcion() const {
	return descripcion;
}

void Videojuego::setDescripcion(const string& descripcion) {
	this->descripcion = descripcion;
}

const string& Videojuego::getGenero() const {
	return genero;
}

void Videojuego::setGenero(const string& genero) {
	this->genero = genero;
}

const string& Videojuego::getId() const {
	return id;
}

void Videojuego::setId(const string& id) {
	this->id = id;
}

const string& Videojuego::getNombre() const {
	return nombre;
}

void Videojuego::setNombre(const string& nombre) {
	this->nombre = nombre;
}

const string& Videojuego::getPlataforma() const {
	return plataforma;
}

void Videojuego::setPlataforma(const string& plataforma) {
	this->plataforma = plataforma;
}

float Videojuego::getPrecio() const {
	return precio;
}

void Videojuego::setPrecio(float precio) {
	this->precio = precio;
}

Videojuego::~Videojuego() {
	// TODO Auto-generated destructor stub
}

bool Videojuego::comprobarID(string id, Master m) {
	
	list<Videojuego> videojuegos = m.getListaVideojuegos();
	list<Videojuego>::iterator it = videojuegos.begin();
	bool enc = false;
	while (it != videojuegos.end() && enc == false) {
		if ((*it).getId() == id) {
			enc = true;
		}
		it++;
	}
	return enc;	
}

void Videojuego::mostrar() {
	cout << "Nombre: " << this->getNombre() << endl;
	cout << "Plataforma: " << this->getPlataforma() << endl;
	cout << "Genero: " << this->getGenero() << endl;
	cout << "Año de lanzamiento: " << this->getAnioLanzamiento() << endl;
	cout << "Precio: " << this->getPrecio() << endl;
	cout << "Descripción: " << this->getDescripcion() << endl;
}

string Videojuego::generarIdVideojuego(Master m) {
	string nom = getNombre();
	nom = nom.substr(0, 3);
	string a = "_";
	string plat = getPlataforma();
	string id = nom + a + plat;
	if (comprobarID(id, m) == false) {
		return id;
	}
	else {
		nom = getNombre();
		id = nom + a + plat;
		if (comprobarID(id, m) == false) {
			return id;
		}
		else {
			cout << "Este juego ya esta incluido en la base de datos" << endl;
			string idnull = "-1";
			return idnull;
		}
	}
}

void Videojuego::modificarVideojuego(Master m) {
	cout << "Los datos actruales del juego son: " << endl;
	this->mostrar();

	string i, p, g, n, d;
	int a;
	float pr;

	cout << "Introduzca campo a campo sus nuevos datos" << endl;
	cout << "Nombre:" << endl;
	cin >> n;
	setNombre(n);
	cout << "Genero:" << endl;
	cin >> g;
	setGenero(g);
	cout << "Plataforma:" << endl;
	cin >> p;
	setPlataforma(p);
	cout << "Anio de lanzamiento:" << endl;
	cin >> a;
	setAnioLanzamiento(a);
	cout << "Precio:" << endl;
	cin >> pr;
	setPrecio(pr);
	cout << "Descripcción:" << endl;
	cin >> d;
	setDescripcion(d);
	//Generar ID
	string id=generarIdVideojuego(m);
	if (id == "0") {
		cout << "Error: Por favor vuelva a modificar este videojuego" << endl;
	}
	else {
		setId(id);
	}
}
