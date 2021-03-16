#include"UsuarioNoIdentificado.h"
#include"Videojuego.h"
#include"Usuario.h"
#include"Administrador.h"
#include"Master.h"
#include <iostream>
using namespace std;

int main() {
	cout << "!!!Proyecto en desarrollo, por favor este atento a nuestras RRSS!!!" << endl; // prints !!!Hello World!!!

	Master master;
	master.primerInicio();
	master.menuInicio();

	return 0;
	/*  Asi es como llamariamos a funciones desde el suusario guarado en master cuando sea admin
	Master m;
	m.loguin();
	m.getU()->menu();
	dynamic_cast <Administrador*>(m.getU())->adminpop();
	return 0;	
	*/

	/*    Entonces para las funciones haremos `si se puede hacer el casteo admin´se ejecuta la funciond eadmin y si no... sorry no eres admiin
	void pav::verSueldo(Persona * p)
	{
		if (Empleado * emp = dynamic_cast<Empleado*>(p))
		{
			emp->verSueldo();
		}
		else
		{
			cout << "No tiene salario" << endl;
		}
	}*/

}