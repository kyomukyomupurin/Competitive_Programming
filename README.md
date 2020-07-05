[![](https://img.shields.io/badge/license-CC0-lightgrey.svg?style=flat&logo=Creative-Commons)](https://github.com/kyomukyomupurin/competitive_programming/blob/master/LICENSE)
![](https://img.shields.io/badge/C++-17-brightgreen.svg?style=flat&logo=c%2B%2B)
![](https://img.shields.io/badge/Python-3.6.9-brightgreen.svg?style=flat&logo=Python)
![](https://img.shields.io/badge/JSON-brightgreen.svg?style=flat&logo=JSON)
![](https://img.shields.io/badge/g++-7.5.0-blue.svg?style=flat&logo=GNU)
![](https://img.shields.io/badge/-VSCode-blue.svg?style=flat&logo=Visual-Studio-Code)
![](https://img.shields.io/badge/OS-WSL-yellow.svg?style=flat&logo=Linux)
![](https://img.shields.io/badge/Ubuntu-18.04-orange.svg?style=flat&logo=Ubuntu)

# Competitive Programming

Libraries for competitive programming

## Information

- **All** functions are 0-indexed.  
- **Not** every function is for semi-open section(read comments carefully). 
- [Snippets generator for Visual Studio Code](https://github.com/kyomukyomupurin/snippets_generator)  

## Environment

- Windows subsystem for Linux, Ubuntu 18.04  
- g++ 7.5.0  
- Compilation command :  ```g++ -std=c++17 -Wall -Wextra -Wshadow -Wno-unknown-pragmas -fsanitize=address -fsanitize=undefined -O2 -D_GLIBCXX_DEBUG -DLOCAL main.cc```

## TO DO

- Modify [timer.cc](https://github.com/kyomukyomupurin/competitive_programming/blob/master/src/etc/timer.cc)  
- Add binary search function on Segment Tree.  
- Add Lazy Segment Tree.  
- Add FFT.    
- Add Self-Balancing Binary Search Tree(Treap, Splay Tree, or AVL Tree).   
- Make [FastIO](https://github.com/kyomukyomupurin/competitive_programming/blob/master/src/etc/fastio.cc) faster.  
  - Input of std::string contains bug, the length of a string cannot be decided when declared.  
