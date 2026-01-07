# 输入输出+Buffer

### 竞赛用法

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

## 缓冲类型

- 行缓冲
    - 设备：键盘（`stdin`）、屏幕（`stdout`）
    - 刷新时机： 
        - `\n`
        - `flush/cout.flush()`，析构时自动 `flush`
        - `缓冲满了`
        - `程序结束`
    > 行缓冲的具体行为依赖于实现与运行环境，但该模式在交互式终端中最为常见 [^1][^2]。
- 全缓冲
    - 设备：文件
    - 只有在缓冲区满或显式 flush 时才会真正写出 [^1]
- 无缓冲
    - `stderr`
    - 输出立即写入设备，主要用于错误信息 [^1]

## C Buffer

### 缓冲结构 `File*`

```c
FILE *stdin;
FILE *stdout;

struct FILE {
    char* buffer;     // 指向缓冲区的指针
    int   buf_size;   // 缓冲区大小
    int   pos;        // 当前读/写位置
    int   mode;       // 读 / 写 / 行缓冲 / 全缓冲
    int   fd;         // 文件描述符（和内核交互）
};
```
在 C 标准中，FILE 被定义为不透明类型，其内部结构由实现决定，但可以确定的是：
stdio 在用户态维护缓冲区，并通过系统调用与内核交互[^1][^3]。

### 函数

!!! note "进缓冲区 ➡ 触发刷新 ➡ “交付”"

- `scanf()`：数据先进 **stdin 缓冲区**，遇到回车，才“交付”给程序
- `printf()`：输出时，数据先进 **stdio 缓冲区**，触发刷新条件，才真正输出到屏幕[^3]。

## C++ Buffer

### 缓冲结构 `cout`

```cpp
ostream cout
│
├── streambuf* sb   ← 关键！真正存数据的是 streambuf
│     └── char buffer[...]
│
└── 格式控制 / 类型系统

```

C++ I/O 的核心是 `std::basic_streambuf`，它负责真正的数据缓冲与指针管理 [^4]。

```cpp
// streambuf 的三指针模型
buffer memory:
┌------------------------------─┐
│ gptr        pptr        epptr │
└------------------------------─┘
```


-  `gptr`   get pointer（读指针）     
-  `pptr`   put pointer（写指针）  
-  `epptr`  end put pointer（写区尾） 

> 注意：这里的读写，均是以程序为主体而言的。

#### 机制

- `pptr == epptr`：
    - **触发 flush**
    - 调用 `write()` 把整个 buffer 写入内核
    - **重置指针**：`pptr == buffer_begin`[^4][^5]
- `gptr == epptr`
    - 当前 `buffer` 已读空
    - 调用 `read()` 从内核 再读一批[^4]
    - 覆盖整个 `buffer`
- `epptr = buffer_begin + buffer_size`
    - 即 `buffer` 起始地址 + `buffer` 容量
    - 通常大小为 4KB/8KB
- `pptr` 和 `gptr` 怎么移动的呢：
    - 都是从前往后读写
    - 并非脑子里想的“同时+共用”：
        - 输入流：只用 `gptr`
        - 输出流：只用 `pptr`
        - 同一个 `streambuf` **不会同时读写**

### 函数

!!! note "进缓冲区 ➡ 触发刷新 ➡ “交付”"

- `cout`：`data` 存入 `buffer`，`pptr` 向前移动，触发才调用 `write()`
- `cin`：`read()` 拿数据填满 `buffer`，`gptr` 向前移动

## C / C++ Buffer 同步

### 空间结构

C++ 的 `streambuf` 绑定到 C 的 `FILE` 缓冲

```cpp
cout.streambuf
    ⬇
stdout.FILE.buffer
```  

- 机制：共享数据源，但各自维护状态，通过同步机制保持输出顺序一致[^4][^6]；
- 但每次 I/O 都要“对齐”，所以慢！

### 函数

- `ios::sync_with_stdio(false)`：

    - 和 `stdio` 的缓冲区解绑，不同步，可节省**同步**开销；
    - 关闭后禁止混用 printf / cout [^6]

- `cin.tie()`

    - `nullptr`：解绑，免得输入前都要 `cout.flush()`，可节省**刷新**开销；
    - `&cout`：绑定，适用于需要立即显示输出的情况[^7]。

- 刷新方式

    ```cpp
    cout >> flush;
    cout.flush();
    
    cout >> endl; // endl == '\n' + flush
    
    // 开启/关闭 每次输出后自动刷新
    std::unitbuf
    std::nounitbuf
    ```

### I/O 开销分类

```cpp
I/O 总开销
├── ① 同步开销（synchronization）
├── ② 刷新开销（flush）
├── ③ 系统调用开销（syscall）
└── ④ 用户态处理开销（format / locale / 类型）
```

### 参考资料（References）

[^1]: ISO/IEC 9899:2018 — Programming Languages — C

[^2]:Kernighan, Ritchie — The C Programming Language, 2nd Edition

[^3]:Stevens — Advanced Programming in the UNIX Environment

[^4]:ISO/IEC 14882:2020 — Programming Languages — C++

[^5]:cppreference.com — std::basic_streambuf

[^6]:cppreference.com — std::ios::sync_with_stdio

[^7]:cppreference.com — std::istream::tie