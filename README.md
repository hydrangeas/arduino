arduino
=======

## 利用方法

+ SleepClock/SleepClock.inoを立ち上げると他はタブとして読み込まれる

「タブ」とはArduino用語で、メイン（setup/loop）以外に分割されたファイルの
ことをいいます。

## 解析

+ SleepClockData.shでSDカードから書式にマッチしたデータだけを抽出します
+ SleepClockPlot.shでグラフを出力します

`SleepClockData.sh`内に`totalPer1min`と記述されている箇所があり、
そこで１分毎にデータを集計しています。
`totalPer1sec`と`totalPer10sec`はそれぞれ1秒毎、10秒毎に集計できます。

`SleepClockPlot.sh`は内部でGnuplotを使用していますので、
これがない場合はエラーとなり、終了します。
必ず、このシェルが参照できる場所にパスを通しておいてください （検索まではしません）。

