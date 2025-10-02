#include "allcpp.h"

void initSnake(){
	g_snake.len=3;
	g_snake.dir=1;
	
    int startX = 14*GRID_SIZE;  // 蛇头初始X
    int startY = 14*GRID_SIZE;                         // 蛇头初始Y（偏下）
    
    // 4. 赋值蛇身每节坐标（从蛇头到蛇尾，X依次减GRID_SIZE）
    for (int i = 0; i < g_snake.len; i++) {
        g_snake.x[i] = startX - i * GRID_SIZE;  // 蛇头（i=0）在最右，节数越往后X越小
        g_snake.y[i] = startY;                  // 所有节Y坐标相同（水平初始）
    }
}
