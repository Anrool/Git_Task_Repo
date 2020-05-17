#include "calculator.h"

#include <iostream>
#include <utility>

namespace {
template <typename T, typename F, typename R>
bool DoTest (T x, T y, F f, R expRes)
{
    const auto res = f(x, y);

    if (res != expRes) {
        std::cout << "bad result: expected " << expRes
                  << ", got " << res << std::endl;
        return false;
    }

    return true;
}

template <typename T, size_t Size>
constexpr size_t GetSize (const T(&)[Size])
{
    return Size;
}

bool PerformTesting () {
    constexpr size_t TestLoopNum = 3;
    constexpr std::pair<double, double> args [] =
    {
        {2.5, 3.},
        {7.5, 4.},
        {5.05, 10.},
    };
    constexpr int (* funcToTest []) (double, double)  =
    {
        Calculator::Add,
        Calculator::Sub,
        Calculator::Mul,
    };
    constexpr int expRes [] = {6, 4, 51};

    static_assert(GetSize (args) == TestLoopNum, "bad args pair count");
    static_assert(GetSize (funcToTest) == TestLoopNum, "bad testing func count");
    static_assert(GetSize (expRes) == TestLoopNum, "bad exp result count");

    for (size_t i = 0; i < TestLoopNum; i++)
    {
        if (!DoTest (args[i].first, args[i].second, funcToTest[i], expRes[i]))
        {
            return false;
        }
    }

    return true;
}

}

int main (int, char *[])
{
    std::cout << "Test is running!\n"
              << (PerformTesting ()
                  ? "Test finished successfully!\n"
                  : "Test failed!\n");

    return 0;
}


