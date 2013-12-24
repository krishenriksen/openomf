#ifndef _GAME_STATE_TYPE_H
#define _GAME_STATE_TYPE_H

#include "utils/vector.h"

typedef struct scene_t scene;
typedef struct game_player_t game_player;

typedef struct game_state_t {
    unsigned int run;
    unsigned int this_id, next_id;
    unsigned int tick;
    unsigned int role;
    scene *sc;
    vector objects;
    game_player *players[2];
} game_state;

#endif // _GAME_STATE_TYPE_H
