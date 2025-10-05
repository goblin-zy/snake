#ifndef FOOD_MODULE_H
#define FOOD_MODULE_H

// ��������ö�٣������޵е��ߣ�
typedef enum {
    PROP_SPEEDUP,    // ����
    PROP_INVINCIBLE, // �޵�
    PROP_GROW,       // ����
    PROP_DOUBLE,     // �÷ּӱ�
    PROP_NONE        // �޵���
} PropType;

// ʳ��ṹ��
typedef struct {
    int x;       // ʳ��X����
    int y;       // ʳ��Y����
    bool exist;  // ʳ���Ƿ����
} Food;

// ���߽ṹ��
typedef struct {
    int x;               // ����X����
    int y;               // ����Y����
    PropType type;       // ��������
    bool exist;          // �����Ƿ����
    int duration;        // ���ߴ���ʱ�䣨֡����
} Prop;

// ����ʳ��͵��ߣ������Ѷ����ɣ�
void generateFood();

// ���λ���Ƿ�������ʳ��ϰ����ص�
bool isFoodOverlap(int x, int y);

// ��������Ч��
void triggerPropEffect(PropType type);

// ���µ���Ч��������ʱ����١�״̬�ָ���
void updatePropEffect();

// �Ƴ�����
void removeProp(int index);

#endif
