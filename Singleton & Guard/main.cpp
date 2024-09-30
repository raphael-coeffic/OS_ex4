#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "Singleton.hpp" 
#include "Guard.cpp"

int main() {
    // Mutex to protect a shared resource
    pthread_mutex_t demoMutex = PTHREAD_MUTEX_INITIALIZER;

    // Execute a task with Guard to automatically lock and unlock the mutex
    {
        Guard guard(demoMutex); // The mutex is locked here
        std::cout << "We are protected by Guard\n";
        sleep(1); // Simulate an operation
        // The mutex will be automatically unlocked here
    }

    // Using Singleton
    Singleton* singleton = MySingleton::getInstance(); // Retrieve the instance of MySingleton via Singleton
    MySingleton* mySingleton = dynamic_cast<MySingleton*>(singleton);
    
    if (mySingleton) {
        mySingleton->doSomething(); // Call a method on the Singleton instance
    }

    return 0;
}