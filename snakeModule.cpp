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

// �ƶ���
void moveSnake() {
    // ����β��ʼ��ÿ���ڵ��ƶ���ǰһ���ڵ��λ��
    for (int i = g_snake.len - 1; i > 0; i--) {
        g_snake.x[i] = g_snake.x[i - 1];
        g_snake.y[i] = g_snake.y[i - 1];
    }
    
    // ���ݷ����ƶ���ͷ
    switch (g_snake.dir) {
        case 0:  // ��
            g_snake.y[0] -= GRID_SIZE;
            break;
        case 1:  // ��
            g_snake.x[0] += GRID_SIZE;
            break;
        case 2:  // ��
            g_snake.y[0] += GRID_SIZE;
            break;
        case 3:  // ��
            g_snake.x[0] -= GRID_SIZE;
            break;
    }
}

// �ı��ߵķ��򣬷�ֹ180�ȵ�ͷ
void changeDirection(int newDir) {
    // ����Ƿ����෴����(�統ǰ���Ҳ���ֱ������)
    if ((g_snake.dir == 0 && newDir == 2) || 
        (g_snake.dir == 2 && newDir == 0) || 
        (g_snake.dir == 1 && newDir == 3) || 
        (g_snake.dir == 3 && newDir == 1)) {
        return;  // ������180�ȵ�ͷ
    }
    g_snake.dir = newDir;
}
