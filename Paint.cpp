#include"allcpp.h"

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
}

void drawDifficultySelect(){
    // 1. ���ƺ�ɫ���������800��600���ڣ�
    setfillcolor(BLACK);
    bar(0, 0, 800, 600);

    // 2. ���Ʊ��⣨������ʾ"�Ѷ�ѡ��"��
    setcolor(WHITE);
    setfont(45, 0, "����");
    char title[] = "�Ѷ�ѡ��";
    int titleWidth = textwidth(title);
    int titleX = (800 - titleWidth) / 2;  
    outtextxy(titleX, 63, title);  

    // -------------------------- �ؼ��޸�1����������͸��������ȫ����Ч�� --------------------------
    setbkmode(TRANSPARENT);  // EGE �������������ֱ���Ϊ͸��������������Χ���ֺڿ�

    // 3. ����"��"��ť���޸�����ʽ������ɫ����׼�������־��У�
    setfillcolor(GREEN);      // ��ť����ɫ����ɫ
    bar(BTN_DIFF_X, BTN_EASY_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_EASY_Y+BTN_DIFF_H);
    setcolor(BLACK);          // ������ɫ����ɫ������ɫ�����Աȣ�
    setfont(18, 0, "����");   // ���ִ�С��18�ţ�����50�ߵİ�ť��
    char easyText[] = "��";
    int easyTextW = textwidth(easyText);
    int easyTextH = textheight(easyText);  // ��������ȡ���ָ߶ȣ����ⴹֱƫ��
    // ���־��У�X=��ť����-���ְ��Y=��ť����-���ְ�ߣ��ȹ̶�+15����׼��
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - easyTextW)/2, 
              BTN_EASY_Y + (BTN_DIFF_H - easyTextH)/2, 
              easyText);

    // 4. ����"�е�"��ť���޸���������ɫ������̳���һ����ť��״̬��
    setfillcolor(YELLOW);     // ��ť����ɫ����ɫ
    bar(BTN_DIFF_X, BTN_MEDIUM_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_MEDIUM_Y+BTN_DIFF_H);
    setcolor(BLACK);          // ��ʽ����������ɫ������̳�������ɫ��
    setfont(18, 0, "����");   // ��ʽ�������壨���������С�쳣��
    char mediumText[] = "�е�";
    int mediumTextW = textwidth(mediumText);
    int mediumTextH = textheight(mediumText);
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - mediumTextW)/2, 
              BTN_MEDIUM_Y + (BTN_DIFF_H - mediumTextH)/2, 
              mediumText);

    // 5. ����"����"��ť��ͬ�����޸��߼���
    setfillcolor(RED);        // ��ť����ɫ����ɫ
    bar(BTN_DIFF_X, BTN_HARD_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_HARD_Y+BTN_DIFF_H);
    setcolor(BLACK);          // ������ɫ����ɫ�����ɫ�����Աȣ�
    setfont(18, 0, "����");
    char hardText[] = "����";
    int hardTextW = textwidth(hardText);
    int hardTextH = textheight(hardText);
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - hardTextW)/2, 
              BTN_HARD_Y + (BTN_DIFF_H - hardTextH)/2, 
              hardText);

    // 6. ���Ʒ��ذ�ť���޸���������ɫ�����壩
    setfillcolor(DARKGRAY);   // ��ť����ɫ�����ɫ
    bar(BTN_BACK_X, BTN_BACK_Y, BTN_BACK_X+BTN_BACK_W, BTN_BACK_Y+BTN_BACK_H);
    setcolor(WHITE);          // ������ɫ����ɫ
    setfont(14, 0, "����");   // ������С��14�ţ�����30�ߵİ�ť��
    char backText[] = "����";
    int backTextW = textwidth(backText);
    int backTextH = textheight(backText);
    outtextxy(BTN_BACK_X + (BTN_BACK_W - backTextW)/2, 
              BTN_BACK_Y + (BTN_BACK_H - backTextH)/2, 
              backText);

    // -------------------------- �ؼ��޸�2��ˢ�»�������ȷ������ʵʱ��ʾ --------------------------
   // flushgraph();  // EGE ˫����ˢ�£�������������ӳٻ����
}

