#include "graphics.h"
#include "piso.h"

graphics::
graphics(unsigned int h, unsigned int w, unsigned int robotNum, unsigned int dw, unsigned int dh)
{
	hcount = h;
	wcount = w;
	robotCount = robotNum;

	/* Inicialización de Allegro */
	bool error_flag = false;
	error.err_code = NO_ERR;

	if (!al_init())
	{
		error_flag = true;
	}

	else if (!(display = al_create_display(dw, dh)))
	{
		error_flag = true;
	}

	else if (!(al_init_image_addon()))
	{
		error_flag = true;
		al_destroy_display(display);
	}

	else if ((dirty_tile = al_load_bitmap("dirty_tile.png")) != NULL)
	{
		error_flag = true;
		al_destroy_display();
		al_shutdown_image_addon();
	}

	else if ((clean_tile = al_load_bitmap("clean_tile.png")) != NULL)
	{
		error_flag = true;
		al_destroy_display();
		al_shutdown_image_addon();
	}

	else if ((robot = al_load_bitmap("robot.png")) != NULL)
	{
		error_flag = true;
		al_destroy_display();
		al_shutdown_image_addon();
	}

	if (error_flag == true)
	{
		error.err_code = ALLEGRO_ERR;
		error.description = "Error en la inicialización de Allegro!\n";
	}


}