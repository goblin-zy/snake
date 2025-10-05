#ifndef COLLISION_MODULE_H
#define COLLISION_MODULE_H

// 检查蛇是否吃到食物
bool checkFoodCollision();
// 检查蛇是否碰撞(边界、自身、障碍物)
bool checkCollision();

bool checkPropCollision();
#endif
