#include "allcpp.h"

// ��֤�ϰ���λ����Ч�ԣ����ص���
bool isObstacleValid(int x, int y) {
    // ����Ƿ������ص�
    for (int i = 0; i < g_snake.len; i++) {
        if (g_snake.x[i] == x && g_snake.y[i] == y) {
            return false;
        }
    }
    // ����Ƿ���ʳ���ص�
    for (int i = 0; i < g_foodCount; i++) {
        if (g_food[i].exist && g_food[i].x == x && g_food[i].y == y) {
            return false;
        }
    }
    // ����Ƿ��������ϰ����ص�
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].exist && g_obstacles[i].x == x && g_obstacles[i].y == y) {
            return false;
        }
    }
    // ����Ƿ񳬳���ͼ��Χ
    if (x < MAP_START_X || x >= MAP_END_X || y < MAP_START_Y || y >= MAP_END_Y) {
        return false;
    }
    return true;
}

// ��ӵ�����̬�ϰ���
void addSingleObstacle(int x, int y) {
    if (g_obstacleCount < 100 && isObstacleValid(x, y)) {
        g_obstacles[g_obstacleCount].x = x;
        g_obstacles[g_obstacleCount].y = y;
        g_obstacles[g_obstacleCount].exist = true;
        g_obstacles[g_obstacleCount].type = OBSTACLE_STATIC;
        g_obstacleCount++;
    }
}

// ��ӵ�����̬�ϰ��ָ����ʼ����
void addMovingObstacle(int x, int y, int initialDir) {
    if (g_obstacleCount < 100 && isObstacleValid(x, y)) {
        g_obstacles[g_obstacleCount].x = x;
        g_obstacles[g_obstacleCount].y = y;
        g_obstacles[g_obstacleCount].exist = true;
        g_obstacles[g_obstacleCount].type = OBSTACLE_MOVING;
        g_obstacles[g_obstacleCount].dir = initialDir; // 0-3����������
        g_obstacleCount++;
    }
}

// ��״���ɺ���ʵ��
// ʮ���Σ�����+�������ң���5�����ӣ�
void addCrossShape(int centerX, int centerY) {
    addSingleObstacle(centerX, centerY);                  // ����
    addSingleObstacle(centerX, centerY - GRID_SIZE);      // ��
    addSingleObstacle(centerX, centerY + GRID_SIZE);      // ��
    addSingleObstacle(centerX - GRID_SIZE, centerY);      // ��
    addSingleObstacle(centerX + GRID_SIZE, centerY);      // ��
}

// �����Σ�2x2����4�����ӣ�
void addSquareShape(int topLeftX, int topLeftY) {
    addSingleObstacle(topLeftX, topLeftY);                // ����
    addSingleObstacle(topLeftX + GRID_SIZE, topLeftY);    // ����
    addSingleObstacle(topLeftX, topLeftY + GRID_SIZE);    // ����
    addSingleObstacle(topLeftX + GRID_SIZE, topLeftY + GRID_SIZE); // ����
}

// L�Σ�3�����ӣ�ֱ�ǳ����·���
void addLShape(int topLeftX, int topLeftY) {
    addSingleObstacle(topLeftX, topLeftY);                // ����
    addSingleObstacle(topLeftX, topLeftY + GRID_SIZE);    // ����
    addSingleObstacle(topLeftX, topLeftY + 2*GRID_SIZE);  // ����
    addSingleObstacle(topLeftX + GRID_SIZE, topLeftY + 2*GRID_SIZE); // ���£�ת�ۣ�
}

// T�Σ�����+��/���ң���4�����ӣ�����T��
void addTshape(int centerX, int centerY) {
    addSingleObstacle(centerX, centerY);                  // ����
    addSingleObstacle(centerX, centerY - GRID_SIZE);      // ��
    addSingleObstacle(centerX - GRID_SIZE, centerY);      // ��
    addSingleObstacle(centerX + GRID_SIZE, centerY);      // ��
}

