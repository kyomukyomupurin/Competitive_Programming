# これはなに

プログラミングコンテストに参加する際に使用しているライブラリです。ここに載っているソースコードは自由に使用していただいて構いませんが、そのソースコードを使用したことによって発生したコンテスト中のペナルティに関してはいかなる理由があっても一切責任を負いません。

## Information

-  関数の引数等は全て 0-indexed で実装しています。
-  区間に対するクエリを処理する関数は半開区間のものと閉区間があるので、コメントをよく見て注意して使いましょう(自戒)。
-  ライブラリを Visual Studio Code にスニペットとして追加する際は、[Snippets generator for Visual Studio Code](https://github.com/kyomukyomupurin/snippets_generator) を使うと快適です(宣伝)。

## Environment

-  Windows subsystem for Linux, Ubuntu 18.04 でコードを書いています。
-  コンパイラは g++ 7.5.0 を利用しています。C++17 の文法も多少使っているので、ジャッジサーバのコンパイラが古いサイト(AOJ 等)では動かないコードも含まれています。悲しい。
-  次のようなコマンドでコードをコンパイルしています。  
```g++ -std=c++17 -Wall -Wextra -Wshadow -Wno-unknown-pragmas -fsanitize=address -fsanitize=undefined -fsplit-stack -O2 -D_GLIBCXX_DEBUG -DLOCAL main.cc```

## TO DO

これから追加したいものたち。

-  セグ木上の二分探索( <img src="https://render.githubusercontent.com/render/math?math=O(\log^2 N)\to O(\log N)"> に落とせるやつ)
-  FFT(高速フーリエ変換)、NTT (余裕があれば(なさそう))
-  平衡二分探索木(Treap, Splay 木、AVL 木のどれか or 複数書いてみたい、でも実装辛そう)
- [FastIO](https://github.com/kyomukyomupurin/competitive_programming/blob/master/src/etc/fastio.cc) をさらに高速化したい。Scanner の ```memmove``` を ```memcpy``` で置き換えられたら速くなるはず。他の箇所はどうすればこれ以上速くなるかわからない...。
- グラフ関連のライブラリ(HL 分解、強連結成分分解、DFS 木)の整備
- Pollard's rho 高速素因数分解

## 各ライブラリの使い方

随時更新していきます。

### algorithm

<details>
  <summary>coodinate_compression.cc</summary>

  #### 概要

  座標圧縮を行う。最近は、これ別にいらないのではという気持ちになっており、今後も使うことはなさそう。  

  #### 使い方

  座標圧縮したい vector を用意し(vec とする)、```CoodinateCompression cc(vec);``` と宣言する。 ```cc[i].before, cc[i].after``` はそれぞれ座標圧縮前、座標圧縮後の値を返す。
  
  #### 計算量
  (<img src="https://render.githubusercontent.com/render/math?math=N"> を vec のサイズとして)  
  CoodinateCompression() : <img src="https://render.githubusercontent.com/render/math?math=O(N\log N)">
</details>

<details>
  <summary>cumulative_sum.cc</summary>

  #### 概要

  一次元の累積和をとる。  

  #### 使い方

  累積和をとりたい vector を用意し(vec とする)、```CumulativeSum cs(vec);``` と宣言する。

  get(l, r) : <img src="https://render.githubusercontent.com/render/math?math=\sum_{i=l}^{r} vec[i]"> を返す。  
  lower_bound(val) : 初めて <img src="https://render.githubusercontent.com/render/math?math=\sum_{i=0}^{pos}\geq val"> となるような pos を返す。  
  upper_bound(val) : 初めて <img src="https://render.githubusercontent.com/render/math?math=\sum_{i=0}^{pos}> val"> となるような pos を返す。 
  
  #### 計算量

  (<img src="https://render.githubusercontent.com/render/math?math=N"> を vec のサイズとして)  
  CumulativeSum() : <img src="https://render.githubusercontent.com/render/math?math=O(N)">  
  get(l, r) : <img src="https://render.githubusercontent.com/render/math?math=O(1)">  
  lower_bound(val) : <img src="https://render.githubusercontent.com/render/math?math=O(\log N)">  
  upper_bound(val) : <img src="https://render.githubusercontent.com/render/math?math=O(\log N)">  

</details>

<details>
  <summary>cumulative_sum_2d.cc</summary>

  #### 概要

  二次元の累積和をとる。  

  #### 使い方

  累積和をとりたい二次元の vector を用意し(vec とする)、```CumulativeSum2D cs(vec);``` と宣言する。
  -  get(sx, sy, gx, gy) : 長方形の閉区間 <img src="https://render.githubusercontent.com/render/math?math=[sx, gx]\times[sy, gy]"> の和を返す。

  #### 計算量

  (<img src="https://render.githubusercontent.com/render/math?math=H"> を vec のサイズ、<img src="https://render.githubusercontent.com/render/math?math=W"> を vec[0] のサイズとして)  
  -  CumulativeSum2D : <img src="https://render.githubusercontent.com/render/math?math=O(HW)">  
  -  get(sx, sy, gx, gy) : <img src="https://render.githubusercontent.com/render/math?math=O(1)">  

</details>