#include "allcpp.h"



// ȫ�ֱ������壨ֻ����һ�Σ�
GameState g_currentState;  // ��ǰ��Ϸ״̬
int g_currentScore = 0;
Snake g_snake;
Food g_food[100];
int g_foodCount = 0;
int snakespeed;
int obstacle;

//�������
bool g_isInvincible = false;
int g_invincibleDuration = 0;
bool g_isDoubleScore = false;
int g_doubleScoreDuration = 0;
int g_originalSpeed = 0;
int g_speedEffectDuration = 0;
Prop g_props[10] = {0};
int g_propCount = 0;

// ��ʼ��ȫ�ֱ���
Obstacle g_obstacles[100];  // ����������100��
int g_obstacleCount = 0;

RankingEntry g_ranking[10];  // �̶�10������λ��

char g_username[20];

//ͼƬ 
    PIMAGE img_start;
    PIMAGE img_rank;
    PIMAGE img_setting;
    PIMAGE img_exit;
//�ߵ�ͼƬ
    PIMAGE img_head_up;
    PIMAGE img_head_down;
    PIMAGE img_head_left;
    PIMAGE img_head_right;
    PIMAGE img_body;
//ʳ���ͼƬ
    PIMAGE img_food;
//�ϰ���ͼƬ
    PIMAGE img_wall; 

//����
 PIMAGE img_prop_speedup;    // ���ٵ���ͼƬ
 PIMAGE img_prop_invincible; // �޵е���ͼƬ
 PIMAGE img_prop_grow;       // ��������ͼƬ
 PIMAGE img_prop_double;     // �÷ּӱ�����ͼƬ


// �������˵����������׶�1�����߼���
void handleMainMenu();
void handleReadyStage();
void handleRunning();
void handleGameOver();
void handleSetting();
void handleRanking(); 
void handlePaused();

int main() {
    srand((unsigned int)time(NULL));    
    initWindow(800,600);
    loadResources();
    initCoreData();
    loadRankingFromFile(); // ���ر�������а�

    while (is_run()) {
        switch (g_currentState) {
            case STATE_MAIN_MENU:
                handleMainMenu();
                break;
            case STATE_READY:
                handleReadyStage();
                break;
            case STATE_RUNNING:
                handleRunning();
                break;
            case STATE_PAUSED: // ��ͣ״̬��������ʱ�Ļ����߼�
                handlePaused();
				break; 
            case STATE_GAME_OVER:
                handleGameOver();
                break;
            case STATE_RANKING:
                handleRanking();
                break;
            case STATE_SETTING:
                handleSetting();
                break;
            case STATE_EXIT:
                closegraph(); // �˳���Ϸ
                return 0;
            default:
                break;
        }
        delay_fps(30);
    }

    releaseResources();
    return 0;
}

// ���˵��߼��������ơ�����������л�״̬��
void handleMainMenu() {
    // ����1���������˵�����
    drawMainMenu();

    // ����2�����������
    ClickType click = listenMouseClick_Mainmenu();

    // ����3�����ݵ�������л�״̬
    switch (click) {
        case CLICK_START:
            switchState(STATE_READY);  
            break;
        case CLICK_RANKING:
            switchState(STATE_RANKING);            // ���а�����а�״̬
            break;
        case CLICK_SETTING:
            switchState(STATE_SETTING);            // ���á������Ѷ� 
            break;
        case CLICK_EXIT:
            switchState(STATE_EXIT);               // �˳�����ֹ����
            break;
        default:
            break;  // �޵���򲻴���
    }
}



/*void handleReadyStage(){
    resetScore();
    initSnake();
    generateFood();
	drawReady(); 
    ClickType click=listenMouseClick_Run();
    if(click==CLICK_RUN){
        switchState(STATE_RUNNING);
    }
}*/

void handleReadyStage(){
    resetScore();
    initSnake();
    initObstacles(); // ��ʼ���ϰ���
    generateObstacles(); // �����ϰ���

    /* ���� �޸�3��ȷ�����߼�������ȫ���� */
    g_propCount = 0;
    for (int i = 0; i < 10; ++i){
        g_props[i].exist = false;
        g_props[i].type = PROP_NONE;
        g_props[i].duration = 0;
        g_props[i].x = 0;
        g_props[i].y = 0;
    }


    // ��Ӿ�̬��־��ȷ��ʳ��ֻ����һ��
    static bool hasGeneratedFood = false;
    if (!hasGeneratedFood) {
        generateFood();  // ���״ν���׼���׶�ʱ����ʳ��
        hasGeneratedFood = true;
    }
    
    drawReady(); 
    ClickType click = listenMouseClick_Run();
    if(click == CLICK_RUN){
        hasGeneratedFood = false;  // ���ñ�־���´ν���׼���׶���������
        switchState(STATE_RUNNING);
    }
}

