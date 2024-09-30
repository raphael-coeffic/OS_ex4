#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>
#include <pthread.h>

class Singleton {
public:
    // Prevent copy and assignment
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Pure virtual method to be implemented by derived classes
    virtual void doSomething() = 0;

    // Methods to lock and unlock the mutex
    static void lock();
    static void unlock();

protected:
    Singleton() = default;  // Protected constructor
    virtual ~Singleton() = default;

    static pthread_mutex_t mutex;  // Mutex for locking access
};

// MySingleton class derived from Singleton
class MySingleton : public Singleton {
public:
    // Method to get the unique instance of MySingleton
    static MySingleton* getInstance();
    
    // Implementation of the pure virtual method from Singleton
    void doSomething() override;

private:
    MySingleton() = default;  // Private constructor
    static MySingleton* instance;  // Unique instance of MySingleton
};

#endif // SINGLETON_HPP