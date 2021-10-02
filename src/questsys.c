// questsys.c

#include "questsys.h"

void questsys_level00(t_game *game);

void questsys_init(t_game *game) {
    game->questsys.stage = 0;
    game->is_last_stage = false;
}

void questsys_logic(t_game *game) {
    switch (game->questsys.level)
    {
    case 0:
        questsys_level00(game);
        break;

    case 1:
        /* code */
        break;
    }
}

void questsys_level00(t_game *game) {
    t_entity *general = entity_by_slag(game, "general");
    t_entdata_npc *general_data = general->data;
    t_entity *scientist = entity_by_slag(game, "scientist");
    t_entdata_npc *scientist_data = scientist->data;
    t_entity *stone = entity_by_slag(game, "stone");
    t_entdata_object *stone_data = stone->data;
    t_entity *fdoor = entity_by_slag(game, "front_door");
    t_entdata_door *fdoor_data = fdoor->data;

    switch (game->questsys.stage) {
        case 0:
            if (!general_data->is_active) {
                game->questsys.stage = 1;
            }
            break;

        case 1:
            if (!game->is_last_stage) {
                game->is_last_stage = true;

                stone_data->is_active = true;
                player_set_spawnpoint(game, 28, 5);
            }

            if (stone_data->is_used) {
                game->questsys.stage = 2;
                game->is_last_stage = false;
            }
            break;
        
        case 2:
            if (!game->is_last_stage) {
                game->is_last_stage = true;

                general_data->is_active = true;
                general_data->current_branch = 1;
            }

            if (!general_data->is_active) {
                game->questsys.stage = 3;
                game->is_last_stage = false;
            }
            break;

        case 3:
            if (!game->is_last_stage) {
                game->is_last_stage = true;

                scientist_data->is_active = true;
                scientist_data->current_branch = 0;
            }

            if (!scientist_data->is_active) {
                game->questsys.stage = 4;
                game->is_last_stage = false;
            }
            break;

        case 4:
            if (!game->is_last_stage) {
                game->is_last_stage = true;

                fdoor_data->required_item = ITEM_NOTSET;
            }

            break;
    }
}
