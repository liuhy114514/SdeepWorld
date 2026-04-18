// ansi_color.h
#pragma once
#include <iostream>
using namespace std;

/*
我查资料自己实现的跨平台颜色函数
0 = 黑色       8 = 灰色
1 = 蓝色       9 = 淡蓝色
2 = 绿色       A = 淡绿色
3 = 浅绿色     B = 淡浅绿色
4 = 红色       C = 淡红色
5 = 紫色       D = 淡紫色
6 = 黄色       E = 淡黄色
7 = 白色       F = 亮白色
*/

// 颜色定义
#define COLOR_BLACK     0
#define COLOR_BLUE      1
#define COLOR_GREEN     2
#define COLOR_CYAN      3
#define COLOR_RED       4
#define COLOR_MAGENTA   5
#define COLOR_YELLOW    6
#define COLOR_WHITE     7
#define COLOR_GRAY      8
#define COLOR_LBLUE     9
#define COLOR_LGREEN    10
#define COLOR_LCYAN     11
#define COLOR_LRED      12
#define COLOR_LMAGENTA  13
#define COLOR_LYELLOW   14
#define COLOR_BWHITE    15

// ANSI颜色编码
static const char* ANSI_COLORS[] = {
    "\033[30m",  // 0: 黑色
    "\033[34m",  // 1: 蓝色
    "\033[32m",  // 2: 绿色
    "\033[36m",  // 3: 青色
    "\033[31m",  // 4: 红色
    "\033[35m",  // 5: 紫色
    "\033[33m",  // 6: 黄色
    "\033[37m",  // 7: 白色
    "\033[90m",  // 8: 灰色
    "\033[94m",  // 9: 淡蓝色
    "\033[92m",  // 10: 淡绿色
    "\033[96m",  // 11: 淡青色
    "\033[91m",  // 12: 淡红色
    "\033[95m",  // 13: 淡紫色
    "\033[93m",  // 14: 淡黄色
    "\033[97m"   // 15: 亮白色
};

// 设置颜色
static inline void setColor(int color) {
    if (color >= 0 && color <= 15) cout << ANSI_COLORS[color];
}

// 重置颜色
static inline void resetColor() {
    cout << "\033[0m";
}

// 彩色输出便捷函数
static inline void printColored(int color, const char* text) {
    setColor(color);
    cout << text;
    resetColor();
}