void drawReady() {
    // 1. ���ƺ�ɫ������ԭ���߼�������
    setfillcolor(BLACK);
    bar(0, 0, WINDOW_W, WINDOW_H);

    // -------------------------- ����1������20��20�����ߵ�ͼ --------------------------
    setcolor(BLUE); // ��������ǳ��ɫ�����ɫ��������
    // �� �������ߣ�ÿ20pxһ�����ӵ�ͼ���ң�
    for (int x = MAP_START_X; x <= MAP_END_X; x += GRID_SIZE) {
        line(x, MAP_START_Y, x, MAP_END_Y); // ���ߣ�x�̶���y�ӵ�ͼ������
    }
    // �� ���ƺ��ߣ�ÿ20pxһ�����ӵ�ͼ�ϵ��£�
    for (int y = MAP_START_Y; y <= MAP_END_Y; y += GRID_SIZE) {
        line(MAP_START_X, y, MAP_END_X, y); // ���ߣ�y�̶���x�ӵ�ͼ����
    }

    // -------------------------- ����2�����Ʋ��״̬�� --------------------------
    setcolor(WHITE);
    setfont(20, 0, "����");
// �� ״̬�����⣨�Ҳ�200��600״̬���ھ��У�
char statusTitle[] = "��Ϸ״̬";
// �Ҳ�״̬����������ȷ�߽磩
#define STATUS_RIGHT_LEFT 600    // ״̬����߽磨�����Ҳ࿪ʼ��
#define STATUS_RIGHT_WIDTH 200   // ״̬����ȣ��̶�200��

// �������ֿ��
int titleTextWidth = textwidth(statusTitle);
// ����X���� = ״̬����߽� + (״̬����� - ���ֿ��)/2
int titleX = STATUS_RIGHT_LEFT + (STATUS_RIGHT_WIDTH - titleTextWidth) / 2;
// Y���걣��ԭ�У��綥��50px����
int titleY = 50;

// ���ƾ��б���
outtextxy(titleX, titleY, statusTitle);

    // �� �÷���ʾ����ʼ0�֣�g_currentScore��ȫ�ֱ�����
    char scoreText[30];
    sprintf(scoreText, "��ǰ�÷֣�%d", g_currentScore);
    outtextxy(TEXT_SCORE_X, TEXT_SCORE_Y+100, scoreText);
    // �� �Ѷ���ʾ������g_difficultyӳ�����֣�
    char diffText[30];
    if (obstacle == 1) sprintf(diffText, "��ǰ�Ѷȣ���");
    else if (obstacle == 2) sprintf(diffText, "��ǰ�Ѷȣ��е�");
    else sprintf(diffText, "��ǰ�Ѷȣ�����");
    outtextxy(TEXT_DIFF_X, TEXT_DIFF_Y+100, diffText);
    // �� ���ƿ�ʼ��ť����ɫ����+��ɫ���֣�״̬���ڣ�
    setfillcolor(GREEN);
    bar(BTN_READY_START_X, BTN_READY_START_Y, 
        BTN_READY_START_X + BTN_READY_START_W, 
        BTN_READY_START_Y + BTN_READY_START_H);
    setcolor(WHITE);
    setbkmode(TRANSPARENT);//����ڿ���� 
    setfont(18, 0, "����");
    char startBtnText[] = "��ʼ��Ϸ";
    int startBtnTextW = textwidth(startBtnText);
    // ��ť���־���
    outtextxy(BTN_READY_START_X + (BTN_READY_START_W - startBtnTextW)/2, 
              BTN_READY_START_Y + 10, startBtnText);


//����ǽ
    drawObstacles();

    //�ߺ�ʳ��Ļ���
    // 1. �����ߣ�ʹ��ͼƬ�����ɫ��䣩
    for (int i = 0; i < g_snake.len; i++) {
        if (i == 0) {
            // ������ͷ��ʹ����ͷͼƬ����������Ӷ���
            // ����˵����Ŀ��X, Ŀ��Y, ͼƬ��, ͼƬ��, ͼƬָ��, ͼƬ��ʼX, ͼƬ��ʼY, ����ģʽ
            putimage(g_snake.x[i], g_snake.y[i], img_head_right);
        } else {
            // ��������ʹ������ͼƬ
            putimage(g_snake.x[i], g_snake.y[i], img_body);
        }
    }

    // 2. ����ʳ�ʹ��ͼƬ���Բ�Σ�
    for (int i = 0; i < 5; i++) {
        if (g_food[i].exist) {
            // ����ʳ��ͼƬ��ȷ����ȫ���20��20����
            putimage(g_food[i].x, g_food[i].y, img_food);
        }
    }

    // ���� �޸�2����׼���׶�Ҳ���Ƶ���
    drawProp();
}

