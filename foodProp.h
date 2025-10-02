#ifndef FOOD_MODULE_H
#define FOOD_MODULE_H
typedef struct {
    int x;       // 食物X坐标
    int y;       // 食物Y坐标
    bool exist;  // 食物是否存在（避免重复绘制）
} Food;



// 生成食物（准备阶段调用，根据当前难度生成对应数量的食物）
void generateFood();

// 辅助函数：判断食物坐标是否与蛇身重叠（避免食物生成在蛇身上）
bool isFoodOverlap(int x, int y);

#endif
