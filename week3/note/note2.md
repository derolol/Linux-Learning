# 文件操作函数

## open

## `FILE* fopen(const char* pathname, const char* mode)`

+ **mode** r r+ w w+ a a+

+ open() flags和fopen() mode

fopen() mode|open() flags
-|-
r|O\_RDONLY
w|O\_WRONLY | O\_CREAT | O\_TRUNC
a|O\_WRONLY | O\_CREAT | O\_APPEND
r+|O\_RDWR
w+|O\_RDWR | O\_CREAT | O\_TRUNC
a+|O\_RDWR | O\_CREAT | O\_APPEND

## `FILE* fdopen(int fd, const char* mode)`

+ 已经打开的文件描述符
+ 文件流对该文件的操作方式说明 
+ 返回值 - 用来操作文件描述符所指向的文件指针

## `FILE* freopen(const char* pathname, const char* mode, FILE* stream)`

## `int fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream)`

+ ptr 源指针
+ size 每次写的字节数
+ nmemb 写的次数
+ stream 目标文件流
+ 返回值 写的次数

## `char* fgets(char* s, int size, FILE* stream)`
