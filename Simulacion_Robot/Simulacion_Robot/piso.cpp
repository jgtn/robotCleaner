#include "piso.h"

piso::
piso(unsigned int h, unsigned int w)
{
	hcount = h; // inicializo cantidad de tiles
	wcount = w; 
	baldosas = (bool*)malloc(h*w * sizeof(bool)); // reservo memoria para el arreglo

	if (baldosas != NULL)
	{
		for (int i = 0; i < w*h; i++) // inicializo baldosas en sucias
		{
			baldosas[i] = DIRTY;
		}

		error.err_code = NO_ERR;
	}

	else
	{
		error.err_code = MEM_ERR;
		error.description = "Error en la alocación de memoria!"
	}

}

bool piso::
isDirty(unsigned int x, unsigned int y)
{
	if ((x<wcount) && (y<hcount)) // valido coordenadas
	{
		return (baldosas[x + y * wcount]);
	}

}

bool piso::
isClean(void)
{
	bool res = CLEAN;
	for (int i = 0; i < hcount*wcount; i++)
	{
		if (baldosas[i] = DIRTY)
		{
			res = DIRTY;
		}
	}
	return res;
}

void piso::
cleanTile(unsigned int x, unsigned int y)
{
	if ((x<wcount) && (y < hcount))
	{
		baldosas[x + y * wcount] = CLEAN;
	}
}

void piso::
cleanTile(position_t pos)
{
	unsigned int x = floor(pos.x);
	unsigned int y = floor(pos.y);

	if ((x < wcount) &&  (y< hcount))
	{
		baldosas[x + y * wcount] = CLEAN;
	}
}

void piso::
destroyFloor(void)
{
	free((void*)baldosas);
}

unsigned int piso::
getHeight(void)
{
	return(hcount);
}

unsigned int piso::
getWidth(void)
{
	return(wcount);
}