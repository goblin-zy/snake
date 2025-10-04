#include "allcpp.h"

// 验证障碍物位置有效性（不重叠）
bool isObstacleValid(int x, int y) {
    // 检查是否与蛇重叠
    for (int i = 0; i < g_snake.len; i++) {
        if (g_snake.x[i] == x && g_snake.y[i] == y) {
            return false;
        }
    }
    // 检查是否与食物重叠
    for (int i = 0; i < g_foodCount; i++) {
        if (g_food[i].exist && g_food[i].x == x && g_food[i].y == y) {
            return false;
        }
    }
    // 检查是否与其他障碍物重叠
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].exist && g_obstacles[i].x == x && g_obstacles[i].y == y) {
            return false;
        }
    }
    // 检查是否超出地图范围
    if (x < MAP_START_X || x >= MAP_END_X || y < MAP_START_Y || y >= MAP_END_Y) {
        return false;
    }
    return true;
}

// 添加单个静态障碍物
void addSingleObstacle(int x, int y) {
    if (g_obstacleCount < 100 && isObstacleValid(x, y)) {
        g_obstacles[g_obstacleCount].x = x;
        g_obstacles[g_obstacleCount].y = y;
        g_obstacles[g_obstacleCount].exist = true;
        g_obstacles[g_obstacleCount].type = OBSTACLE_STATIC;
        g_obstacleCount++;
    }
}

// 添加单个动态障碍物（指定初始方向）
void addMovingObstacle(int x, int y, int initialDir) {
    if (g_obstacleCount < 100 && isObstacleValid(x, y)) {
        g_obstacles[g_obstacleCount].x = x;
        g_obstacles[g_obstacleCount].y = y;
        g_obstacles[g_obstacleCount].exist = true;
        g_obstacles[g_obstacleCount].type = OBSTACLE_MOVING;
        g_obstacles[g_obstacleCount].dir = initialDir; // 0-3：上下左右
        g_obstacleCount++;
    }
}

// 形状生成函数实现
// 十字形（中心+上下左右，共5个格子）
void addCrossShape(int centerX, int centerY) {
    addSingleObstacle(centerX, centerY);                  // 中心
    addSingleObstacle(centerX, centerY - GRID_SIZE);      // 上
    addSingleObstacle(centerX, centerY + GRID_SIZE);      // 下
    addSingleObstacle(centerX - GRID_SIZE, centerY);      // 左
    addSingleObstacle(centerX + GRID_SIZE, centerY);      // 右
}

// 正方形（2x2，共4个格子）
void addSquareShape(int topLeftX, int topLeftY) {
    addSingleObstacle(topLeftX, topLeftY);                // 左上
    addSingleObstacle(topLeftX + GRID_SIZE, topLeftY);    // 右上
    addSingleObstacle(topLeftX, topLeftY + GRID_SIZE);    // 左下
    addSingleObstacle(topLeftX + GRID_SIZE, topLeftY + GRID_SIZE); // 右下
}

// L形（3个格子，直角朝右下方）
void addLShape(int topLeftX, int topLeftY) {
    addSingleObstacle(topLeftX, topLeftY);                // 左上
    addSingleObstacle(topLeftX, topLeftY + GRID_SIZE);    // 左中
    addSingleObstacle(topLeftX, topLeftY + 2*GRID_SIZE);  // 左下
    addSingleObstacle(topLeftX + GRID_SIZE, topLeftY + 2*GRID_SIZE); // 右下（转折）
}

// T形（中心+上/左右，共4个格子，横向T）
void addTshape(int centerX, int centerY) {
    addSingleObstacle(centerX, centerY);                  // 中心
    addSingleObstacle(centerX, centerY - GRID_SIZE);      // 上
    addSingleObstacle(centerX - GRID_SIZE, centerY);      // 左
    addSingleObstacle(centerX + GRID_SIZE, centerY);      // 右
}

// 直线形（水平/垂直，长度为格子数）
void addLineShape(int startX, int startY, int length, bool horizontal) {
    for (int i = 0; i < length; i++) {
        if (horizontal) {
            addSingleObstacle(startX + i*GRID_SIZE, startY); // 水平（X递增）
        } else {
            addSingleObstacle(startX, startY + i*GRID_SIZE); // 垂直（Y递增）
        }
    }
}

// 菱形（中心+对角线，共5个格子）
void addDiamondShape(int centerX, int centerY) {
    addSingleObstacle(centerX, centerY);                  // 中心
    addSingleObstacle(centerX - GRID_SIZE, centerY - GRID_SIZE); // 上左
    addSingleObstacle(centerX + GRID_SIZE, centerY - GRID_SIZE); // 上右
    addSingleObstacle(centerX - GRID_SIZE, centerY + GRID_SIZE); // 下左
    addSingleObstacle(centerX + GRID_SIZE, centerY + GRID_SIZE); // 下右
}

