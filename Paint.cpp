#include"allcpp.h"



void drawMainMenu() {
// 1. 绘制背景（黑色填充整个窗口，适配800×600）
setfillcolor(BLACK);
bar(0, 0, 800, 600);  // 窗口宽高从640×480改为800×600

// 2. 绘制标题（居中优化，适配新窗口）
setcolor(WHITE);
setfont(45, 0, "宋体");  // 字体按比例放大（原36→45，1.25倍）
char title[] = "贪吃蛇游戏";
int titleWidth = textwidth(title);  // 动态获取文字宽度
int titleX = (800 - titleWidth) / 2;  // 基于新窗口宽度（800）计算居中坐标
outtextxy(titleX, 63, title);  // Y坐标按比例调整（原50→63，1.25倍）

    // 3. 绘制按钮（替换为图片）
    putimage(BTN_START_X, BTN_START_Y, img_start);
    putimage(BTN_RANK_X, BTN_RANK_Y,img_rank);
    putimage(BTN_SET_X, BTN_SET_Y,img_setting);
    putimage(BTN_EXIT_X, BTN_EXIT_Y, img_exit);




/*
    // 3. 绘制按钮（优化文字显示）
    setfillcolor(YELLOW);
    setcolor(DARKGRAY);  // 按钮边框用深灰色
    setfont(18, 0, "宋体");  // 按钮文字使用宋体

    // 开始按钮
    bar(BTN_START_X, BTN_START_Y, BTN_START_X+BTN_W, BTN_START_Y+BTN_H);
    char startText[] = "开始游戏";
    int startTextWidth = textwidth(startText);
    outtextxy(BTN_START_X + (BTN_W - startTextWidth)/2, BTN_START_Y + 10, startText);
    
    // 排行榜按钮
    bar(BTN_RANK_X, BTN_RANK_Y, BTN_RANK_X+BTN_W, BTN_RANK_Y+BTN_H);
    char rankText[] = "排行榜";
    int rankTextWidth = textwidth(rankText);
    outtextxy(BTN_RANK_X + (BTN_W - rankTextWidth)/2, BTN_RANK_Y + 10, rankText);
    
    // 设置按钮
    bar(BTN_SET_X, BTN_SET_Y, BTN_SET_X+BTN_W, BTN_SET_Y+BTN_H);
    char setText[] = "设置";
    int setTextWidth = textwidth(setText);
    outtextxy(BTN_SET_X + (BTN_W - setTextWidth)/2, BTN_SET_Y + 10, setText);
    
    // 退出按钮
    bar(BTN_EXIT_X, BTN_EXIT_Y, BTN_EXIT_X+BTN_W, BTN_EXIT_Y+BTN_H);
    char exitText[] = "退出";
    int exitTextWidth = textwidth(exitText);
    outtextxy(BTN_EXIT_X + (BTN_W - exitTextWidth)/2, BTN_EXIT_Y + 10, exitText);
    */
}



