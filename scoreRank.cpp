#include"allcpp.h"


void resetScore() {
    g_currentScore = 0;
}

// 修改：完善排行榜更新逻辑
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

    // 移动排名
    for (int i = 9; i > insertPos; i--) {
        g_ranking[i] = g_ranking[i-1];
    }

    // 插入新记录
    g_ranking[insertPos].score = g_currentScore;
    strncpy(g_ranking[insertPos].name, username, 19);
    g_ranking[insertPos].name[19] = '\0';

    return true;
}

// 保存排行榜到文件
void saveRankingToFile() {
    FILE* f = fopen("ranking.dat", "wb");
    if (f) {
        fwrite(g_ranking, sizeof(RankingEntry), 10, f);
        fclose(f);
    }
}

// 从文件加载排行榜
void loadRankingFromFile() {
    FILE* f = fopen("ranking.dat", "rb");
    if (f) {
        fread(g_ranking, sizeof(RankingEntry), 10, f);
        fclose(f);
    } else {
        // 初始化空排行榜
        for (int i = 0; i < 10; i++) {
            g_ranking[i].score = 0;
            strcpy(g_ranking[i].name, "");
        }
    }
}
