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

### int init_players(PLAYER_T \*head)
- 内容
	- プレイヤー全員の初期化
- 戻り値
	- 正常終了→TRUE
	- エラー発生→FALSE
- 呼び出し
	- init_player

### int init_player(PLAYER_T \*player)
- 内容
	- プレイヤー一人の初期化
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

### game_main()
