#include "src/game/envfx_snow.h"

const GeoLayout highstrikercarnie_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, HighStrikerCarnie_offset_000_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, HighStrikerCarnie_offset_000_mesh_layer_4),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -60, 0, -54, HighStrikerCarnie_offset_000_001_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 149, 0, -65, HighStrikerCarnie_offset_000_002_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -60, 0, 46, HighStrikerCarnie_offset_000_003_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 149, 0, 64, HighStrikerCarnie_offset_000_004_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, HighStrikerCarnie_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, HighStrikerCarnie_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
