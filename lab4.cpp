#include <iostream>
#include <vector>
#include <algorithm>

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

    void operator()(T value)
    {
        auto tmp = std::find_if(vec.begin(), vec.end(), [value](const T& m) -> bool { return m == value; });
        /* std::cout << *tmp << std::endl; */
        auto tmp2 = std::distance(vec.begin(), tmp);

        if (tmp2 == vec.size()) {
            std::cout << "No element\n";
        } else {
            std::cout << "Index of element = " << tmp2 << std::endl;
        }
    }
};

int main()
{
    std::vector<int> values = {1, 2, 3, 4, 5, 6};
    functor<int> f(values);
    
    int a = 0;
    std::cin >> a;
    f(a);
    return 0;
}

