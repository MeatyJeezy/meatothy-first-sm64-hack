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
		OBJECT(MODEL_YELLOW_COIN, -501, 908, 7450, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 468, 310, 9111, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 473, 665, 10162, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 487, 310, 11282, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -1295, -593, 5048, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_NONE, 6072, -665, 1892, 0, -35, 0, 0x100E0000, bhvWarp),
		OBJECT(MODEL_NONE, 14408, -623, 2667, 0, -4, 0, 0x100F0000, bhvWarp),
		OBJECT(MODEL_NONE, -5254, -665, 1942, 0, 37, 0, 0x10100000, bhvWarp),
		OBJECT(MODEL_NONE, -13489, -662, 2808, 0, -1, 0, 0x10110000, bhvWarp),
		OBJECT(MODEL_NONE, 569, -592, 4221, 0, -180, 0, 0x000D0000, bhvLaunchDeathWarp),
		OBJECT(MODEL_NONE, 569, -651, 4363, 0, 0, 0, 0x100B0000, bhvWarp),
		OBJECT(MODEL_NONE, 569, -255, 4171, 0, -180, 0, 0x00120000, bhvPaintingStarCollectWarp),
		OBJECT(MODEL_BREAKABLE_BOX, 576, -659, 13458, 0, 0, 0, 0x00040000, bhvBreakableBox),
		OBJECT(MODEL_LAKITU, 735, -556, 14763, 0, 0, 0, 0x00B90000, bhvCameraLakitu),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, 12134, 439, 8773, 0, 0, 0, 0x00000000, bhvJumpingBox),
		OBJECT(MODEL_LAKITU, -8875, -634, 7616, 0, 0, 0, 0x00BA0000, bhvCameraLakitu),
		OBJECT(MODEL_TOAD, -8825, -662, 9642, 0, -116, 0, 0xAC000000, bhvToadMessage),
		OBJECT(MODEL_NONE, -8811, -628, 6827, 0, 169, 0, 0x00130000, bhvLaunchDeathWarp),
		OBJECT(MODEL_WOODEN_SIGNPOST, 4575, -664, 3965, 0, -49, 0, 0x00C60000, bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, -4242, -664, 3529, 0, 15, 0, 0x00C60000, bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, -12928, -664, 4095, 0, 15, 0, 0x00C60000, bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 13391, -664, 4291, 0, -4, 0, 0x00C60000, bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 446, -592, 5609, 0, 4, 0, 0x00C20000, bhvMessagePanel),
		OBJECT(MODEL_TOAD, 12366, -196, 10532, 0, 0, 0, 0xBF000000, bhvToadMessage),
		OBJECT(MODEL_TOAD, -1471, -651, 5093, 0, 0, 0, 0xAA000000, bhvToadMessage),
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
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_HOT),
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
		OBJECT(MODEL_TOAD, 831, -4142, 6268, 0, 0, 0, 0xB4000000, bhvToadMessage),
		OBJECT(MODEL_YELLOW_COIN, -663, -4337, 2416, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -12564, -3513, -6307, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -8178, -120, -5319, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -7358, -334, -5631, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -8891, 217, -4969, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -9422, 457, -4862, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -9939, 667, -4910, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 6234, -609, -1436, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -5038, -1209, -1314, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 433, -615, 159, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 427, -4815, -2430, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 444, -8145, -10048, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 1357, -4287, 2399, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_WOODEN_SIGNPOST, 426, -3939, -208, 0, 0, 0, 0x00A80000, bhvMessagePanel),
		OBJECT(MODEL_NONE, 6484, -4142, 14952, 0, -138, 0, 0x100E0000, bhvWarp),
		OBJECT(MODEL_NONE, 12281, -4077, 1743, 0, -131, 0, 0x100F0000, bhvWarp),
		OBJECT(MODEL_NONE, -5456, -4088, 14837, 0, 139, 0, 0x10100000, bhvWarp),
		OBJECT(MODEL_NONE, -11378, -4082, 1563, 0, 154, 0, 0x10110000, bhvWarp),
		OBJECT(MODEL_BLUE_COIN, 503, 3304, -12943, 0, 0, 0, 0x00010000, bhvRedCoin),
		OBJECT(MODEL_NONE, -9715, -3884, -5730, 0, 0, 0, 0x00000000, bhvHighStrikerMachine),
		OBJECT(MODEL_PIANTA, -8296, -3919, -6139, 0, 0, 0, 0x00000000, bhvHighStrikerCarny),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 503, -8432, -13006, 0, 0, 0, 0x00000000, bhvMegaTree),
		OBJECT(MODEL_1UP, -9708, 785, -5740, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_WOODEN_SIGNPOST, -8975, -4141, -3005, 0, 20, 0, 0x009F0000, bhvMessagePanel),
		OBJECT(MODEL_NONE, 11008, -4067, -5929, 0, -37, 0, 0x100C0000, bhvWarp),
		OBJECT(MODEL_TOAD, -248, -8437, -12732, 0, 0, 0, 0xB6000000, bhvToadMessage),
		OBJECT(MODEL_NONE, 0, -3752, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, -3752, 0),
		TERRAIN(castle_grounds_area_2_collision),
		MACRO_OBJECTS(castle_grounds_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_HOT),
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
