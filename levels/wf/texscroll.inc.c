void scroll_wf_dl_Main_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 63;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Main_mesh_layer_1_vtx_2);

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
	scroll_wf_dl_Main_mesh_layer_1_vtx_2();
}
