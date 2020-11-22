# exec

+ 在一个可执行程序中调用另一个可执行新程序（木马程序的来源）

+ execve

  + e -> 可修改环境变量
  + v -> 运行参数以vector形式给出
    + char \*args[] = {"./test", "ABC", NULL}

+ execle

  + execle("./test", "ABD", "123", NULL, NULL)
    + e -> 需要提供环境变量、运行参数需要以NULL结尾(如果写0要进行类型强转)

  + execlp("test", "ABC", NULL)
    + p -> 到PATH中搜寻

  + l -> 运行参数直接在程序中给出
