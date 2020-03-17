# C语言中预定义符 __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__ 的使用演示

本文演示了C语言中预定义符 __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__ 的使用。

这几个预定义符的名称就没必要再介绍了，顾名思义嘛。

```cpp
// 演示 __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__ 的使用

#include "stdio.h"

void testFunc(void){
    printf("File = %s\nLine = %d\nFunc=%s\nDate=%s\nTime=%s\n", 
        __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__);
}

int main(int argc, char* argv[])
{
    testFunc();
    getchar();
    return 0;
}
```

VC2010编译通过，运行结果为：

```
File = c:\test\test__func__.cpp
Line = 8
Func=testFunc
Date=Sep  7 2012
Time=00:15:42
```

注意，这些预定义符可能在有些编译器会使用小写单词。