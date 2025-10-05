#ifndef GLOBAL_H
#define GLOBAL_H


// ȫ�ֱ���������ֻ���������壩
extern GameState g_currentState;
extern int g_currentScore;
extern Snake g_snake;
extern Food g_food[100];
extern int g_foodCount;
extern int snakespeed;
extern int obstacle;

//ͼƬ 
    extern PIMAGE img_start;
    extern PIMAGE img_rank;
    extern PIMAGE img_setting;
    extern PIMAGE img_exit;

    extern PIMAGE img_head_up;
    extern PIMAGE img_head_down;
    extern PIMAGE img_head_left;
    extern PIMAGE img_head_right;
    extern PIMAGE img_body;
    extern PIMAGE img_food;

    extern PIMAGE img_prop_speedup;    // ���ٵ���ͼƬ
    extern PIMAGE img_prop_invincible; // �޵е���ͼƬ
    extern PIMAGE img_prop_grow;       // ��������ͼƬ
    extern PIMAGE img_prop_double;     // �÷ּӱ�����ͼƬ

    // ȫ���ϰ������鼰����
    extern Obstacle g_obstacles[100];  // ���50���ϰ���
    extern int g_obstacleCount;
    
    extern PIMAGE img_wall;  // ������ǽ��ͼƬ

    // ��ԭ�л������������ȫ�ֱ�������
extern bool g_isInvincible;            // �޵�״̬���
extern int g_invincibleDuration;       // �޵г���ʱ�䣨֡����
extern bool g_isDoubleScore;           // �÷ּӱ����
extern int g_doubleScoreDuration;      // �÷ּӱ�����ʱ��
extern int g_originalSpeed;            // ԭʼ�ٶȣ����ڼ���Ч���ָ���
extern int g_speedEffectDuration;      // �ٶ�Ч������ʱ��
extern Prop g_props[10];               // ��������
extern int g_propCount;                // ��������
#endif
