#include "allcpp.h"


// 辅助函数：判断食物是否与蛇身重叠（原有逻辑保留）
bool isFoodOverlap(int x, int y) {
    for (int i = 0; i < g_snake.len; i++) {
        if (g_snake.x[i] == x && g_snake.y[i] == y) return true;
    }
    return false;
}

void generateFood() {
    srand((unsigned int)time(NULL)); // 初始化随机种子（原有逻辑保留）

    // -------------------------- 调整：食物坐标适配地图格子 --------------------------
    //每次只生成一个食物，用g_foodCount来计数
        do {
            // 食物X：地图内随机列（MAP_START_X + 列号×20）
            int randCol = rand() % MAP_COL; 
            g_food[g_foodCount].x = MAP_START_X + randCol * GRID_SIZE;
            // 食物Y：地图内随机行（MAP_START_Y + 行号×20）
            int randRow = rand() % MAP_ROW;
            g_food[g_foodCount].y = MAP_START_Y + randRow * GRID_SIZE;
        } while (isFoodOverlap(g_food[g_foodCount].x, g_food[g_foodCount].y)); // 重叠则重新生成

        g_food[g_foodCount].exist = true;
        g_foodCount++;


    /*多余食物标记为不存在（原有逻辑保留）
    for (int i = g_foodCount; i < 5; i++) {
        g_food[i].exist = false;
    }
    */
}
