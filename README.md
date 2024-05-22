# cpp-benchmarker-windows
Scoped-based C++ timer for benchmarking, specific to Windows.

# How to use
Include the file as a header:
```cpp
#include "timer.h"
```
Then simply create a scope using `{}` around the code you want to benchmark, or place it at the start of your `int main` function to time your entire code base.

# Example Usage
```cpp
#include <iostream>
#include "timer.h"

int main()
{
    // Code block to be timed
    {
        Timer timer; // Timer starts here
        for (int i = 0; i < 100000; ++i)
        {
            std::cout << i << "\n";
        }
        // Timer stops automatically at the end of this scope
    }
}
```
This example demonstrates how to measure the execution time of a code block using the Timer class. The timer starts when the Timer object is created and stops automatically when the scope ends, printing the elapsed time.
