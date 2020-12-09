# TaskManager

### Queue implementation

A data structure such as a queue has been created for this laboratory work. Its job is to organise and manipulate FIFO data (first input - first output). Methods such as adding an element to the queue ( push ), removing an element ( pop ) and checking for emptiness have been implemented. The queue was implemented on the basis of a linked list and the input data is a value type. 
The linked list was implemented using the Node data structure, which has only one ptr field - a pointer to the current queue object. 

`void Queue::push(Task* d)` -  function accepts as a parameter the execution time of the task (Tusk type). Allocate memory for a new object and set a pointer to this object 

`Task* Queue::pop()` - the function takes the object out of the queue. First it receives the pointer to the first element of the queue, then it moves the pointer to the previous element and returns the element that should have been removed (in order to display the information that it was poisoned afterwards). 

`bool Queue::isEmpty()` - the function checks for emptiness in the queue. If there is no pointer to an existing element, the queue is empty and return false. Otherwise - return true. 

### Task Manager 

The Task Manager consists of one parameter of the queue type and three methods: adding a task, performing the task and outputting the result data. 

`void TaskManager::execution()` - the function takes turns removing values from the queue until the queue is empty. Output the result of the execution and make a small delay so that the output takes place in turn 

`void TaskManager::add(int count)` - the function adds queue elements to the execution. First we allocate memory for the given task, set the execution time at random, add an element to the queue and display information about what the task has added to the queue. 

`void TaskManager::output(string execution_result)` - the function is designed to output the result of the functions so that the flows of these functions do not intersect. 


### Structure Value

The structure of the value stores the time it takes to complete the task. 


### Multithreading 

Two streams were used to implement multithreadreading. The first one performs the addition of the task to the queue. Each task is given randomly the time to complete it. After successful execution, the task is entered by the second thread, which removes the task from the queue and informs about its completion. A separate output function was implemented using a mutex so that the output threads do not intersect. 





### Graphic

