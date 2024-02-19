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
    T operator()()
    {
        auto tmp = std::find_if(vec.begin(), vec.end(), [](const T& m) -> bool
            {
                if (m < 2)
                    return false;
                else if (m == 2) {
                    return true;
                }
                for (unsigned int i = 2; i <= sqrt(m); i++) { 
                    if (m % i == 0) {
                        return false;
                    } 
                }
                return true;
            }
        );

        return *tmp;
    }
private:
    std::vector<T> vec;
};

int main()
{
    std::vector<int> a = {9, 16, 3, 7};
    lab5<int> l(a);
    auto result = l();

    std::cout << "The first prime num is " << result << std::endl;
    return 0;
}

