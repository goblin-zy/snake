#ifndef FOOD_MODULE_H
#define FOOD_MODULE_H
typedef struct {
    int x;       // ʳ��X����
    int y;       // ʳ��Y����
    bool exist;  // ʳ���Ƿ���ڣ������ظ����ƣ�
} Food;



// ����ʳ�׼���׶ε��ã����ݵ�ǰ�Ѷ����ɶ�Ӧ������ʳ�
void generateFood();

// �����������ж�ʳ�������Ƿ��������ص�������ʳ�������������ϣ�
bool isFoodOverlap(int x, int y);

#endif
