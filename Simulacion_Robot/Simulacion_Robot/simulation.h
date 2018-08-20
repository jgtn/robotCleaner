#ifndef SIMULATION
#define SIMULATION

#include <string>
#include "piso.h" 
#include "graphics.h"
#include "robots.h"


using namespace std;

class simulation
{
	unsigned int tickCount;
	error_t error;
	string mode;
	unsigned int robotCount;
	robot* robots;
	void step(void);
	graphics graph; // objeto dibujador
	piso p; // objeto piso

public:
	simulation(unsigned int robotNum, string modeNum, unsigned int w, unsigned int h);
	string getMode(void);
	unsigned int simulate(void);
	unsigned int getTickCount(void);
	unsigned int getRobotCount(void);
	void destroy(void);
	error_t getError();

};
#endif // simulation