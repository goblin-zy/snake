#include "allcpp.h"



// 全局变量定义（只定义一次）
GameState g_currentState;  // 当前游戏状态
int g_currentScore = 0;
Snake g_snake;
Food g_food[100];
int g_foodCount = 0;
int snakespeed;
int obstacle;

//道具相关
bool g_isInvincible = false;
int g_invincibleDuration = 0;
bool g_isDoubleScore = false;
int g_doubleScoreDuration = 0;
int g_originalSpeed = 0;
int g_speedEffectDuration = 0;
Prop g_props[10] = {0};
int g_propCount = 0;

// 初始化全局变量
Obstacle g_obstacles[100];  // 增加容量到100个
int g_obstacleCount = 0;

RankingEntry g_ranking[10];  // 固定10个排名位置

char g_username[20];

//图片 
    PIMAGE img_start;
    PIMAGE img_rank;
    PIMAGE img_setting;
    PIMAGE img_exit;
//蛇的图片
    PIMAGE img_head_up;
    PIMAGE img_head_down;
    PIMAGE img_head_left;
    PIMAGE img_head_right;
    PIMAGE img_body;
//食物的图片
    PIMAGE img_food;
//障碍物图片
    PIMAGE img_wall; 

//道具
 PIMAGE img_prop_speedup;    // 加速道具图片
 PIMAGE img_prop_invincible; // 无敌道具图片
 PIMAGE img_prop_grow;       // 增长道具图片
 PIMAGE img_prop_double;     // 得分加倍道具图片


// 声明主菜单处理函数（阶段1核心逻辑）
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
    loadRankingFromFile(); // 加载保存的排行榜

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
            case STATE_PAUSED: // 暂停状态共用运行时的绘制逻辑
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
                closegraph(); // 退出游戏
                return 0;
            default:
                break;
        }
        delay_fps(30);
    }

    releaseResources();
    return 0;
}

// 主菜单逻辑处理（绘制→监听点击→切换状态）
void handleMainMenu() {
    // 步骤1：绘制主菜单界面
    drawMainMenu();

    // 步骤2：监听鼠标点击
    ClickType click = listenMouseClick_Mainmenu();

    // 步骤3：根据点击类型切换状态
    switch (click) {
        case CLICK_START:
            switchState(STATE_READY);  
            break;
        case CLICK_RANKING:
            switchState(STATE_RANKING);            // 排行榜→排行榜状态
            break;
        case CLICK_SETTING:
            switchState(STATE_SETTING);            // 设置→设置难度 
            break;
        case CLICK_EXIT:
            switchState(STATE_EXIT);               // 退出→终止程序
            break;
        default:
            break;  // 无点击则不处理
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
    initObstacles(); // 初始化障碍物
    generateObstacles(); // 生成障碍物

    /* ★★★ 修复3：确保道具计数器完全清零 */
    g_propCount = 0;
    for (int i = 0; i < 10; ++i){
        g_props[i].exist = false;
        g_props[i].type = PROP_NONE;
        g_props[i].duration = 0;
        g_props[i].x = 0;
        g_props[i].y = 0;
    }


    // 添加静态标志，确保食物只生成一次
    static bool hasGeneratedFood = false;
    if (!hasGeneratedFood) {
        generateFood();  // 仅首次进入准备阶段时生成食物
        hasGeneratedFood = true;
    }
    
    drawReady(); 
    ClickType click = listenMouseClick_Run();
    if(click == CLICK_RUN){
        hasGeneratedFood = false;  // 重置标志，下次进入准备阶段重新生成
        switchState(STATE_RUNNING);
    }
}

void handleRunning() {
    if (g_currentState == STATE_RUNNING) { // 只有运行状态才更新游戏逻辑
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
                 //   updateRanking("玩家");
                    switchState(STATE_GAME_OVER);
                    return;
                }
            }
            
            speedCounter = 0;
        } else {
            speedCounter++;
        }
    }
    
    drawRunning(); // 无论运行还是暂停都绘制界面
}

void handleGameOver() {
    drawGameOver();
    key_msg key;
    
    static bool hasSaved = false;
    static int inputPos = 0;

    // 处理用户名输入
    if (kbhit()) {
        key = getkey();
            //  ESC键返回主菜单
            if (key.key == VK_ESCAPE) {
                hasSaved = false;
                inputPos = 0;
                memset(g_username, 0, sizeof(g_username));
                switchState(STATE_MAIN_MENU);
                return;
            }

            // 回车键确认输入
            if (key.key == VK_RETURN && inputPos > 0) {
                if (!hasSaved) {
                    updateRanking(g_username);
                    saveRankingToFile();
                    hasSaved = true;
                }
                return;
            }

            // 退格键删除字符
            if (key.key == VK_BACK && inputPos > 0) {
                inputPos--;
                g_username[inputPos] = '\0';
            }

            // 字母数字输入
            if (key.key >= 32 && key.key <= 126 && inputPos < 19) {
                g_username[inputPos++] = key.key;  // 此处将key.asc改为key.key
                g_username[inputPos] = '\0';
            }
    }

    // 显示输入提示和当前用户名
  /*  setcolor(WHITE);
    setfont(20, 0, "宋体");
    outtextxy(300, 300, "请输入用户名:");
    outtextxy(300, 330, g_username);  */
}

// 新增：处理设置界面（包含难度选择）
void handleSetting() {
    drawSetting();
    ClickType click = listenMouseClick_difficulty(); // 复用难度选择的鼠标监听
    if (click == CLICK_EASY || click == CLICK_MEDIUM || click == CLICK_DIFFICULT) {
        setDifficulty(click); // 设置难度
    }
    if (click == CLICK_BACK) {
        switchState(STATE_MAIN_MENU); // 返回主菜单
    }
}


void handleRanking(){
                // 按ESC返回主菜单
                key_msg key;
                if (kbhit()) {
                    key = getkey();
                    if ( key.key == 27) {   //有延迟所以不能使用 key.msg == key_msg_down &&判断 
                        switchState(STATE_MAIN_MENU);
                    }
                }
                drawRanking(); // 显示排行榜
}

// 处理暂停状态
void handlePaused() {
    // 绘制暂停界面
    setfillcolor(BLACK);
    bar(0, 0, WINDOW_W, WINDOW_H);
    
    setcolor(WHITE);
    setfont(40, 0, "宋体");
    char pauseText[] = "游戏暂停";
    int textWidth = textwidth(pauseText);
    int textX = (WINDOW_W - textWidth) / 2;
    outtextxy(textX, 200, pauseText);
    
    // 显示提示信息
    setfont(20, 0, "宋体");
    char hintText[] = "按空格键继续游戏 | 按ESC返回主菜单";
    int hintWidth = textwidth(hintText);
    int hintX = (WINDOW_W - hintWidth) / 2;
    outtextxy(hintX, 300, hintText);
    
    listenKeyPress();
}
