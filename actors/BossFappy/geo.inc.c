#include "src/game/envfx_snow.h"

const GeoLayout bossfappy_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, BossFappy_offset_000_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 205, 0, -6, BossFappy_offset_000_001_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -255, 0, -4, BossFappy_offset_000_002_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 46, 0, -162, BossFappy_offset_000_003_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, -39, 0, -85, BossFappy_offset_000_004_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, -46, 0, -92, BossFappy_offset_000_005_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 51, 0, 145, BossFappy_offset_000_006_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, -42, 0, 86, BossFappy_offset_000_007_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, -43, 0, 93, BossFappy_offset_000_008_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, BossFappy_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