// ֱ���Σ�ˮƽ/��ֱ������Ϊ��������
void addLineShape(int startX, int startY, int length, bool horizontal) {
    for (int i = 0; i < length; i++) {
        if (horizontal) {
            addSingleObstacle(startX + i*GRID_SIZE, startY); // ˮƽ��X������
        } else {
            addSingleObstacle(startX, startY + i*GRID_SIZE); // ��ֱ��Y������
        }
    }
}

// ���Σ�����+�Խ��ߣ���5�����ӣ�
void addDiamondShape(int centerX, int centerY) {
    addSingleObstacle(centerX, centerY);                  // ����
    addSingleObstacle(centerX - GRID_SIZE, centerY - GRID_SIZE); // ����
    addSingleObstacle(centerX + GRID_SIZE, centerY - GRID_SIZE); // ����
    addSingleObstacle(centerX - GRID_SIZE, centerY + GRID_SIZE); // ����
    addSingleObstacle(centerX + GRID_SIZE, centerY + GRID_SIZE); // ����
}

// ��̬�ϰ����ƶ��߼�
void moveObstacles() {
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].type != OBSTACLE_MOVING || !g_obstacles[i].exist) {
            continue; // ֻ����̬�ϰ���
        }

        // ���浱ǰλ��
        int oldX = g_obstacles[i].x;
        int oldY = g_obstacles[i].y;
        // ������λ�ã����ڷ���
        int newX = oldX;
        int newY = oldY;
        switch (g_obstacles[i].dir) {
            case 0: newY -= GRID_SIZE; break; // ��
            case 1: newX += GRID_SIZE; break; // ��
            case 2: newY += GRID_SIZE; break; // ��
            case 3: newX -= GRID_SIZE; break; // ��
        }

        // �����λ���Ƿ���Ч������ײ�߽硢�ߡ���̬�ϰ��
        // ��ʱ��ǵ�ǰλ��Ϊ��Ч������������
        g_obstacles[i].exist = false;
        bool canMove = isObstacleValid(newX, newY);
        g_obstacles[i].exist = true;

        if (canMove) {
            // �ƶ�����λ��
            g_obstacles[i].x = newX;
            g_obstacles[i].y = newY;
        } else {
            // ��ײʱ����ı䷽��0-3��
            g_obstacles[i].dir = rand() % 4;
        }
    }
}

// ��ģʽģ�壨8-10���ϰ��
void generateEasyTemplate1() {
    addSquareShape(MAP_START_X + 4*GRID_SIZE, MAP_START_Y + 4*GRID_SIZE);
    addLShape(MAP_START_X + 22*GRID_SIZE, MAP_START_Y + 6*GRID_SIZE);
    addTshape(MAP_START_X + 6*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addLineShape(MAP_START_X + 18*GRID_SIZE, MAP_START_Y + 22*GRID_SIZE, 2, true);
    addSingleObstacle(MAP_START_X + 15*GRID_SIZE, MAP_START_Y + 15*GRID_SIZE);
}

void generateEasyTemplate2() {
    addLineShape(MAP_START_X + 3*GRID_SIZE, MAP_START_Y + 5*GRID_SIZE, 2, false);
    addCrossShape(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 8*GRID_SIZE);
    addSquareShape(MAP_START_X + 5*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE);
    addLShape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 18*GRID_SIZE);
    addTshape(MAP_START_X + 14*GRID_SIZE, MAP_START_Y + 14*GRID_SIZE);
}

void generateEasyTemplate3() {
    addTshape(MAP_START_X + 6*GRID_SIZE, MAP_START_Y + 3*GRID_SIZE);
    addLineShape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 5*GRID_SIZE, 3, true);
    addCrossShape(MAP_START_X + 8*GRID_SIZE, MAP_START_Y + 22*GRID_SIZE);
    addSquareShape(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addLShape(MAP_START_X + 16*GRID_SIZE, MAP_START_Y + 16*GRID_SIZE);
}

