# 尾调用（Tail Call）

### 定义

尾调用 （tail call） 指的是一个函数的最后一条语句也是一个返回调用函数的语句。在函数体末尾被返回的可以是对另一个函数的调用，也可以是对自身调用（即自身递归调用）。[[1\]](https://zh.wikipedia.org/wiki/尾调用#cite_note-N.C.Zakas_p61-64-1)

### 特征与简单示例

尾调用可能位于一个函数语法上最后的位置：

```c++
function foo(data) {
    a(data);
    return b(data);
}
```

在这里，`a(data)`、`b(data)` 都是函数调用，但是 `b(data)` 是函数返回前的最后运行的东西，所以也是所谓的尾位置。然后，并非所有的尾调用都必须在一个函数语法上最后的位置。考虑：

```c++
function bar(data) {
    if ( a(data) ) {
        return b(data);
    }
    return c(data);
}
```

在这里，`b`、`c` 的调用都在尾位置。这是因为尽管 `b(data)` 不在 `bar` 语法上最后的位置，它是 `if` 叙述其中一个分支最后的位置。

现在考虑以下代码：

```c++
function foo1(data) {
    return a(data) + 1;
}
function foo2(data) {
    var ret = a(data);
    return ret;
}
function foo3(data) {
    var ret = a(data);
    return (ret === 0) ? 1 : ret;
}
```

在这里，`a(data)` 处于 `foo2` 的尾位置，但**不**处于 `foo1` 或 `foo3` 的尾位置。这是因为程序必须返回这2个 `a` 函数的调用以检查、更动 `a` 的返回值。

### 说明

传统模式的编译器对于尾调用的处理方式就像处理其他普通函数调用一样，总会在调用时创建一个新的栈帧（stack frame）并将其推入[调用栈](https://zh.wikipedia.org/wiki/调用栈)顶部，用于表示该次函数调用。[[1\]](https://zh.wikipedia.org/wiki/尾调用#cite_note-N.C.Zakas_p61-64-1)

当一个函数调用发生时，电脑必须 “记住” 调用函数的位置 —— 返回位置，才可以在调用结束时带着返回值回到该位置，返回位置一般存在调用栈上。在尾调用这种特殊情形中，电脑理论上可以不需要记住尾调用的位置而从被调用的函数直接带着返回值返回调用函数的返回位置（相当于直接连续返回两次）。尾调用消除即是在不改变当前调用栈（也不添加新的返回位置）的情况下跳到新函数的一种优化（完全不改变调用栈是不可能的，还是需要校正调用栈上[形式参数](https://zh.wikipedia.org/w/index.php?title=形式参数&action=edit&redlink=1)与[局部变量](https://zh.wikipedia.org/wiki/局部变量)的信息。[[2\]](https://zh.wikipedia.org/wiki/尾调用#cite_note-2)）

由于当前[函数帧](https://zh.wikipedia.org/wiki/函数帧)上包含局部变量等等大部分的东西都不需要了，当前的函数帧经过适当的更动以后可以直接当作被尾调用的函数的帧使用，然后程序即可以[跳](https://zh.wikipedia.org/wiki/分支_(計算機科學))到被尾调用的函数。产生这种函数帧更动代码与 “jump”（而不是一般常规函数调用的代码）的过程称作**尾调用消除**(Tail Call Elimination)或**尾调用优化**(Tail Call Optimization, TCO)。尾调用优化让位于尾位置的函数调用跟 [`goto` 语句](https://zh.wikipedia.org/wiki/Goto)性能一样高，也因此使得高效的结构编程成为现实。

然而，对于 [C++](https://zh.wikipedia.org/wiki/C%2B%2B) 等语言来说，在函数最后 return g(x); 并不一定是尾递归——在返回之前很可能涉及到对象的[析构函数](https://zh.wikipedia.org/wiki/析构函数)，使得 g(x) 不是最后执行的那个。这可以通过[返回值优化](https://zh.wikipedia.org/wiki/返回值优化)来解决。

通过汇编分析的例子:
https://blog.csdn.net/longintchar/article/details/79101221