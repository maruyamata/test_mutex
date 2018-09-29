#include <stdio.h>
#include <thread>
#include <mutex>

// variable
int sum = 0;
std::mutex sum_mutex;

// function
void add_count()
{
    std::lock_guard<std::mutex> lock(sum_mutex);
    sum++;
}

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
    printf("result %d \n", sum);

    return 0;
}
