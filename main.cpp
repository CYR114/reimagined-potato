#include "main.h"

int main(int argc, char* argv[])
{
	setinitmode(INIT_NOBORDER | INIT_RENDERMANUAL, 0, 0);
	//initgraph(-1, -1);
//	setinitmode(IBM8514HI);
	initgraph(800, 800, INIT_RENDERMANUAL);
	setcaption("∫Ωø’“«±Ì");
	setbkcolor(WHITE);
	ege_enable_aa(true);
	int i = 0, j = 0;
	for (; is_run(); delay_fps(30)) {
		//«Â∆¡
		cleardevice();
		//ªÊ÷∆Õº∆¨
		airPanel(i,j);
		//drawScrew();
		i += 1;
		j += 3;
	}

	getch();
	closegraph();
	return 0;
}

