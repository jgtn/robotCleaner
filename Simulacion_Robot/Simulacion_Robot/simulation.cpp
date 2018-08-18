#include "simulation.h"

using namespace std;

simulation::
simulation(unsigned int robotNum, string modeNum, unsigned int w, unsigned int h):p(h,w) // llamo al contructor de piso
{
	tickCount = 0;
	mode = modeNum;
	robotCount = robotNum;
	robots = new robot[robotNum];
	if (robots != NULL)
	{
		error.err_code = NO_ERR;
	}

	else
	{
		error.err_code = MEM_ERR;
		error.description = "Error en la alocación de memoria!\n";
	}

}

unsigned int simulation::
getTickCount(void)
{
	return tickCount;
}

unsigned int simulation::
getRobotCount(void)
{
	return robotCount;
}

void simulation::
destroy(void)
{
	delete robots[];
}

error_t simulation::
getError(void)
{
	return error;
}

string simulation::
getMode(void)
{
	return mode;
}

void simulation::
step(void)
{

}