// 动态障碍物移动逻辑
void moveObstacles() {
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].type != OBSTACLE_MOVING || !g_obstacles[i].exist) {
            continue; // 只处理动态障碍物
        }

        // 保存当前位置
        int oldX = g_obstacles[i].x;
        int oldY = g_obstacles[i].y;
        // 计算新位置（基于方向）
        int newX = oldX;
        int newY = oldY;
        switch (g_obstacles[i].dir) {
            case 0: newY -= GRID_SIZE; break; // 上
            case 1: newX += GRID_SIZE; break; // 右
            case 2: newY += GRID_SIZE; break; // 下
            case 3: newX -= GRID_SIZE; break; // 左
        }

        // 检查新位置是否有效（不碰撞边界、蛇、静态障碍物）
        // 临时标记当前位置为无效，避免检测自身
        g_obstacles[i].exist = false;
        bool canMove = isObstacleValid(newX, newY);
        g_obstacles[i].exist = true;

        if (canMove) {
            // 移动到新位置
            g_obstacles[i].x = newX;
            g_obstacles[i].y = newY;
        } else {
            // 碰撞时随机改变方向（0-3）
            g_obstacles[i].dir = rand() % 4;
        }
    }
}

// 简单模式模板（8-10个障碍物）
void generateEasyTemplate1() {
    addSquareShape(MAP_START_X + 4*GRID_SIZE, MAP_START_Y + 4*GRID_SIZE);
    addLShape(MAP_START_X + 22*GRID_SIZE, MAP_START_Y + 6*GRID_SIZE);
    addTshape(MAP_START_X + 6*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addLineShape(MAP_START_X + 18*GRID_SIZE, MAP_START_Y + 22*GRID_SIZE, 2, true);
    addSingleObstacle(MAP_START_X + 15*GRID_SIZE, MAP_START_Y + 15*GRID_SIZE);
}

void generateEasyTemplate2() {
    addLineShape(MAP_START_X + 3*GRID_SIZE, MAP_START_Y + 5*GRID_SIZE, 2, false);
    addCrossShape(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 8*GRID_SIZE);
    addSquareShape(MAP_START_X + 5*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE);
    addLShape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 18*GRID_SIZE);
    addTshape(MAP_START_X + 14*GRID_SIZE, MAP_START_Y + 14*GRID_SIZE);
}

void generateEasyTemplate3() {
    addTshape(MAP_START_X + 6*GRID_SIZE, MAP_START_Y + 3*GRID_SIZE);
    addLineShape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 5*GRID_SIZE, 3, true);
    addCrossShape(MAP_START_X + 8*GRID_SIZE, MAP_START_Y + 22*GRID_SIZE);
    addSquareShape(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addLShape(MAP_START_X + 16*GRID_SIZE, MAP_START_Y + 16*GRID_SIZE);
}

// 中等模式模板（12-14个障碍物）
void generateMediumTemplate1() {
    addSquareShape(MAP_START_X + 3*GRID_SIZE, MAP_START_Y + 3*GRID_SIZE);
    addLineShape(MAP_START_X + 10*GRID_SIZE, MAP_START_Y + 5*GRID_SIZE, 2, false);
    addCrossShape(MAP_START_X + 22*GRID_SIZE, MAP_START_Y + 4*GRID_SIZE);
    addLShape(MAP_START_X + 26*GRID_SIZE, MAP_START_Y + 10*GRID_SIZE);
    addTshape(MAP_START_X + 5*GRID_SIZE, MAP_START_Y + 22*GRID_SIZE);
    addLineShape(MAP_START_X + 12*GRID_SIZE, MAP_START_Y + 26*GRID_SIZE, 3, true);
    addDiamondShape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addSquareShape(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE);
}

void generateMediumTemplate2() {
    addLShape(MAP_START_X + 4*GRID_SIZE, MAP_START_Y + 6*GRID_SIZE);
    addTshape(MAP_START_X + 8*GRID_SIZE, MAP_START_Y + 4*GRID_SIZE);
    addLineShape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 6*GRID_SIZE, 2, true);
    addSquareShape(MAP_START_X + 25*GRID_SIZE, MAP_START_Y + 8*GRID_SIZE);
    addCrossShape(MAP_START_X + 6*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addLineShape(MAP_START_X + 10*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE, 2, false);
    addDiamondShape(MAP_START_X + 22*GRID_SIZE, MAP_START_Y + 22*GRID_SIZE);
    addTshape(MAP_START_X + 18*GRID_SIZE, MAP_START_Y + 26*GRID_SIZE);
}

