#include "src/game/envfx_snow.h"

const GeoLayout castle_grounds_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11628, -2327, -6631, castle_grounds_dl_aesthetic_Tents_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11628, -2327, -6631, castle_grounds_dl_aesthetic_Tents_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 12538, -2327, -6515, -180, 0, 0),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 204, -665, 10812),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_barrel_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 910, 0, 116, -180, 0, 0, castle_grounds_dl_barrel_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Bench_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Bench_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 6551, 0, castle_grounds_dl_bordar_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, castle_grounds_dl_Cube_001_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Cube_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Cylinder_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 910, 0, 116, -180, 0, 0, castle_grounds_dl_Cylinder_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 6551, 0, castle_grounds_dl_Entreis_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 6484, -4142, 14951),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_HighStriker_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, castle_grounds_dl_HighStriker_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Lamp_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 549, -4142, 10028, 0, -23, 0, castle_grounds_dl_planter_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Stairs_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11051, -4151, -5986, castle_grounds_dl_statueBases_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, castle_grounds_dl_Statues_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_stuckinwallstuff_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 910, 0, 116, -180, 0, 0, castle_grounds_dl_stuckinwallstuff_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 6551, 0, castle_grounds_dl_superquiztent_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_tentacleparkour_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, castle_grounds_dl_tentacleparkour_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 6551, 0, castle_grounds_dl_tentsave_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_grounds_dl_tentsave_mesh_layer_5),
			GEO_DISPLAY_LIST(LAYER_ALPHA, castle_grounds_dl_tentsave_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11628, -2327, -6631, castle_grounds_dl_torches_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_waterfall_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_grounds_dl_waterfall_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_grounds_area_2[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_OCEAN_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, castle_grounds_area_2_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, castle_grounds_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_grounds_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, castle_grounds_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
