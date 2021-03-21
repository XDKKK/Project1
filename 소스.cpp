#include <bangtal.h>

SceneID scene1;
ObjectID startButton, endButton;
ObjectID img1, img2, img3, img4, img5, img6, img7, img8, img9, blank;
TimerID timer1;

ObjectID puzzle[3][3] = {
	{img1, img2, img3},
	{img4, img5, img6},
	{img7, img8, blank}
};

int puzzleX[3][3] = {
{ 306,553,801 },
{ 306, 553, 801 },
{ 306, 553, 801 }
};
	

int puzzleY[3][3] = { 
{474, 474, 474},
{ 259, 259, 259 },
{ 43.95, 43.95, 43.95 }
};



ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown) {
	showObject(object);
	}
    return object;	
}

void createMessage(SceneID scene, const char* message, int x, int y) {
	showMessage(message);
}

void startGame() {
	showObject(startButton);
}

void endGame(bool success) {
	if (success) {
		createMessage(scene1, "部何扁 荤柳 肯己~", 0, 230);
	}
	else {
		createMessage(scene1, "玫玫洒 促矫 秦焊磊..", 0, 230);
	}
	setObjectImage(startButton, "Images/restart.png");
	showObject(startButton);
	showObject(endButton);
}


void Swap(ObjectID &a, ObjectID &b) {
	ObjectID t = a;
	a = b;
	b = t;
}

void SwapX(int x1, int x2) {
	int tt = x1;
	x1 = x2;
	x2 = tt;
}

void SwapY(int y1, int y2) {

	int ttt = y1;
	y1 = y2;
	y2 = ttt;
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == startButton) {
		hideObject(startButton);
	}
	
	
	  for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			 {
				if (object == puzzle[i][j] && object != blank) {
					if(i < 2 && puzzle[i+1][j] == blank)
			 
			    Swap(puzzle[i][j], blank);
				
				SwapX(puzzleX[i][j], puzzleX[i + 1][j]);
				SwapY(puzzleY[i][j], puzzleY[i + 1][j]);

				locateObject(puzzle[i][j], scene1, puzzleX[i + 1][j], puzzleY[i + 1][j]);
				locateObject(puzzle[i + 1][j], scene1, puzzleX[i][j], puzzleY[i][j]);
			}	
			else if (i > 0 && puzzle[i - 1][j] == blank) {
					Swap(puzzle[i][j], blank);
				    locateObject(puzzle[i][j], scene1, puzzleX[i - 1][j], puzzleY[i - 1][j]);
				    locateObject(puzzle[i - 1][j], scene1, puzzleX[i][j], puzzleY[i][j]);
				
			
			}

			else if (j < 2 && puzzle[i][j + 1] == blank) {
					Swap(puzzle[i][j], blank);
			        locateObject(puzzle[i][j], scene1, puzzleX[i][j + 1], puzzleY[i][j + 1]);
			        locateObject(puzzle[i][j + 1], scene1, puzzleX[i][j],puzzleY[i][j]);
				
			
			}

			else if (j > 0 && puzzle[i][j - 1] == blank) {
					Swap(puzzle[i][j], blank);
					locateObject(puzzle[i][j], scene1, puzzleX[i][j - 1], puzzleY[i][j - 1]);
					locateObject(puzzle[i][j - 1], scene1, puzzleX[i][j], puzzleY[i][j]);
					
				}
				
			}
		
		}
	}
}
			
			








	int main() {

	setMouseCallback(mouseCallback);

	scene1 = createScene("欺榴嘎眠扁", "Images/硅版.png");
	puzzle[0][0] = createObject("Images/部何扁_001.jpg", scene1, puzzleX[0][0], puzzleY[0][0], true);
	puzzle[0][1] = createObject("Images/部何扁_002.jpg", scene1, puzzleX[0][1], puzzleY[0][1], true);
	puzzle[0][2] = createObject("Images/部何扁_003.jpg", scene1, puzzleX[0][2], puzzleY[0][2], true);
	puzzle[1][0] = createObject("Images/部何扁_004.jpg", scene1, puzzleX[1][0], puzzleY[1][0], true);
	puzzle[1][1] = createObject("Images/部何扁_005.jpg", scene1, puzzleX[1][1], puzzleY[1][1], true);
	puzzle[1][2] = createObject("Images/部何扁_006.jpg", scene1, puzzleX[1][2], puzzleY[1][2], true);
	puzzle[2][0] = createObject("Images/部何扁_007.jpg", scene1, puzzleX[2][0], puzzleY[2][0], true);
	puzzle[2][1] = createObject("Images/部何扁_008.jpg", scene1, puzzleX[2][1], puzzleY[2][1], true);
    puzzle[2][2] = createObject("Images/喉废.jpg", scene1, puzzleX[2][2], puzzleY[2][2], true);
	startButton = createObject("Images/start.png", scene1, 1150, 300, true);

	startGame(scene1);

}