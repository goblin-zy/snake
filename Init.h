#ifndef INIT_MODULE_H
#define INIT_MODULE_H

#define BTN_W        125  // ԭ100 �� 100��1.25=125
#define BTN_H        50   // ԭ40 �� 40��1.25=50


// �Ƴ�����IMAGE��������
void initWindow(int width, int height);
void loadResources();  // ���������壬���漰ͼ��
void initCoreData();
void releaseResources();

#endif

