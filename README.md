# CodeBook

forked from [https://github.com/Jinkela-Xiao-Zuan-Feng-Mountaineer/Codebook.git]()

## Setup

進去該資料夾

```
cd CodeBook
```

開啟 docker，再執行以下動作：

先 build docker images

```bash
docker build -t latex-build .
```

之後要執行時，跑以下指令（此後每次更改後也只要執行這個指令即可）：

```bash
docker run --rm -v ${PWD}:/usr/src/app latex-build
```

## How to edit

編輯或新增 code 的話，進去 codes 這個資料夾編輯就好了。