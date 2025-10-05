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
// 无敌状态仅忽略障碍物碰撞，边界和自身碰撞仍有效
bool checkCollision() {
    // 1. 检查边界碰撞（无敌状态不影响边界碰撞）
    if (g_snake.x[0] < MAP_START_X || g_snake.x[0] >= MAP_END_X ||
        g_snake.y[0] < MAP_START_Y || g_snake.y[0] >= MAP_END_Y) {
        return true;
    }
    
    // 2. 检查自身碰撞（无敌状态不影响自身碰撞）
    for (int i = 1; i < g_snake.len; i++) {
        if (g_snake.x[0] == g_snake.x[i] && g_snake.y[0] == g_snake.y[i]) {
            return true;
        }
    }
    
    // 3. 检查障碍物碰撞（无敌状态下忽略此项）
    // 新增全局变量g_isInvincible标识无敌状态（需在global.h中声明）
    if (!g_isInvincible) {  // 仅当非无敌状态时检查障碍物碰撞
        for (int i = 0; i < g_obstacleCount; i++) {
            if (g_obstacles[i].exist && 
                g_snake.x[0] == g_obstacles[i].x && 
                g_snake.y[0] == g_obstacles[i].y) {
                return true;
            }
        }
    }
    
    return false;
}

// 检查蛇是否吃到道具
bool checkPropCollision() {
    for (int i = 0; i < 10; i++) {  // 遍历所有道具（最多10个）
        if (g_props[i].exist && 
            g_snake.x[0] == g_props[i].x && 
            g_snake.y[0] == g_props[i].y) {
            
            // 触发道具效果
            triggerPropEffect(g_props[i].type);
            
            // 移除道具
            removeProp(i);
            
            return true;
        }
    }
    return false;
}