void handleRunning() {
    if (g_currentState == STATE_RUNNING) { // ֻ������״̬�Ÿ�����Ϸ�߼�
        updatePropEffect();
        listenKeyPress();
        
        static int speedCounter = 0;
        if (speedCounter >= snakespeed) {
            moveSnake();
            
            if (checkCollision()) {
                switchState(STATE_GAME_OVER);
                return;
            }
            
            bool ateFood = checkFoodCollision();
            checkPropCollision();
            
            if (ateFood) {
                generateFood();
            }
            
            if (obstacle == 3) {
                moveObstacles();
                if (checkCollision()) {
                 //   updateRanking("���");
                    switchState(STATE_GAME_OVER);
                    return;
                }
            }
            
            speedCounter = 0;
        } else {
            speedCounter++;
        }
    }
    
    drawRunning(); // �������л�����ͣ�����ƽ���
}

void handleGameOver() {
    drawGameOver();
    key_msg key;
    
    static bool hasSaved = false;
    static int inputPos = 0;

    // �����û�������
    if (kbhit()) {
        key = getkey();
            //  ESC���������˵�
            if (key.key == VK_ESCAPE) {
                hasSaved = false;
                inputPos = 0;
                memset(g_username, 0, sizeof(g_username));
                switchState(STATE_MAIN_MENU);
                return;
            }

            // �س���ȷ������
            if (key.key == VK_RETURN && inputPos > 0) {
                if (!hasSaved) {
                    updateRanking(g_username);
                    saveRankingToFile();
                    hasSaved = true;
                }
                return;
            }

            // �˸��ɾ���ַ�
            if (key.key == VK_BACK && inputPos > 0) {
                inputPos--;
                g_username[inputPos] = '\0';
            }

            // ��ĸ��������
            if (key.key >= 32 && key.key <= 126 && inputPos < 19) {
                g_username[inputPos++] = key.key;  // �˴���key.asc��Ϊkey.key
                g_username[inputPos] = '\0';
            }
    }

    // ��ʾ������ʾ�͵�ǰ�û���
  /*  setcolor(WHITE);
    setfont(20, 0, "����");
    outtextxy(300, 300, "�������û���:");
    outtextxy(300, 330, g_username);  */
}

// �������������ý��棨�����Ѷ�ѡ��
void handleSetting() {
    drawSetting();
    ClickType click = listenMouseClick_difficulty(); // �����Ѷ�ѡ���������
    if (click == CLICK_EASY || click == CLICK_MEDIUM || click == CLICK_DIFFICULT) {
        setDifficulty(click); // �����Ѷ�
    }
    if (click == CLICK_BACK) {
        switchState(STATE_MAIN_MENU); // �������˵�
    }
}


void handleRanking(){
                // ��ESC�������˵�
                key_msg key;
                if (kbhit()) {
                    key = getkey();
                    if ( key.key == 27) {   //���ӳ����Բ���ʹ�� key.msg == key_msg_down &&�ж� 
                        switchState(STATE_MAIN_MENU);
                    }
                }
                drawRanking(); // ��ʾ���а�
}

// ������ͣ״̬
void handlePaused() {
    // ������ͣ����
    setfillcolor(BLACK);
    bar(0, 0, WINDOW_W, WINDOW_H);
    
    setcolor(WHITE);
    setfont(40, 0, "����");
    char pauseText[] = "��Ϸ��ͣ";
    int textWidth = textwidth(pauseText);
    int textX = (WINDOW_W - textWidth) / 2;
    outtextxy(textX, 200, pauseText);
    
    // ��ʾ��ʾ��Ϣ
    setfont(20, 0, "����");
    char hintText[] = "���ո��������Ϸ | ��ESC�������˵�";
    int hintWidth = textwidth(hintText);
    int hintX = (WINDOW_W - hintWidth) / 2;
    outtextxy(hintX, 300, hintText);
    
    listenKeyPress();
}
