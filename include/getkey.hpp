#include <stdio.h>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>

    /* 跨平台的getch()实现 */
    int _getch(void) {
        struct termios oldt, newt;
        int ch;
        
        tcgetattr(STDIN_FILENO, &oldt);      /* 保存当前终端设置 */
        newt = oldt;
        
        newt.c_lflag &= ~(ICANON | ECHO);    /* 关闭规范模式和回显 */
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);  /* 应用新设置 */
        
        ch = getchar();                      /* 读取一个字符 */
        
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  /* 恢复原始设置 */
        return ch;
    }
#endif
