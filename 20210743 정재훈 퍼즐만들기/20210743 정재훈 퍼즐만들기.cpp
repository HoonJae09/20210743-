#include<bangtal.h>



SceneID scene1;

ObjectID scr;

ObjectID start;

ObjectID ta1, ta2, ta3, ta4, ta5, ta6, ta7, ta8, ta9;

int bgameX[3][3] = {
	{604,737,870},{604,737,870},{604,737,870}
};
int bgameY[3][3] = {
	{260,260,260},{130,130,130},{0,0,0}
};
ObjectID bgame[3][3] = {
	{ta1,ta2,ta3},{ta4,ta5,ta6},{ta7,ta8,ta9}
};


ObjectID createObject(const char* name,const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(name);
	locateObject(object, scene, x, y);
	if (shown) {
		showObject(object);
	}
	return object;
}

void Swap(ObjectID&a, ObjectID&b) {
	ObjectID c = a;
	a = b;
	b = c;
}

void SwapX(int x1, int x2) {
	int cc = x1;
	x1 = x2;
	x2 = cc;
}

void SwapY(int y1, int y2) {
	int ccc = y1;
	y1 = y2;
	y2 = ccc;
}

void Random() {
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == start) {
		hideObject(start);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int h = 0; h < 3;h++)
		{

			if (object == bgame[i][h] && object != ta9){
				if (i < 2 && bgame[i + 1][h] == ta9) {
					Swap(bgame[i][h], ta9);
					SwapX(bgameX[i][h], bgameX[i + 1][h]);
					SwapY(bgameY[i][h], bgameY[i + 1][h]);

					locateObject(bgame[i][h], scene1, bgameX[i][h], bgameY[i][h]);
					locateObject(bgame[i + 1][h], scene1, bgameY[i][h], bgameY[i][h]);
				}
				else if (i > 0 && bgame[i - 1][h] == ta9) {
					locateObject(bgame[i][h], scene1, bgameX[i - 1][h], bgameY[i - 1][h]);
					locateObject(bgame[i - 1][h], scene1, bgameX[i][h], bgameY[i][h]);
					Swap(bgame[i][h], ta9);
				}
				else if (h < 2 && bgame[i][h + 1] == ta9) {
					locateObject(bgame[i][h], scene1, bgameX[i][h + 1], bgameY[i][h + 1]);
					locateObject(bgame[i][h + 1], scene1, bgameX[i][h + 1], bgameY[i][h + 1]);
					Swap(bgame[i][h], ta9);
				}
				else if (h < 2 && bgame[i][h + 1] == ta9) {
					locateObject(bgame[i][h], scene1, bgameX[i][h - 1], bgameY[i][h - 1]);
					locateObject(bgame[i][h - 1], scene1, bgameX[i][h], bgameY[i][h]);
					Swap(bgame[i][h], ta9);
				}
			}
		}
	}

}




int main() {
	setMouseCallback(mouseCallback);
	
	scene1 = createScene("퍼즐", "scr.png");



	bgame[0][0] = createObject("ta1.png");
	locateObject(scene1, bgameX[0][0], bgameY[0][0],true);

	bgame[0][1] = createObject("ta2.png");
	locateObject(scene1, bgameX[0][1], bgameY[0][1], true);

	bgame[0][2] = createObject("ta3.png");
	locateObject(scene1, bgameX[0][2], bgameY[0][2], true);

	bgame[1][0] = createObject("ta4.png");
	locateObject(scene1, bgameX[1][0], bgameY[1][0], true);

	bgame[1][1] = createObject("ta5.png");
	locateObject(scene1, bgameX[1][1], bgameY[1][1], true);

	bgame[1][2] = createObject("ta6.png");
	locateObject(scene1, bgameX[1][2], bgameY[1][2], true);

	bgame[2][0] = createObject("ta7.png");
	locateObject(scene1, bgameX[2][0], bgameY[2][0], true);

	bgame[2][1] = createObject("ta8.png");
	locateObject(scene1, bgameX[2][1], bgameY[0][0], true);

	bgame[2][2] = createObject("ta9.png");
	locateObject(scene1, bgameX[2][2], bgameY[2][2], false);

	start = createObject("start.png");
	locateObject(start, scene1, 0, 0);
	showObject(start);

	startGame(scene1);

}