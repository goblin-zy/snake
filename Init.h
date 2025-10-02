#ifndef INIT_MODULE_H
#define INIT_MODULE_H

#define BTN_W        125  // 原100 → 100×1.25=125
#define BTN_H        50   // 原40 → 40×1.25=50


// 移除所有IMAGE变量声明
void initWindow(int width, int height);
void loadResources();  // 仅加载字体，不涉及图像
void initCoreData();
void releaseResources();

#endif

