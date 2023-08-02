Lights1 rr_dl_sm64_material_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 rr_dl_death_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Vtx rr_dl_Cube_mesh_layer_1_vtx_0[24] = {
	{{ {515, 129, -515}, 0, {624, 496}, {0, 127, 0, 255} }},
	{{ {-515, 129, -515}, 0, {880, 496}, {0, 127, 0, 255} }},
	{{ {-515, 129, 515}, 0, {880, 240}, {0, 127, 0, 255} }},
	{{ {515, 129, 515}, 0, {624, 240}, {0, 127, 0, 255} }},
	{{ {515, -129, 515}, 0, {368, 240}, {0, 0, 127, 255} }},
	{{ {515, 129, 515}, 0, {624, 240}, {0, 0, 127, 255} }},
	{{ {-515, 129, 515}, 0, {624, -16}, {0, 0, 127, 255} }},
	{{ {-515, -129, 515}, 0, {368, -16}, {0, 0, 127, 255} }},
	{{ {-515, -129, 515}, 0, {368, 1008}, {129, 0, 0, 255} }},
	{{ {-515, 129, 515}, 0, {624, 1008}, {129, 0, 0, 255} }},
	{{ {-515, 129, -515}, 0, {624, 752}, {129, 0, 0, 255} }},
	{{ {-515, -129, -515}, 0, {368, 752}, {129, 0, 0, 255} }},
	{{ {-515, -129, -515}, 0, {112, 496}, {0, 129, 0, 255} }},
	{{ {515, -129, -515}, 0, {368, 496}, {0, 129, 0, 255} }},
	{{ {515, -129, 515}, 0, {368, 240}, {0, 129, 0, 255} }},
	{{ {-515, -129, 515}, 0, {112, 240}, {0, 129, 0, 255} }},
	{{ {515, -129, -515}, 0, {368, 496}, {127, 0, 0, 255} }},
	{{ {515, 129, -515}, 0, {624, 496}, {127, 0, 0, 255} }},
	{{ {515, 129, 515}, 0, {624, 240}, {127, 0, 0, 255} }},
	{{ {515, -129, 515}, 0, {368, 240}, {127, 0, 0, 255} }},
	{{ {-515, -129, -515}, 0, {368, 752}, {0, 0, 129, 255} }},
	{{ {-515, 129, -515}, 0, {624, 752}, {0, 0, 129, 255} }},
	{{ {515, 129, -515}, 0, {624, 496}, {0, 0, 129, 255} }},
	{{ {515, -129, -515}, 0, {368, 496}, {0, 0, 129, 255} }},
};

Gfx rr_dl_Cube_mesh_layer_1_tri_0[] = {
	gsSPVertex(rr_dl_Cube_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(rr_dl_Cube_mesh_layer_1_vtx_0 + 16, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};

Vtx rr_dl_Deathplane_mesh_layer_5_vtx_0[4] = {
	{{ {-3639, 0, 3639}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {3639, 0, 3639}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {3639, 0, -3639}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-3639, 0, -3639}, 0, {-16, -16}, {0, 127, 0, 255} }},
};

Gfx rr_dl_Deathplane_mesh_layer_5_tri_0[] = {
	gsSPVertex(rr_dl_Deathplane_mesh_layer_5_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_rr_dl_sm64_material_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(rr_dl_sm64_material_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_rr_dl_death[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(rr_dl_death_lights),
	gsSPEndDisplayList(),
};

Gfx rr_dl_Cube_mesh_layer_1[] = {
	gsSPDisplayList(mat_rr_dl_sm64_material_001),
	gsSPDisplayList(rr_dl_Cube_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx rr_dl_Deathplane_mesh_layer_5[] = {
	gsSPDisplayList(mat_rr_dl_death),
	gsSPDisplayList(rr_dl_Deathplane_mesh_layer_5_tri_0),
	gsSPEndDisplayList(),
};

Gfx rr_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

