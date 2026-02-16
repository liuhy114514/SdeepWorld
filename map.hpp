#include "constants.hpp"

// getLR是用来获取当前朝向在L或者R数组的位置
int getLR(int facing, bool LR);

class Map {
	public:
		// 生成地图
		void generate_map(MC gm[256][256]) {
			srand(time(0));
			for (int y = 0; y < 256; y++) {
				for (int x = 0; x < 256; x++) {
					gm[y][x].type = TypeMin + rand() % (TypeMax - TypeMin + 1);
					gm[y][x].c = boime[gm[y][x].type].c;
				}
			}
		}
		// 玩家移动处理（其实也算玩家处理）
		void player_move(char m, Survivor &player){
			// 这里的m是玩家输入
			switch (m) {
				case 'w':case 'W':
					if (player.facing == UP && player.py > 0) player.py--;
					else if (player.facing == DOWN && player.py < 255) player.py++;
					else if (player.facing == LEFT && player.px > 0) player.px--;
					else if (player.facing == RIGHT && player.px < 255) player.px++;
					break;
				case 's':case 'S':
					if (player.facing == UP && player.py < 255) player.py++;
					else if (player.facing == DOWN && player.py > 0) player.py--;
					else if (player.facing == LEFT && player.px < 255) player.px++;
					else if (player.facing == RIGHT && player.px > 0) player.px--;
					break;
				case 'a':case 'A':player.facing = L[(getLR(player.facing, 0) + 1) % 4];break;
				case 'd':case 'D':player.facing = R[(getLR(player.facing, 1) + 1) % 4];break;
			}
		}
		// 绘制地图
		void drawMap(MC gm[256][256], Survivor &player,int px, int py){
			// 玩家面前的x和y坐标
			int fx = px + FC[player.facing][X];  // facing X
			int fy = py + FC[player.facing][Y];  // facing Y
			// 判断fx和fy是否合法
			bool tx = fx > -1 && fx < 256;
			bool ty = fy > -1 && fy < 256;
			// 绘制, 遍历玩家周围3x5的区域
			for (int y = max(0, py - 1); y <= min(py + 1, 255); y++){
				for (int x = max(0, px - 5); x <= min(px + 5, 255); x++) { 
					if (y == py && x == px){
						setColor(boime[PLAYER].color);
						cout << boime[PLAYER].c;
					}else if (y == fy && x == fx && (tx && ty)){
						cout << "■";
						player.playerFacing = gm[y][x].name;
					}else {
						setColor(gm[y][x].color);
						cout << gm[y][x].c;
					}
				}
				cout << endl;
			}
		}
};

int getLR(int facing, bool LR){
	for (int i = 0;i < 4;i++){
		if (!LR) if (facing == L[i]) return i;
		else {if (facing == R[i]) return i;}
	}
}
