# EMU6802

[*v0.33a*](https://github.com/ryu10/emu6802/releases/tag/v0.33a)

(JA | [EN](Readme_en.md))

  電脳伝説様作の [EMUZ80](https://github.com/vintagechips/emuz80) を利用した PIC16F47Q84 + MC6802 コンピュータです。

  - RAM 12KB
  - Mikbug
  - Basic（フリーエリア 6KB）

## 構成方法

PIC16F47Q84 を搭載した EMUZ80 を使います。EMUZ80 基板の CPU ソケットは Z80 準拠のピン配列ですので MC6802 には直接使えません。別途ブレッドボードに MC6802 を載せてジャンパ線で配線します。

![emu6802-breadboard](/img/emu6802bb.jpg)

上の画像ではワイヤラッピングを利用しています。配線が細くバス配線作業が容易です。

## 配線

具体的な配線は下の回路図のとおりです（[PDF 版](/emu6802.kicad5/emu6802/emu6802_sch.pdf)）。図の右半分は PIC 内部の CLC と NCO の構成を説明するためのもので、実際に配線する必要はありません。

![schematic](/img/emu6802_sch.png)

## PIC プログラム

PIC プログラムは EMUZ80 やユーザの方々による派生システムを参考にして記述しました。また、MCC（MPLAB Code Configurator）を使って PIC 内部モジュールの構成を行っています。このリポジトリの [emu6802.X](/emu6802.X/) 以下のプロジェクトを MPLAB X IDE で開くと内容が確認できます。

PIC 書き込みにはビルド済み HEX ファイル [emu6802.X.production.hex](https://github.com/ryu10/emu6802/releases/download/v0.31/emu6802.X.production.hex) が利用できます。

注：現行の HEX ファイルは PIC18F47Q84 をターゲットにしてビルドされています。

## 実行までの手順

1. EMUZ80 を組み立てます。PIC18F47Q84 を使用します。
2. EMUZ80 から Z80 を取り去り、ブレッドボードに刺した 6802 へジャンパ線を使って配線します。結線は上の回路図を参照してください。
3. PIC に HEX ファイル [emu6802.X.production.hex](https://github.com/ryu10/emu6802/releases/download/v0.31/emu6802.X.production.hex) を書き込みます。
4. 電源投入すると EMUZ80 のシリアルポート（9600bps）から Mikbug を使用できます。
5. 'G' コマンドのジャンプベクタアドレスは $7F48-$7F49です。デフォルトで $0000 が設定されているので、電源投入後すぐに 'G' キーを押すと Basic が立ち上がります。起動時の質問には下記の画面のとおり順に「12544」「80」「Y」と答えると一般的な設定が選択されます。

![startup-mikbug-altair](/img/mikbug-abasic.png)

## 動作

EMUZ80 と同様に PIC が MPU バス信号を読み取って ROM、RAM、UART をエミュレートします。

通常のハードウェアに比べてメモリ応答が遅くなるので、6802 の MR ピンを使ってシステムクロック E をストレッチしています。

外部クロックピン EXTAL に 2MHz を入力した場合システムクロック E は本来 500kHz になるはずですが、クロックのストレッチを含めて平均化すると 200kHz 前後で動作するようです。

![timing2](/img/timing2.png)

（Ch1: EXTAL, Ch1: E, Ch3: MR）

PIC コード次第ではもう少し高速化できるかもしれません。現状のコードでは SBC6802 のメモリマップが再現される反面、メモリ割り当てが複雑になり処理効率は落ちます。

## 課題

- PIC のメモリエミュレーションを最適化する。
- Altair 680 Basic を走らせる。✅
- 割り込みピンを配線する。
- EMUZ80 基板に載せられるアダプタボードを作る。
- MC6802 内蔵 128 Byte RAM を有効にする。 (branch 'ram128') ✅
