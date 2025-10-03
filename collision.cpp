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