#include"allcpp.h"

void switchState(GameState targetState) {
    // ״̬�л�ǰ�Ļ����������ã��׶�1�������˳��߼���
    if (targetState == STATE_EXIT) {
        closegraph();  // �˳�ʱ�رմ���
        exit(0);       // ��ֹ����
    }
    // ���µ�ǰ״̬
    g_currentState = targetState;
}
