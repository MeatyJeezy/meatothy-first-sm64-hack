#include "src/game/envfx_snow.h"

const GeoLayout highstrikerbell_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 5, 6890, -601, HighStrikerBell_000_offset_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, HighStrikerBell_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
