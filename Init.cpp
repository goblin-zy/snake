#include"allcpp.h" 




void initWindow(int width, int height) {
    setinitmode(0);
    initgraph(width, height);
    setcaption("̰���� - ���˵�");
}

void loadResources() {
//Ĭ�����ã��й���ͼƬ֮�ࡣ 

    img_start=newimage();
    img_rank=newimage();
    img_setting=newimage();
    img_exit=newimage();

    img_head_up=newimage();
    img_head_down=newimage();
    img_head_left=newimage();
    img_head_right=newimage();
    img_body=newimage();

    img_food=newimage();

    getimage(img_start,"btn_start.png");
    getimage(img_rank,"btn_rank.png");
    getimage(img_setting,"btn_setting.png");
    getimage(img_exit,"btn_exit.png");

    getimage(img_head_up,"btn_head_up.png");
    getimage(img_head_down,"btn_head_down.png");
    getimage(img_head_left,"btn_head_left.png");
    getimage(img_head_right,"btn_head_right.png");
    getimage(img_body,"btn_body.png");

    getimage(img_food,"btn_food.png");

    
}

void initCoreData() {
    g_currentState = STATE_MAIN_MENU;  // ��ʼ��״̬
}

void releaseResources() {
	delimage(img_start);
	delimage(img_rank);
	delimage(img_setting);
	delimage(img_exit);
	cleardevice(); 
    closegraph();
}

