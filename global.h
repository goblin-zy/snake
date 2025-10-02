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
#endif
