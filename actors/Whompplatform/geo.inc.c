#include "src/game/envfx_snow.h"

const GeoLayout whompplatform_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, Whompplatform_offset_000_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, Whompplatform_offset_000_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, Whompplatform_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, Whompplatform_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
