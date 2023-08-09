Lights1 HighStrikerRinger_f3dlite_material_017_lights = gdSPDefLights1(
	0x6E, 0x5C, 0x19,
	0xDD, 0xBB, 0x3C, 0x28, 0x28, 0x28);

Vtx HighStrikerRinger_offset_000_mesh_layer_1_vtx_0[24] = {
	{{ {10, -34, 37}, 0, {-16, 1008}, {127, 0, 0, 255} }},
	{{ {10, -34, -37}, 0, {1008, 1008}, {127, 0, 0, 255} }},
	{{ {10, 34, -37}, 0, {1008, -16}, {127, 0, 0, 255} }},
	{{ {10, 34, 37}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {10, 34, 37}, 0, {-16, -16}, {0, 0, 127, 255} }},
	{{ {-10, -34, 37}, 0, {-16, 1008}, {0, 0, 127, 255} }},
	{{ {10, -34, 37}, 0, {-16, 1008}, {0, 0, 127, 255} }},
	{{ {-10, 34, 37}, 0, {-16, -16}, {0, 0, 127, 255} }},
	{{ {10, -34, 37}, 0, {-16, 1008}, {0, 129, 0, 255} }},
	{{ {-10, -34, 37}, 0, {-16, 1008}, {0, 129, 0, 255} }},
	{{ {-10, -34, -37}, 0, {1008, 1008}, {0, 129, 0, 255} }},
	{{ {10, -34, -37}, 0, {1008, 1008}, {0, 129, 0, 255} }},
	{{ {10, -34, -37}, 0, {1008, 1008}, {0, 0, 129, 255} }},
	{{ {-10, -34, -37}, 0, {1008, 1008}, {0, 0, 129, 255} }},
	{{ {-10, 34, -37}, 0, {1008, -16}, {0, 0, 129, 255} }},
	{{ {10, 34, -37}, 0, {1008, -16}, {0, 0, 129, 255} }},
	{{ {10, 34, -37}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-10, 34, 37}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {10, 34, 37}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {-10, 34, -37}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-10, -34, 37}, 0, {-16, 1008}, {127, 0, 0, 255} }},
	{{ {-10, 34, -37}, 0, {1008, -16}, {127, 0, 0, 255} }},
	{{ {-10, 34, 37}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {-10, -34, -37}, 0, {1008, 1008}, {127, 0, 0, 255} }},
};

Gfx HighStrikerRinger_offset_000_mesh_layer_1_tri_0[] = {
	gsSPVertex(HighStrikerRinger_offset_000_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(HighStrikerRinger_offset_000_mesh_layer_1_vtx_0 + 16, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_HighStrikerRinger_f3dlite_material_017[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(HighStrikerRinger_f3dlite_material_017_lights),
	gsSPEndDisplayList(),
};

Gfx HighStrikerRinger_offset_000_mesh_layer_1[] = {
	gsSPDisplayList(mat_HighStrikerRinger_f3dlite_material_017),
	gsSPDisplayList(HighStrikerRinger_offset_000_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx HighStrikerRinger_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

