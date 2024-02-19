#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>

#define ELEMENT_COUNT 23
#define FIRST_ELEMENT 12

/* 1.С помощью функции iota() заполните вектор соответствующим вашему варианту образом. */
/* 2.Перемешайте содержимое вектора случайным образом. */
/* 3.Отсортируйте вектор по указанному для варианта принципу. (по кратности 3) */

/* Даны 3 целочисленных массива, описывающий перемещение объекта в пространстве */
/* (Например: Z = {-1; 10; -15; 5 …}). При помощи функций библиотеки <algorithm> найти */
/* абсолютные значения координат объекта, на каждом из шагов.  */
/* Начальное положение объекта задается пользователем. */

int main()
{
    srand(time(NULL));
    std::vector<int> vec(ELEMENT_COUNT);

    std::cout << "TASK 1" << std::endl;
    std::iota(vec.begin(), vec.end(), FIRST_ELEMENT);
    
    std::cout << "Create vector\n";
    for (const auto &i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::shuffle(vec.begin(), vec.end(), std::mt19937(std::random_device()()));
    
    std::cout << "Shuffle\n";
    for (const auto &i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::qsort(vec.begin().base(), vec.size(), sizeof(vec.at(0)),
            [](const void *a, const void *b) -> int {
            auto a_i = *((const int *) a);
            auto b_i = *((const int *) b);

            auto tmp1 = (a_i % 3 == 0);
            auto tmp2 = (b_i % 3 == 0);

            if (tmp1 > tmp2) {
                return -1;
            } else if (tmp1 < tmp2) {
                return 1;
            } else {
                return 0;
            }
    });
    
    std::cout << "Sorted\n";
    for (const auto &i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "TASK 2" << std::endl;

    int x, y, z;
    std::cin >> x >> y >> z;

    std::vector<int> X = {1, -2, 3, -4, 5};
    std::vector<int> Y = {-5, 4, -3, 2, -1};
    std::vector<int> Z = {-3, 2, 4, 1, -5};
    
    int _x[X.size()];
    int _y[Y.size()];
    int _z[Z.size()];

    std::partial_sum(X.begin(), X.end(), _x);
    std::partial_sum(Y.begin(), Y.end(), _y);
    std::partial_sum(Z.begin(), Z.end(), _z);

    for (uint32_t i = 0; i < X.size(); i++) {
        std::cout << "X" << i + 1 << ": " << std::abs(x + _x[i]) << "\t";
        std::cout << "Y" << i + 1 << ": " << std::abs(y + _y[i]) << "\t";
        std::cout << "Z" << i + 1 << ": " << std::abs(z + _z[i]) << "\n";
    }

    return 0;
}

