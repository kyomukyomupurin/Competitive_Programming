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

<details>
  <summary markdown="span"> Information </summary>

- **All** functions are 0-indexed.  
- **Not** every function is for semi-open section(read comments carefully). 
- [Snippets generator for Visual Studio Code](https://github.com/kyomukyomupurin/snippets_generator)

</details>

<details>
  <summary markdown="span"> Environment </summary>

- Windows subsystem for Linux, Ubuntu 18.04  
- g++ 7.5.0  
- Compilation command :  ```g++ -std=c++17 -Wall -Wextra -Wshadow -Wno-unknown-pragmas -fsanitize=address -fsanitize=undefined -fsplit-stack -O2 -D_GLIBCXX_DEBUG -DLOCAL main.cc```

</details>

<details>
  <summary markdown="span"> TO DO </summary>

- Add binary search function on Segment Tree.  
- Add FFT(and NTT).  
- Add Self-Balancing Binary Search Tree(Treap, Splay Tree, or AVL Tree).   
- Make [FastIO](https://github.com/kyomukyomupurin/competitive_programming/blob/master/src/etc/fastio.cc) faster.  
- Add graph libraries(hld_forest, dfs_forest, scc_digraph, ...).
- Add Brent's version of Pollard's rho.

</details>

# How to use

## algorithm

### coodinate_compression.cc

|  Name  |  Return value  |  Description  |  Time complexity  |
|:----:|:----:|:----:|:----:|
|Compress()|void|Called in constructor|O(N log N)|
|[](int pos)|state|Access element|O(1)|

### cumulative_sum.cc

|  Name  |  Return value  |  Description  |  Time complexity  |
|:----:|:----:|:----:|:----:|
|build()|void|Called in constructor|O(N)|
|get(l, r)|T|Returns <img src="https://render.githubusercontent.com/render/math?math=\sum_{i=l}^{r}vec[i]">|O(1)|
|lower_bound(val)|int|Returns the first pos where <img src="https://render.githubusercontent.com/render/math?math=\sum_{i=0}^{pos}vec[i]\geq val">|O(log N)|
|upper_bound(val)|int|Returns the first pos where <img src="https://render.githubusercontent.com/render/math?math=\sum_{i=0}^{pos}vec[i]\gt val">|O(log N)|

### cumulative_sum_2d.cc

### doubling.cc

### golden_section_search.cc

## data_structure

## etc

## graph

## math

## string

## typical