#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include "piso.h"

#define PI 3.1415965359
#define MAX_ROBOTS 50

using namespace std;

typedef unsigned int uint;

typedef struct
{
	double x; 
	double y; 
}posT; 

typedef struct 
{
	posT position;
	double direction;
} robotType;



class robot
{
	posT pos;
	double direction;// esta dada por un angulo
	uint nro;
	uint hCount; 
	uint wCount;
	robotType roboto;
	robotType* ptorobots;
	error_t error;

public:
	robot()//Constructor
	{ 
		pos.x = 0;
		pos.y = 0; 
		direction = 0;
		nro = 0; 
		hCount = 0; 
		wCount = 0;
		roboto.position = pos; 
		roboto.direction = 0; 
		ptorobots = NULL;
		error.err_code = NO_ERR; 
	};

	//initRobot: Funcion que genera los n robots, les asigna una ubicacion y direccion arbitraria
	void initRobot(uint n,uint Hcount, uint Wcount);//n:cantidad de Robots a crear
	
	//moveRobot: funcion que asigna una nueva nueva posision si se encuentra dentro de los limites del piso.
	// de no hacerlo asigna una nueva direccion
	void moveRobot();

	//getRobotPos: funcion que devuelve la posicion del robot i, contador del arreglo que tiene la info
	//de todos los robots
	posT getRobotPos(uint i);
	
	//Libera la memoria del malloc
	void destRobot();


};
