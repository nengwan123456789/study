#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

namespace study
{

class TimerBase {
    public:
    TimerBase(): m_start (std::chrono::system_clock::now()){};

    void clear(void) {
        m_start = std::chrono::system_clock::now();
    }
    void print_ms() {
        auto time = std::chrono::system_clock::now();
        std::cout << (std::chrono::duration_cast<std::chrono::milliseconds> 
                    (time - m_start).count()) << "ms" << std::endl;
    }
    void print_start_system_time() {
        auto time = std::chrono::system_clock::to_time_t(m_start);      //std::time_t
        std::cout << std::ctime(&time) << std::endl;
    }
    void print_fmt_system_time() {
        auto time = std::chrono::system_clock::to_time_t(m_start);
        auto time_info = std::localtime(&time);
        std::cout << std::put_time(time_info, "%Y-%m-%d %H:%M:%S") << std::endl;
    }
    private:
    std::chrono::system_clock::time_point m_start;  /*系统的实际时间， 可能会受到系统时间的影响*/
/*
    std::chrono::steady_clock::time_point           稳定的时间，时间从不调整
    std::chrono::high_resolution_clock::time_point  最小可表示的时间间隔
*/
};

}