// �е�ģʽģ�壨12-14���ϰ��
void generateMediumTemplate1() {
    addSquareShape(MAP_START_X + 3*GRID_SIZE, MAP_START_Y + 3*GRID_SIZE);
    addLineShape(MAP_START_X + 10*GRID_SIZE, MAP_START_Y + 5*GRID_SIZE, 2, false);
    addCrossShape(MAP_START_X + 22*GRID_SIZE, MAP_START_Y + 4*GRID_SIZE);
    addLShape(MAP_START_X + 26*GRID_SIZE, MAP_START_Y + 10*GRID_SIZE);
    addTshape(MAP_START_X + 5*GRID_SIZE, MAP_START_Y + 22*GRID_SIZE);
    addLineShape(MAP_START_X + 12*GRID_SIZE, MAP_START_Y + 26*GRID_SIZE, 3, true);
    addDiamondShape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addSquareShape(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE);
}

void generateMediumTemplate2() {
    addLShape(MAP_START_X + 4*GRID_SIZE, MAP_START_Y + 6*GRID_SIZE);
    addTshape(MAP_START_X + 8*GRID_SIZE, MAP_START_Y + 4*GRID_SIZE);
    addLineShape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 6*GRID_SIZE, 2, true);
    addSquareShape(MAP_START_X + 25*GRID_SIZE, MAP_START_Y + 8*GRID_SIZE);
    addCrossShape(MAP_START_X + 6*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addLineShape(MAP_START_X + 10*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE, 2, false);
    addDiamondShape(MAP_START_X + 22*GRID_SIZE, MAP_START_Y + 22*GRID_SIZE);
    addTshape(MAP_START_X + 18*GRID_SIZE, MAP_START_Y + 26*GRID_SIZE);
}

void generateMediumTemplate3() {
    addLineShape(MAP_START_X + 2*GRID_SIZE, MAP_START_Y + 2*GRID_SIZE, 3, true);
    addCrossShape(MAP_START_X + 12*GRID_SIZE, MAP_START_Y + 6*GRID_SIZE);
    addSquareShape(MAP_START_X + 22*GRID_SIZE, MAP_START_Y + 2*GRID_SIZE);
    addLShape(MAP_START_X + 26*GRID_SIZE, MAP_START_Y + 12*GRID_SIZE);
    addTshape(MAP_START_X + 4*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addLineShape(MAP_START_X + 8*GRID_SIZE, MAP_START_Y + 25*GRID_SIZE, 3, false);
    addDiamondShape(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 18*GRID_SIZE);
    addCrossShape(MAP_START_X + 18*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE);
}

// ����ģʽģ�壨16-18���ϰ������̬��
void generateHardTemplate1() {
    // ��̬�ϰ���
    addSquareShape(MAP_START_X + 2*GRID_SIZE, MAP_START_Y + 2*GRID_SIZE);
    addLShape(MAP_START_X + 6*GRID_SIZE, MAP_START_Y + 10*GRID_SIZE);
    addCrossShape(MAP_START_X + 10*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addLineShape(MAP_START_X + 4*GRID_SIZE, MAP_START_Y + 26*GRID_SIZE, 3, true);
    addTshape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 4*GRID_SIZE);
    addDiamondShape(MAP_START_X + 26*GRID_SIZE, MAP_START_Y + 12*GRID_SIZE);
    addLineShape(MAP_START_X + 18*GRID_SIZE, MAP_START_Y + 18*GRID_SIZE, 3, false);
    addSquareShape(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE);
    
    // ��̬�ϰ����ʼ����1=�ң�2=�£�
    addMovingObstacle(MAP_START_X + 14*GRID_SIZE, MAP_START_Y + 8*GRID_SIZE, 1);
    addMovingObstacle(MAP_START_X + 16*GRID_SIZE, MAP_START_Y + 22*GRID_SIZE, 2);
}

void generateHardTemplate2() {
    // ��̬�ϰ���
    addCrossShape(MAP_START_X + 4*GRID_SIZE, MAP_START_Y + 4*GRID_SIZE);
    addLineShape(MAP_START_X + 12*GRID_SIZE, MAP_START_Y + 2*GRID_SIZE, 3, true);
    addTshape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 6*GRID_SIZE);
    addSquareShape(MAP_START_X + 26*GRID_SIZE, MAP_START_Y + 10*GRID_SIZE);
    addLShape(MAP_START_X + 6*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE);
    addDiamondShape(MAP_START_X + 14*GRID_SIZE, MAP_START_Y + 24*GRID_SIZE);
    addLineShape(MAP_START_X + 22*GRID_SIZE, MAP_START_Y + 26*GRID_SIZE, 3, false);
    addCrossShape(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 18*GRID_SIZE);
    
    // ��̬�ϰ����ʼ����3=��0=�ϣ�
    addMovingObstacle(MAP_START_X + 8*GRID_SIZE, MAP_START_Y + 14*GRID_SIZE, 3);
    addMovingObstacle(MAP_START_X + 24*GRID_SIZE, MAP_START_Y + 16*GRID_SIZE, 0);
}

