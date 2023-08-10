#include "src/game/envfx_snow.h"

const GeoLayout warp_pipe_red_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_CULLING_RADIUS(350),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, warp_pipe_red_000_displaylist_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, warp_pipe_red_001_displaylist_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, warp_pipe_red_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
