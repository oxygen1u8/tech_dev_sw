#include <iostream>
#include <memory>
#include <string>
#include <vector>

/* Выберите вариант в соответствии с вашим номером в списке группы. Для реализации */
/* связей между элементами списка/дерева выберите наиболее подходящий */
/* из умных указателей (unique_ptr, shared_ptr или weak_ptr). */

/* Разработать класс стека с операциями вставки и извлечения элемента (push и pop) */

template <typename T>
class stack {
private:
    struct node {
        T data;
        std::unique_ptr<node> next;
    };

    std::unique_ptr<node> head;
public:
    ~stack()
    {
        while (head) {
            auto next = std::move(head->next);
            head = std::move(next);
        }
    }

    void push(T value)
    {
        head = std::unique_ptr<node>(new node{value, std::move(head)});
    }

    T pop()
    {
        T tmp = head->data;
        auto next = std::move(head->next);
        head = std::move(next);
        return tmp;
    }
};

/* Согласно варианту реализовать класс, наполнить его полями и методами.  */
/* Использовать в реализации умные указатели. Протестировать в случаях, */
/* где вероятна утечка памяти (досрочный выход с помощью return или */
/* генерации исключения, циклическая зависимость указателей). */

class magazine {
private:
    struct product {
        std::string name;
        int count;
        int cost;
    };
    std::string name;
    std::vector<std::unique_ptr<struct product>> arr;
public: 
    void add_new_product(std::string name, int count, int cost)
    {
        std::unique_ptr<struct product> new_product(new struct product);

        new_product->name = name;
        new_product->count = count;
        new_product->cost = cost;

        if (count < 0 || cost < 0 || name.size() == 0) {
            throw -1;
        } else {
            arr.push_back(std::move(new_product));
        }
    }

    void print_name_of_all_products()
    {
        for (const auto& i: arr) {
            std::cout << i->name << std::endl;
        }
    }
};

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    std::cout << st.pop() << std::endl << st.pop() << std::endl << st.pop() << std::endl;

    magazine mag;

    try {
        mag.add_new_product("Hleb", 10, 10);
        mag.add_new_product("Pirozhok", -1, -2);
    }
    catch (int except) {
        if (except == -1) {
            std::cout << "Bad value\n";
        }
    }
    mag.print_name_of_all_products();

    return 0;
}

