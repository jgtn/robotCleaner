#ifndef GRAPHICS
#define GRAPHICS

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
	void allegroInit(unsigned int dw, unsigned int dh);

public:
	graphics(unsigned int h, unsigned int w, unsigned int robotNum, unsigned int dw, unsigned int dh ); // inicialización de Allegro
	void showTile(unsigned int x, unsigned int y, bool state);
	void clearDisplay(void);
	void showRobot(double x, double y);
	void showTime(unsigned int time);
	void refreshScreen(void);




};

#endif //graphics