# Software Engineering Interviews at Jane Street

Welcome to our version of the “Technical Interviews at `insert your company here`” post. This topic has been covered by a lot of people already, so I’m going to do my best to not repeat [all](https://steve-yegge.blogspot.com/2008/03/get-that-job-at-google.html) of the [copious](https://www.facebook.com/notes/facebook-engineering/get-that-job-at-facebook/10150964382448920) [advice](https://www.palantir.com/2011/10/the-coding-interview/) already out there.

Interviewing, for both the interviewers and the interviewee is just plain old hard work. We spend a lot of time working on the process, and we know that you have spent years working on your skillset.

Even so, sometimes all that hard work doesn’t work out - even with a great candidate - just due to the the awkwardness of the interview process itself: time is short, the questions are weirdly artificial, and of course people get nervous. Programming for an audience on a whiteboard, a web browser, or even just on a computer that isn’t yours is a bit like playing the guitar with mittens on. It can put even an accomplished person off their game.

Missing out on good people makes us sad.

That’s what this post is for. By talking a bit about what we’re looking for, the ways people do poorly, and how we think you might be able to prepare we hope we’ll reduce the mitten handicap - at least a bit.

## What Do We Look For?

From our perspective, the main thing we want to figure out when we interview someone is: are they someone we want to work with?

That probably seems obvious and maybe even trite, but it’s a point that can easily get lost once an interview is underway. We think of our interviews as little simulations of what it’s like to work with the candidate; and while it may seem like the interview is all about solving the problem, it’s really not. We’re much more interested in learning about  how you work.

We are looking for candidates who engage in clear and productive discussions about the problem at hand. Ideally they quickly find the right technical level for the discussion - not too abstract and not too detailed. They cleanly describe the most important considerations, and lay out a good plan for dealing with them. Where there are tradeoffs they note them and explain which side they took and why. They ask thoughtful questions about parts of the problem that are unclear. Overall they show tenacity and and curiosity; they want to engage with the problem and with the people they are working with.

We model our interviews in a way that allows us to simulate, as best we can in an hour, what it’s like to work with someone. That means we don’t particularly value seeing someone write union-find in 15 lines, or care if a candidate knows exactly how an AVL tree is written (though we do care about understanding tree balance at a higher level). Those kinds of things can be found on the internet.

To that end, we try to avoid algorithm bingo and puzzles with clever “aha” solutions. We prefer more open-ended problems that have several plausible angles of attack and maybe even no single best answer. They give us more freedom to work together and to see how the candidates’ thinking plays out.

That sounds nice enough, but it’s a bit high-level and hand-wavy. So here’s a more concrete list of suggestions that follow from our overall approach.

### Be nice

The smartest, most technically clever person in the world won’t get hired at Jane Street if they aren’t courteous and pleasant to talk to. Most problems at Jane Street are solved with a lot of collaboration and discussion, and the solutions often take days or weeks to work out, incorporating ideas from many many people. The tenor and quality of those discussions is an essential part of getting to the right answer.

### Be clear

And by clear, we mean simple and to the point. Use words and examples that get the core idea across to the widest technical audience possible.

Avoid showy, highly technical or deeply obscure terms of art, especially if you don’t fully understand them. In the best case we’ll likely just ask exactly what you meant by “hylomorphism”, which wastes precious time. In the worst case it will become clear that you should have said “metamorphism” instead, which is just embarrassing for everyone involved.

### Know what you don’t know

Naturally we like it when candidates are good at solving the problems we put in front of them. But just as important - perhaps more important - is their ability to reason about their own  level of understanding.

In other words, we really like people who can admit when they’re unsure and speak confidently when they have the basis to do so. Be willing to say, “I don’t know” rather than guessing. Tell us when you are fairly confident but still a little bit uncertain. Get used to talking about not just the problem but also your own confidence in individual assumptions and statements.

### Know your language

Code is a wonderful language for communicating complex ideas. It provides a concise and unambiguous way of expressing them. But, like any foreign language, it takes a lot of time and practice to get really comfortable. We need you to be comfortable with it because we communicate ideas in code a lot.

Now, comfortable doesn’t mean that you need to have memorized the spec for a language (assuming it even has one beyond the reference implementation). It means that you should be able to read and write code in your language of choice without constant access to reference materials for common things, such as:

- Standard control structures (loops/if-then/etc.)
- Function, module, class, type, etc. definitions
- Common data types like arrays, lists, hash tables/maps/dictionaries
- Exceptions and other error handling techniques
- Reasonable code organization

That especially means you shouldn’t pick a language because you think it will make us happy.

We’d much prefer you use a language that you know well, and can prove your skills with. Similarly, when picking which features of the language to use pick the ones you understand best. We’re not going to be impressed with your elegant use of Python decorators if you don’t really understand what they do.

### Write the code you said you would write

We love it when a plan comes together, but it’s extra hard to watch when a good plan falls apart on execution. Once you discuss a plan of attack with your interviewer do what you claimed you would do. Don’t change the plan in the middle or drop it in favor of a better idea without some discussion. You have a very limited amount of time and executing a decent plan well is better than producing a Frankenstein’s monster of 3 different plans that doesn’t quite come to life.

If you do get partway through and start to lose faith step back and talk about it. Explain exactly why you are concerned. If there really is a fatal flaw and you’ve seen it we’ll help you get out of the jam, and we’ll appreciate that you articulated it. If it’s just not quite perfect we’ll likely encourage you to continue.

### Review CS 101

We’ve hired plenty of successful people who didn’t have a traditional college background in CS and we certainly don’t require a masters or a PhD. That said, we need you to have a solid working knowledge of core computer science concepts, including:

- Abstraction layers like functions, objects, and modules
- Basic algorithms and data structures, including binary search, sorting, hashing, breadth/depth first search, hash tables, binary trees and heaps.
- Techniques for estimating CPU and memory costs, including big-O notation.
- Recursion and exhaustive case analysis

So if you can’t for the life of you recall what amortized analysis is and you can’t nimbly bang out the code for a depth-first search it’s probably worth reviewing some of this material.

### Think about real computers

Depending on your point of view it’s either a sad or beautiful fact that the most elegant code can only run on top of the giant jangly amalgam of parts and OS glue that is a real computer. Unfortunately we need programs to actually run so we need people who understand the inner workings of that behemoth.

This doesn’t mean that we quiz every candidate about deep kernel internals, or the differences between SDRAM vs SGRAM. But for some jobs in systems development we do expect a fair amount of detailed knowledge, and in general it’s a big plus if you can take into account things like cache effects, IO patterns, memory representations, and the capabilities of real CPUs.

## What We Don’t Look For

Lot’s of things. But there are a few things that pop up time and again that people worry we are looking for that bear mentioning.

We aren’t looking for you to finish. Our questions are often designed to be open ended enough that even the best people we’ve seen couldn’t answer them fully in the time allotted. We want to keep the conversation going to learn everything we can, and we don’t expect that you’ll answer everything 100% perfectly.

We also don’t expect you to give the perfect answer or to deliver bug free code. Coding in front of people is hard. Coding with a time limit is hard. Coding, in general, is hard.

We don’t ask software engineers to do mental math, or math olympiad questions, or to contemplate logic puzzles about pirate tigers that only tell the truth despite what you might have read online. Dev interviews are about programming, plain and simple. That’s what we are hiring you to do and that’s what we expect you to demonstrate. There are other jobs at Jane Street that do care about mental math and logic puzzles for good reasons. Just not this one.

## What Can You Do To Prepare?

This part is short and sweet. Practice.

Build something from scratch and on your own in a language you like. Don’t stop short. Build the whole thing. Make yourself do the parts that are hard for you and don’t accept half-finished code just because you think you know how you would finish it. Dive deep into the layers of the libraries and language that you built it upon, and understand how they work too.

When you think you are done show it to the smartest people you know, get feedback, tear it down and build it again with what you’ve learned.

Repeat with a new problem.

We are looking for people to build real things with us, and practice really does make perfect.