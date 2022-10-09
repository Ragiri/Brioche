#include <lapin.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

typedef struct dir {
	int x;
    int y;
} t_dir;

typedef struct s_bunny_data {
    t_bunny_pixelarray *pix;
    t_bunny_window *win;
	t_bunny_position *position;
	t_dir *dir;
} t_bunny_data;

t_bunny_response display_function(void *d);
void move(t_dir *dir, t_bunny_position *position, t_bunny_pixelarray *px);
t_bunny_response loop_function(void *d);
void std_set_line(t_bunny_pixelarray *picture, t_bunny_position start, t_bunny_position end);
t_bunny_response eventHandler(t_bunny_event_state state, t_bunny_keysym key, void *data);

void std_clear_pixelarray(t_bunny_pixelarray *picture, unsigned int color);