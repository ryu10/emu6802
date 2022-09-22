# EMU6802

[v0.6]

(日本語 | [EN](Readme_en.md))

  電脳伝説様作の [EMUZ80](https://github.com/vintagechips/emuz80) を利用した PIC16F47Q84 + MC6802 コンピュータです。

## TL;DR

 - [回路図](/img/emu6802_conv_sch.pdf)
 - [Gerber](/data/emu6802r1-gerber.zip)
 - [emu6802.X.production.hex](/data/emu6802.X.production.hex)（PIC16F47Q84 用）
 
## 機能と特徴

  - MC6802 用変換基板
  - RAM 12KB
  - Mikbug モニタ
  - Basic（フリーエリア 5.5KB）
  - PIC TU16A タイマモジュール（IRQ 割り込み可）

![emu6802](/img/emu6802pcb.jpg)

## 構成方法

以下の部品が必要です。

 - EMUZ80 キット（Z80 を除く）
 - PIC16F47Q84
 - EMU682 変換基板（[Gerber](/data/emu6802r1-gerber.zip)）
 - MC6802 または互換チップ
 - DIP 40P ソケット
 - 20x1 ピンソケット x2
 - 20x1 ピンヘッダ x2（細ピンタイプ、秋月電子などで入手可）
 - （オプション）C1/C2 パスコン（0.1uF, 10uF）、J3/J4/J5 パッチベイ用ピンヘッダ（5x2, 1x1, 3x1）

上の画像では MC6802 互換の MB8870H を使用しています。

## 配線

変換基板の配線を下の回路図に示します（[PDF 版](/img/emu6802_conv_sch.pdf)）。標準でデータバス、アドレスバス、制御信号、IRQ が配線されています。

![schematic](/img/emu6802_conv_sch.png)

6802 の NMI、HALT、BA、RE ピンを使用する場合は回路図を参考に次の要領で行ってください。

1. 変換基板上のジャンパパターンを切って既存の配線をカットします。
2. パッチベイにピンヘッダを取り付けます。
3. ジャンパ線を使って PIC の RA4/RE1/RE2 へ配線するか、ジャンパブロックを使ってプルアップ／プルダウンを選択します。
4. 目的に応じて PIC のピン割り当て設定とプログラムを変更します。

## PIC プログラム

HEX ファイル [emu6802.X.production.hex](/data/emu6802.X.production.hex) を PIC へ書き込みます。ソースコードはこのリポジトリの [emu6802.X](/emu6802.X/) 以下を参照してください。プロジェクトを MPLAB X IDE で開きます。

注：現行の HEX ファイルは PIC18F47Q84 をターゲットにしてビルドされています。

## BASIC 実行までの手順

1. EMUZ80 を組み立てます。PIC18F47Q84 を使用します。Z80 は取り付けません。
2. Z80 ソケットの外側のパターンに 20x1 ピンソケットを 2 本はんだ付けします。
3. PIC に HEX ファイル [emu6802.X.production.hex](/data/emu6802.X.production.hex) を書き込みます。なお PIC 書き込みの際は念のため 6802 または変換基板を取り外してください。
4. 変換基板を組み立てて EMUZ80 基板のピンソケットに刺します。
5. 電源投入すると EMUZ80 のシリアルポート（9600bps）から Mikbug を使用できます。
6. 'G' コマンドが参照するジャンプベクタアドレスは $2F48-$2F49です。デフォルトでジャンプベクタ $0000 が設定されているので、電源投入後すぐに 'G' キーを押すと Basic が立ち上がります。起動時の質問には下記の画面のとおり順に「12160」「80」「Y」と答えると一般的な設定が選択されます。

![startup-mikbug-altair](/img/mikbug-abasic.png)

## 動作

EMUZ80 と同様に PIC が MPU バス信号を読み取って ROM、RAM、UART、タイマをエミュレートします。

通常のハードウェアに比べてメモリ応答が遅くなるので、6802 の MR ピンを使ってシステムクロック E をストレッチしています。現状のコードでは、外部クロック入力 EXTAL に 2.3MHz を入力した場合に BASIC プログラムが最も高速に動作するようです。このとき 6802 のシステムクロック E の実効値は 387kHz 程度です。

![timing2](/img/timing2.png)

（Ch1: EXTAL, Ch1: E, Ch3: MR）

## PIC タイマと IRQ 割り込み

PIC タイマモジュール TU16A の出力は CLC の FF 回路を経由して 6802 の IRQ に接続されます。6802 メモリ空間の \$A007 - \$A00F 経由で TU16A の設定レジスタにアクセスできます。アドレスとレジスタの対応は下表のとおりです。

| 6802 アドレス | PIC レジスタ名  |
|--------------|---------------|
| 0xa007       | TU16ACON0     |
| 0xa008       | TU16ACON1     |
| 0xa009       | TU16AHLT      |
| 0xa00a       | TU16APS       |
| 0xa00b       | TU16ATMRH / TU16ACRH |
| 0xa00c       | TU16ATMRL / TU16ACRL |
| 0xa00d       | TU16APRH      |
| 0xa00e       | TU16APRL      |
| 0xa00f       | TU16ACLK      |
| 0xa01f       | IRQ フラグリセット   |

タイマ割り込みを応用した MC6802 時計表示プログラムが [clock.a](data/irq/clock.a) です。

![clockapp](/img/clockapp.png)

また PIC 内で動く RTC がプログラムされており、RTC の時刻データを \$B000 - \$B003 で読み出せるようにしてあります。この場合 IRQ 割り込みは不要です。これを利用した Basic 時計表示プログラムが [clock.bas](data/pictmr/clock.bas) です。

なお PIC の内部発振は誤差 2% 程度なので、実用的な RTC としては精度が不十分です。

## 課題

- PIC のメモリエミュレーションを最適化する。✅
- Altair 680 Basic を走らせる。✅
- 割り込みピンを配線する。✅
- EMUZ80 基板に載せられるアダプタボードを作る。✅
- ~~MC6802 内蔵 128 Byte RAM を有効にする。✅~~（※本リリースのデフォルト設定では無効。[リリース v0.33](https://github.com/ryu10/emu6802/tree/v0.33) を参照してください）
