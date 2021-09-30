// enums.h
#ifndef ENUMS_H
#define ENUMS_H

typedef enum e_facing {
	FACING_LEFT,
	FACING_RIGHT
} t_facing;

typedef enum e_anchor {
	TOP_LEFT,
	TOP_CENTER,
	TOP_RIGHT,
	CENTER_LEFT,
	CENTER_CENTER,
	CENTER_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_CENTER,
	BOTTOM_RIGHT
} t_anchor;

typedef enum e_entity_type {
	PLAYER,
	NPC,
	ITEM,
	OBJECT
} t_entity_type;

typedef enum e_item {
	ITEM_PAINT
} t_item;

#endif
