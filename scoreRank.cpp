#include"allcpp.h"


void resetScore() {
    g_currentScore = 0;
}

// �޸ģ��������а�����߼�
bool updateRanking(const char* username) {
    if (g_currentScore <= 0) return false;

    int insertPos = -1;
    for (int i = 0; i < 10; i++) {
        if (g_currentScore > g_ranking[i].score) {
            insertPos = i;
            break;
        }
    }

    if (insertPos == -1) return false;

    // �ƶ�����
    for (int i = 9; i > insertPos; i--) {
        g_ranking[i] = g_ranking[i-1];
    }

    // �����¼�¼
    g_ranking[insertPos].score = g_currentScore;
    strncpy(g_ranking[insertPos].name, username, 19);
    g_ranking[insertPos].name[19] = '\0';

    return true;
}

// �������а��ļ�
void saveRankingToFile() {
    FILE* f = fopen("ranking.dat", "wb");
    if (f) {
        fwrite(g_ranking, sizeof(RankingEntry), 10, f);
        fclose(f);
    }
}

// ���ļ��������а�
void loadRankingFromFile() {
    FILE* f = fopen("ranking.dat", "rb");
    if (f) {
        fread(g_ranking, sizeof(RankingEntry), 10, f);
        fclose(f);
    } else {
        // ��ʼ�������а�
        for (int i = 0; i < 10; i++) {
            g_ranking[i].score = 0;
            strcpy(g_ranking[i].name, "");
        }
    }
}
