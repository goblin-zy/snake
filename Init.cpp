#include <graphics.h>   // EGE����ͷ�ļ�
#include <cstdio>       // �����������
#include <ctime>        // ʱ����أ�״̬�����ã�
// �Զ���ģ��ͷ�ļ���������ӣ�
#include "Init.h"
#include "Input.h"
#include "Paint.h"
#include "statechange.h"

extern GameState g_currentState;

    PIMAGE img_start;
    PIMAGE img_rank;
    PIMAGE img_setting;
    PIMAGE img_exit;


void initWindow(int width, int height) {
    setinitmode(0);
    initgraph(width, height);
    setcaption("̰���� - ���˵�");
}

void loadResources() {
//Ĭ�����ã��й���ͼƬ֮�ࡣ 

    img_start=newimage();
    img_rank=newimage();
    img_setting=newimage();
    img_exit=newimage();

    getimage(img_start,"btn_start.png");
    getimage(img_rank,"btn_rank.png");
    getimage(img_setting,"btn_setting.png");
    getimage(img_exit,"btn_exit.png");
    
}

void initCoreData() {
    g_currentState = STATE_MAIN_MENU;  // ��ʼ��״̬
}

void releaseResources() {
	delimage(img_start);
	delimage(img_rank);
	delimage(img_setting);
	delimage(img_exit);
	cleardevice(); 
    closegraph();
}
