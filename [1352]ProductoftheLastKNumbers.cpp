#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers
{
public:
    ProductOfNumbers()
    {
        numlist = vector<int>();
    }

    void add(int num)
    {
        numlist.push_back(num);
    }

    int getProduct(int k)
    {
        if (k == 0)
            return 0;

        int ssize = numlist.size(), ret = 1;

        for (int i = ssize - 1; i > ssize - k - 1; i--){
            ret = ret * numlist[i];
            if(ret==0)
                return 0;
        }

        return ret;
    }

private:
    vector<int> numlist;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */