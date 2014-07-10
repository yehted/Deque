# Deques and Randomized Queues#

[Programming Assignment 2](http://coursera.cs.princeton.edu/algs4/assignments/queues.html)

[Checklist](http://coursera.cs.princeton.edu/algs4/checklists/queues.html)

## Overview ##

This project implements a double ended queue (dequeue) and a randomized queue in C++. 

## Things I've learned
* Implementing iterators took me like 2 weeks.
* This site was finally the answer [Iterators for linked list](http://www.oreillynet.com/pub/a/network/2005/11/21/what-is-iterator-in-c-plus-plus-part2.html?page=4)
* An iterator is a pointer that knows how to traverse your container. Inheriting it from std::iterator allows you to do stuff like std::copy, find, and others from STL.

1. Inherit your custom iterator from std::iterator
2. Put it inside your container class - there is no reason to put it outside when the container is the only thing that will be accessing it.
3. If you need to forward declare it, make sure the declaration is PUBLIC
4. Implement all of the things necessary for that type of iterator (input, output, forward, etc.)
5. Make sure you write a begin() and end() for your container that returns an iterator

## Todo list ##
* Check if I need to write StdRandom for Knuth shuffle
* Implement iterators - done(ish)
* Clean up iterator implementation
* Check for_each functionality