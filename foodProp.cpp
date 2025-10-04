#include "allcpp.h"


bool isFoodOverlap(int x, int y) {
    // ���е������ʳ���ص����
    for (int i = 0; i < g_snake.len; i++) {
        if (g_snake.x[i] == x && g_snake.y[i] == y) return true;
    }
    for (int i = 0; i < g_foodCount; i++) {
        if (g_food[i].exist && g_food[i].x == x && g_food[i].y == y) {
            return true;
        }
    }

    // ������������ϰ����ص�
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].exist && g_obstacles[i].x == x && g_obstacles[i].y == y) {
            return true;
        }
    }

    return false;
}

void generateFood() {
    srand((unsigned int)time(NULL)); // ��ʼ�����������
    
    // �������ʳ��
    for (int i = 0; i < g_foodCount; i++) {
        g_food[i].exist = false;
    }
    g_foodCount = 0;
    
    // �����Ѷ����ɲ�ͬ������ʳ��
    int foodNum = 1;  

    
    // ����ָ��������ʳ��
    for (int i = 0; i < foodNum; i++) {
        do {
            // ʳ��X�����ڵ�ͼ��Χ��:MAP_START_X + ����*20
            int randCol = rand() % MAP_COL; 
            g_food[g_foodCount].x = MAP_START_X + randCol * GRID_SIZE;
            // ʳ��Y�����ڵ�ͼ��Χ��:MAP_START_Y + ����*20
            int randRow = rand() % MAP_ROW;
            g_food[g_foodCount].y = MAP_START_Y + randRow * GRID_SIZE;
        } while (isFoodOverlap(g_food[g_foodCount].x, g_food[g_foodCount].y)); // �ص�����������
        
        g_food[g_foodCount].exist = true;
        g_foodCount++;
    }
}
