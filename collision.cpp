#include "allcpp.h"

// 检查蛇是否吃到食物
bool checkFoodCollision() {
    for (int i = 0; i < g_foodCount; i++) {
        if (g_food[i].exist && 
            g_snake.x[0] == g_food[i].x && 
            g_snake.y[0] == g_food[i].y) {
            
            // 食物被吃掉，消失
            g_food[i].exist = false;
            
            // 蛇长度增加
            g_snake.len++;
            
            // 分数增加
            g_currentScore += 10;
            
            return true;
        }
    }
    return false;
}

// 检查蛇是否碰撞(边界、自身、障碍物)
bool checkCollision() {
    // 1. 检查边界碰撞
    if (g_snake.x[0] < MAP_START_X || g_snake.x[0] >= MAP_END_X ||
        g_snake.y[0] < MAP_START_Y || g_snake.y[0] >= MAP_END_Y) {
        return true;
    }
    
    // 2. 检查自身碰撞
    for (int i = 1; i < g_snake.len; i++) {
        if (g_snake.x[0] == g_snake.x[i] && g_snake.y[0] == g_snake.y[i]) {
            return true;
        }
    }
    
    // 3. 检查障碍物碰撞
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].exist && 
            g_snake.x[0] == g_obstacles[i].x && 
            g_snake.y[0] == g_obstacles[i].y) {
            return true;
        }
    }
    
    return false;
}