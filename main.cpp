#include <iostream>
#include "us_chrono.h"
#include <thread>
int main()
{
    study::TimerBase time;
    time.clear();
    std::this_thread::sleep_for(std::chrono::milliseconds(666));
    time.print_ms();
    time.print_start_system_time();
    time.print_fmt_system_time();
}