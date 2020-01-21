# What a Jane Street software engineering interview is like

Are you thinking about [applying](https://www.janestreet.com/join-jane-street/apply/) to Jane Street for a software engineering role? Or already have a phone interview scheduled but unsure what to expect? Read on as we walk through an example phone interview with you.

We want to give you some insight into what a typical Jane Street phone interview looks like and give you a chance to prepare. We’re going to take a look at a question we call “*Memo*” which we used to ask regularly (but of course don’t ask anymore so no need to memorize anything on this page!). As such this post is meant to be a specific case analysis. If you haven’t yet seen it, we recommend reading [this blog post](https://blog.janestreet.com/interviewing-at-jane-street/) for a general overview what we are looking for in candidates.

## Getting started

To allow us to work on the question together, we’ll use a shared online editor. We’ll provide you with the link to use (either before hand or during the interview).

We expect you to write code in a real programming language in the interview, not pseudo-code. You can use any programming language you’d like, but we strongly recommend you use the one you’re most familiar with and will let you solve the problem in the best way (it’s fine to change your mind as you’re exploring the problem!). You should be comfortable with basic data structures and APIs in the language of your choice.

Note, there are no bonus points for using a functional language like OCaml. Please don’t use OCaml just because you think it will make us happy. We want to see you at your best, so you should use the language you’re most comfortable with. If OCaml isn’t your strongest language, then don’t use it.

If during the interview you realize you have seen a question before, then please let us know and we can do a different question. As you’ll see in this post, knowing a question in advance greatly reduces what we can learn about you!

## Part 1 – Basic coding

Have you heard about memoization? Can you carefully describe what it is? If you haven’t heard about it, don’t worry. We’ll bring you up to speed. (A good introduction is on [Wikipedia](https://en.wikipedia.org/wiki/Memoization).)

Now let’s say there is a function `f` of type `int -> int` whose output only depends on the input. `f` is very expensive to compute. We’d like you to write a memoized version of this function, i.e. another function `g` of the same type, that returns the same values – `g(x) = f(x)` for all x – but only does the expensive computation once for each input value.

A typical first solution we’re looking for at this stage uses a hash-table to store calculated results. A possible solution in OCaml might be:

```
let memo f =
  let results = Hashtbl.create 256 in
  (fun input ->
     match Hashtbl.find results input with
     | None ->
        let result = f input in
        Hashtbl.add results ~key:input ~data:result;
        result
     | Some result -> result)
```

*(As I said above, you’re not required or expected to write in OCaml but in this blog post I’m going to follow my own advice and use the language I’m most familiar with, which is OCaml. You might also object that this does a test-and-set without a lock, so can’t possibly be thread-safe. Nice spot! For the purpose of this question let’s ignore re-entry to focus on the core ideas.)*

Whichever APIs or data structures you end up using for your solution: you should be prepared to talk about how they work and what the complexity of various operations is.

## Part 2 – Reasoning about and improving your code

Can you think of any issues we could run into when using the function from part 1? For example, let’s say we run your function in production and notice our application performs significantly worse than before. Quite the opposite from what we hoped memoization would do! Can you see what the problem might be?

The big problem is memory usage. Our application might call `f` with lots of different inputs and each result will be stored in the hashtable forever – a memory leak! Can you come up with some ideas to improve upon this?

A reasonable approach to control the memory usage is to bound the size of the hash-table and to evict things from it in a FIFO fashion. What trade-offs does FIFO have versus other eviction schemes? How could you modify your memo function to implement FIFO? Let’s aim for O(1) complexity when evicting from the cache.

There are a few different ways to do this. A good solution keeps a separate queue: when adding a new result to your hashtable, if the size grows beyond the bound, then dequeue from the queue and remove that element from the hashtable.

Besides being able to write code to do this, we look for how you communicate your thoughts on the problem and ideas to improve it. We don’t necessarily expect every candidate to immediately jump to the O(1) solution, but we’re interested in the process of talking through this problem and what you can come up with.

## Part 3 – Going further

As you probably realize, FIFO can be very inefficient in some use-cases. Let’s say we want to do LRU (least recently used) instead. We still want the implementation to be as efficient as possible. How can you implement this?

Once more, there are multiple ways to do this. The easiest solution stores timestamps with each value in the hashtable and linearly scans through the table when evicting. This is O(n). It’s possible to improve to O(log n) using a min-heap or even to O(1) using a doubly-linked list.

> ***Side-note: implementing the most efficient solution\*** *One way to get to O(1) is to maintain a doubly linked list and make the values in the hash-table point to elements in that list. Then when looking up a cached value in the hash-table, you can slice it out of its current position in the list and put it at the top in O(1). You maintain a separate pointer to the bottom of the doubly linked list to evict in O(1).*

Few candidates come up with the doubly-linked list immediately, so don’t worry if this is not something you thought of straight away. While we might ask you to implement parts of your solution, this part is intended as a discussion and test your ideas for improving complexity. We’ll guide you to the right level of abstraction, so you don’t have to worry too much about which details to include.

We also have various other extensions for this question that make it possible to keep going further as far as time allows.

## What we look for

Again, for a good overview see [this post](https://blog.janestreet.com/interviewing-at-jane-street/).

While interviewing, we try to evaluate how well you would fit in our work environment by collaboratively solving a problem. This means the journey through the interview is a lot more important than the snapshot of the solution at the end of it. We are more interested in seeing how you approach a difficult problem than just capturing a boolean flag whether you can come up with the solution.

As a concrete example, we might prefer a candidate that wrote careful and clear code, communicated well and had good insights and ideas along the way, but didn’t get as far through the problem compared to another candidate that immediately solved every part but was sloppy and hard to follow.

This makes it impossible to give a rigid set of requirements of what needs to be achieved during the interview. Nevertheless, to give you some rough guidelines:

Every successful candidate should achieve a bug-free solution for part 1 relatively quickly. If some of part 1 sounds unfamiliar to you, it might be better to hold off applying to give yourself more time to prepare.

Most candidates that we pass also complete part 2 fully in the time of the interview. Strong candidates finish part 3 with a complete solution, but not finishing this part doesn’t mean that you will be rejected! As said above, it’s what happens during the interview that really counts, not the result at the end.

## Sharing questions afterwards

We are interested in seeing you approach a difficult problem and walk through the process of deriving a solution with you. If you already know the question in advance (either by finding it online, or by talking to friends who have previously applied), it reduces the efficacy of the interview: We now only get to test if you can write code for a problem you’ve already understood and solved, which is a small subset of things we are interested in learning about. For example, if you’ve read through this post, we wouldn’t learn much from asking you *Memo*!

Thus we would like to ask you *not to share the interview question* with anybody else (in person or online).