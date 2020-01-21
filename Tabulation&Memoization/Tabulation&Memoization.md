# Tabulation vs Memoization

Prerequisite – [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming-set-1/), [How to solve Dynamic Programming problems?](https://www.geeksforgeeks.org/solve-dynamic-programming-problem/)
There are following two different ways to store the values so that the values of a sub-problem can be reused. Here, will discuss two patterns of solving DP problem:

1. **Tabulation:** Bottom Up
2. **Memoization:** Top Down

Before getting to the definitions of the above two terms consider the below statements:

- **Version 1**: I will study the theory of Dynamic Programming from GeeksforGeeks, then I will practice some problems on classic DP and hence I will master Dynamic Programming.
- **Version 2**: To Master Dynamic Programming, I would have to practice Dynamic problems and to practice problems – Firstly, I would have to study some theory of Dynamic Programming from GeeksforGeeks

Both the above versions say the same thing, just the difference lies in the way of conveying the message and that’s exactly what Bottom Up and Top Down DP do. Version 1 can be related to as Bottom Up DP and Version-2 can be related as Top Down Dp.

**Tabulation Method – Bottom Up Dynamic Programming** 

As the name itself suggests starting from the bottom and cumulating answers to the top. Let’s discuss in terms of state transition.

Let’s describe a state for our DP problem to be dp[x] with dp[0] as base state and dp[n] as our destination state. So, we need to find the value of destination state i.e dp[n].
If we start our transition from our base state i.e dp[0] and follow our state transition relation to reach our destination state dp[n], we call it Bottom Up approach as it is quite clear that we started our transition from the bottom base state and reached the top most desired state.

**Now, Why do we call it tabulation method?**

To know this let’s first write some code to calculate the factorial of a number using bottom up approach. Once, again as our general procedure to solve a DP we first define a state. In this case, we define a state as dp[x], where dp[x] is to find the factorial of x.

Now, it is quite obvious that dp[x+1] = dp[x] * (x+1)

```
// Tabulated version to find factorial x.
int dp[MAXN];

// base case
int dp[0] = 1;
for (int i = 1; i< =n; i++)
{
    dp[i] = dp[i-1] * i;
}
```

The above code clearly follows the bottom-up approach as it starts its transition from the bottom-most base case dp[0] and reaches its destination state dp[n]. Here, we may notice that the dp table is being populated sequentially and we are directly accessing the calculated states from the table itself and hence, we call it tabulation method.

**Memoization Method – Top Down Dynamic Programming** 

Once, again let’s describe it in terms of state transition. If we need to find the value for some state say dp[n] and instead of starting from the base state that i.e dp[0] we ask our answer from the states that can reach the destination state dp[n] following the state transition relation, then it is the top-down fashion of DP.

Here, we start our journey from the top most destination state and compute its answer by taking in count the values of states that can reach the destination state, till we reach the bottom most base state.

Once again, let’s write the code for the factorial problem in the top-down fashion

```
// Memoized version to find factorial x.
// To speed up we store the values
// of calculated states

// initialized to -1
int dp[MAXN]

// return fact x!
int solve(int x)
{
    if (x==0)
        return 1;
    if (dp[x]!=-1)
        return dp[x];
    return (dp[x] = x * solve(x-1));
}
```

As we can see we are storing the most recent cache up to a limit so that if next time we got a call from the same state we simply return it from the memory. So, this is why we call it memoization as we are storing the most recent state values.

In this case the memory layout is linear that’s why it may seem that the memory is being filled in a sequential manner like the tabulation method, but you may consider any other top down DP having 2D memory layout like [Min Cost Path](https://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/), here the memory is not filled in a sequential manner.
![tabulation-vs-memoization](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Tabulation-vs-Memoization-1.png)



# Memoization

In [computing](https://en.wikipedia.org/wiki/Computing), **memoization** or **memoisation** is an [optimization](https://en.wikipedia.org/wiki/Optimization_(computer_science)) technique used primarily to speed up [computer programs](https://en.wikipedia.org/wiki/Computer_programs) by storing the results of expensive [function calls](https://en.wikipedia.org/wiki/Subroutine) and returning the cached result when the same inputs occur again. Memoization has also been used in other contexts (and for purposes other than speed gains), such as in simple [mutually recursive](https://en.wikipedia.org/wiki/Mutual_recursion) descent parsing.[[1\]](https://en.wikipedia.org/wiki/Memoization#cite_note-Norvig1991-1) Although related to [caching](https://en.wikipedia.org/wiki/Cache_(computing)), memoization refers to a specific case of this optimization, distinguishing it from forms of caching such as [buffering](https://en.wikipedia.org/wiki/Buffer_(computer_science)) or [page replacement](https://en.wikipedia.org/wiki/Page_replacement_algorithm). In the context of some [logic programming](https://en.wikipedia.org/wiki/Logic_programming) languages, memoization is also known as [tabling](https://en.wikipedia.org/wiki/Prolog#Tabling).[[2\]](https://en.wikipedia.org/wiki/Memoization#cite_note-Warren1999-2)

## Overview

A memoized function "remembers" the results corresponding to some set of specific inputs. Subsequent calls with remembered inputs return the remembered result rather than recalculating it, thus eliminating the primary cost of a call with given parameters from all but the first call made to the function with those parameters. The set of remembered associations may be a fixed-size set controlled by a replacement algorithm or a fixed set, depending on the nature of the function and its use. A function can only be memoized if it is [referentially transparent](https://en.wikipedia.org/wiki/Referential_transparency); that is, only if calling the function has exactly the same effect as replacing that function call with its return value. (Special case exceptions to this restriction exist, however.) While related to [lookup tables](https://en.wikipedia.org/wiki/Lookup_table), since memoization often uses such tables in its implementation, memoization populates its cache of results transparently on the fly, as needed, rather than in advance.

Memoization is a way to lower a function's *time* cost in exchange for *space* cost; that is, memoized functions become optimized for *speed* in exchange for a higher use of [computer memory](https://en.wikipedia.org/wiki/Computer_memory) *space*. The time/space "cost" of [algorithms](https://en.wikipedia.org/wiki/Algorithm) has a specific name in computing: *[computational complexity](https://en.wikipedia.org/wiki/Computational_complexity_theory)*. All functions have a computational complexity in *time* (i.e. they take time to execute) and in *space*.

Although a [space–time tradeoff](https://en.wikipedia.org/wiki/Space–time_tradeoff) occurs (i.e., space used is speed gained), this differs from some other optimizations that involve time-space trade-off, such as [strength reduction](https://en.wikipedia.org/wiki/Strength_reduction), in that memoization is a [run-time](https://en.wikipedia.org/wiki/Run_time_(program_lifecycle_phase)) rather than [compile-time](https://en.wikipedia.org/wiki/Compile-time) optimization. Moreover, strength reduction potentially replaces a costly operation such as multiplication with a less costly operation such as addition, and the results in savings can be highly [machine-dependent](https://en.wikipedia.org/wiki/Machine-dependent) (non-portable across machines), whereas memoization is a more machine-independent, [cross-platform](https://en.wikipedia.org/wiki/Cross-platform) strategy.

Consider the following [pseudocode](https://en.wikipedia.org/wiki/Pseudocode) function to calculate the [factorial](https://en.wikipedia.org/wiki/Factorial) of *n*:

```
function factorial (n is a non-negative integer)
    if n is 0 then
        return 1 [by the convention that 0! = 1]
    else   
        return factorial(n – 1) times n [recursively invoke factorial 
                                        with the parameter 1 less than n]
    end if
end function
```

For every [integer](https://en.wikipedia.org/wiki/Integer) *n* such that `*n*≥0`, the final result of the function `factorial` is [invariant](https://en.wikipedia.org/wiki/Invariant_(computer_science)); if invoked as `*x* = factorial(3)`, the result is such that *x* will *always* be assigned the value 6. The non-memoized implementation above, given the nature of the [recursive](https://en.wikipedia.org/wiki/Recursion) algorithm involved, would require *n + 1* invocations of `factorial` to arrive at a result, and each of these invocations, in turn, has an associated cost in the time it takes the function to return the value computed. Depending on the machine, this cost might be the sum of:

1. The cost to set up the functional call stack frame.
2. The cost to compare *n* to 0.
3. The cost to subtract 1 from *n*.
4. The cost to set up the recursive call stack frame. (As above.)
5. The cost to multiply the result of the recursive call to `factorial` by *n*.
6. The cost to store the return result so that it may be used by the calling context.

In a non-memoized implementation, *every* top-level call to `factorial` includes the cumulative cost of steps 2 through 6 proportional to the initial value of *n*.

A memoized version of the `factorial` function follows:

```
function factorial (n is a non-negative integer)
    if n is 0 then
        return 1 [by the convention that 0! = 1]
    else if n is in lookup-table then
        return lookup-table-value-for-n
    else
        let x = factorial(n – 1) times n [recursively invoke factorial
                                         with the parameter 1 less than n]
        store x in lookup-table in the nth slot [remember the result of n! for later]
        return x
    end if
end function
```

In this particular example, if `factorial` is first invoked with 5, and then invoked later with any value less than or equal to five, those return values will also have been memoized, since `factorial` will have been called recursively with the values 5, 4, 3, 2, 1, and 0, and the return values for *each* of those will have been stored. If it is then called with a number greater than 5, such as 7, only 2 recursive calls will be made (7 and 6), and the value for 5! will have been stored from the previous call. In this way, memoization allows a function to become more time-efficient the more often it is called, thus resulting in eventual overall **speed up**.