void generateHardTemplate3() {
    // ��̬�ϰ���
    addSquareShape(MAP_START_X + 3*GRID_SIZE, MAP_START_Y + 3*GRID_SIZE);
    addLShape(MAP_START_X + 25*GRID_SIZE, MAP_START_Y + 3*GRID_SIZE);
    addTshape(MAP_START_X + 3*GRID_SIZE, MAP_START_Y + 25*GRID_SIZE);
    addDiamondShape(MAP_START_X + 25*GRID_SIZE, MAP_START_Y + 25*GRID_SIZE);
    addLineShape(MAP_START_X + 14*GRID_SIZE, MAP_START_Y + 2*GRID_SIZE, 2, true);
    addLineShape(MAP_START_X + 28*GRID_SIZE, MAP_START_Y + 14*GRID_SIZE, 2, false);
    addLineShape(MAP_START_X + 14*GRID_SIZE, MAP_START_Y + 28*GRID_SIZE, 2, true);
    addLineShape(MAP_START_X + 2*GRID_SIZE, MAP_START_Y + 14*GRID_SIZE, 2, false);
    addCrossShape(MAP_START_X + 15*GRID_SIZE, MAP_START_Y + 15*GRID_SIZE);
    
    // ��̬�ϰ����ʼ����1=�ң�2=�£�
    addMovingObstacle(MAP_START_X + 10*GRID_SIZE, MAP_START_Y + 10*GRID_SIZE, 1);
    addMovingObstacle(MAP_START_X + 20*GRID_SIZE, MAP_START_Y + 20*GRID_SIZE, 2);
}

// ��ʼ���ϰ��������У�
void initObstacles() {
    g_obstacleCount = 0;
    for (int i = 0; i < 100; i++) {
        g_obstacles[i].exist = false;
    }
}

// �����Ѷ������ϰ���
void generateObstacles() {
    initObstacles(); // ��������ϰ���
    srand((unsigned int)time(NULL));
    int templateIdx = rand() % 3; // 0-2���ѡ��ģ��

    switch (obstacle) { // obstacle��Ӧ�Ѷȣ�1=�򵥣�2=�еȣ�3=����
        case 1: // ��ģʽ
            switch (templateIdx) {
                case 0: generateEasyTemplate1(); break;
                case 1: generateEasyTemplate2(); break;
                case 2: generateEasyTemplate3(); break;
            }
            break;
        case 2: // �е�ģʽ
            switch (templateIdx) {
                case 0: generateMediumTemplate1(); break;
                case 1: generateMediumTemplate2(); break;
                case 2: generateMediumTemplate3(); break;
            }
            break;
        case 3: // ����ģʽ
            switch (templateIdx) {
                case 0: generateHardTemplate1(); break;
                case 1: generateHardTemplate2(); break;
                case 2: generateHardTemplate3(); break;
            }
            break;
    }
}