void generateMediumTemplate3() {
    addLineShape(MAP_START_X + 2*GRID_SIZE, MAP_START_Y + 2*GRID_SIZE, 3, true);
    addCrossShape(MAP_START_X + 12*GRID_SIZE, MAP_START_Y + 6*GRID_SIZE);
    addSquareShape(MAP_START_X + 22*GRID_SIZE, MAP_START_Y + 2*GRID_SIZE);
    addLShape(MAP_START_X + 26*GRID_SIZE, MAP_START_Y + 12*GRID_SIZE);
    addTshape(MAP_START_X + 4*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addLineShape(MAP_START_X + 8*GRID_SIZE, MAP_START_Y + 25*GRID_SIZE, 3, false);
    addDiamondShape(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 18*GRID_SIZE);
    addCrossShape(MAP_START_X + 18*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE);
}

// 困难模式模板（16-18个障碍物，含动态）
void generateHardTemplate1() {
    // 静态障碍物
    addSquareShape(MAP_START_X + 2*GRID_SIZE, MAP_START_Y + 2*GRID_SIZE);
    addLShape(MAP_START_X + 6*GRID_SIZE, MAP_START_Y + 10*GRID_SIZE);
    addCrossShape(MAP_START_X + 10*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addLineShape(MAP_START_X + 4*GRID_SIZE, MAP_START_Y + 26*GRID_SIZE, 3, true);
    addTshape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 4*GRID_SIZE);
    addDiamondShape(MAP_START_X + 26*GRID_SIZE, MAP_START_Y + 12*GRID_SIZE);
    addLineShape(MAP_START_X + 18*GRID_SIZE, MAP_START_Y + 18*GRID_SIZE, 3, false);
    addSquareShape(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE);
    
    // 动态障碍物（初始方向：1=右，2=下）
    addMovingObstacle(MAP_START_X + 14*GRID_SIZE, MAP_START_Y + 8*GRID_SIZE, 1);
    addMovingObstacle(MAP_START_X + 16*GRID_SIZE, MAP_START_Y + 22*GRID_SIZE, 2);
}

void generateHardTemplate2() {
    // 静态障碍物
    addCrossShape(MAP_START_X + 4*GRID_SIZE, MAP_START_Y + 4*GRID_SIZE);
    addLineShape(MAP_START_X + 12*GRID_SIZE, MAP_START_Y + 2*GRID_SIZE, 3, true);
    addTshape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 6*GRID_SIZE);
    addSquareShape(MAP_START_X + 26*GRID_SIZE, MAP_START_Y + 10*GRID_SIZE);
    addLShape(MAP_START_X + 6*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addDiamondShape(MAP_START_X + 14*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE);
    addLineShape(MAP_START_X + 22*GRID_SIZE, MAP_START_Y + 26*GRID_SIZE, 3, false);
    addCrossShape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 18*GRID_SIZE);
    
    // 动态障碍物（初始方向：3=左，0=上）
    addMovingObstacle(MAP_START_X + 8*GRID_SIZE, MAP_START_Y + 14*GRID_SIZE, 3);
    addMovingObstacle(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 16*GRID_SIZE, 0);
}

void generateHardTemplate3() {
    // 静态障碍物
    addSquareShape(MAP_START_X + 3*GRID_SIZE, MAP_START_Y + 3*GRID_SIZE);
    addLShape(MAP_START_X + 25*GRID_SIZE, MAP_START_Y + 3*GRID_SIZE);
    addTshape(MAP_START_X + 3*GRID_SIZE, MAP_START_Y + 25*GRID_SIZE);
    addDiamondShape(MAP_START_X + 25*GRID_SIZE, MAP_START_Y + 25*GRID_SIZE);
    addLineShape(MAP_START_X + 14*GRID_SIZE, MAP_START_Y + 2*GRID_SIZE, 2, true);
    addLineShape(MAP_START_X + 28*GRID_SIZE, MAP_START_Y + 14*GRID_SIZE, 2, false);
    addLineShape(MAP_START_X + 14*GRID_SIZE, MAP_START_Y + 28*GRID_SIZE, 2, true);
    addLineShape(MAP_START_X + 2*GRID_SIZE, MAP_START_Y + 14*GRID_SIZE, 2, false);
    addCrossShape(MAP_START_X + 15*GRID_SIZE, MAP_START_Y + 15*GRID_SIZE);
    
    // 动态障碍物（初始方向：1=右，2=下）
    addMovingObstacle(MAP_START_X + 10*GRID_SIZE, MAP_START_Y + 10*GRID_SIZE, 1);
    addMovingObstacle(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE, 2);
}

// 初始化障碍物（清空现有）
void initObstacles() {
    g_obstacleCount = 0;
    for (int i = 0; i < 100; i++) {
        g_obstacles[i].exist = false;
    }
}

// 根据难度生成障碍物
void generateObstacles() {
    initObstacles(); // 清空现有障碍物
    srand((unsigned int)time(NULL));
    int templateIdx = rand() % 3; // 0-2随机选择模板

    switch (obstacle) { // obstacle对应难度：1=简单，2=中等，3=困难
        case 1: // 简单模式
            switch (templateIdx) {
                case 0: generateEasyTemplate1(); break;
                case 1: generateEasyTemplate2(); break;
                case 2: generateEasyTemplate3(); break;
            }
            break;
        case 2: // 中等模式
            switch (templateIdx) {
                case 0: generateMediumTemplate1(); break;
                case 1: generateMediumTemplate2(); break;
                case 2: generateMediumTemplate3(); break;
            }
            break;
        case 3: // 困难模式
            switch (templateIdx) {
                case 0: generateHardTemplate1(); break;
                case 1: generateHardTemplate2(); break;
                case 2: generateHardTemplate3(); break;
            }
            break;
    }
}
