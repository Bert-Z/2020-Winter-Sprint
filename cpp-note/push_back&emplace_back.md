# push_back vs emplace_back

看一下现在push到vector的5种方法的耗时情况对比：

```c++
#include <vector>
#include <string>
#include "time_interval.h"

int main() {


    std::vector<std::string> v;
    int count = 10000000;
    v.reserve(count);       //预分配十万大小，排除掉分配内存的时间

    {
        TIME_INTERVAL_SCOPE("push_back string:");
        for (int i = 0; i < count; i++)
        {
            std::string temp("ceshi");
            v.push_back(temp);// push_back(const string&)，参数是左值引用
        }
    }

    v.clear();
    {
        TIME_INTERVAL_SCOPE("push_back move(string):");
        for (int i = 0; i < count; i++)
        {
            std::string temp("ceshi");
            v.push_back(std::move(temp));// push_back(string &&), 参数是右值引用
        }
    }

    v.clear();
    {
        TIME_INTERVAL_SCOPE("push_back(string):");
        for (int i = 0; i < count; i++)
        {
            v.push_back(std::string("ceshi"));// push_back(string &&), 参数是右值引用
        }
    }

    v.clear();
    {
        TIME_INTERVAL_SCOPE("push_back(c string):");
        for (int i = 0; i < count; i++)
        {
            v.push_back("ceshi");// push_back(string &&), 参数是右值引用
        }
    }

    v.clear();
    {
        TIME_INTERVAL_SCOPE("emplace_back(c string):");
        for (int i = 0; i < count; i++)
        {
            v.emplace_back("ceshi");// 只有一次构造函数，不调用拷贝构造函数，速度最快
        }
    }
}

```

vs2015 release下编译，运行结果：

```shell
push_back string:327 ms
push_back move(string):213 ms
push_back(string):229 ms
push_back(c string):215 ms
emplace_back(c string):122 ms

```

第1中方法耗时最长，原因显而易见，将调用左值引用的push_back，且将会调用一次string的拷贝构造函数，比较耗时，这里的string还算很短的，如果很长的话，差异会更大

第2、3、4中方法耗时基本一样，参数为右值，将调用右值引用的push_back，故调用string的移动构造函数，移动构造函数耗时比拷贝构造函数少，因为不需要重新分配内存空间。

第5中方法耗时最少，因为emplace_back只调用构造函数，没有移动构造函数，也没有拷贝构造函数。

**结论：在C++11情况下，果断用emplace_back代替push_back**