void scroll_bowser_3_dl_Circle_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 122;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bowser_3_dl_Circle_mesh_layer_1_vtx_0);

	deltaX = (int)(0.2500000596046448 * 0x20) % width;
	deltaY = (int)(1.4499999284744263 * 0x20) % height;

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

void scroll_bowser_3() {
	scroll_bowser_3_dl_Circle_mesh_layer_1_vtx_0();
}
