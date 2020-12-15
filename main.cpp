#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

struct Task{
    uint16_t time;
};

class Queue {
    struct Node {
        Task* d;
        Node* next;
    };
private:
    Node*  ptr;
public:
    Queue();
    void push(Task* d);
    Task* pop();
    bool isEmpty();
};

Queue::Queue() {
    this->ptr = nullptr;
}

void Queue::push(Task* d){
    Node* node = (Node*)(malloc(sizeof(Node)));
    node->d = d;
    if(!ptr) {
        ptr = node;
        ptr->next = ptr;
    } else {
        node->next = ptr->next;
        ptr = ptr->next = node;
    }
}
Task* Queue::pop() {
    Task *task = ptr->next->d;
    if(ptr == ptr->next) {
        delete ptr;
        ptr = nullptr;
        return task;
    }
    Node* tmp = ptr->next;
    ptr->next = tmp->next;
    delete tmp;
    return task;
}

bool Queue::isEmpty() {
        return (! ptr);

};

class TaskManager {
public:
    Queue queue;
    void add(int count);
    void execution();
    static void output(string text);
};


void TaskManager::execution() {
    while (!queue.isEmpty()) {
        Task* task = queue.pop();
        output("The task was accomplished. Wasted time: " + to_string(task->time));
        this_thread::sleep_for((1ms) * task->time);
    }
    output("Done.");
}

void TaskManager::add(int count) {
    srand((unsigned) time(nullptr));
    for (int i = 0; i < count; i++) {
        auto* exercise = (Task*)(malloc(sizeof(Task)));
        exercise->time = (rand()%2000);
        queue.push(exercise);
        this_thread::sleep_for(300ms);
        output("New task. Time to complete: " + to_string(exercise->time));
    }
}

void TaskManager::output(string execution_result) {
    mutex mtx;
    mtx.lock();
    cout << execution_result << endl;
    mtx.unlock();
}


int main() {

    TaskManager taskManager;
    taskManager.add(5);
    thread solver(&TaskManager::execution, &taskManager);
    thread adder(&TaskManager::add, &taskManager, 10);
    solver.join();
    adder.join();
    return 0;
}
