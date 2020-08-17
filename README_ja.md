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

追加したいものがたくさん。

- セグ木上の二分探索(<img src="https://render.githubusercontent.com/render/math?math=O(\log^2 N)\to O(\log N))"> に落とせるやつ)