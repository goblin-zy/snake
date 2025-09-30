#include <graphics.h>   // EGE����ͷ�ļ�
#include <cstdio>       // �����������
#include <ctime>        // ʱ����أ�״̬�����ã�
// �Զ���ģ��ͷ�ļ���������ӣ�
#include "Init.h"
#include "Input.h"
#include "Paint.h"
#include "statechange.h"



// ����ȫ�ֺ��ı�������ģ�鹲��
GameState g_currentState;  // ��ǰ��Ϸ״̬

// �������˵����������׶�1�����߼���
void handleMainMenu();

int main() {
    // 1. ��ʼ�������ڡ���Դ������
    initWindow(800,600);    // ����640��480����
    loadResources();         // �������˵�ͼƬ/����
    initCoreData();          // ��ʼ����Ϸ״̬Ϊ���˵�

    // 2. ��ѭ��������δ�ر���������У�
    while (is_run()) {
        // ���ݵ�ǰ״ִ̬�ж�Ӧ�߼����׶�1�����˵���
        switch (g_currentState) {
            case STATE_MAIN_MENU:
                handleMainMenu();
                break;
            // ����״̬���Ѷ�ѡ��/���а�ȣ������׶β���
            default:
                break;
        }
        delay_fps(30);  // ����֡�ʣ�30֡/�룬����CPUռ�ù��ߣ�
    }

    // 3. �ͷ���Դ�������˳���
    releaseResources();
    return 0;
}

// ���˵��߼��������ơ�����������л�״̬��
void handleMainMenu() {
    // ����1���������˵�����
    drawMainMenu();

    // ����2�����������
    ClickType click = listenMouseClick();

    // ����3�����ݵ�������л�״̬
    switch (click) {
        case CLICK_START:
            switchState(STATE_DIFFICULTY_SELECT);  // ��ʼ���Ѷ�ѡ��
            break;
        case CLICK_RANKING:
            switchState(STATE_RANKING);            // ���а�����а�״̬
            break;
        case CLICK_SETTING:
            switchState(STATE_SETTING);            // ���á�����״̬
            break;
        case CLICK_EXIT:
            switchState(STATE_EXIT);               // �˳�����ֹ����
            break;
        default:
            break;  // �޵���򲻴���
    }
}
