#ifndef SNAKE_MODULE_H
#define SNAKE_MODULE_H

typedef struct {
    int x[100];  // ����ÿ��X���꣨���100�ڣ����������
    int y[100];  // ����ÿ��Y����
    int dir;     // ���ƶ�����0=�ϣ�1=�ң�2=�£�3=��
    int len;     // ������
} Snake;



 void initSnake(); 
// �ƶ���
void moveSnake();
// �ı��ߵķ���
void changeDirection(int newDir);
 #endif
