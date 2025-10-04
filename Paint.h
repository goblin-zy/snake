#ifndef RENDER_MODULE_H
#define RENDER_MODULE_H




#define WINDOW_W 800
#define WINDOW_H 600

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

//�ѶȻ��ƶ��峣��
    // �����ѶȰ�ť�ߴ磨�����˵���ťһ�£�125��50��
    #define BTN_DIFF_W 125
    #define BTN_DIFF_H 50
    // ��ťˮƽ���У�800���ڿ�� - ��ť��ȣ�/2
    #define BTN_DIFF_X (800 - BTN_DIFF_W)/2
    // ��ť��ֱλ�ã������·��������У����50����
    #define BTN_EASY_Y 200    // �򵥰�ťY����
    #define BTN_MEDIUM_Y 280  // �еȰ�ťY���꣨200+50+30�����
    #define BTN_HARD_Y 360    // ���Ѱ�ťY����

    #define BTN_BACK_W 80
    #define BTN_BACK_H 30
    #define BTN_BACK_X 20
    #define BTN_BACK_Y 550

//��ʼ��������Ҫ�ĳ���
#define GRID_SIZE 20    // ���ӳߴ磨20��20���أ�����Ҫ��

#define MAP_START_X 0 // ��ͼ���Ͻ�X���꣨�Ҳ���200������״̬����
#define MAP_START_Y 0  // ��ͼ���Ͻ�Y���꣨������50���ؼ�ࣩ
#define MAP_COL 30      // ��ͼ������30�С�20px=600px����ͼ�ܿ�600��
#define MAP_ROW 30      // ��ͼ������25�С�20px=500px����ͼ�ܸ�500��
#define MAP_END_X (MAP_START_X + MAP_COL * GRID_SIZE) // ��ͼ���½�X
#define MAP_END_Y (MAP_START_Y + MAP_ROW * GRID_SIZE) // ��ͼ���½�Y

// -------------------------- ������״̬����������߲��֣� --------------------------
#define STATUS_START_X 680 // ״̬�����Ͻ�X����
#define STATUS_START_Y 100 // ״̬�����Ͻ�Y����
// 1. ��ʼ��ť������״̬���ڣ�
#define BTN_READY_START_W 120 // ��ʼ��ť���
#define BTN_READY_START_H 40  // ��ʼ��ť�߶�
#define BTN_READY_START_X 640
#define BTN_READY_START_Y 150 // ״̬����Y����
// 2. �÷�/�Ѷ��ı�λ�ã�״̬���ڣ�
#define TEXT_SCORE_X 640
#define TEXT_SCORE_Y  300// �÷��ı�Y
#define TEXT_DIFF_X 640
#define TEXT_DIFF_Y  450 // �Ѷ��ı�Y 

// �������˵����棨�׶�1���Ļ��ƺ�����
void drawMainMenu();
void drawDifficultySelect();
void drawReady();
// ������Ϸ����״̬
void drawRunning();
// �����ϰ���
void drawObstacles();
#endif