// ������Ϸ�����е�Ԫ��
void drawRunning() {
    // 1. ���ƺ�ɫ����
    setfillcolor(BLACK);
   bar(0, 0, WINDOW_W, WINDOW_H);

    // 2. ��������
    setcolor(BLUE);
    for (int x = MAP_START_X; x <= MAP_END_X; x += GRID_SIZE) {
        line(x, MAP_START_Y, x, MAP_END_Y);
    }
    for (int y = MAP_START_Y; y <= MAP_END_Y; y += GRID_SIZE) {
        line(MAP_START_X, y, MAP_END_X, y);
    }

//����ǽ
    drawObstacles();

    // 3. ������
    for (int i = 0; i < g_snake.len; i++) {
        if (i == 0) {  // ��ͷ
            switch (g_snake.dir) {
                case 0: putimage(g_snake.x[i], g_snake.y[i], img_head_up); break;
                case 1: putimage(g_snake.x[i], g_snake.y[i], img_head_right); break;
                case 2: putimage(g_snake.x[i], g_snake.y[i], img_head_down); break;
                case 3: putimage(g_snake.x[i], g_snake.y[i], img_head_left); break;
            }
        } else {  // ����
            putimage(g_snake.x[i], g_snake.y[i], img_body);
        }
    }

    // 4. ����ʳ��
    for (int i = 0; i < g_foodCount; i++) {
        if (g_food[i].exist) {
            putimage(g_food[i].x, g_food[i].y, img_food);
        }
    }

    // ���������Ƶ���
    drawProp();

    // 5. ���Ʒ������Ѷ���Ϣ
    setcolor(WHITE);
    setfont(20, 0, "����");
    char scoreText[30];
    sprintf(scoreText, "��ǰ����:%d", g_currentScore);
    outtextxy(TEXT_SCORE_X, TEXT_SCORE_Y, scoreText);

    char diffText[30];
    if (obstacle == 1) sprintf(diffText, "��ǰ�Ѷ�:��");
    else if (obstacle == 2) sprintf(diffText, "��ǰ�Ѷ�:�е�");
    else sprintf(diffText, "��ǰ�Ѷ�:����");
    outtextxy(TEXT_DIFF_X, TEXT_DIFF_Y, diffText);

    if (g_isInvincible) {
        setcolor(RED);
        setfont(16, 0, "����");
        outtextxy(TEXT_SCORE_X, TEXT_SCORE_Y + 30, "�޵�״̬��Ч��!");
    }

    // ��ͣ״̬��ʾ��������
    if (g_currentState == STATE_PAUSED) {
        setcolor(YELLOW);
        setfont(30, 0, "����");
        outtextxy(TEXT_SCORE_X, 200, "����ͣ");
        outtextxy(TEXT_SCORE_X - 30, 240, "���ո����");
    }
}


