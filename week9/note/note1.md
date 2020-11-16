# 进程

+ 进程 = PCB + 资源（Mem + fd）

+ fork() -> father process copy itself to son process, the only difference is the PID

  + Fork return a number which upper 0 and it stand for the PID of process
  + [9-1.c]the code is public but the father process and son process can just run the part of their own by judging the OUD
  + PID from 1 to MAX
  + Father process end before son process, the resource cannot be reslove`
  + If son process has exec(include execve/execle), use new process(runnable mirror) replace old process code, that mean it can call other runnable call

+ vfork()

  + son process and father process share stack/leap resource(memory space)

+ find max fork number

  + `cat /proc/sys/kernel/pid\_max`
  + `sysctl kernel.pid\_max`

+ `ps -ejH`

+ File

  + use the same file and share file position and point
