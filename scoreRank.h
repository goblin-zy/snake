#ifndef SCORERANK_H
#define SCORERANK_H


// ���а���Ŀ���������������û�����
struct RankingEntry {
    int score;          // ����
    char name[20];      // �û���
};


// ���а��ܺ���
void resetScore();                  // ���õ�ǰ����
bool updateRanking(const char* username);  // �������а񣨴����û�����
void saveRankingToFile();
void loadRankingFromFile();

#endif
