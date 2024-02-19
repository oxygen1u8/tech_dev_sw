#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/* Дан целочисленный список. Используя функцию for_each найти сумму */
/* простых элементов списка (по определению 0 и 1 простыми числами не являются). */

template <typename T>
class functor {
private:
    std::vector<T> vec;

public:
    functor(std::vector<T>& vec)
    {
        this->vec = vec;
    }

    int operator()()
    {
        unsigned int sum = 0;
        std::for_each(vec.begin(), vec.end(), [&sum](const T& m)
            {
                bool flag = true;

                if (m < 2)
                    return;
                else if (m == 2) {
                    sum += m;
                    return;
                }
                for (unsigned int i = 2; i <= sqrt(m); i++) { 
                    if (m % i == 0) {
                        flag = false;
                        break; 
                    } 
                }

                if (flag) {
                    sum += m;
                }
            }
        );

        return sum;
    }
};

int main()
{
    std::vector<int> values = {1, 2, 3, 4, 5, 6};
    functor<int> f(values);
    
    auto result = f();

    std::cout << "Result sum is " << result << std::endl;

    return 0;
}

