#include <graphics.h>   // EGE����ͷ�ļ�
#include <cstdio>       // �����������
#include <ctime>        // ʱ����أ�״̬�����ã�
// �Զ���ģ��ͷ�ļ���������ӣ�
#include "Init.h"
#include "Input.h"
#include "Paint.h"
#include "statechange.h"


// ȫ����Ϸ״̬������main.cpp�ж��壬�˴�����Ϊ�ⲿ������
extern GameState g_currentState;

void switchState(GameState targetState) {
    // ״̬�л�ǰ�Ļ����������ã��׶�1�������˳��߼���
    if (targetState == STATE_EXIT) {
        closegraph();  // �˳�ʱ�رմ���
        exit(0);       // ��ֹ����
    }
    // ���µ�ǰ״̬
    g_currentState = targetState;
}
