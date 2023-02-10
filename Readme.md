# Introduction

Philosophers is a 42 Scool project built around the famous philosophers dinner problem posed by Dijkstra in 1965 . It aims to introduce the concept of concurrent programming, where we must find a solution to the problem using only threads and mutexes.

# General Description

The subject describes the problem as follows:
______________
*One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table. The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping;and, of course, while sleeping, they are not eating nor thinking. There are also forks on the table. There are as many forks as philosophers. 
Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.  When a philosopher has finished eating, they put their forks back on the table and
start sleeping. 
Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
Every philosopher needs to eat and should never starve.
Philosophers don’t speak with each other.
Philosophers don’t know if another philosopher is about to die.
No need to say that philosophers should avoid dying!*
______________

The program should take the following arguments:

- *number_of_philosophers*: the number of philosophers around the table,
- *time_to_die*: a number representing the time in milliseconds a philosopher has to live after a meal. If a philosopher hasn’t started eating time_to_die milliseconds after the beginning of his last meal or the beginning of the simulation, he will die.
- *time_to_eat*: a number representing the time in milliseconds a philosopher takes to finish his meal. During that time, the philosopher keeps his two forks in hand.
- *time_to_sleep*: the time in milliseconds that a philosopher spends sleeping.
- *number_of_times_each_philosopher_must_eat*: an optional argument that allows the program to stop if all the philosophers have eaten at least that many times. If this argument is not specified, the simulation carries on unless a philosopher dies.

## usage

Git clone the project:
```sh
git https://github.com/leaozim/42-course-Philosophers.git
```
To compile, use make
```sh
cd 42-course-Philosophers/philo && make
```
Run the program with the following arguments:
```sh
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philo_must_eat]
``` 
