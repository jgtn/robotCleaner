#include <string>
#include <cstdlib>
#include <cmath>

#define CLEAN true;
#define DIRTY false;

typedef enum error{NO_ERR,MEM_ERR} errtype_t;

typedef struct
{
	unsigned int x;
	unsigned int y;
}position_t;

typedef struct
{
	string description;
	errtype_t err_code; // agregar typedef de enum ???
}error_t;

class piso
{
	bool* baldosas;
	error_t error;
	unsigned int hcount;
	unsigned int wcount;
public:
	piso(unsigned int h, unsigned int w);
	bool isDirty(unsigned int x, unsigned int y);
	bool isClean(void);
	void cleanTile(unsigned int x, unsigned int y);
	void cleanTile(position_t pos);
	void destroyFloor(void);
	unsigned int getHeight(void);
	unsigned int getWidth(void);
};