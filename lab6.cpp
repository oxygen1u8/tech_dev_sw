#include <iostream>
#include <memory>
#include <string>

/* Выберите вариант в соответствии с вашим номером в списке группы. Для реализации */
/* связей между элементами списка/дерева выберите наиболее подходящий */
/* из умных указателей (unique_ptr, shared_ptr или weak_ptr). */

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
    std::string name;
public: 
    magazine(std::string magazine_name) : name(magazine_name)
    {

    }
};

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    std::cout << st.pop() << std::endl << st.pop() << std::endl << st.pop() << std::endl;

    return 0;
}

