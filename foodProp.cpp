#include "allcpp.h"


// �����������ж�ʳ���Ƿ��������ص���ԭ���߼�������
bool isFoodOverlap(int x, int y) {
    for (int i = 0; i < g_snake.len; i++) {
        if (g_snake.x[i] == x && g_snake.y[i] == y) return true;
    }
    return false;
}

void generateFood() {
    srand((unsigned int)time(NULL)); // ��ʼ��������ӣ�ԭ���߼�������

    // -------------------------- ������ʳ�����������ͼ���� --------------------------
    //ÿ��ֻ����һ��ʳ���g_foodCount������
        do {
            // ʳ��X����ͼ������У�MAP_START_X + �кš�20��
            int randCol = rand() % MAP_COL; 
            g_food[g_foodCount].x = MAP_START_X + randCol * GRID_SIZE;
            // ʳ��Y����ͼ������У�MAP_START_Y + �кš�20��
            int randRow = rand() % MAP_ROW;
            g_food[g_foodCount].y = MAP_START_Y + randRow * GRID_SIZE;
        } while (isFoodOverlap(g_food[g_foodCount].x, g_food[g_foodCount].y)); // �ص�����������

        g_food[g_foodCount].exist = true;
        g_foodCount++;


    /*����ʳ����Ϊ�����ڣ�ԭ���߼�������
    for (int i = g_foodCount; i < 5; i++) {
        g_food[i].exist = false;
    }
    */
}
