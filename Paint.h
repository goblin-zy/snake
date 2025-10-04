#ifndef RENDER_MODULE_H
#define RENDER_MODULE_H




#define WINDOW_W 800
#define WINDOW_H 600

#define BTN_START_X  338  // 原270 → 270×1.25=337.5≈338
#define BTN_START_Y  188  // 原150 → 150×1.25=187.5≈188
#define BTN_RANK_X   338  // 原270 → 338
#define BTN_RANK_Y   263  // 原210 → 210×1.25=262.5≈263
#define BTN_SET_X    338  // 原270 → 338
#define BTN_SET_Y    338  // 原270 → 270×1.25=337.5≈338
#define BTN_EXIT_X   338  // 原270 → 338
#define BTN_EXIT_Y   413  // 原330 → 330×1.25=412.5≈413
#define BTN_W        125  // 原100 → 100×1.25=125
#define BTN_H        50   // 原40 → 40×1.25=50

//难度绘制定义常量
    // 定义难度按钮尺寸（与主菜单按钮一致，125×50）
    #define BTN_DIFF_W 125
    #define BTN_DIFF_H 50
    // 按钮水平居中（800窗口宽度 - 按钮宽度）/2
    #define BTN_DIFF_X (800 - BTN_DIFF_W)/2
    // 按钮垂直位置：标题下方依次排列，间距50像素
    #define BTN_EASY_Y 200    // 简单按钮Y坐标
    #define BTN_MEDIUM_Y 280  // 中等按钮Y坐标（200+50+30间隔）
    #define BTN_HARD_Y 360    // 困难按钮Y坐标

    #define BTN_BACK_W 80
    #define BTN_BACK_H 30
    #define BTN_BACK_X 20
    #define BTN_BACK_Y 550

//初始化窗口需要的常量
#define GRID_SIZE 20    // 格子尺寸（20×20像素，核心要求）

#define MAP_START_X 0 // 地图左上角X坐标（右侧留200像素做状态栏）
#define MAP_START_Y 0  // 地图左上角Y坐标（顶部留50像素间距）
#define MAP_COL 30      // 地图列数（30列×20px=600px，地图总宽600）
#define MAP_ROW 30      // 地图行数（25行×20px=500px，地图总高500）
#define MAP_END_X (MAP_START_X + MAP_COL * GRID_SIZE) // 地图右下角X
#define MAP_END_Y (MAP_START_Y + MAP_ROW * GRID_SIZE) // 地图右下角Y

// -------------------------- 新增：状态栏参数（侧边布局） --------------------------
#define STATUS_START_X 680 // 状态栏左上角X坐标
#define STATUS_START_Y 100 // 状态栏左上角Y坐标
// 1. 开始按钮参数（状态栏内）
#define BTN_READY_START_W 120 // 开始按钮宽度
#define BTN_READY_START_H 40  // 开始按钮高度
#define BTN_READY_START_X 640
#define BTN_READY_START_Y 150 // 状态栏内Y坐标
// 2. 得分/难度文本位置（状态栏内）
#define TEXT_SCORE_X 640
#define TEXT_SCORE_Y  300// 得分文本Y
#define TEXT_DIFF_X 640
#define TEXT_DIFF_Y  450 // 难度文本Y 

// 绘制主菜单界面（阶段1核心绘制函数）
void drawMainMenu();
void drawDifficultySelect();
void drawReady();
// 绘制游戏运行状态
void drawRunning();
// 绘制障碍物
void drawObstacles();
#endif

