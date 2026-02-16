#include "constants.hpp"
#include "interface.hpp"
using namespace std;
//采用彭++代码换行技术

int main() {
	try {
		GameSys gs = GameSys();
		gs.Game();
	} catch(...){
		cout << "游戏出错";
		system("pause");
		exit(0);
	}
	return 0;
}
