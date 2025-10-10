#include "allcpp.h"

// ���λ���Ƿ��ص�������ʳ��ϰ��
bool isFoodOverlap(int x, int y) {
    // �������
    for (int i = 0; i < g_snake.len; i++) {
        if (g_snake.x[i] == x && g_snake.y[i] == y) return true;
    }
    // ���ʳ��
    for (int i = 0; i < g_foodCount; i++) {
        if (g_food[i].exist && g_food[i].x == x && g_food[i].y == y) {
            return true;
        }
    }
    // ����ϰ���
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].exist && g_obstacles[i].x == x && g_obstacles[i].y == y) {
            return true;
        }
    }
    // ������
    for (int i = 0; i < 10; i++) {
        if (g_props[i].exist && g_props[i].x == x && g_props[i].y == y) {
            return true;
        }
    }
    return false;
}

// �Ƴ�����
void removeProp(int index) {
    if (index >= 0 && index < 10) {
        g_props[index].exist = false;
        g_props[index].type = PROP_NONE;
        g_propCount--;
    }
}

// ��������Ч��
void triggerPropEffect(PropType type) {
    switch (type) {
        case PROP_SPEEDUP: {
            // ���٣�ԭʼ�ٶ�*0.5������ԭʼ�ٶȣ�
            g_originalSpeed = snakespeed;
            snakespeed = (int)(snakespeed * 0.5);
            g_speedEffectDuration = 150; // 5�루30֡/�룩
            break;
        }
        case PROP_INVINCIBLE: {
            // �޵�Ч��
            g_isInvincible = true;
            g_invincibleDuration = 150; // 5��
            break;
        }
        case PROP_GROW: {
        // ���浱ǰβ������
        int lastIndex = g_snake.len - 1;
        int newTailX = g_snake.x[lastIndex];
        int newTailY = g_snake.y[lastIndex];
        	
            // ֱ������3��
            g_snake.len += 3;
            
        for(int i=1;i<=3;i++){
        	g_snake.x[g_snake.len-i]=newTailX;
        	g_snake.y[g_snake.len-i]=newTailY;
		}
        
            break;
        }
        case PROP_DOUBLE: {
            // �÷ּӱ�
            g_isDoubleScore = true;
            g_doubleScoreDuration = 240; // 8��
            break;
        }
        default:
            break;
    }
}

// ���µ���Ч��������ʱ�����
void updatePropEffect() {
    // �ٶ�Ч������
    if (g_speedEffectDuration > 0) {
        g_speedEffectDuration--;
        if (g_speedEffectDuration == 0) {
            snakespeed = g_originalSpeed; // �ָ�ԭʼ�ٶ�
        }
    }

    // �÷ּӱ�Ч������
    if (g_doubleScoreDuration > 0) {
        g_doubleScoreDuration--;
        if (g_doubleScoreDuration == 0) {
            g_isDoubleScore = false;
        }
    }

    // �޵�Ч������
    if (g_invincibleDuration > 0) {
        g_invincibleDuration--;
        if (g_invincibleDuration == 0) {
            g_isInvincible = false;
        }
    }

    // ���ߴ���ʱ����£���ʱ��ʧ��
    for (int i = 0; i < 10; i++) {
        if (g_props[i].exist) {
            g_props[i].duration--;
            if (g_props[i].duration <= 0) {
                removeProp(i);
            }
        }
    }
}

// ����ʳ��͵���
void generateFood() {
    
    // �������ʳ��
    for (int i = 0; i < g_foodCount; i++) {
        g_food[i].exist = false;
    }
    g_foodCount = 0;

    // �����Ѷ�����ʳ������
    int foodNum = 1;

    // ����ʳ��
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

    // ���� �޸�1����ߵ������ɸ��ʣ�ȷ�������ܹ�����
    // ������ɵ��ߣ�50%���ʣ���߳��ּ��ʣ�
    if (rand() % 100 < 50 && g_propCount < 10) {
        int idx = 0;
        // �ҵ��յ���λ��
        while (idx < 10 && g_props[idx].exist) idx++;
        if (idx < 10) {
            do {
                int randCol = rand() % MAP_COL;
                g_props[idx].x = MAP_START_X + randCol * GRID_SIZE;
                int randRow = rand() % MAP_ROW;
                g_props[idx].y = MAP_START_Y + randRow * GRID_SIZE;
            } while (isFoodOverlap(g_props[idx].x, g_props[idx].y));
            
            // ����������ͣ�4�ֵ��߸��ʾ��ȣ�
            g_props[idx].type = (PropType)(rand() % 4);
            g_props[idx].exist = true;
            g_props[idx].duration = 300; // ���ߴ���10��
            g_propCount++;
            
            // ���� ������Ϣ����ӡ���ɵĵ�����Ϣ
            // printf("���ɵ���: ����=%d, λ��=(%d,%d)\n", g_props[idx].type, g_props[idx].x, g_props[idx].y);
        }
    }
}
