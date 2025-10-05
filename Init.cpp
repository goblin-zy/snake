#include"allcpp.h" 




void initWindow(int width, int height) {
    setinitmode(0);
    initgraph(width, height);
    setcaption("贪吃蛇 - 主菜单");
}

// 在loadResources函数中添加道具图片加载
void loadResources() {
    // 原有图片加载...
    img_start = newimage();
    img_rank = newimage();
    img_setting = newimage();
    img_exit = newimage();
    img_head_up = newimage();
    img_head_down = newimage();
    img_head_left = newimage();
    img_head_right = newimage();
    img_body = newimage();
    img_food = newimage();
    img_wall = newimage();

    // 新增：道具图片加载
    img_prop_speedup = newimage();
    img_prop_invincible = newimage();
    img_prop_grow = newimage();
    img_prop_double = newimage();

    // 加载图片文件（确保图片路径正确）
    getimage(img_start, "btn_start.png");
    getimage(img_rank, "btn_rank.png");
    getimage(img_setting, "btn_setting.png");
    getimage(img_exit, "btn_exit.png");
    getimage(img_head_up, "btn_head_up.png");
    getimage(img_head_down, "btn_head_down.png");
    getimage(img_head_left, "btn_head_left.png");
    getimage(img_head_right, "btn_head_right.png");
    getimage(img_body, "btn_body.png");
    getimage(img_food, "btn_food.png");
    getimage(img_wall, "btn_wall.png");
    
    // 新增：道具图片加载
    getimage(img_prop_speedup, "prop_speedup.png");
    getimage(img_prop_invincible, "prop_invincible.png");
    getimage(img_prop_grow, "prop_grow.png");
    getimage(img_prop_double, "prop_double.png");
}

void initCoreData() {
    g_currentState = STATE_MAIN_MENU;  // 初始化状态
}

void releaseResources() {
    // 原有资源释放...
    delimage(img_start);
    delimage(img_rank);
    delimage(img_setting);
    delimage(img_exit);
    delimage(img_head_up);
    delimage(img_head_down);
    delimage(img_head_left);
    delimage(img_head_right);
    delimage(img_body);
    delimage(img_food);
    delimage(img_wall);
    
    // 新增：道具图片释放
    delimage(img_prop_speedup);
    delimage(img_prop_invincible);
    delimage(img_prop_grow);
    delimage(img_prop_double);
    
    cleardevice();
    closegraph();
}

