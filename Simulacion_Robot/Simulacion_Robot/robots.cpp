#include "robots.h"

void robot::
initRobot(unsigned int maxh, unsigned int maxw)
{
	srand(time_t());
	position.x = (double) (rand() % maxw);// cambiar
	position.y = (double) (rand() % maxh);
	dir = (double) (rand() % 360);
	Hcount = maxh;
	Wcount = maxw;

}

void robot::
moveRobot(void)
{
	double nextX;
	double nextY;

	nextX = position.x + sin(dir * 180 / PI); // buffer directions
	nextY = position.y + cos(dir * 180 / PI); // verificar esto!!! ************************************************

	if ((nextX > 0) && (nextX < Wcount) && (nextY > 0) && (nextY < Hcount)) // si la siguiente posición es válida...
	{
		position.x = nextX;	// Escribo la siguiente posición del robot
		position.y = nextY;
	}
	
	else // si no es válida, el robot no se mueve y cambia su dirección
	{
		dir = (double) (rand() % 360);
	}
}	

robpos_t robot::
getRobotPos(void)
{
	robpos_t pos = { position.x, position.y };
	return pos;
}