# EMU6802

[*v0.21*](https://github.com/ryu10/emu6802/releases/tag/v0.21) 

  電脳伝説様作 [EMUZ80](https://github.com/vintagechips/emuz80) を利用した PIC16F47Q84 + MC6802 コンピュータです。

## 構成

  EMUZ80 基板の CPU ソケットは当然ながら Z80 準拠のピン配列ですので、別途ブレッドボードに MC6802 を刺してジャンパ線で配線します。下図ではワイヤラッピング線を利用しています。線が細くバス配線が楽です。

![emu6802-breadboard](/img/emu6802bb.jpg)

## 配線

具体的な配線は下図のとおりです（[PDF 版はこちら](/emu6802.kicad5/emu6802/emu6802_sch.pdf)）。図の右半分は PIC 内部の CLC と NCO の構成を説明するもので、実際に配線する必要はありません。

![schematic](/img/emu6802_sch.png)

## PIC プログラム

EMUZ80 やその他の派生システムを参考にして記述したコードのほか、MCC（MPLAB Code Configurator）を使って PIC 内部モジュールの構成を行っています。[emu6802.X](/emu6802.X/) 以下のプロジェクトを MPLAB X IDE で開いてください。

PIC 書き込みの際はビルド済み HEX ファイル [emu6802.X.production.hex](/emu6802.X/dist/default/production/emu6802.X.production.hex) を使用できます。

注：現行の HEX ファイルは PIC18F47Q84 をターゲットにしてビルドされています。

## 実行までの手順

1. EMUZ80 を組み立てます。PIC18F47Q84 を使用します。
2. EMUZ80 から Z80 を取り去り、ブレッドボードに刺した 6802 へジャンパ線を使って配線します。結線は上の回路図を参照してください。
3. PIC に HEX ファイル [emu6802.X.production.hex](/emu6802.X/dist/default/production/emu6802.X.production.hex) を書き込みます。
4. 電源投入すると EMUZ80 のシリアルポート（9600bps）から Mikbug を使用できます。メモリマップは SBC6800 と同じです。

![startup-mikbug](/img/mikbug.png)

## 動作

EMUZ80 と同様、PIC が MPU バス信号を読み取って ROM、RAM、UART をエミュレートします。

通常のハードウェアに比べてメモリ応答が遅くなるので、6802 の MR ピンを使ってシステムクロック E をストレッチしています。

外部クロックピン EXTAL に 2MHz を入力した場合システムクロック E は本来 500kHz になるはずですが、クロックのストレッチを含めて平均化すると 160kHz 前後で動作するようです。PIC のコード次第ではもう少し高速化できるかもしれません。

![timing](/img/timing.png)

（黄色：EXTAL、シアン：E、マゼンタ：MR）


## 課題

- PIC のメモリエミュレーションを最適化する。
- Altair Basic を走らせる。
- 割り込みピンを配線する。
- EMUZ80 基板に載せられるアダプタボードを作る。
