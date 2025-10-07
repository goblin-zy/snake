#ifndef SCORERANK_H
#define SCORERANK_H


// 排行榜条目（仅包含分数和用户名）
struct RankingEntry {
    int score;          // 分数
    char name[20];      // 用户名
};


// 排行榜功能函数
void resetScore();                  // 重置当前分数
bool updateRanking(const char* username);  // 更新排行榜（传入用户名）
void saveRankingToFile();
void loadRankingFromFile();

#endif
