#include "pong.h"


void move(t_dir *dir, t_bunny_position *position, t_bunny_pixelarray *px) {

  position->x = position->x + dir->x;
  position->y = position->y + dir->y;
  if (position->x < 0)
    dir->x = 1;
  if (position->x > px->clipable.buffer.width)
    dir->x= -1;
  if (position->y < 0)
    dir->y = 1;
  if (position->y > px->clipable.buffer.height)
    dir->y = -1;

}

void std_set_pixel(t_bunny_pixelarray *picture, t_bunny_position pos, unsigned int color) {
    int i = 0;
    for(int y = 0; y < (int)(picture->clipable.clip_height) ; y++) {
        for (int x = 0; x < (int)picture->clipable.clip_width; x++, i++)
            if (y == pos.y && x == pos.x)
                ((t_color*)picture->pixels)[i].full = color;
    }
}

void std_set_line(t_bunny_pixelarray *picture, t_bunny_position start, t_bunny_position end) {
    t_bunny_accurate_position pos = {(double)start.x, (double)start.y};
    t_bunny_color tmp;
    double percentY = (end.y - start.y) / 300.0;
    double percentX = (end.x - start.x) / 300.0;
    for (int i = 0; ; pos.x += percentX, pos.y += percentY, i++) {
		int color = i > 150 ? TEAL : BLUE;
        if (((int)pos.x == end.x ||(int)pos.x == end.x -1 || (int)pos.x == end.x +1 )
        && ((int)pos.y == end.y ||(int)pos.y == end.y -1 || (int)pos.y == end.y +1 ))
            break;
        std_set_pixel(picture,  (t_bunny_position){(int)pos.x , (int)pos.y }, color);
    }
}

int main() {
    t_bunny_data data;
    data.pix = bunny_new_pixelarray(500, 400);
    data.win = bunny_start(500, 400, false, "truc");
	data.dir = (t_dir[]){(t_dir){1, -1}, (t_dir){-1, 1}};
	data.position = (t_bunny_position[]){(t_bunny_position){rand() % data.pix->clipable.clip_width, rand() % data.pix->clipable.clip_height},
	(t_bunny_position){rand() % data.pix->clipable.clip_width, rand() % data.pix->clipable.clip_height}};

    bunny_clear(&data.win->buffer, BLACK);
    bunny_set_loop_main_function(loop_function);
    bunny_set_display_function(display_function);
    bunny_set_key_response(eventHandler);
    bunny_loop(data.win, 60, &data);
    bunny_stop(data.win);
    return (0);
}