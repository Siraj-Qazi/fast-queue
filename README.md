## Fast Queue

A fast implementation of a (templatized) circular queue container (with std::vector as underlying buffer) and automatic resizing as required. Complete with (most) functions of std::queue, including move/cpy constructors.

### Compiling

To compile with g++
```g++ fast-queue.cpp -o fast-queue```


### Available functions

`FastQueue::enqueue()` : Enqueue an element 
`FastQueue::dequeue()` : Dequeue an element