void drawDifficultySelect(){
    // 1. 绘制黑色背景（填充800×600窗口）
    setfillcolor(BLACK);
    bar(0, 0, 800, 600);

    // 2. 绘制标题（居中显示“难度选择”）
    setcolor(WHITE);
    setfont(45, 0, "宋体");
    char title[] = "难度选择";
    int titleWidth = textwidth(title);
    int titleX = (800 - titleWidth) / 2;  
    outtextxy(titleX, 63, title);  

    // -------------------------- 关键修复1：开启文字透明背景（全局生效） --------------------------
    setbkmode(TRANSPARENT);  // EGE 函数：设置文字背景为透明，避免文字周围出现黑块

    // 3. 绘制“简单”按钮（修复：显式重置颜色，精准计算文字居中）
    setfillcolor(GREEN);      // 按钮背景色：绿色
    bar(BTN_DIFF_X, BTN_EASY_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_EASY_Y+BTN_DIFF_H);
    setcolor(BLACK);          // 文字颜色：黑色（与绿色背景对比）
    setfont(18, 0, "宋体");   // 文字大小：18号（适配50高的按钮）
    char easyText[] = "简单";
    int easyTextW = textwidth(easyText);
    int easyTextH = textheight(easyText);  // 新增：获取文字高度，避免垂直偏移
    // 文字居中：X=按钮中心-文字半宽，Y=按钮中心-文字半高（比固定+15更精准）
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - easyTextW)/2, 
              BTN_EASY_Y + (BTN_DIFF_H - easyTextH)/2, 
              easyText);

    // 4. 绘制“中等”按钮（修复：重置颜色，避免继承上一个按钮的状态）
    setfillcolor(YELLOW);     // 按钮背景色：黄色
    bar(BTN_DIFF_X, BTN_MEDIUM_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_MEDIUM_Y+BTN_DIFF_H);
    setcolor(BLACK);          // 显式重置文字颜色（避免继承其他颜色）
    setfont(18, 0, "宋体");   // 显式重置字体（避免字体大小异常）
    char mediumText[] = "中等";
    int mediumTextW = textwidth(mediumText);
    int mediumTextH = textheight(mediumText);
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - mediumTextW)/2, 
              BTN_MEDIUM_Y + (BTN_DIFF_H - mediumTextH)/2, 
              mediumText);

    // 5. 绘制“困难”按钮（同上述修复逻辑）
    setfillcolor(RED);        // 按钮背景色：红色
    bar(BTN_DIFF_X, BTN_HARD_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_HARD_Y+BTN_DIFF_H);
    setcolor(BLACK);          // 文字颜色：白色（与红色背景对比）
    setfont(18, 0, "宋体");
    char hardText[] = "困难";
    int hardTextW = textwidth(hardText);
    int hardTextH = textheight(hardText);
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - hardTextW)/2, 
              BTN_HARD_Y + (BTN_DIFF_H - hardTextH)/2, 
              hardText);

    // 6. 绘制返回按钮（修复：重置颜色和字体）
    setfillcolor(DARKGRAY);   // 按钮背景色：深灰色
    bar(BTN_BACK_X, BTN_BACK_Y, BTN_BACK_X+BTN_BACK_W, BTN_BACK_Y+BTN_BACK_H);
    setcolor(WHITE);          // 文字颜色：白色
    setfont(14, 0, "宋体");   // 字体缩小到14号（适配30高的按钮）
    char backText[] = "返回";
    int backTextW = textwidth(backText);
    int backTextH = textheight(backText);
    outtextxy(BTN_BACK_X + (BTN_BACK_W - backTextW)/2, 
              BTN_BACK_Y + (BTN_BACK_H - backTextH)/2, 
              backText);

    // -------------------------- 关键修复2：刷新缓冲区，确保画面实时显示 --------------------------
   // flushgraph();  // EGE 双缓冲刷新：避免绘制内容延迟或残留
}









