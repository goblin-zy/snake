#ifndef OBSTACLE_MODULE_H
#define OBSTACLE_MODULE_H

// 障碍物类型定义（保持不变）
enum ObstacleType {
    OBSTACLE_STATIC,   // 静态障碍物
    OBSTACLE_MOVING    // 动态障碍物
};

// 障碍物结构体（保持不变）
typedef struct {
    int x;              // X坐标
    int y;              // Y坐标
    bool exist;         // 是否存在
    ObstacleType type;  // 障碍物类型
    int dir;            // 移动方向(0-7，八方移动)
} Obstacle;

// 初始化障碍物
void initObstacles();

// 生成障碍物（核心修改函数）
void generateObstacles();

// 移动障碍物（困难模式）
void moveObstacles();

// 简单难度模板（3套）
void generateEasyTemplate1();
void generateEasyTemplate2();
void generateEasyTemplate3();

// 中等难度模板（3套）
void generateMediumTemplate1();
void generateMediumTemplate2();
void generateMediumTemplate3();

// 困难难度模板（3套）
void generateHardTemplate1();
void generateHardTemplate2();
void generateHardTemplate3();

// 形状生成函数（保持不变）
void addCrossShape(int centerX, int centerY);
void addSquareShape(int topLeftX, int topLeftY);
void addLShape(int topLeftX, int topLeftY);
void addTshape(int centerX, int centerY);
void addLineShape(int startX, int startY, int length, bool horizontal);
void addDiamondShape(int centerX, int centerY);

#endif
