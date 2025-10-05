#ifndef FOOD_MODULE_H
#define FOOD_MODULE_H

// 道具类型枚举（包含无敌道具）
typedef enum {
    PROP_SPEEDUP,    // 加速
    PROP_INVINCIBLE, // 无敌
    PROP_GROW,       // 增长
    PROP_DOUBLE,     // 得分加倍
    PROP_NONE        // 无道具
} PropType;

// 食物结构体
typedef struct {
    int x;       // 食物X坐标
    int y;       // 食物Y坐标
    bool exist;  // 食物是否存在
} Food;

// 道具结构体
typedef struct {
    int x;               // 道具X坐标
    int y;               // 道具Y坐标
    PropType type;       // 道具类型
    bool exist;          // 道具是否存在
    int duration;        // 道具存在时间（帧数）
} Prop;

// 生成食物和道具（根据难度生成）
void generateFood();

// 检查位置是否与蛇身、食物、障碍物重叠
bool isFoodOverlap(int x, int y);

// 触发道具效果
void triggerPropEffect(PropType type);

// 更新道具效果（持续时间减少、状态恢复）
void updatePropEffect();

// 移除道具
void removeProp(int index);

#endif