// �����ϰ���
void drawObstacles() {
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].exist) {
            // ��̬�ϰ��ʹ�� wall.png ͼƬ����
            if (g_obstacles[i].type == OBSTACLE_STATIC) {
                // ȷ�� img_wall ������Դ���غ�������ȷ����
                putimage(g_obstacles[i].x, g_obstacles[i].y, img_wall);
            } 
            // �ƶ��ϰ��ʹ�ú�ɫʵ�ķ�����ƣ����� EGE 19.01��
            else {
                setfillcolor(RED);  // ���������ɫΪ��ɫ
                // ʹ�� EGE ���ݵ� bar �������ƾ��Σ�����Ϊ���ϽǺ����½�����
                bar(
                    g_obstacles[i].x,                // ���Ͻ� X
                    g_obstacles[i].y,                // ���Ͻ� Y
                    g_obstacles[i].x + GRID_SIZE,    // ���½� X���������Сƥ�䣩
                    g_obstacles[i].y + GRID_SIZE     // ���½� Y���������Сƥ�䣩
                );
            }
        }
    }
}

// ���Ƶ���
void drawProp() {
    for (int i = 0; i < 10; i++) {  // �������е���
        if (g_props[i].exist) {
            // ���ݵ������ͻ��Ʋ�ͬ��ͼƬ
            switch (g_props[i].type) {
                case PROP_SPEEDUP:
                    putimage(g_props[i].x, g_props[i].y, img_prop_speedup);
                    break;
                case PROP_INVINCIBLE:
                    putimage(g_props[i].x, g_props[i].y, img_prop_invincible);
                    break;
                case PROP_GROW:
                    putimage(g_props[i].x, g_props[i].y, img_prop_grow);
                    break;
                case PROP_DOUBLE:
                    putimage(g_props[i].x, g_props[i].y, img_prop_double);
                    break;
                default:
                    break;
            }
        }
    }
}

void drawGameOver() {
    setfillcolor(BLACK);
    bar(0, 0, WINDOW_W, WINDOW_H);

    // 1. ��Ϸ��������
    setcolor(RED);
    setfont(50, 0, "����");
    const char* title = "��Ϸ����";
    int titleWidth = textwidth(title);
    int titleX = (WINDOW_W - titleWidth) / 2;
    outtextxy(titleX, 100, title);  // ���Ʊ��⣬��������ռ�

    // 2. ���յ÷���ʾ
    char scoreText[50];
    sprintf(scoreText, "���յ÷�: %d", g_currentScore);
    setcolor(WHITE);
    setfont(30, 0, "����");
    int scoreX = (WINDOW_W - textwidth(scoreText)) / 2;
    outtextxy(scoreX, 200, scoreText);  // ��������λ��

    // 3. ���������������а�
    bool isInRanking = false;
    for (int i = 0; i < 10; i++) {
        if (g_ranking[i].score == g_currentScore&&g_currentScore!=0) {
            isInRanking = true;
            break;
        }
    }
    if (isInRanking) {
        setcolor(GREEN);
        setfont(25, 0, "����");
        const char* congrats = "��ϲ������������а�";
        int congratsX = (WINDOW_W - textwidth(congrats)) / 2;
        outtextxy(congratsX, 260, congrats);  // ����������
    }

    // 4. �û��������������ƣ������ص���
    setcolor(WHITE);
    setfont(20, 0, "����");
    outtextxy(300, 320, "�������û���:");  // ������ʾ����
    // ��������򱳾�
    setcolor(LIGHTGRAY);
    rectangle(300, 350, 550, 380);  // ���������
    // ��ʾ��ǰ������û���
    outtextxy(310, 353, g_username);  // �û�����ʾ����

    // 5. ������ʾ
    setcolor(LIGHTGRAY);
    setfont(20, 0, "����");
    outtextxy(280, 420, "���س�ȷ�ϣ�ESC�������˵�");  // ��ʾ��Ϣ����
}





