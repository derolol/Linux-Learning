# int main(int argc, char* argv[], char* env)

+ 函数参数

  + `argc` 参数计数器
  + `argv` 位置参数
  + `env` 修改运行环境

+ 命令行 `./testmain 123 4fdf oo`

+ 命令行参数

0|1|2|3
-|-|-|-
.testmain|123|4fdf|oo


+ 匿名缓冲区

index|argv[index]
-|-
0|./testmain
1|123
2|4fdf
3|oo
