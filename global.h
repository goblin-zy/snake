#ifndef GLOBAL_H
#define GLOBAL_H


// 全局变量声明（只声明不定义）
extern GameState g_currentState;
extern int g_currentScore;
extern Snake g_snake;
extern Food g_food[100];
extern int g_foodCount;
extern int snakespeed;
extern int obstacle;

//图片 
    extern PIMAGE img_start;
    extern PIMAGE img_rank;
    extern PIMAGE img_setting;
    extern PIMAGE img_exit;

    extern PIMAGE img_head_up;
    extern PIMAGE img_head_down;
    extern PIMAGE img_head_left;
    extern PIMAGE img_head_right;
    extern PIMAGE img_body;
    extern PIMAGE img_food;

    extern PIMAGE img_prop_speedup;    // 加速道具图片
    extern PIMAGE img_prop_invincible; // 无敌道具图片
    extern PIMAGE img_prop_grow;       // 增长道具图片
    extern PIMAGE img_prop_double;     // 得分加倍道具图片

    // 全局障碍物数组及数量
    extern Obstacle g_obstacles[100];  // 最多50个障碍物
    extern int g_obstacleCount;
    
    extern PIMAGE img_wall;  // 新增：墙的图片

    // 在原有基础上添加以下全局变量声明
extern bool g_isInvincible;            // 无敌状态标记
extern int g_invincibleDuration;       // 无敌持续时间（帧数）
extern bool g_isDoubleScore;           // 得分加倍标记
extern int g_doubleScoreDuration;      // 得分加倍持续时间
extern int g_originalSpeed;            // 原始速度（用于加速效果恢复）
extern int g_speedEffectDuration;      // 速度效果持续时间
extern Prop g_props[10];               // 道具数组
extern int g_propCount;                // 道具数量
#endif
