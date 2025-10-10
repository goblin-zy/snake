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
}

void drawDifficultySelect(){
    // 1. 绘制黑色背景（填充800×600窗口）
    setfillcolor(BLACK);
    bar(0, 0, 800, 600);

    // 2. 绘制标题（居中显示"难度选择"）
    setcolor(WHITE);
    setfont(45, 0, "宋体");
    char title[] = "难度选择";
    int titleWidth = textwidth(title);
    int titleX = (800 - titleWidth) / 2;  
    outtextxy(titleX, 63, title);  

    // -------------------------- 关键修复1：开启文字透明背景（全局生效） --------------------------
    setbkmode(TRANSPARENT);  // EGE 函数：设置文字背景为透明，避免文字周围出现黑块

    // 3. 绘制"简单"按钮（修复：显式重置颜色，精准计算文字居中）
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

    // 4. 绘制"中等"按钮（修复：重置颜色，避免继承上一个按钮的状态）
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

    // 5. 绘制"困难"按钮（同上述修复逻辑）
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
    outtextxy(TEXT_SCORE_X, TEXT_SCORE_Y+100, scoreText);
    // ③ 难度显示（根据g_difficulty映射文字）
    char diffText[30];
    if (obstacle == 1) sprintf(diffText, "当前难度：简单");
    else if (obstacle == 2) sprintf(diffText, "当前难度：中等");
    else sprintf(diffText, "当前难度：困难");
    outtextxy(TEXT_DIFF_X, TEXT_DIFF_Y+100, diffText);
    // ④ 绘制开始按钮（绿色背景+白色文字，状态栏内）
    setfillcolor(GREEN);
    bar(BTN_READY_START_X, BTN_READY_START_Y, 
        BTN_READY_START_X + BTN_READY_START_W, 
        BTN_READY_START_Y + BTN_READY_START_H);
    setcolor(WHITE);
    setbkmode(TRANSPARENT);//避免黑框产生 
    setfont(18, 0, "宋体");
    char startBtnText[] = "开始游戏";
    int startBtnTextW = textwidth(startBtnText);
    // 按钮文字居中
    outtextxy(BTN_READY_START_X + (BTN_READY_START_W - startBtnTextW)/2, 
              BTN_READY_START_Y + 10, startBtnText);


//绘制墙
    drawObstacles();

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

    // ★★★ 修复2：在准备阶段也绘制道具
    drawProp();
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

//绘制墙
    drawObstacles();

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

    // 新增：绘制道具
    drawProp();

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

    if (g_isInvincible) {
        setcolor(RED);
        setfont(16, 0, "宋体");
        outtextxy(TEXT_SCORE_X, TEXT_SCORE_Y + 30, "无敌状态生效中!");
    }

    // 暂停状态显示（新增）
    if (g_currentState == STATE_PAUSED) {
        setcolor(YELLOW);
        setfont(30, 0, "黑体");
        outtextxy(TEXT_SCORE_X, 200, "已暂停");
        outtextxy(TEXT_SCORE_X - 30, 240, "按空格继续");
    }
}


// 绘制障碍物
void drawObstacles() {
    for (int i = 0; i < g_obstacleCount; i++) {
        if (g_obstacles[i].exist) {
            // 静态障碍物：使用 wall.png 图片绘制
            if (g_obstacles[i].type == OBSTACLE_STATIC) {
                // 确保 img_wall 已在资源加载函数中正确加载
                putimage(g_obstacles[i].x, g_obstacles[i].y, img_wall);
            } 
            // 移动障碍物：使用红色实心方块绘制（适配 EGE 19.01）
            else {
                setfillcolor(RED);  // 设置填充颜色为红色
                // 使用 EGE 兼容的 bar 函数绘制矩形，参数为左上角和右下角坐标
                bar(
                    g_obstacles[i].x,                // 左上角 X
                    g_obstacles[i].y,                // 左上角 Y
                    g_obstacles[i].x + GRID_SIZE,    // 右下角 X（与网格大小匹配）
                    g_obstacles[i].y + GRID_SIZE     // 右下角 Y（与网格大小匹配）
                );
            }
        }
    }
}

