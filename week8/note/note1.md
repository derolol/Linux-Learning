# Adress Space

## The adress space of process

+ stack (local var) 每个函数分配一个zhanzhen

  + from top to down

+ heap

  + from down to top

+ data data segment (global var and staic var)

+ TEXT code segment

## goto

+ break the run flow

  + function inside
    + goto + label

  + between function

    + setjmp -> set jump point
	
      return 0

    + longjmp -> jump to set jump point

      restore the break point
      return 1
