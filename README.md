*This project has been created as part of the 42 curriculum by **toandrad***

# Philosophers

## Description

The dining philosophers problem is a common example used when talking about concurrent algorithms and is used to illustrate synchronization issues and techniques to solve them.

This project implements a solution based on threads and mutexes, where each philosopher needs to be represented by a thread and each fork is protected by a mutex.

**The concept**: there are `n` philosophers sitting at a table. All of them need to eat the spaghetti bowl in front of them, but there's a catch: to eat, they need 2 forks, but there are only as many forks as there are philosophers. Which means they'll need to take turns when eating, and that's where the problem starts. Philosophers can only eat, think and sleep. When they're eating, they are not thinking or sleeping; while thinking, they're not eating or sleeping; and while sleeping, they're not eating or thinking.

This becomes a problem, because every one of them needs to eat, but they all have a defined `time_to_die`, which means that if they don't eat for that amount of time, they starve and die. So our objective is to prevent the philosophers' deaths by managing when and how they pick up forks.

## Basic Concepts

**Threads**:

A thread is the smallest unit of execution within a program. Threads are normally used when you need multiple tasks to run at the same time (**concurrency**) or frequent data sharing. Threads can have problems when accessing shared data, where they can access or write to the same data at the same time, leading to a "Race condition", where threads 'race' and data can get corrupted, leading to unpredictable behavior. That's where **mutexes** come in.

**Mutexes**:

A mutex is a synchronization object used to protect shared data. Before a thread can access a shared variable, to prevent a data race, it should "lock" the mutex. This makes it so only that thread accesses that variable at a given time, making other threads that want to access that same variable have to wait for the first one to finish.

## Instructions

First, compile the project:

`make`

To run, use the command:

`./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
`

**Example** (last argument is optional):

`./philo 5 800 200 200`

- 5 Philosophers
- Takes 800 ms for each philosopher to die
- Takes 200 ms for each philosopher to eat
- Takes 200 ms for each philosopher to sleep
- **Expected outcome:** Infinite loop (there's no specific amount of times each philosopher has to eat)

`./philo 5 800 200 200 7`

- 5 Philosophers
- Takes 800 ms for each philosopher to die
- Takes 200 ms for each philosopher to eat
- Takes 200 ms for each philosopher to sleep
- **Expected outcome:** Each philosopher will eat 7 times, without any deaths

Default project rules:

- `make clean` - Remove object files
- `make fclean` - Remove all generated files
- `make re` - Rebuild from scratch

## Resources

### Documentation and References

- [Project Subject](https://cdn.intra.42.fr/pdf/pdf/199022/en.subject.pdf)
- [Philosophers 42 Guide](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2)

### AI Usage

AI tools were used in this project for:
- **Guidance**
- **Algorithm Design Choices**
- **Code review / debugging**
