#pragma once
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>

class Timer
{
public:
    Timer()
    {
        QueryPerformanceFrequency(&m_Frequency);
        QueryPerformanceCounter(&m_StartTimePoint);
    }

    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        LARGE_INTEGER endTimePoint;
        QueryPerformanceCounter(&endTimePoint);

        auto start = m_StartTimePoint.QuadPart;
        auto end = endTimePoint.QuadPart;

        auto duration = end - start;
        double microseconds = static_cast<double>(duration) * 1000000 / m_Frequency.QuadPart;
        double milliseconds = microseconds * 0.001;

        std::cout << microseconds << "us (" << milliseconds << "ms)\n";
    }

private:
    LARGE_INTEGER m_StartTimePoint;
    LARGE_INTEGER m_Frequency;
};
