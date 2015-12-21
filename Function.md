# 関数定義
変数名このとおりでオナシャス！
## テンプレート
この様式で書いてあります
### void template(void)
- 内容
- 戻り値
- 呼び出し
- 呼びだされ

## 初期化関数群
ゲーム開始前に用いる関数群
### int program_init(void)
- 内容
	- 乱数初期化
	- カレンダーファイルの読み込み(元のカレンダーはグローバル変数で持ちます！)
- 戻り値
 - 正常終了→TRUE
 - エラー発生→FALSE

### int init_players(PLAYER_T \*players)
- 内容
	- プレイヤー全員の初期化
- 戻り値
	- 正常終了→TRUE
	- エラー発生→FALSE
- 呼び出し
	- init_player

### int init_player(PLAYER_T \*player)
- 内容
	- プレイヤー1人の初期化
		- 名前，学年，部活，彼女，カレンダーは関数で初期化
		- 各ポイントは定数なので代入で初期化
- 戻り値
	- 正常終了→TRUE
	- エラー発生→FALSE
- 呼び出し
	- set_player_name
	- set_player_status
	- init_calender
- 呼びだされ
	- init_players

### void set_player_name(char \*name)
- 内容
	- プレイヤーの名前を入力する
	- 規定文字数以上であればやり直し
- 戻り値
	- ナシ
- 呼びだされ
	- init_player

### void set_player_status(int \*grade, int \*club, int \*girlfriend)
- 内容
	- 学年，部活，彼女を初期化
	- 学年と部活は入力から(エラー入力はやりなおし)
	- 彼女は乱数で決定
- 戻り値
	- ナシ
- 呼びだされ
	- init_player

### void init_calender(TROUT_T \*calender, int grade, int club, int girlfriend))
- 内容
	- プレイヤー固有のカレンダーを初期化
- 戻り値
	- ナシ
- 呼びだされ
	- init_player

## ゲーム中関数群
はじまってからの関数たち

### void game_main(PLAYER_T \*players)
- 内容
	- 二重ループを回す
	- 一重目は全員がゴールするまで
		- 二重目ループ
		- イベントの発生
	- 二重目は全員が一週間終わるまで
		- 一番遅い人を調べる関数
		- 1ターンの処理
- 戻り値
	- ナシ
- 呼び出し
	- select_active_player
- 呼びだされ
	- main

### int select_active_player(PLAYER_T \*players)
- 内容
	- 一番後ろのプレイヤーのIDを返す
- 戻り値
	- プレイヤーのID(配列の添字)
- 呼びだされ
	- game_main

### void move_player(PLAYER_T \*player)
- 内容
	- プレイヤー1人のターン処理
		- サイコロを投げる
		- 進む
		- ステータスを変更
- 戻り値
	- ナシ
- 呼び出し
	- throw_dice
- 呼びだされ
	- game_main

### int throw_dice(int n)
- 内容
	- 1~nの値をランダムで返す
	- return (rand()%n) +1
- 戻り値
	- サイコロの目
- 呼びだされ
	- move_player

# ミニゲームは保留します！！！！！！

## ゲーム終了後処理関数群
終わってからの関数たち

### void game_end(PLAYER_T \*players)
- 内容
	- ポイントの計算
	- 順位付け
	- 表示
