#include "allcpp.h"



// 全局变量定义（只定义一次）
GameState g_currentState;  // 当前游戏状态
int g_currentScore = 0;
Snake g_snake;
Food g_food[100];
int g_foodCount = 0;
int snakespeed;
int obstacle;

// 初始化全局变量
Obstacle g_obstacles[100];  // 增加容量到100个
int g_obstacleCount = 0;

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


// 声明主菜单处理函数（阶段1核心逻辑）
void handleMainMenu();
void handleDifficultySelect();
void handleReadyStage();
void handleRunning();

int main() {
    // 1. 初始化：窗口→资源→数据
    initWindow(800,600);    // 创建640×480窗口
    loadResources();         // 加载主菜单图片/字体
    initCoreData();          // 初始化游戏状态为主菜单

    // 2. 主循环（窗口未关闭则持续运行）
    while (is_run()) {
        // 根据当前状态执行对应逻辑（阶段1仅主菜单）
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
            // 其他状态（难度选择/排行榜等）后续阶段补充
            default:
                break;
        }
        delay_fps(30);  // 控制帧率（30帧/秒，避免CPU占用过高）
    }

    // 3. 释放资源（程序退出）
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
            switchState(STATE_DIFFICULTY_SELECT);  // 开始→难度选择1
            break;
        case CLICK_RANKING:
            switchState(STATE_RANKING);            // 排行榜→排行榜状态
            break;
        case CLICK_SETTING:
            switchState(STATE_SETTING);            // 设置→设置状态
            break;
        case CLICK_EXIT:
            switchState(STATE_EXIT);               // 退出→终止程序
            break;
        default:
            break;  // 无点击则不处理
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
    initObstacles(); // 初始化障碍物
    generateObstacles(); // 生成障碍物
    
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

void handleRunning(){
    // 1. 监听键盘，改变蛇的方向
    listenKeyPress();
    
    // 2. 控制蛇的移动速度，根据难度调整
    static int speedCounter = 0;
    if (speedCounter >= snakespeed) {
        // 移动蛇
        moveSnake();
        
        // 检查是否碰撞(边界、自身、障碍物)
        if (checkCollision()) {
            // 碰撞后游戏结束，返回主菜单
            switchState(STATE_MAIN_MENU);
            return;
        }
        
        // 3. 检查是否吃到食物
        bool ateFood = checkFoodCollision();
        
        // 4. 如果吃到食物，重新生成食物
        if (ateFood) {
            generateFood();
        }
        
    // 困难模式：移动障碍物
    if (obstacle == 3) {
        moveObstacles();
        // 补充检测：移动障碍物后是否与蛇碰撞
        if (checkCollision()) {
            switchState(STATE_MAIN_MENU);
            return;
        }
    }
        
        speedCounter = 0;
    } else {
        speedCounter++;
    }
    
    // 5. 绘制游戏元素
    drawRunning();
}
