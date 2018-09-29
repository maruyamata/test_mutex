#include <stdio.h>
#include <thread>
#include "MutexVariable.h"

// variable
MutexVariable<uint32_t> data;

// function
void add_count() { data.add(1); }
void work()
{
    for (int i = 0; i < 100000; ++i) {
        add_count();
    }
}

// entry point
int main(void)
{
    // create thread
    std::thread th_A(work);
    std::thread th_B(work);

    printf("do_work \n");

    th_A.join();
    th_B.join();

    printf("work_end \n");
    printf("result %d \n", data.getValue());

    return 0;
}
