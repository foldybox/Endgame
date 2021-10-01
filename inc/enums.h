// enums.h
#ifndef ENUMS_H
#define ENUMS_H

typedef enum e_facing {
	FACING_LEFT,
	FACING_RIGHT
} t_facing;

typedef enum e_traps {
	TRAP_TRIGGER,
	TRAP_GLIMMER
} t_trap_type;

typedef enum e_anchor {
	ANCHOR_TOP_LEFT,
	ANCHOR_TOP_CENTER,
	ANCHOR_TOP_RIGHT,
	ANCHOR_CENTER_LEFT,
	ANCHOR_CENTER_CENTER,
	ANCHOR_CENTER_RIGHT,
	ANCHOR_BOTTOM_LEFT,
	ANCHOR_BOTTOM_CENTER,
	ANCHOR_BOTTOM_RIGHT
} t_anchor;

typedef enum e_entype {
	ENTYPE_PLAYER,
	ENTYPE_NPC,
	ENTYPE_ITEM,
	ENTYPE_DOOR
} t_entity_type;

typedef enum e_item {
	ITEM_NULL,
	ITEM_NOTSET,
	ITEM_PAINT,
	ITEM_KEY
} t_item;

#endif
