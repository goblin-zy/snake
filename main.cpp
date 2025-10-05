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
void handleDifficultySelect();
void handleReadyStage();
void handleRunning();

int main() {
    srand((unsigned int)time(NULL));    

    // 1. ��ʼ�������ڡ���Դ������
    initWindow(800,600);    // ����640��480����
    loadResources();         // �������˵�ͼƬ/����
    initCoreData();          // ��ʼ����Ϸ״̬Ϊ���˵�

    // 2. ��ѭ��������δ�ر���������У�
    while (is_run()) {
        // ���ݵ�ǰ״ִ̬�ж�Ӧ�߼����׶�1�����˵���
        switch (g_currentState) {
            case STATE_MAIN_MENU:{
                handleMainMenu();
                break;
            }
            case STATE_DIFFICULTY_SELECT:{
            	handleDifficultySelect();
				break;
			}
			case STATE_READY:{
				handleReadyStage();
				break;
			} 
            case STATE_RUNNING:{
                handleRunning();
            }
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
    ClickType click = listenMouseClick_Mainmenu();

    // ����3�����ݵ�������л�״̬
    switch (click) {
        case CLICK_START:
            switchState(STATE_DIFFICULTY_SELECT);  // ��ʼ���Ѷ�ѡ��1
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

void handleDifficultySelect(){
	drawDifficultySelect();
	ClickType click = listenMouseClick_difficulty();
	if(click==CLICK_EASY||click==CLICK_MEDIUM||click==CLICK_DIFFICULT){
    loadDefaultDifficulty();
    setDifficulty(click);
    switchState(STATE_READY);
}
    if(click==CLICK_BACK){
	switchState(STATE_MAIN_MENU);
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

void handleRunning(){
    // ���µ���Ч��״̬
    updatePropEffect();

    // 1. �������룬�ı��ߵķ���
    listenKeyPress();
    
    // 2. �����ߵ��ƶ��ٶ�
    static int speedCounter = 0;
    if (speedCounter >= snakespeed) {
        // �ƶ���
        moveSnake();
        
        // ����Ƿ���ײ
        if (checkCollision()) {
            switchState(STATE_MAIN_MENU);
            return;
        }
        
        // 3. ����Ƿ�Ե�ʳ��
        bool ateFood = checkFoodCollision();
        
        // 4. ����Ƿ�Ե�����
        checkPropCollision();
        
        // 5. ����Ե�ʳ���������ʳ��
        if (ateFood) {
            generateFood();
        }
        
        // �ƶ��ϰ������ģʽ��
        if (obstacle == 3) {
            moveObstacles();
            if (checkCollision()) {
                switchState(STATE_MAIN_MENU);
                return;
            }
        }
        
        speedCounter = 0;
    } else {
        speedCounter++;
    }
    
    // 6. ������ϷԪ�أ���ӵ��߻��ƣ�
    drawRunning();
}
