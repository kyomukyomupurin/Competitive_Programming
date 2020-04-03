# Competitive-Programming

競プロ用のライブラリ。たまに更新する。  

## Information

- クエリ系の取得は全部 0-indexed でやる  
- 半開区間のものと両閉区間のものがあるので、気を付ける(関数の上のコメントを見る)  
- ```g++ -std=c++17 -Wall -Wextra -Wshadow -O2 -DLOCAL main.cc && ./a.exe(Linux/Mac なら ./a.out)``` で実行  

## TO DO  

- 遅延セグメント木をかく
  - [こどふぉのブログ](https://codeforces.com/blog/entry/18051)を読んでるけどしっくりきていない :thinking:
  - ラムダ式をたくさん渡すのはしんどいので、ある程度機能を絞ったものを複数用意しておこうと思っている。
  - 次のものがあれば十分かなと思っている
    - 区間加算($a_l,a_{l+1}...,a_r\to a_l+x,a_{l+1}+x,...,a_r+x$)・区間 min/max 取得 $\to$ できた
    - 区間変更($a_l,a_{l+1},...,a_r\to x,x,...,x$)・区間 min/max 取得 $\to$ できた
    - 区間加算($a_l,a_{l+1}...,a_r\to a_l+x,a_{l+1}+x,...,a_r+x$)・区間 sum 取得 $\to$ できてない  
      - fenwick tree 2 本でできる(できた)  
    - 区間変更($a_l,a_{l+1},...,a_r\to x,x,...,x$)・区間 sum 取得 $\to$ できてない
  - 区間 sum 取得は区間 min/max ほどシンプルにはかけないっぽい
    - min/max だと $f(f(a,b), f(b,c)) = f(a,c)$ が成り立つけど、sum に対しては成り立たないからかな？と思っている(正しいかどうかは知らない)  

- FFT をかく  
  - ~~適当にググって出てきたやつをコピペすればヨシ！~~  

- クラスのメンバ関数を大文字にするか小文字にするかが悩ましい。[Google のスタイルガイド](https://ttsuki.github.io/styleguide/cppguide.ja.html) では大文字にしましょうとあるけど、そもそも STL のコンテナのメンバ関数は小文字だよなあと思ったり(push_back とか)。  

- assert をマメに使う。  

- 短い Build, Initialize 関数はコンストラクタに直書きした方が速くなりそう。  

## えー

GitHub って数式表示してくれないの :cry:  
