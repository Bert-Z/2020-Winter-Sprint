# C++ 中 public、protected 及 private 的作用总结

| 成员变量修饰符 | 类外的普通函数 | public 派生类         | private 派生类      | protected 派生类      |
| -------------- | -------------- | --------------------- | ------------------- | --------------------- |
| public         | 可以访问       | 可以访问（public）    | 可以访问（private） | 可以访问（protected） |
| protected      | 无法访问       | 可以访问（protected） | 可以访问（private） | 可以访问（protected） |
| private        | 无法访问       | 无法访问（private）   | 无法访问（private） | 无法访问（private）   |

