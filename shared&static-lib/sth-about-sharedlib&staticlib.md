# gcc/g++ 链接库的编译与链接

程序编译一般需要经预处理、编译、汇编和链接几个步骤。在实际应用中，有些公共代码需要反复使用，就把这些代码编译成为“库”文件。在链接步骤中，连接器将从库文件取得所需的代码，复制到生成的可执行文件中，这种库称为静态（链接）库，其特点是可执行文件中包含了库代码的一份完整拷贝，缺点是被多次使用就会多份冗余拷贝。还有一种库，就是程序在开始运行后调用库函数时才被载入，这种库独立于现有的程序，其本身不可执行，但包含着程序需要调用的一些函数，这种库称为**动态（链接）库（Dynamic Link Library）**。

![img](https://img-blog.csdn.net/20140912225212712?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

在widows平台下，静态链接库是.lib文件，动态库文件是.dll文件。在linux平台下，静态链接库是.a文件，动态链接库是.so文件。这里主要讲在linux平台下的动态库和静态库的生成以及链接。

## 一、库的基本知识

首先说明要对库有一个比较直观的理解。库是写好的现有的，成熟的，可以复用的代码。现实中每个程序都依赖很多基础的底层库，不可能每个人的代码都从零开始，因此库的存在意义非同寻常。本质上说来库是一种可执行代码的二进制形式（注，其本身不可执行），可以被操作系统载入内存执行。

**静态链接库**，之所以称为“静态库”，是因为在链接阶段，会将汇编生成的目标文件.o与引用到的库一起链接打包到可执行文件中，因此对应的链接方式为静态链接。其实一个静态链接库可以简单看成一组目标文件(.o/.obj文件)的集合，即很多目标文件经过压缩打包后形成的一个文件。静态库特点总结：

             1. 静态库对函数库的链接是放在编译时期完成
             2. 运行时对函数库再无瓜葛，一直方便。
             3. 浪费空间和资源，因为所有相关的目标文件和牵涉到的函数库被链接合成一个可执行文件。

linux下使用ar工具（windows下用lib.exe）（具体的用法参考【5】），可以将目标文件压缩到一起，并且对其进行编号和索引，一便于查找和索引。一般创建静态链接库的步骤如下：

![img](https://img-blog.csdn.net/20140912225446965?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

静态链接库的命名规则，库的名称和库文件名称不同，有联系，假定库名称为"my_library_name"，那么起库文件名为"lib[my_library_name].a"(方括号是为了区分，实际上没有)

**动态链接库**，在程序编译是并不会被连接到目标代码中，而是在程序运行时才被载入。不同的应用程序如果调用相同的库，那么在内存里只需要有一份该共享库的实例，规避了空间浪费问题。动态库的一些总结：

          1. 动态库把对一些库函数的链接载入推迟到程序运行时期
          2. 可以实现进程之间的资源共享，（动态库也成为共享库）
          3. 将一些程序升级变得简单
          4. 设置可以真正做到链接载入完全由程序员在程序代码中控制（显式调用）

Linux下gcc编译的执行文件默认是ELF格式，不需要初始化入口，亦不需要函数做特别的声明，编写比较方便。与windows系统下的格式不同。与创建静态库不同的是，不需要打包工具，直接使用编译器即可创建动态库。

![img](https://img-blog.csdn.net/20140912225337062?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

动态链接库的命名规则，与静态链接库的方式相同，不过其后缀名为.so，命名形为"lib[my_library_name].so"   。但是在实际使用过程中libxxx.so 大多数情况只是一个链接，它链接到一个包含版本信息的库文件 libxxxx.so.xx，如下图。当然自己可以使用 ln 命令，制作链接 ln -s libxxxx.so.xx libxxxx.so。

![img](https://img-blog.csdn.net/20140912225456281?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 二、库的编译和链接

下面使用一个例子来说明链接库是如何生成与链接的。这个例子的源代码参考【4】。这里有五个文件，头文件“SoDemoTest.h”，三个cpp文件“one.cpp”、"two.cpp"、"three.cpp"，main函数实现文件“main.cpp”。

```cpp
#ifndef _SO_DEMO_TEST_HEADER_
#define _SO_DEMO_TEST_HEADER_
#include <iostream>
using namespace std;
void one();
void two();
void three();
#endif
```



```cpp
/* one.cpp */
#include "SoDemoTest.h"
void one(){
    cout << "call one() function" << endl;
}
```



```cpp
/* two.cpp */
#include "SoDemoTest.h"
void two(){
    cout << "call two() function" << endl;
}
```



```cpp
/* three.cpp */
#include "SoDemoTest.h"
void three(){
    cout << "call three() function" << endl;
}
```



```cpp
/* main.cpp */
#include "SoDemoTest.h"
int main(){
    one();
    two();
    three();
    return 0;
}
```

> gcc/g++的编译参数，这里只介绍 -L 、-l、-include、-I、-shared、-fPIC
>
> -L ：表示要链接的库所在的目录。-L.  表示要链接的库在当前目录， -L/usr/lib 表示要连接的库在/usr/lib下。目录在/usr/lib时，系统会自动搜索这个目录，可以不用指明。
>
> -l (L的小写)：表示需要链接库的名称，注意不是库文件名称，比如库文件为 libtest.so，那么库名称为test
>
> -include ：包含头文件，这个很少用，因为一般情况下在源码中，都有指定头文件。
>
> -I (i 的大写)：指定头文件的所在的目录，可以使用相对路径。
>
> -shared ：指定生成动态链接库
>
> -fPIC：  表示编译为位置独立的代码，不用此选项的话编译后的代码是位置相关的所以动态载入时事通过代码拷贝的方式来满足不同进程的需要，而不能达到真正代码共享的目的。

   **生成链接库**

   第1步，生成目标文件：g++ -c xxx.cpp

![img](https://img-blog.csdn.net/20140912225641828?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

 第2步，创建静态链接库:  ar  cqs  libxxxx.a  xx1.o xx2.o xx3.o

![img](https://img-blog.csdn.net/20140912230000572?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

第3步，程序中使用静态链接库

![img](https://img-blog.csdn.net/20140912230114282?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

第4步，创建动态链接库 g++ -fPIC -shared -o libxxx.so xx1.cpp xx2.cpp xx3.cpp

![img](https://img-blog.csdn.net/20140912230210692?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

 第5步，动态链接库使用

![img](https://img-blog.csdn.net/20140912230128781?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)



​    **库的链接**，上面简单演示了一遍库的生成过程，但是还有很多细节没有讲清楚。以下问题需要注意：

​    1. 链接过程中可能出现多种链接方式，需要使用一些参数来指定，下面只是一个演示，在测试时，自己填写具体的名称

```shell
g++ testmain.o -o testmain -WI,-Bstatic -lstaticlib -WI,-Bdynamic -ldynamiclib
```

2. 链接过程中同一个库（名称相同）的静态和动态两种链接库，在链接过程中，系统优先选择动态链接库

![img](https://img-blog.csdn.net/20140912230507612?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

3. 动态链接库路径，系统默认在/usr/lib 和/usr/local/lib两个库目录搜索，自己定义的库需要格外指定路径（设定变量LD_LIABRARY_PATH）或者将其拷贝到这两个目录下，在上面的例子的测试过程，已经有说明。当然也可以将当前路径添加到/etc/ld.so.conf文件中或者/etc/ld.so.conf.d目录下的一个文件中。

  4. 查看动态链接库。有时候可能需要查看一个库中到底有哪些函数，nm命令可以打印出库中的涉及到的所有符号。库既可以是静态的也可以是动态的。nm列出的符号有很多，常见的有三种：
     一种是在库中被调用，但并没有在库中定义（表明需要其他库支持），用U表示；
     一种是在库中定义的函数，用T表示，这是最常见的；
     另一种所谓的“弱态”符号，它们虽然在库中定义，但可能被其他库中的同名符号覆盖，用W表示。

![img](https://img-blog.csdn.net/20140912230701898?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

使用ldd命令可以查看程序的库依赖：

![img](https://img-blog.csdn.net/20140912230815546?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VyZ2V3b25n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)