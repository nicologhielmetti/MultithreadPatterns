# MultithreadDesignPatterns
Some implementations of multithread patterns.
* ## Producer/Consumer
![image](https://user-images.githubusercontent.com/16907319/96274028-55153700-0fd0-11eb-93ac-9c09fc741a31.png)
* ## ActiveObject
Define a thread that is binded with a callable function, like `thread0.run()`
* ## Reactor
Decouple task creation from execution. An executor thread waits on a task queue shared with the rest of the program. Tasks are executed in a FIFO order.
* ## ThreadPool
Extension of Reactor: more queues with a parametrizable number of executor threads.
