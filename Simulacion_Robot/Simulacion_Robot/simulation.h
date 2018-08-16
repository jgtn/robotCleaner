#include <string>
#include "piso.h" // para los errores, por ahi se puede cambiar

typedef int robot_t; // definición provisoria

using namespace std;

class simulation
{
	unsigned int tickCount;
	error_t error;
	string mode;
	// dibujeitor
	unsigned int robotCount;
	robot* robots;
	void step(void);
	graphic graph;
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