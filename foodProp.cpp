#include "allcpp.h"


bool isFoodOverlap(int x, int y) {
    // 已有的蛇身和食物重叠检查
    for (int i = 0; i < g_snake.len; i++) {
        if (g_snake.x[i] == x && g_snake.y[i] == y) return true;
    }
    for (int i = 0; i < g_foodCount; i++) {
        if (g_food[i].exist && g_food[i].x == x && g_food[i].y == y) {
            return true;
        }
    }

    // 新增：检查与障碍物重叠
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].exist && g_obstacles[i].x == x && g_obstacles[i].y == y) {
            return true;
        }
    }

    return false;
}

void generateFood() {
    srand((unsigned int)time(NULL)); // 初始化随机数种子
    
    // 清空现有食物
    for (int i = 0; i < g_foodCount; i++) {
        g_food[i].exist = false;
    }
    g_foodCount = 0;
    
    // 根据难度生成不同数量的食物
    int foodNum = 1;  

    
    // 生成指定数量的食物
    for (int i = 0; i < foodNum; i++) {
        do {
            // 食物X坐标在地图范围内:MAP_START_X + 列数*20
            int randCol = rand() % MAP_COL; 
            g_food[g_foodCount].x = MAP_START_X + randCol * GRID_SIZE;
            // 食物Y坐标在地图范围内:MAP_START_Y + 行数*20
            int randRow = rand() % MAP_ROW;
            g_food[g_foodCount].y = MAP_START_Y + randRow * GRID_SIZE;
        } while (isFoodOverlap(g_food[g_foodCount].x, g_food[g_foodCount].y)); // 重叠则重新生成
        
        g_food[g_foodCount].exist = true;
        g_foodCount++;
    }
}
