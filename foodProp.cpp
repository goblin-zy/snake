#include "allcpp.h"

// 检查位置是否重叠（蛇身、食物、障碍物）
bool isFoodOverlap(int x, int y) {
    // 检查蛇身
    for (int i = 0; i < g_snake.len; i++) {
        if (g_snake.x[i] == x && g_snake.y[i] == y) return true;
    }
    // 检查食物
    for (int i = 0; i < g_foodCount; i++) {
        if (g_food[i].exist && g_food[i].x == x && g_food[i].y == y) {
            return true;
        }
    }
    // 检查障碍物
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].exist && g_obstacles[i].x == x && g_obstacles[i].y == y) {
            return true;
        }
    }
    // 检查道具
    for (int i = 0; i < 10; i++) {
        if (g_props[i].exist && g_props[i].x == x && g_props[i].y == y) {
            return true;
        }
    }
    return false;
}

// 移除道具
void removeProp(int index) {
    if (index >= 0 && index < 10) {
        g_props[index].exist = false;
        g_props[index].type = PROP_NONE;
        g_propCount--;
    }
}

// 触发道具效果
void triggerPropEffect(PropType type) {
    switch (type) {
        case PROP_SPEEDUP: {
            // 加速：原始速度*0.5（备份原始速度）
            g_originalSpeed = snakespeed;
            snakespeed = (int)(snakespeed * 0.5);
            g_speedEffectDuration = 150; // 5秒（30帧/秒）
            break;
        }
        case PROP_INVINCIBLE: {
            // 无敌效果
            g_isInvincible = true;
            g_invincibleDuration = 150; // 5秒
            break;
        }
        case PROP_GROW: {
        // 保存当前尾部坐标
        int lastIndex = g_snake.len - 1;
        int newTailX = g_snake.x[lastIndex];
        int newTailY = g_snake.y[lastIndex];
        	
            // 直接增长3节
            g_snake.len += 3;
            
        for(int i=1;i<=3;i++){
        	g_snake.x[g_snake.len-i]=newTailX;
        	g_snake.y[g_snake.len-i]=newTailY;
		}
        
            break;
        }
        case PROP_DOUBLE: {
            // 得分加倍
            g_isDoubleScore = true;
            g_doubleScoreDuration = 240; // 8秒
            break;
        }
        default:
            break;
    }
}

// 更新道具效果（持续时间管理）
void updatePropEffect() {
    // 速度效果更新
    if (g_speedEffectDuration > 0) {
        g_speedEffectDuration--;
        if (g_speedEffectDuration == 0) {
            snakespeed = g_originalSpeed; // 恢复原始速度
        }
    }

    // 得分加倍效果更新
    if (g_doubleScoreDuration > 0) {
        g_doubleScoreDuration--;
        if (g_doubleScoreDuration == 0) {
            g_isDoubleScore = false;
        }
    }

    // 无敌效果更新
    if (g_invincibleDuration > 0) {
        g_invincibleDuration--;
        if (g_invincibleDuration == 0) {
            g_isInvincible = false;
        }
    }

    // 道具存在时间更新（超时消失）
    for (int i = 0; i < 10; i++) {
        if (g_props[i].exist) {
            g_props[i].duration--;
            if (g_props[i].duration <= 0) {
                removeProp(i);
            }
        }
    }
}

// 生成食物和道具
void generateFood() {
    
    // 清空现有食物
    for (int i = 0; i < g_foodCount; i++) {
        g_food[i].exist = false;
    }
    g_foodCount = 0;

    // 根据难度生成食物数量
    int foodNum = 1;

    // 生成食物
    for (int i = 0; i < foodNum; i++) {
        do {
            int randCol = rand() % MAP_COL;
            g_food[g_foodCount].x = MAP_START_X + randCol * GRID_SIZE;
            int randRow = rand() % MAP_ROW;
            g_food[g_foodCount].y = MAP_START_Y + randRow * GRID_SIZE;
        } while (isFoodOverlap(g_food[g_foodCount].x, g_food[g_foodCount].y));
        
        g_food[g_foodCount].exist = true;
        g_foodCount++;
    }

    // ★★★ 修复1：提高道具生成概率，确保道具能够生成
    // 随机生成道具（50%概率，提高出现几率）
    if (rand() % 100 < 50 && g_propCount < 10) {
        int idx = 0;
        // 找到空道具位置
        while (idx < 10 && g_props[idx].exist) idx++;
        if (idx < 10) {
            do {
                int randCol = rand() % MAP_COL;
                g_props[idx].x = MAP_START_X + randCol * GRID_SIZE;
                int randRow = rand() % MAP_ROW;
                g_props[idx].y = MAP_START_Y + randRow * GRID_SIZE;
            } while (isFoodOverlap(g_props[idx].x, g_props[idx].y));
            
            // 随机道具类型（4种道具概率均等）
            g_props[idx].type = (PropType)(rand() % 4);
            g_props[idx].exist = true;
            g_props[idx].duration = 300; // 道具存在10秒
            g_propCount++;
            
            // ★★★ 调试信息：打印生成的道具信息
            // printf("生成道具: 类型=%d, 位置=(%d,%d)\n", g_props[idx].type, g_props[idx].x, g_props[idx].y);
        }
    }
}