// �������������ý��棨�����Ѷ�ѡ��
void drawSetting() {
    setfillcolor(BLACK);
    bar(0, 0, 800, 600);

    // ����
    setcolor(WHITE);
    setfont(45, 0, "����");
    char title[] = "����";
    int titleWidth = textwidth(title);
    int titleX = (800 - titleWidth) / 2;
    outtextxy(titleX, 63, title);

    // �Ѷ�ѡ�����
    setfont(30, 0, "����");
    outtextxy(340, 150, "ѡ���Ѷ�");

    // �ѶȰ�ť����ֲ���Ѷ�ѡ����棩
    setbkmode(TRANSPARENT);
    
    // ��
    setfillcolor(GREEN);
    bar(BTN_DIFF_X, BTN_EASY_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_EASY_Y+BTN_DIFF_H);
    setcolor(BLACK);
    setfont(18, 0, "����");
    char easyText[] = "��";
    int easyTextW = textwidth(easyText);
    int easyTextH = textheight(easyText);
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - easyTextW)/2, 
              BTN_EASY_Y + (BTN_DIFF_H - easyTextH)/2, 
              easyText);

    // �е�
    setfillcolor(YELLOW);
    bar(BTN_DIFF_X, BTN_MEDIUM_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_MEDIUM_Y+BTN_DIFF_H);
    setcolor(BLACK);
    setfont(18, 0, "����");
    char mediumText[] = "�е�";
    int mediumTextW = textwidth(mediumText);
    int mediumTextH = textheight(mediumText);
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - mediumTextW)/2, 
              BTN_MEDIUM_Y + (BTN_DIFF_H - mediumTextH)/2, 
              mediumText);

    // ����
    setfillcolor(RED);
    bar(BTN_DIFF_X, BTN_HARD_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_HARD_Y+BTN_DIFF_H);
    setcolor(BLACK);
    setfont(18, 0, "����");
    char hardText[] = "����";
    int hardTextW = textwidth(hardText);
    int hardTextH = textheight(hardText);
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - hardTextW)/2, 
              BTN_HARD_Y + (BTN_DIFF_H - hardTextH)/2, 
              hardText);

    // ���ذ�ť
    setfillcolor(DARKGRAY);
    bar(BTN_BACK_X, BTN_BACK_Y, BTN_BACK_X+BTN_BACK_W, BTN_BACK_Y+BTN_BACK_H);
    setcolor(WHITE);
    setfont(14, 0, "����");
    char backText[] = "����";
    int backTextW = textwidth(backText);
    int backTextH = textheight(backText);
    outtextxy(BTN_BACK_X + (BTN_BACK_W - backTextW)/2, 
              BTN_BACK_Y + (BTN_BACK_H - backTextH)/2, 
              backText);
}





// �������а����
void drawRanking() {
    setfillcolor(BLACK);
    bar(0, 0, WINDOW_W, WINDOW_H);

    // ����
    setcolor(WHITE);
    setfont(45, 0, "����");
    const char* title = "�÷����а�";
    int titleX = (WINDOW_W - textwidth(title)) / 2;
    outtextxy(titleX, 63, title);

    // ��ͷ
    setfont(25, 0, "����");
    outtextxy(220, 150, "����");
    outtextxy(350, 150, "����");
    outtextxy(480, 150, "�û���");

    // ���а�����
    for (int i = 0; i < 10; i++) {
        char buf[50];
        sprintf(buf, "%d.", i+1);
        outtextxy(230, 200 + i*30, buf);

        sprintf(buf, "%d", g_ranking[i].score);
        outtextxy(360, 200 + i*30, buf);

        outtextxy(480, 200 + i*30, g_ranking[i].name);
    }

    // ������ʾ
    setcolor(LIGHTGRAY);
    setfont(20, 0, "����");
    outtextxy(300, 500, "��ESC�������˵�");
}
