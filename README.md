# Hungry-Birds
Hungry birds problem with Semaphores

The Hungry Birds Problem.
One producer (parent) and multiple consumers (children)

Given is n number of baby birds and one parent bird. The baby birds eat out of a common dish that initially contains W worms. Each baby bird repeatedly takes a worm, eats it, sleeps for a while, takes another worm, and so on. If the dish is empty, the baby bird who discovers the empty dish chirps to awaken the parent bird. The parent bird flies off and gathers W more worms, puts them in the dish, and then waits for the dish to be empty again. This pattern repeats forever.
Develop and implement a multithreaded program to simulate the actions of the birds. Represent the birds as concurrent threads (i.e. array of "babyBird" threads and a "parentBird" thread), and the dish as a critical shared resource that can be accessed by at most one bird at a time. Use only semaphores for synchronization. Your program should print a trace of interesting simulation events.
