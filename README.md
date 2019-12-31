# Competitive-Programming

Libraries for competitive programming  

## Information

- クエリ系の取得は全部 0-indexed でやる  
- 半開区間のものと両閉区間のものがあるので、気を付ける(関数の上のコメントを見る)  

## TO DO  

- 遅延セグメント木をかく
  - [こどふぉのブログ](https://codeforces.com/blog/entry/18051)を読んでるけどしっくりきていない。
  - ラムダ式をたくさん渡すのはしんどいので、ある程度機能を絞ったものを複数用意しておこうと思っている。
  - 次のものがあれば十分かなと思っている
    - 区間加算($a_l,...,a_r$に $x$ を加える)・区間 min/max 取得 $\to$ できた
    - 区間変更($a_l,...,a_r$を $x$ に変更)・区間 min/max 取得 $\to$ できた
    - 区間加算($a_l,...,a_r$に $x$ を加える)・区間 sum 取得 $\to$ できてない  
      - fenwick tree 2 本でできる(できた)  
    - 区間変更($a_l,...,a_r$を $x$ に変更)・区間 sum 取得 $\to$ できてない
  - 区間 sum 取得は区間 min/max ほどシンプルにはかけないっぽい
    - min/max だと $f(f(a, b), f(b, c)) = f(a, c)$ が成り立つけど、sum に対しては成り立たないからかな？と思っている(正しいかどうかは知らない)  

- FFT をかく

## えー

GitHub って数式表示してくれないの  
