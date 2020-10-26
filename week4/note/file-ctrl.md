# 常用文件操作函数

## 1. 打开和关闭流

+ FILE\* **fopen** (const char\* pathname, const char\* opentype);

opentype|describtion
:-:|-
"r"|**读** 定位于文件开始
"w"|**写** 长度截为0
"a"|**文件尾写**
"r+"|**读写** 定位于文件开始
"w+"|**读写** 长度截为0
"a+"|**读写** 添加总在末尾，文件位置只能控制从文件读数据

+ int **fclose** (FILE\* stream);

+ FILE\* **freopen** (const char\* pathname, const char\* opentype, FILE\* stream);

  如果stream指定的流是打开的，则先将该流关闭，然后用opentype方式打开文件pathname并将指向文件流的指针赋给stream

## 2. 读和写流

### 2.1 字符I/O

> stdio.h

+ int **fgetc** (FILE\* stream);

  按 unsigned char 类型读取下一个字符，不能将返回值存储在字符类型的变量中

+ int **getc** (FILE\* stream);

  允许被作为宏实现，高度优化，最常用

+ int **getchar** (void);

  等价于 getc(stdin)

+ int **fputc** (int c, FILE\* stream);

+ int **putc** (int c, FILE\* stream);

+ int **putchar** (int c);
