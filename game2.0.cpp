 
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <vector>
#include<conio.h>
#include<time.h>
#define screen_x 80
#define screen_y 40

FILE* fp;
using namespace std;
HANDLE wHnd;
COORD bufferSize = { screen_x,screen_y };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
char tmp_map[30][40];
unsigned int readcount = 0;
struct score
{
	char playername[20];
	unsigned int playerscore;
} player[6];

int setConsole(int x, int y)
{
wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
SetConsoleScreenBufferSize(wHnd, bufferSize);
return 0;
}

char map[30][40] = {
	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
	"|                                xxx |",
	"|xx xxxxxx | | | xxxxxxxxxx| |   | | |",
	"|xx xxxxxx | | | xxxxxxxxxx|x|       |",
	"|   |                                |",
	"| | |xxx |  |           |            |",
	"| |      |  | |xxx  |   |  |xxxxxxxx |",
	"| | xxxxx|  | |      xx |            |",
	"| |           |xxx  |      |         |",
	"| |xxxx xxx         xx        x      |",
	"|          xxxxx  xxxxxx xxxxx       |",
	"|                                    |",
	"|x xxx xxxxx     xxx   xxxxxxx|  |xxx|",
	"|                             |  |xxx|",
	"|                             |  |xxx|",
	"|                             |  |xxx|",
	"|  xxxxxxxxxxxxxxxxxxxxxxxxxxx|  |xxx|",
	"|  |         |xxxxxxxxxxxxxxxxx  xxxx|",
	"|  x|          |xxxxxxxx             |",
	"|  xx|           |xxxxxxxx       |  x|",
	"|  xxx|            |xxxxxxxx  |  |  x|",
	"|                                   x|",
	"| xx  x  x   xxxxxxxxxxxxxxxxxxxxxxxx|",
	"| |                                  |",
	"| |   x     x    x     x   x     x   |",
	"|  x     x    x     x    x    x      |",
	"|                                    |",
	"|                                    |",
	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
};
void gotoxy(SHORT x, SHORT y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void ShowMap()
{
	for (int i = 0; i < 30; i++) {
		setcolor(5, 0); printf("%s\n", map[i]);setcolor(7, 0);
	}

}

void white_dot()
{
	for (int x = 0;x < 40;x++) {
		for (int y = 0;y < 26;y++) {

			if (map[y][x] == ' ') { gotoxy(x, y); printf(".");
			map[y][x] = '.';
			}
			 
		}
	}

	
}

void gold_drop()
{
	int x=0;
	int y=0;
	for(int i=0;i<=100;i++)
	{
		x = (rand() % 36) + 1;
		y = (rand() % 26) + 1;
			if (map[y][x] == '.')
			{
				gotoxy(x, y); setcolor(14, 0);printf("0");setcolor(7, 0);
				map[y][x] = '0';
			}

	}


}

void header()
{
	 
	printf("\n\n\n");
	printf("     iiiiii        h      h          a         tttttttt   eeeeee\n");
	printf("       ii          h      h       a     a         tt      e\n");
	printf("       ii          hhhhhhhh      aaaaaaaaa        tt      eeeeee      ");setcolor(4, 0);printf("\'F\'\n");setcolor(7, 0);
	printf("       ii          h      h      a       a        tt      e\n");
	printf("     iiiiii        h      h      a       a        tt      eeeeee\n");
	setcolor(7, 0);
	gotoxy(50,37);printf("Sitthi Nawamawat 64011301");
}


void cout_point(int x,char y[20])
{
	gotoxy(43, 1);   printf("Score : %d\n", x);
	gotoxy(43, 2);   printf("Player name : "); cout << y;
}

void print_player(int x)
{
	setcolor(x, 0); printf("M"); setcolor(7, 0);
}
void enemy(int x)
{
	setcolor(x, 0); printf("F"); setcolor(7, 0);
}
 

void readfile()
{
	int a;
	fp = fopen("ScoreBoard.txt", "r");
	do
	{
		a = fscanf(fp, "%d %s", &player[readcount].playerscore, player[readcount].playername);
		readcount++;
	} while (player[readcount - 1].playername[0] != 'x' && readcount <= 4);

}

void writefile()
{
	int i, j, a, o;
	char name[20];
	fp = fopen("ScoreBoard.txt", "w");
	for (i = 0; i <= readcount; i++)
	{
		for (j = i + 1; j <= readcount; j++)
		{
			if (player[i].playerscore < player[j].playerscore)
			{
				a = player[j].playerscore;
				player[j].playerscore = player[i].playerscore;
				player[i].playerscore = a;
				strcpy(name, player[j].playername);
				strcpy(player[j].playername, player[i].playername);
				strcpy(player[i].playername, name);
			}
		}
	}
	for (i = 0; i < readcount; i++)
	{
		o = fprintf(fp, "%d %s\n", player[i].playerscore, player[i].playername);
	}
	if (readcount < 5)
	{
		for (i = 0; i <= 5 - readcount; i++)
		{
			o = fprintf(fp, "0 x\n");
		}
	}
	readcount = 0;
	fclose(fp);
}

void scoreboard()
{
	setcolor(rand() % 9 + 1, 0);
	for(int y=0;y<=15;y++)
	{
		gotoxy(45+y,5);printf("_");
		gotoxy(45+y,22);printf("_");
	}
	for(int x=0;x<=16;x++)
	{
		gotoxy(44,6+x);printf("|");
		gotoxy(61,6+x);printf("|");
	}
	gotoxy(48, 7);
	
    printf("Top 5 score");
    for (int i = 0; i < 5; i++)
    {
        gotoxy(46, 9 + 3 * i);
        printf(" %d. %s    %d\n\n", i + 1, player[i].playername, player[i].playerscore);
    }
    
    setcolor(6,0);
	gotoxy(40,25);printf("Press \" x \" for exit the game. ");
	setcolor(7, 0);
}

void setfont(int x,int y)
{
    int newWidth = x, newHeight = y;
    CONSOLE_FONT_INFOEX fontStructure = {0};
    fontStructure.cbSize = sizeof(fontStructure);
    fontStructure.dwFontSize.X = newWidth;
    fontStructure.dwFontSize.Y = newHeight;
    wcscpy(fontStructure.FaceName, L"Courier New");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetCurrentConsoleFontEx(hConsole, true, &fontStructure);
}

class entity {
public:
	entity(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void move_x(int p) {
		if (map[y][x + p] == ' ') x += p;
	}

	void move_y(int p) {
		if (map[y + p][x] == ' ') y += p;
	}

	void move(int p, int q) {
		x += p;
		y += q;
	}

	int get_x() { return x; }
	int get_y() { return y; }

	void draw(char p) {
		map[x][y] = p;
		gotoxy(x, y); printf("%c", p);
	}

private:
	int x;
	int y;
};

struct walk {
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {
	short x;
	short y;
};

vector<target> walk_queue;

vector<walk> BFSArray;

void AddArray(int x, int y, int wc, int back) {
	if (tmp_map[y][x] == ' ' || tmp_map[y][x] == '.') {
		tmp_map[y][x] = '#';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		BFSArray.push_back(tmp);
	}
}

void FindPath(int sx, int sy, int x, int y) {
	memcpy(tmp_map, map, sizeof(map));
	BFSArray.clear();
	walk tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	BFSArray.push_back(tmp);

	int i = 0;
	while (i < BFSArray.size()) {
		if (BFSArray[i].x == x && BFSArray[i].y == y) {
			walk_queue.clear();
			target tmp2;
			while (BFSArray[i].walk_count != 0) {
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back(tmp2);

				i = BFSArray[i].back;
			}

			break;
		}

		AddArray(BFSArray[i].x + 1, BFSArray[i].y, BFSArray[i].walk_count + 1, i);
		AddArray(BFSArray[i].x - 1, BFSArray[i].y, BFSArray[i].walk_count + 1, i);
		AddArray(BFSArray[i].x, BFSArray[i].y + 1, BFSArray[i].walk_count + 1, i);
		AddArray(BFSArray[i].x, BFSArray[i].y - 1, BFSArray[i].walk_count + 1, i);

		i++;
	}

	BFSArray.clear();
}


int main()
{
	bool running = true;
	int x = 18;
	int y = 26;
	int old_x;
	int old_y;
	
	int ex = 1;
	int ey = 1;
	int ox=0, oy=0, o2x=0, o2y=0, o3x=0, o3y=0;
	int ch = '.';
 
	int pts = 990;
	int color = 7;
	int color_e = 4;
	int speedmod = 4;
	int ax=0, ay=0;
	int cpts,cpts2,cpts3;
	int cpts4;
    setConsole(screen_x, screen_y);

	header();
	
	
	readfile();
	gotoxy(30,12);printf("ENTER NAME : ");
	scanf("%[^\n]s", player[readcount].playername);

	gotoxy(27, 14);printf("CHOOSE COLOR (1-14) : ");
	cin >> color;
	

	system("cls");
	
	srand(time(NULL));
	ShowMap();
	white_dot();

	gotoxy(x, y); print_player(color);

	int frame = 0;

	FindPath(ex, ey, x, y);

	while (running) {
		gotoxy(x, y); printf(" ");

		old_x = x;
		old_y = y;
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') {
				if (map[y][x - 1] == '.') { x--; pts++; }
				else
					if (map[y][x - 1] == ' ') x--;
				else
					if (map[y][x - 1] == 'a') { x--; pts = pts + 5; ax = 0; ay = 0;}
				else
					if (map[y][x - 1] == '0') { x--; pts = pts + 50; }
			}
			if (ch == 's') {
				if (map[y + 1][x] == '.') { y++; pts++; }
				else
					if (map[y + 1][x] == ' ') y++;
				else
					if (map[y + 1][x] == 'a') { y++; pts = pts + 5; ax = 0; ay = 0; }
				else
					if (map[y + 1][x] == '0') { y++; pts = pts + 50; }
			}
			if (ch == 'w') {
				if (map[y - 1][x] == '.') { y--; pts++; }
				else
					if (map[y - 1][x] == ' ') y--;
				else
					if (map[y - 1][x] == 'a') { y--; pts = pts + 5; ax = 0; ay = 0;}
				else
					if (map[y - 1][x] == '0') { y--; pts = pts + 50; }
			}
			if (ch == 'd') {
				if (map[y][x + 1] == '.') { x++; pts++; }
				else
					if (map[y][x + 1] == ' ') x++;
				else
					if (map[y][x + 1] == 'a') { x++; pts = pts + 5; ax = 0; ay = 0;}
				else
					if (map[y][x + 1] == '0') { x++; pts = pts + 50; }
			}
			if (ch == 'x') {
				break;
			}
			fflush(stdin);

		}
		if (old_x != x || old_y != y) {
			FindPath(ex, ey, x, y);
		}


		gotoxy(x, y); print_player(color);


		map[ey][ex] = '.';
 
	
		 
		gotoxy(ex, ey); cout << ".";

		if (frame % speedmod == 0 && walk_queue.size() != 0) {
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}

		gotoxy(ex, ey); enemy(color_e);

		if (ex == x && ey == y) {
			break;
		}

		if (pts >= 100 && pts < 1000) {
			cpts = pts % 100;
			if (cpts==0) {
				ox = (rand() % 36) + 1;
				oy = (rand() % 26) + 1;
				if (map[oy][ox] == ' '||map[oy][ox] == '.') {
					gotoxy(ox, oy);
					setcolor(4, 0);printf("o");
					setcolor(7, 0);
					pts += 1;
				}
				
			}
		}
		if (ox == x && oy == y) { speedmod = 6; }
		
		if (pts >= 220) {
			cpts2 = pts % 220;
			if (cpts2 == 0) {
				 
				o2x = (rand() % 36) + 1;
				o2y = (rand() % 26) + 1;
				if (map[o2y][o2x] == ' ' || map[o2y][o2x] == '.') {
					gotoxy(o2x, o2y);
					setcolor(2, 0);printf("o");
					setcolor(7, 0);
					pts += 1;
				}
			}

		}
		if (o2x == x && o2y == y) {
			for (int i = 0;i < 5;i++) {
				ax = (rand() % 36) + 1;
				ay = (rand() % 26) + 1;
				if (map[ay][ax] == ' ' || map[ay][ax] == '.') {
					gotoxy(ax, ay);
					setcolor(2, 0);printf("a");
					setcolor(7, 0);
					map[ay][ax] = 'a';
				}
			}
			o2x = 0; o2y = 0;
		}
		
		 
		if (pts >= 900) {
			cpts3 = pts % 1000;
			if (cpts3 == 0) {
				o3x = (rand() % 36) + 1;
				o3y = (rand() % 26) + 1;
				if (map[o3y][o3x] == ' ' || map[o3y][o3x] == '.') {
					gotoxy(o3x, o3y);
					setcolor(14, 0);printf("o");
					setcolor(7, 0);
					pts += 1;
				}
			}
		}
		if (o3x == x && o3y == y) { gold_drop(); color = 3; color_e = 4; o3x = 0; o3y = 0; }
		
		if (pts >= 200 && pts <= 1000) {
			int speed2;
			speed2 = pts % 220;
			for(int z=0;z<=20;z++){
			if (speed2 == 0+z) {
				speedmod = 4;
			}
			}
		}

		if (pts >= 1000 && pts <= 1500)
		{
			speedmod = 2;
		}

		if (pts > 1500) { 
		 speedmod = 1; 
		}
		
		cout_point(pts,player[readcount].playername);
		scoreboard();
		Sleep(100);
		frame++;
	}

	system("cls");
	gotoxy(34, 4);printf("GAME OVER\n\n");
	gotoxy(30, 7);printf("Name : "); cout << player[readcount].playername;
	gotoxy(30, 8);printf("Total score : %d\n\n\n\n", pts);
	player[readcount].playerscore = pts;
	writefile();
	Sleep(200000);

	return 0;
}
