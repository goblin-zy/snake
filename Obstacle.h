#ifndef OBSTACLE_MODULE_H
#define OBSTACLE_MODULE_H

// �ϰ������Ͷ��壨���ֲ��䣩
enum ObstacleType {
    OBSTACLE_STATIC,   // ��̬�ϰ���
    OBSTACLE_MOVING    // ��̬�ϰ���
};

// �ϰ���ṹ�壨���ֲ��䣩
typedef struct {
    int x;              // X����
    int y;              // Y����
    bool exist;         // �Ƿ����
    ObstacleType type;  // �ϰ�������
    int dir;            // �ƶ�����(0-7���˷��ƶ�)
} Obstacle;

// ��ʼ���ϰ���
void initObstacles();

// �����ϰ�������޸ĺ�����
void generateObstacles();

// �ƶ��ϰ������ģʽ��
void moveObstacles();

// ���Ѷ�ģ�壨3�ף�
void generateEasyTemplate1();
void generateEasyTemplate2();
void generateEasyTemplate3();

// �е��Ѷ�ģ�壨3�ף�
void generateMediumTemplate1();
void generateMediumTemplate2();
void generateMediumTemplate3();

// �����Ѷ�ģ�壨3�ף�
void generateHardTemplate1();
void generateHardTemplate2();
void generateHardTemplate3();

// ��״���ɺ��������ֲ��䣩
void addCrossShape(int centerX, int centerY);
void addSquareShape(int topLeftX, int topLeftY);
void addLShape(int topLeftX, int topLeftY);
void addTshape(int centerX, int centerY);
void addLineShape(int startX, int startY, int length, bool horizontal);
void addDiamondShape(int centerX, int centerY);

#endif
