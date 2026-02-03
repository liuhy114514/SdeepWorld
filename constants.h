#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <array>
#include <iomanip>
#include <iosfwd>
#include <sstream>
#include <windows.h>
#include <algorithm>
using namespace std;

//常量声明
// 季节
struct season {
	double start;
	double end;
};
//状态机
struct status {
	//成就
	bool TenWood = false;
	bool TenStone = false;
	bool Live_for_a_day = false;
	bool Bowl_full_of_blood = false;
	bool Survival_expert = false;
	//是否拥有庇护所
	bool hasShelter = false;
	bool first = true;
};
// 物品类型

//资源
struct Inventory {
	int water = 0;
	int food = 0;
	int wood = 0;
	int stone = 0;
	//will
	int iron = 0;
	int gold = 0;

	int capacity = 10;
};

// 地图类型
struct mapCell {
	int type; // 属性
	string name;  // 名字
	char c; // 外观
};

//人物感受
struct Feel {
	int HealthLevel = 100;
	int HungerLevel = 50;
	int ThirstLevel = 50;

	//bool MoreWet = ((hot && humidity >= 70.0f) || ((cold || (warm || cool || comfort) && humidity > 60.0f))); //较湿
	//bool Dry = ((hot || (warm || cool || comfort)) && humidity < 40.0f) || (cold && humidity < 30.0f); // 干燥
	// 是否处于饥饿或者口渴状态
	bool hunger;
	bool thirst;
	// 疲倦
	bool tired;
};
//计时器有关
struct TimerStruct {
	bool isFindFood = false;
	bool isCuttingDownTrees = false;
	bool isFindWater = false;
	bool isEat = false;
	bool isDrink = false;
	bool isRest = false;
} TimerStruct1;
//玩家结构体
struct Survivor {
	string name;
	int level = 1;
	Feel feel;
	Inventory inventory;
	status state;
};
// 世界结构体
struct World {
	int day = 1;
	int month = 1;
	int year = 1;
	int Season = 1;
	double time = 6;
	double date;
	double temperature; //气温
	double humidity; //湿度,须使用百分比
	mapCell maps[256][256]; // 随机地图生成
};

const string USER_DATA_FILE = "user_data.txt";
// 成就描述
const string miaoshu[5] = {
	"获得十个木头方可解锁",
	"获得十个石头方可解锁",
	"活过1天",
	"背包满了时",
	"生存能手"
};
//成就难度
const string difficulty[2] = {
	"简单",
	"普通"
};
// 成就
const string Achievement[3] = {
	"  A  B  C  D  E     \n",
	"  |  |  |  |  |     \n",
	" -------------------\n",
};
const long long _time = time(NULL);
const int TypeMax = 5; // 随机地形编号的最大值
const string item[10] = {
	"木头",
	"石头",
	"浆果",
	"水",
	"铁",
	"金",
	"水",
};
const mapCell boime[10] = {
	{0, "空地", '.'},
	{1, "草", ','},
	{2, "草丛", ','},
	{3, "树", ','},
	{4, "水", '~'}
};

// 变量
int temp0 = 1;	// 判定天数变化
int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 存日期
bool temp1; // 是否触发随机事件
long long Timer[6]; // 游戏计时器
char Shelter[5][6] = { // 字符串以\0结尾
	"#####",
	"#...#",
	"#..*E",
	"#...#",
	"#####",
};
season The_Four_Seasons0[4] = { { 2.02, 5.07 },  { 5.07, 8.08  }, { 8.08, 11.08 }, { 11.08, 2.02 } };    // [a,b)
World TW;

// 函数
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void showProgressBar(int value, int maxValue, string name) {
	setColor(11);
	cout << name << ": ";
	int bars = value * 20 / maxValue;
	setColor(10);
	for (int i = 0; i < bars; i++) cout << "■";
	setColor(8);
	for (int i = bars; i < 20; i++) cout << "■";
	setColor(15);
	cout << " " << value << "/" << maxValue << endl;
}

typedef mapCell MC;