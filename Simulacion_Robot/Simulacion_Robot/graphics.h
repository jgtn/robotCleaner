#include <allegro5/allegro.h>

class graphics
{
	unsigned int hcount;
	unsigned int wcount;
	unsigned int robotCount;
	unsigned int dWidth;
	unsigned int dHeight;

	ALLEGRO_DISPLAY* display;
	ALLEGRO_BITMAP dirty_tile;
	ALLEGRO_BITMAP clean_tile;
	ALLEGRO_BITMAP robot;

public:
	graphics(unsigned int h, unsigned int w, unsigned int robotNum, unsigned int dw, unsigned int dh );
	showTile(unsigned int x, unsigned int y, bool state);
	showRobot(double x, double y);
	showTime(unsigned int time);
	refreshScreen(void);
	destroy();




};