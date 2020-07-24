## Fast Queue

A fast implementation of a (templatized) circular queue container (with `std::vector` as underlying buffer) and automatic resizing as required. Complete with (most) functions of `std::queue`, including move/cpy constructors.

### Prerequisites

```
 C++11 or later
```

### Compiling

To compile with g++

```g++ fast-queue.cpp -o fast-queue```

### Available functions

```FastQueue::enqueue(const T&)``` : (Circularly) Enqueue an element 

```FastQueue::dequeue()``` : Dequeue an element

```FastQueue::front()``` : Return reference to the front element of the queue

```FastQueue::back()``` : Return reference to the back element of the queue

```FastQueue::at(size_t)``` : Return reference to the element on specified (circular) index

```FastQueue::size()``` : Return size of the queue

```FastQueue::capacity()``` : Return capacity of the queue

```FastQueue::dequeue()``` : Dequeue an element

```FastQueue::fastQueueIsFull()``` : Check if the queue is full

```FastQueue::fastQueueIsEmpty()``` : Check if the queue is empty

```FastQueue::shrink_to_fit()``` : Shrink the capacity of the queue to the current size +2 (implementation detail)


## Built With

* [CLion](https://www.jetbrains.com/clion/) - A cross-platform IDE for C and C++

## Authors

* **Siraj Qazi**

## License

This project is licensed under the GNU General Public License - see the [LICENSE.md](LICENSE.md) file for details


