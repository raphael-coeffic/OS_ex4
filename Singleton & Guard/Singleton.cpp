#include "Singleton.hpp"

// Initialization of static members
pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;
MySingleton* MySingleton::instance = nullptr;

// Method to lock the mutex
void Singleton::lock() {
    pthread_mutex_lock(&mutex);
}

// Method to unlock the mutex
void Singleton::unlock() {
    pthread_mutex_unlock(&mutex);
}

// Implementation of getInstance for MySingleton
MySingleton* MySingleton::getInstance() {
    if (instance == nullptr) {
        Singleton::lock();  // Lock the mutex
        if (instance == nullptr) {
            instance = new MySingleton();  // Create the instance
        }
        Singleton::unlock();  // Unlock the mutex
    }
    return instance;
}

// Implementation of the doSomething method
void MySingleton::doSomething() {
    std::cout << "MySingleton is doing something!" << std::endl;
}