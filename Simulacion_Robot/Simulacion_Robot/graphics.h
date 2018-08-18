#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class graphics
{
	unsigned int hcount;
	unsigned int wcount;
	unsigned int robotCount;
	unsigned int dWidth;
	unsigned int dHeight;
	error_t error;

	ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *dirty_tile;
	ALLEGRO_BITMAP *clean_tile;
	ALLEGRO_BITMAP *robot;

public:
	graphics(unsigned int h, unsigned int w, unsigned int robotNum, unsigned int dw, unsigned int dh ); // inicialización de Allegro
	showTile(unsigned int x, unsigned int y, bool state);
	showRobot(double x, double y);
	showTime(unsigned int time);
	refreshScreen(void);
	destroy();




};