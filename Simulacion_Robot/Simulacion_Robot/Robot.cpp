#include "Robot.h"

void Robot ::
initRobot(uint n,uint Hcount, uint Wcount)
{
	hCount = Hcount; wCount = Wcount;
	ptorobots = (robotType*) malloc(n * sizeof(robotType)); 
	if (ptorobots != NULL)
	{
		unsigned int i; 
		srand(time_t());
		for (i = 0; i < n; i++)
		{
			ptorobots[i].position.x= ((double)rand()*Wcount) / (double)RAND_MAX;
			ptorobots[i].position.y = ((double)rand()*Hcount) / (double)RAND_MAX;
			ptorobots[i].direction = (((double)rand() * 360) / (double)RAND_MAX) * PI / 180;
		}
	}
	else
	{
		error.tipoDeError = ERROR_MEM;
		error.descrip = "Error en la alocación de memoria!";
	}
	

}

void Robot::
moveRobot(){
	double dx =roboto.position.x + sin(roboto.direction);
	double dy = roboto.position.y - cos(roboto.direction);
	double angle = (rand() % 360);
	if (((0<dx) && (dx<wCount)) && ((0<dy) && (dy<hCount)))  
	{
		roboto.position.x = dx;
		roboto.position.y = dy;
	}
	else
		roboto.direction = ((angle*PI / 180));
}

posT Robot::
getRobotPos(uint i)
{
	pos.x = ptorobots[i].position.x;
	pos.y = ptorobots[i].position.y;
	return pos;
}

void Robot::
destRobot()
{
	free(ptorobots);
	ptorobots = NULL;
}