void drawReady() {
    // 1. 绘制黑色背景（原有逻辑保留）
    setfillcolor(BLACK);
    bar(0, 0, WINDOW_W, WINDOW_H);

    // -------------------------- 新增1：绘制20×20格子线地图 --------------------------
    setcolor(BLUE); // 格子线用浅灰色，与黑色背景区分
    // ① 绘制竖线（每20px一条，从地图左到右）
    for (int x = MAP_START_X; x <= MAP_END_X; x += GRID_SIZE) {
        line(x, MAP_START_Y, x, MAP_END_Y); // 竖线：x固定，y从地图顶到底
    }
    // ② 绘制横线（每20px一条，从地图上到下）
    for (int y = MAP_START_Y; y <= MAP_END_Y; y += GRID_SIZE) {
        line(MAP_START_X, y, MAP_END_X, y); // 横线：y固定，x从地图左到右
    }

    // -------------------------- 新增2：绘制侧边状态栏 --------------------------
    setcolor(WHITE);
    setfont(20, 0, "宋体");
// ① 状态栏标题（右侧200×600状态栏内居中）
char statusTitle[] = "游戏状态";
// 右侧状态栏参数（明确边界）
#define STATUS_RIGHT_LEFT 600    // 状态栏左边界（窗口右侧开始）
#define STATUS_RIGHT_WIDTH 200   // 状态栏宽度（固定200）

// 计算文字宽度
int titleTextWidth = textwidth(statusTitle);
// 居中X坐标 = 状态栏左边界 + (状态栏宽度 - 文字宽度)/2
int titleX = STATUS_RIGHT_LEFT + (STATUS_RIGHT_WIDTH - titleTextWidth) / 2;
// Y坐标保持原有（如顶部50px处）
int titleY = 50;

// 绘制居中标题
outtextxy(titleX, titleY, statusTitle);

    // ② 得分显示（初始0分，g_currentScore是全局变量）
    char scoreText[30];
    sprintf(scoreText, "当前得分：%d", g_currentScore);
    outtextxy(TEXT_SCORE_X, TEXT_SCORE_Y, scoreText);
    // ③ 难度显示（根据g_difficulty映射文字）
    char diffText[30];
    if (obstacle == 1) sprintf(diffText, "当前难度：简单");
    else if (obstacle == 2) sprintf(diffText, "当前难度：中等");
    else sprintf(diffText, "当前难度：困难");
    outtextxy(TEXT_DIFF_X, TEXT_DIFF_Y, diffText);
    // ④ 绘制开始按钮（绿色背景+白色文字，状态栏内）
    setfillcolor(GREEN);
    bar(BTN_READY_START_X, BTN_READY_START_Y, 
        BTN_READY_START_X + BTN_READY_START_W, 
        BTN_READY_START_Y + BTN_READY_START_H);
    setcolor(WHITE);
    setfont(18, 0, "宋体");
    char startBtnText[] = "开始游戏";
    int startBtnTextW = textwidth(startBtnText);
    // 按钮文字居中
    outtextxy(BTN_READY_START_X + (BTN_READY_START_W - startBtnTextW)/2, 
              BTN_READY_START_Y + 10, startBtnText);


    //蛇和食物的绘制
    // 1. 绘制蛇（使用图片替代颜色填充）
    for (int i = 0; i < g_snake.len; i++) {
        if (i == 0) {
            // 绘制蛇头：使用蛇头图片，坐标与格子对齐
            // 参数说明：目标X, 目标Y, 图片宽, 图片高, 图片指针, 图片起始X, 图片起始Y, 绘制模式
            putimage(g_snake.x[i], g_snake.y[i], img_head_right);
        } else {
            // 绘制蛇身：使用蛇身图片
            putimage(g_snake.x[i], g_snake.y[i], img_body);
        }
    }

    // 2. 绘制食物（使用图片替代圆形）
    for (int i = 0; i < 5; i++) {
        if (g_food[i].exist) {
            // 绘制食物图片，确保完全填充20×20格子
            putimage(g_food[i].x, g_food[i].y, img_food);
        }
    }

}
    


// 绘制游戏运行中的元素
void drawRunning() {
    // 1. 绘制黑色背景
    setfillcolor(BLACK);
   bar(0, 0, WINDOW_W, WINDOW_H);

    // 2. 绘制网格
    setcolor(BLUE);
    for (int x = MAP_START_X; x <= MAP_END_X; x += GRID_SIZE) {
        line(x, MAP_START_Y, x, MAP_END_Y);
    }
    for (int y = MAP_START_Y; y <= MAP_END_Y; y += GRID_SIZE) {
        line(MAP_START_X, y, MAP_END_X, y);
    }

    // 3. 绘制蛇
    for (int i = 0; i < g_snake.len; i++) {
        if (i == 0) {  // 蛇头
            switch (g_snake.dir) {
                case 0: putimage(g_snake.x[i], g_snake.y[i], img_head_up); break;
                case 1: putimage(g_snake.x[i], g_snake.y[i], img_head_right); break;
                case 2: putimage(g_snake.x[i], g_snake.y[i], img_head_down); break;
                case 3: putimage(g_snake.x[i], g_snake.y[i], img_head_left); break;
            }
        } else {  // 蛇身
            putimage(g_snake.x[i], g_snake.y[i], img_body);
        }
    }

    // 4. 绘制食物
    for (int i = 0; i < g_foodCount; i++) {
        if (g_food[i].exist) {
            putimage(g_food[i].x, g_food[i].y, img_food);
        }
    }

    // 5. 绘制分数和难度信息
    setcolor(WHITE);
    setfont(20, 0, "宋体");
    char scoreText[30];
    sprintf(scoreText, "当前分数:%d", g_currentScore);
    outtextxy(TEXT_SCORE_X, TEXT_SCORE_Y, scoreText);

    char diffText[30];
    if (obstacle == 1) sprintf(diffText, "当前难度:简单");
    else if (obstacle == 2) sprintf(diffText, "当前难度:中等");
    else sprintf(diffText, "当前难度:困难");
    outtextxy(TEXT_DIFF_X, TEXT_DIFF_Y, diffText);
}
