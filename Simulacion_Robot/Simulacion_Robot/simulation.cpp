#include "simulation.h"

using namespace std;

simulation::
simulation(unsigned int robotNum, string modeNum, unsigned int w, unsigned int h):p(h,w),graph(p.getHeight(),p.getWidth(),robotCount,800,800) // llamo al contructor de piso
{
	tickCount = 0;
	mode = modeNum;
	robotCount = robotNum;
	robots = new robot[robotNum];

	if (robots != NULL)
	{
		error.err_code = NO_ERR;

		for (int i = 0; i < robotNum; i++)
		{
			robots[i].initRobot(h, w); // inicializo los robots
		}
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
	delete robots;
}

error_t simulation::
getError(void)
{
	return error; // con [] no funciona
}

string simulation::
getMode(void)
{
	return mode;
}


void simulation::
step(void)
{
	for (int i = 0 ; i < robotCount ; i++)
	{
		p.cleanTile(robots[i].getRobotPos()); // limpio las baldosas sobre las que están los robots
		robots[i].moveRobot(); // muevo robots
		tickCount++; // incremento contador de tiempo
	}
}