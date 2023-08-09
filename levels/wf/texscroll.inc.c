void scroll_wf_dl_Circle_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 427;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Circle_mesh_layer_1_vtx_0);

	deltaX = (int)(0.009999999776482582 * 0x20) % width;
	deltaY = (int)(0.009999999776482582 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_sts_mat_wf_dl_Temp4vision_001() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_Temp4vision_001);
	shift_s(mat, 17, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_wf_dl_Main_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 63;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Main_mesh_layer_0_vtx_0);

	deltaY = (int)(0.04000002145767212 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf() {
	scroll_wf_dl_Circle_mesh_layer_1_vtx_0();
	scroll_sts_mat_wf_dl_Temp4vision_001();
	scroll_wf_dl_Main_mesh_layer_0_vtx_0();
}
