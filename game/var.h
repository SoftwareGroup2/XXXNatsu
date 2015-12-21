// カレンダー構造体
typedef struct trout_t{
    char content[CONTENT_LEN];  // 予定の内容(文章)
    int enhance_p;      // 充実ポイント(変化量)
    int task_p;         // 課題ポイント(変化量)
    int money_p;        // 金(変化量)
    int move_day;       // N日進む
}TROUT_T;

// プレイヤー構造体
typedef struct player_t{
    int grade;              // 学年
    int club;               // 部活(帰宅部/運動部/文化部)
    int girlfriend;         // 彼女(いる/いない)
    int enhance_p;          // 充実ポイント
    int task_p;             // 課題ポイント
    int money_p;            // 金
    int day;                // 現在何日目か
    TROUT_T calender[CALENDER_LEN];   // 自分のカレンダー
}PLAYER_T;
