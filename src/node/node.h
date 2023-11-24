#ifndef STD_MODEL
# define STD_MODEL
# include <stdlib.h>

typedef struct s_coords{
    int x;
    int y;
    int z;
} t_coords;

typedef struct s_prev_points{
    t_point *h_next;
    t_point *v_next;
} t_prev_points;

typedef struct s_point{
    t_coords coords;
    int color;
    t_prev_points prev_points;
    t_point *relative_pos;
} t_point;

typedef enum {
    X,
    Y,
    Z,
    COLOR,
    H_NEXT,
    V_NEXT
} point_config;

t_coords *create_coords(int x, int y, int z);
// Node in-memory CRUD
void init_node(t_point *self, t_coords, char *color, t_prev_points prev_points);
t_point *create_node(t_coords, char *color, t_prev_points prev_points);
void reset_point(t_point *self);
void destroy_point(t_point *self);
void edit_point(point_config config, t_point *self);

#endif