#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "actors/group1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), //New
	LOAD_YAY0(0x05, _group10_yay0SegmentRomStart, _group10_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_grounds_geo_0006F4), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_VCUTM_GRILL, castle_grounds_geo_00070C), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_FLAG, castle_grounds_geo_000660), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CANNON_GRILL, castle_grounds_geo_000724), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 0x01, 0x13, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF3, LEVEL_RR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_CASTLE_GROUNDS, 0x01, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_CASTLE_GROUNDS, 0x02, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0F, LEVEL_CASTLE_GROUNDS, 0x02, 0x0F, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_CASTLE_GROUNDS, 0x02, 0x10, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_CASTLE_GROUNDS, 0x02, 0x11, WARP_NO_CHECKPOINT),
		WARP_NODE(0x12, LEVEL_CASTLE_GROUNDS, 0x01, 0x12, WARP_NO_CHECKPOINT),
		WARP_NODE(0x13, LEVEL_CASTLE_GROUNDS, 0x01, 0x13, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_YELLOW_COIN, -12182, -615, 7812, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -8720, -615, 10648, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -7980, -615, 9202, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 9625, -609, 10650, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 9625, -609, 10650, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 13529, -609, 11136, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 13094, -609, 7816, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -1750, -615, 6209, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -354, -615, 7279, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_NONE, 6072, -665, 1892, 0, -35, 0, 0x100E0000, bhvWarp),
		OBJECT(MODEL_NONE, 14408, -623, 2667, 0, -4, 0, 0x100F0000, bhvWarp),
		OBJECT(MODEL_NONE, -5254, -665, 1942, 0, 37, 0, 0x10100000, bhvWarp),
		OBJECT(MODEL_NONE, -13489, -662, 2808, 0, -1, 0, 0x10110000, bhvWarp),
		OBJECT(MODEL_NONE, 569, -592, 4221, 0, -180, 0, 0x000D0000, bhvLaunchDeathWarp),
		OBJECT(MODEL_NONE, 569, -651, 4363, 0, 0, 0, 0x100B0000, bhvWarp),
		OBJECT(MODEL_NONE, 569, -255, 4171, 0, -180, 0, 0x00120000, bhvPaintingStarCollectWarp),
		OBJECT(MODEL_RED_COIN, -9740, -635, 9465, 0, 0, 0, 0x00010000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10402, -655, 8518, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10470, -665, 8034, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -9758, -605, 7817, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -9533, -572, 7859, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -9643, -591, 8039, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -9385, -662, 8092, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -9180, -615, 8520, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -9133, -658, 7846, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -9895, -615, 8667, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -9244, -615, 8268, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -9581, -615, 8696, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -9581, -615, 8424, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -9832, -615, 8424, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10113, -615, 8767, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10608, -615, 8321, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10016, -615, 7951, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10189, -615, 7951, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10189, -615, 8229, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10189, -615, 8447, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10205, -572, 9070, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10645, -572, 9070, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -10645, -572, 8906, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BREAKABLE_BOX, 576, -659, 13458, 0, 0, 0, 0x00040000, bhvBreakableBox),
		OBJECT(MODEL_LAKITU, 518, -609, 11156, 0, 0, 0, 0x00010000, bhvCameraLakitu),
		OBJECT(MODEL_LAKITU, -8665, -635, 7721, 0, 0, 0, 0x00BA0000, bhvCameraLakitu),
		OBJECT(MODEL_GOOMBA, 138, -665, 12596, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, 446, -665, 12417, 0, 0, 0, 0x00000000, bhvJumpingBox),
		OBJECT(MODEL_TOAD, -690, -662, 14347, 0, -116, 0, 0xAC000000, bhvToadMessage),
		OBJECT(MODEL_NONE, -8811, -628, 6827, 0, 169, 0, 0x00130000, bhvLaunchDeathWarp),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 964, -665, 14507, 0, 0, 0, 0x000C0000, bhvDoorWarp),
		OBJECT(MODEL_TOAD, 2994, -651, 4025, 0, 0, 0, 0xC7000000, bhvToadMessage),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 468, -660, 12046, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 468, -660, 12723, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 468, -660, 7896, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 468, -660, 8573, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 7723, -660, 10558, 0, -63, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 7120, -660, 10866, 0, -63, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -7532, -639, 10124, 0, 62, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -6936, -639, 10444, 0, 62, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -11117, -636, 8548, 0, 62, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 11939, 403, 8454, 0, 62, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_NONE, 479, 217, 15204, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 479, 217, 15204),
		OBJECT(MODEL_WOODEN_SIGNPOST, 494, -661, 14182, 0, -1, 0, 0x00A90000, bhvMessagePanel),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, castle_grounds_area_2),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 0x01, 0x13, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x01, 0x09, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_CASTLE_GROUNDS, 0x01, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_CASTLE_GROUNDS, 0x01, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0F, LEVEL_CASTLE_GROUNDS, 0x01, 0x0F, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_CASTLE_GROUNDS, 0x01, 0x10, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_CASTLE_GROUNDS, 0x01, 0x11, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 6484, -4142, 14952, 0, -138, 0, 0x100E0000, bhvWarp),
		OBJECT(MODEL_NONE, 12281, -4077, 1743, 0, -131, 0, 0x100F0000, bhvWarp),
		OBJECT(MODEL_NONE, -5456, -4088, 14837, 0, 139, 0, 0x10100000, bhvWarp),
		OBJECT(MODEL_NONE, -11378, -4082, 1563, 0, 154, 0, 0x10110000, bhvWarp),
		OBJECT(MODEL_NONE, -9715, -3884, -5730, 0, 0, 0, 0x00000000, bhvHighStrikerMachine),
		OBJECT(MODEL_PIANTA, -8296, -3919, -6139, 0, 0, 0, 0x00000000, bhvHighStrikerCarny),
		OBJECT(MODEL_1UP, -9708, 619, -5740, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_NONE, 11008, -4067, -5929, 0, -37, 0, 0x100C0000, bhvWarp),
		OBJECT(MODEL_NONE, 0, -3752, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, -3752, 0),
		TERRAIN(castle_grounds_area_2_collision),
		MACRO_OBJECTS(castle_grounds_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, -3752, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
