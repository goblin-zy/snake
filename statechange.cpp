#include"allcpp.h"

// ��statechange.cpp�в���״̬�л�ʱ�������߼�
void switchState(GameState targetState) {
    // ״̬�л�ǰ��������
    if (targetState == STATE_MAIN_MENU) {
        // �ص����˵�ʱ������Ϸ״̬
        resetScore();
        // ���Ը�����Ҫ������������߼�
    }
    
    if (targetState == STATE_EXIT) {
        closegraph();
        exit(0);
    }
    g_currentState = targetState;
}
