
// �޸ĺ��Paint.cpp��������˵��������Ż���
#include <graphics.h>   // EGEͼ�ο�ͷ�ļ�
#include <cstdio>       // ��׼�������
#include <ctime>        // ʱ����غ�����״̬ˢ�µȣ�
// �Զ���ģ��ͷ�ļ�������������
#include "Init.h"
#include "Input.h"
#include "Paint.h"
#include "statechange.h"

#define BTN_START_X  338  // ԭ270 �� 270��1.25=337.5��338
#define BTN_START_Y  188  // ԭ150 �� 150��1.25=187.5��188
#define BTN_RANK_X   338  // ԭ270 �� 338
#define BTN_RANK_Y   263  // ԭ210 �� 210��1.25=262.5��263
#define BTN_SET_X    338  // ԭ270 �� 338
#define BTN_SET_Y    338  // ԭ270 �� 270��1.25=337.5��338
#define BTN_EXIT_X   338  // ԭ270 �� 338
#define BTN_EXIT_Y   413  // ԭ330 �� 330��1.25=412.5��413
#define BTN_W        125  // ԭ100 �� 100��1.25=125
#define BTN_H        50   // ԭ40 �� 40��1.25=50

void drawMainMenu() {
// 1. ���Ʊ�������ɫ����������ڣ�����800��600��
setfillcolor(BLACK);
bar(0, 0, 800, 600);  // ���ڿ�ߴ�640��480��Ϊ800��600

// 2. ���Ʊ��⣨�����Ż��������´��ڣ�
setcolor(WHITE);
setfont(45, 0, "����");  // ���尴�����Ŵ�ԭ36��45��1.25����
char title[] = "̰������Ϸ";
int titleWidth = textwidth(title);  // ��̬��ȡ���ֿ��
int titleX = (800 - titleWidth) / 2;  // �����´��ڿ�ȣ�800�������������
outtextxy(titleX, 63, title);  // Y���갴����������ԭ50��63��1.25����

    // 3. ���ư�ť���滻ΪͼƬ��
    putimage(BTN_START_X, BTN_START_Y, img_start);
    putimage(BTN_RANK_X, BTN_RANK_Y,img_rank);
    putimage(BTN_SET_X, BTN_SET_Y,img_setting);
    putimage(BTN_EXIT_X, BTN_EXIT_Y, img_exit);




/*
    // 3. ���ư�ť���Ż�������ʾ��
    setfillcolor(YELLOW);
    setcolor(DARKGRAY);  // ��ť�߿������ɫ
    setfont(18, 0, "����");  // ��ť����ʹ������

    // ��ʼ��ť
    bar(BTN_START_X, BTN_START_Y, BTN_START_X+BTN_W, BTN_START_Y+BTN_H);
    char startText[] = "��ʼ��Ϸ";
    int startTextWidth = textwidth(startText);
    outtextxy(BTN_START_X + (BTN_W - startTextWidth)/2, BTN_START_Y + 10, startText);
    
    // ���а�ť
    bar(BTN_RANK_X, BTN_RANK_Y, BTN_RANK_X+BTN_W, BTN_RANK_Y+BTN_H);
    char rankText[] = "���а�";
    int rankTextWidth = textwidth(rankText);
    outtextxy(BTN_RANK_X + (BTN_W - rankTextWidth)/2, BTN_RANK_Y + 10, rankText);
    
    // ���ð�ť
    bar(BTN_SET_X, BTN_SET_Y, BTN_SET_X+BTN_W, BTN_SET_Y+BTN_H);
    char setText[] = "����";
    int setTextWidth = textwidth(setText);
    outtextxy(BTN_SET_X + (BTN_W - setTextWidth)/2, BTN_SET_Y + 10, setText);
    
    // �˳���ť
    bar(BTN_EXIT_X, BTN_EXIT_Y, BTN_EXIT_X+BTN_W, BTN_EXIT_Y+BTN_H);
    char exitText[] = "�˳�";
    int exitTextWidth = textwidth(exitText);
    outtextxy(BTN_EXIT_X + (BTN_W - exitTextWidth)/2, BTN_EXIT_Y + 10, exitText);
    */
}
