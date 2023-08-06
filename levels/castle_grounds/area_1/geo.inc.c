#include "src/game/envfx_snow.h"

const GeoLayout castle_grounds_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Buildings_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 446, 11208, 5929, castle_grounds_dl_Cloudwarp_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1103, -259, 13458, castle_grounds_dl_Cube_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_entries_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_ExtraTentInvasion_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Houses_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Mainstreet_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_grounds_dl_Mainstreet_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 518, -665, 11156, castle_grounds_dl_Medbay_Amongus_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_grounds_dl_Medbay_Amongus_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_raleroad_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_grounds_dl_raleroad_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Saloon_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_grounds_dl_Saloon_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 3058, 0, 6465, 0, 40, 0, castle_grounds_dl_SHoot_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_grounds_dl_SHoot_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_UltraMain_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_grounds_dl_UltraMain_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_Wamlart_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_grounds_area_1[] = {
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
					GEO_BRANCH(1, castle_grounds_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_grounds_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};