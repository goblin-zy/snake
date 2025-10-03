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

// 移动蛇
void moveSnake() {
    // 从蛇尾开始，每个节点移动到前一个节点的位置
    for (int i = g_snake.len - 1; i > 0; i--) {
        g_snake.x[i] = g_snake.x[i - 1];
        g_snake.y[i] = g_snake.y[i - 1];
    }
    
    // 根据方向移动蛇头
    switch (g_snake.dir) {
        case 0:  // 上
            g_snake.y[0] -= GRID_SIZE;
            break;
        case 1:  // 右
            g_snake.x[0] += GRID_SIZE;
            break;
        case 2:  // 下
            g_snake.y[0] += GRID_SIZE;
            break;
        case 3:  // 左
            g_snake.x[0] -= GRID_SIZE;
            break;
    }
}

// 改变蛇的方向，防止180度掉头
void changeDirection(int newDir) {
    // 检查是否是相反方向(如当前向右不能直接向左)
    if ((g_snake.dir == 0 && newDir == 2) || 
        (g_snake.dir == 2 && newDir == 0) || 
        (g_snake.dir == 1 && newDir == 3) || 
        (g_snake.dir == 3 && newDir == 1)) {
        return;  // 不允许180度掉头
    }
    g_snake.dir = newDir;
}
