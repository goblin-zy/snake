#ifndef SNAKE_MODULE_H
#define SNAKE_MODULE_H

typedef struct {
    int x[100];  // 蛇身每节X坐标（最大100节，避免溢出）
    int y[100];  // 蛇身每节Y坐标
    int dir;     // 蛇移动方向（0=上，1=右，2=下，3=左）
    int len;     // 蛇身长度
} Snake;



 void initSnake(); 
// 移动蛇
void moveSnake();
// 改变蛇的方向
void changeDirection(int newDir);
 #endif
