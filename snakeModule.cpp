#include "allcpp.h"

void initSnake(){
	g_snake.len=3;
	g_snake.dir=1;
	
    int startX = 14*GRID_SIZE;  // ��ͷ��ʼX
    int startY = 14*GRID_SIZE;                         // ��ͷ��ʼY��ƫ�£�
    
    // 4. ��ֵ����ÿ�����꣨����ͷ����β��X���μ�GRID_SIZE��
    for (int i = 0; i < g_snake.len; i++) {
        g_snake.x[i] = startX - i * GRID_SIZE;  // ��ͷ��i=0�������ң�����Խ����XԽС
        g_snake.y[i] = startY;                  // ���н�Y������ͬ��ˮƽ��ʼ��
    }
}
