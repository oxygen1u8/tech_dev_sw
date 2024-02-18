#include <iostream>
#include <vector>
#include <algorithm>

#include <cmath>

/* Дан целочисленный вектор. Используя функцию find_if найти */
/* первое простое число (по определению 0 и 1 простыми числами не являются) */

template <typename T>
class lab5 {
public:
    lab5(std::vector<T>& vec)
    {
        this->vec = vec;
    }
    void operator()()
    {
        double avg = 1;
        std::for_each(vec.begin(), vec.end(), [&avg](const T& m) { avg *= m; });
        this->avg_val = std::pow(avg, (double) 1 / vec.size());

        std::cout << this->avg_val << std::endl;
    }
private:
    std::vector<T> vec;
    double avg_val;
};

int main()
{
    std::vector<int> a = {4, 9, 16};
    lab5<int> l(a);
    l();
    return 0;
}

