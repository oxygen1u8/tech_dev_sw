#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <string>

/* В векторе целого типа заменить максимальный элемент суммой предыдущих элементов, минимальный – суммой последующих элементов */

void lab2_task1(std::vector<int>& array)
{
    auto max = std::max_element(array.begin(), array.end());
    auto min = std::min_element(array.begin(), array.end());

    int sum_max = 0;
    int sum_min = 0;

    for (auto i = std::begin(array); i != max; i++) {
        sum_max += *i;
    }
    
    if (min != array.end()) {
        for (auto i = min + 1; i != array.end(); i++) {
            sum_min += *i;
        }
    }

    *max = sum_max;
    *min = sum_min;

    std::cout << "Sum before max element: " << sum_max << std::endl;
    std::cout << "Sum min element: " << sum_min << std::endl;
}

std::vector<unsigned int> find_all_substr_pos(std::string& str, std::string &substr)
{
    std::vector<unsigned int> a_pos;
    size_t index = 0;

    while (1) {
        index = str.find(substr, index);

        if (index == std::string::npos)
            break;
        else {
            a_pos.push_back(index);
            index += 1;
        }
    }

    return a_pos;
}

/* Дана строка слов. Сформируйте новую строку, вставив перед каждым из слов "а" и "но" запятую. Определите самую короткую подстроку */

std::string lab2_task2(std::string& str)
{
    std::string substr = " a ";
    auto tmp = find_all_substr_pos(str, substr);

    for (const auto &i: tmp) {
        str[i] = ',';
    }

    substr = " no ";
    tmp = find_all_substr_pos(str, substr);

    for (const auto &i: tmp) {
        str[i] = ',';
    }

    substr = ",";

    tmp = find_all_substr_pos(str, substr);

    uint32_t min = 0xffffffff;
    uint32_t min_i = tmp[0];
    
    for (uint32_t i = 0; i < tmp.size() - 1; i++) {
        auto tmp2 = tmp[i + 1] - tmp[i];
        if (tmp2 < min) {
            min = tmp2;
            min_i = i;
        }
    }

    std::string res;
    res = str.substr(tmp[min_i], tmp[min_i + 1] - tmp[min_i]);

    return res;
}

int main()
{
    std::vector<int> a = {5, 6, 0, 4, 8, 2, 3, -9, 7, -3, -2, -1};

    lab2_task1(a);

    for (const auto &i: a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::string str = "Kak zhe tak pochemu ya debil a on net no ya ne samiy tupoi a on samiy no ya luchse no ti loh a ya net";

    auto tmp = lab2_task2(str);
    std::cout << str << std::endl;

    std::cout << tmp << std::endl;

    return 0;
}