// 绘制道具
void drawProp() {
    for (int i = 0; i < 10; i++) {  // 遍历所有道具
        if (g_props[i].exist) {
            // 根据道具类型绘制不同的图片
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

    // 1. 游戏结束标题
    setcolor(RED);
    setfont(50, 0, "黑体");
    const char* title = "游戏结束";
    int titleWidth = textwidth(title);
    int titleX = (WINDOW_W - titleWidth) / 2;
    outtextxy(titleX, 100, title);  // 上移标题，留出更多空间

    // 2. 最终得分显示
    char scoreText[50];
    sprintf(scoreText, "最终得分: %d", g_currentScore);
    setcolor(WHITE);
    setfont(30, 0, "黑体");
    int scoreX = (WINDOW_W - textwidth(scoreText)) / 2;
    outtextxy(scoreX, 200, scoreText);  // 调整分数位置

    // 3. 鼓励语（如果进入排行榜）
    bool isInRanking = false;
    for (int i = 0; i < 10; i++) {
        if (g_ranking[i].score == g_currentScore&&g_currentScore!=0) {
            isInRanking = true;
            break;
        }
    }
    if (isInRanking) {
        setcolor(GREEN);
        setfont(25, 0, "黑体");
        const char* congrats = "恭喜！你进入了排行榜！";
        int congratsX = (WINDOW_W - textwidth(congrats)) / 2;
        outtextxy(congratsX, 260, congrats);  // 鼓励语上移
    }

    // 4. 用户名输入区域（下移，避免重叠）
    setcolor(WHITE);
    setfont(20, 0, "宋体");
    outtextxy(300, 320, "请输入用户名:");  // 输入提示下移
    // 绘制输入框背景
    setcolor(LIGHTGRAY);
    rectangle(300, 350, 550, 380);  // 输入框下移
    // 显示当前输入的用户名
    outtextxy(310, 353, g_username);  // 用户名显示下移

    // 5. 操作提示
    setcolor(LIGHTGRAY);
    setfont(20, 0, "宋体");
    outtextxy(280, 420, "按回车确认，ESC返回主菜单");  // 提示信息下移
}





// 新增：绘制设置界面（包含难度选择）
void drawSetting() {
    setfillcolor(BLACK);
    bar(0, 0, 800, 600);

    // 标题
    setcolor(WHITE);
    setfont(45, 0, "黑体");
    char title[] = "设置";
    int titleWidth = textwidth(title);
    int titleX = (800 - titleWidth) / 2;
    outtextxy(titleX, 63, title);

    // 难度选择标题
    setfont(30, 0, "黑体");
    outtextxy(340, 150, "选择难度");

    // 难度按钮（移植自难度选择界面）
    setbkmode(TRANSPARENT);
    
    // 简单
    setfillcolor(GREEN);
    bar(BTN_DIFF_X, BTN_EASY_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_EASY_Y+BTN_DIFF_H);
    setcolor(BLACK);
    setfont(18, 0, "黑体");
    char easyText[] = "简单";
    int easyTextW = textwidth(easyText);
    int easyTextH = textheight(easyText);
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - easyTextW)/2, 
              BTN_EASY_Y + (BTN_DIFF_H - easyTextH)/2, 
              easyText);

    // 中等
    setfillcolor(YELLOW);
    bar(BTN_DIFF_X, BTN_MEDIUM_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_MEDIUM_Y+BTN_DIFF_H);
    setcolor(BLACK);
    setfont(18, 0, "黑体");
    char mediumText[] = "中等";
    int mediumTextW = textwidth(mediumText);
    int mediumTextH = textheight(mediumText);
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - mediumTextW)/2, 
              BTN_MEDIUM_Y + (BTN_DIFF_H - mediumTextH)/2, 
              mediumText);

    // 困难
    setfillcolor(RED);
    bar(BTN_DIFF_X, BTN_HARD_Y, BTN_DIFF_X+BTN_DIFF_W, BTN_HARD_Y+BTN_DIFF_H);
    setcolor(BLACK);
    setfont(18, 0, "黑体");
    char hardText[] = "困难";
    int hardTextW = textwidth(hardText);
    int hardTextH = textheight(hardText);
    outtextxy(BTN_DIFF_X + (BTN_DIFF_W - hardTextW)/2, 
              BTN_HARD_Y + (BTN_DIFF_H - hardTextH)/2, 
              hardText);

    // 返回按钮
    setfillcolor(DARKGRAY);
    bar(BTN_BACK_X, BTN_BACK_Y, BTN_BACK_X+BTN_BACK_W, BTN_BACK_Y+BTN_BACK_H);
    setcolor(WHITE);
    setfont(14, 0, "黑体");
    char backText[] = "返回";
    int backTextW = textwidth(backText);
    int backTextH = textheight(backText);
    outtextxy(BTN_BACK_X + (BTN_BACK_W - backTextW)/2, 
              BTN_BACK_Y + (BTN_BACK_H - backTextH)/2, 
              backText);
}





// 绘制排行榜界面
void drawRanking() {
    setfillcolor(BLACK);
    bar(0, 0, WINDOW_W, WINDOW_H);

    // 标题
    setcolor(WHITE);
    setfont(45, 0, "宋体");
    const char* title = "得分排行榜";
    int titleX = (WINDOW_W - textwidth(title)) / 2;
    outtextxy(titleX, 63, title);

    // 表头
    setfont(25, 0, "宋体");
    outtextxy(220, 150, "排名");
    outtextxy(350, 150, "分数");
    outtextxy(480, 150, "用户名");

    // 排行榜内容
    for (int i = 0; i < 10; i++) {
        char buf[50];
        sprintf(buf, "%d.", i+1);
        outtextxy(230, 200 + i*30, buf);

        sprintf(buf, "%d", g_ranking[i].score);
        outtextxy(360, 200 + i*30, buf);

        outtextxy(480, 200 + i*30, g_ranking[i].name);
    }

    // 返回提示
    setcolor(LIGHTGRAY);
    setfont(20, 0, "宋体");
    outtextxy(300, 500, "按ESC返回主菜单");
}
