#include <pthread.h>
#include <iostream>

// Guard class that locks a mutex in the constructor and unlocks it in the destructor
class Guard {
public:
    // Constructor that takes a reference to a mutex and locks it
    explicit Guard(pthread_mutex_t& mtx) : mutex(mtx) {
        pthread_mutex_lock(&mutex); // Lock the mutex at the start of the scope
        std::cout << "Mutex locked by Guard\n";
    }

    // Destructor that unlocks the mutex when the Guard object goes out of scope
    ~Guard() {
        pthread_mutex_unlock(&mutex); // Unlock the mutex at the end of the scope
        std::cout << "Mutex unlocked by Guard\n";
    }

private:
    pthread_mutex_t& mutex; // Reference to the mutex
};