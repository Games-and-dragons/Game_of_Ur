#ifndef UR_H
# define UR_H
# define LOCALHOST "127.0.0.1"
# define DEFAULT_PORT 8080

# include "ur_structs.h"

/* File : Display_init.c */

game	*game_init();

/* File : render.c */

void	compose_board(game *game);

/*File update.c */
void	update(game *game);

#endif
