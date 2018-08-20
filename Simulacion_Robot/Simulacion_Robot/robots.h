#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include "piso.h"

#define PI 3.14159265359
typedef struct
{
	double x;
	double y;
}robpos_t;

class robot
{
	robpos_t position;
	double dir;
	unsigned int Hcount;
	unsigned int Wcount;
public:
	void initRobot(unsigned int maxh, unsigned int maxw);
	void moveRobot(void);
	robpos_t getRobotPos(void);
};