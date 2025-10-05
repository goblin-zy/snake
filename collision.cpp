#include "allcpp.h"

// ������Ƿ�Ե�ʳ��
bool checkFoodCollision() {
    for (int i = 0; i < g_foodCount; i++) {
        if (g_food[i].exist && 
            g_snake.x[0] == g_food[i].x && 
            g_snake.y[0] == g_food[i].y) {
            
            // ʳ�ﱻ�Ե�����ʧ
            g_food[i].exist = false;
            
            // �߳�������
            g_snake.len++;
            
            // ��������
            g_currentScore += 10;
            
            return true;
        }
    }
    return false;
}

// ������Ƿ���ײ(�߽硢�����ϰ���)
// �޵�״̬�������ϰ�����ײ���߽��������ײ����Ч
bool checkCollision() {
    // 1. ���߽���ײ���޵�״̬��Ӱ��߽���ײ��
    if (g_snake.x[0] < MAP_START_X || g_snake.x[0] >= MAP_END_X ||
        g_snake.y[0] < MAP_START_Y || g_snake.y[0] >= MAP_END_Y) {
        return true;
    }
    
    // 2. ���������ײ���޵�״̬��Ӱ��������ײ��
    for (int i = 1; i < g_snake.len; i++) {
        if (g_snake.x[0] == g_snake.x[i] && g_snake.y[0] == g_snake.y[i]) {
            return true;
        }
    }
    
    // 3. ����ϰ�����ײ���޵�״̬�º��Դ��
    // ����ȫ�ֱ���g_isInvincible��ʶ�޵�״̬������global.h��������
    if (!g_isInvincible) {  // �������޵�״̬ʱ����ϰ�����ײ
        for (int i = 0; i < g_obstacleCount; i++) {
            if (g_obstacles[i].exist && 
                g_snake.x[0] == g_obstacles[i].x && 
                g_snake.y[0] == g_obstacles[i].y) {
                return true;
            }
        }
    }
    
    return false;
}

// ������Ƿ�Ե�����
bool checkPropCollision() {
    for (int i = 0; i < 10; i++) {  // �������е��ߣ����10����
        if (g_props[i].exist && 
            g_snake.x[0] == g_props[i].x && 
            g_snake.y[0] == g_props[i].y) {
            
            // ��������Ч��
            triggerPropEffect(g_props[i].type);
            
            // �Ƴ�����
            removeProp(i);
            
            return true;
        }
    }
    return false;
}
