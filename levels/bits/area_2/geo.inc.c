#include "src/game/envfx_snow.h"

const GeoLayout bits_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0, -2760, 0, 0, 0, 90, bits_dl_Base_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bits_dl_Circle_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bits_dl_Cube_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bits_dl_Cube_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -3567, 1217, 0, 0, 0, -90, bits_dl_Cylinder_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -3567, 1217, 0, 0, 0, -90, bits_dl_Cylinder_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, -6026, 0, bits_dl_Plane_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, -10318, 0, bits_dl_Plane_003_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, -3567, 1217, 0, 0, 0, -90, bits_dl_winds_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bits_area_2[] = {
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
					GEO_BRANCH(1, bits_area_2_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bits_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bits_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bits_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
