#ifndef MutexVariable_H
#define MutexVariable_H

#include <cstdint>
#include <mutex>

template <typename T>

class MutexVariable {
private:
    T value;
    std::mutex value_mutex;

public:
    MutexVariable() { value = 0; }
    ~MutexVariable() {}
    void add(T a)
    {
        std::lock_guard<std::mutex> lock(value_mutex);
        value = value + a;
    }

    void suba(T a)
    {
        std::lock_guard<std::mutex> lock(value_mutex);
        value = value - a;
    }

    T getValue(void)
    {
        std::lock_guard<std::mutex> lock(value_mutex);
        return value;
    }
};  // MutexVariable
#endif
