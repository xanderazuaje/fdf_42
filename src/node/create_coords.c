#include "node.h"

t_coords *create_coords(int x, int y, int z)
{
    t_coords *coords;

    coords = (t_coords *) malloc(sizeof (t_coords));
    coords->x = x;
    coords->y = y;
    coords->z = z;
    return (coords);
}