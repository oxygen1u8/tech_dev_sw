#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

#include <cmath>
#include <cstdlib>

/* Создать класс- интерфейс пространственной фигуры, который содержит три */
/* элемента с модификатором доступа protected. Создать производные классы: */
/* прямоугольный параллелепипед, правильная пирамида с треугольным основанием, */
/* полый цилиндр. Для каждой из фигур предусмотреть вывод ее названия и вычисление объема. */
/* Случайным образом выбрать фигуру и с помощью оператора dynamic_cast */
/* произвести конвертацию типа из класса-интерфейса в производный. */

class vol_figure {
public:
    void print_name()
    {
        std::cout << name << std::endl;
    }
    virtual double calculate_volume() = 0;
protected:
    std::string name;
    double vol;
private:
};

class trunc_pyramid : public vol_figure {
private:
    double s1;
    double s2;
    double h;
public:
    trunc_pyramid(double s1, double s2, double h)
    {
        this->name = "Truncated pyramid";

        this->s1 = s1;
        this->s2 = s2;
        this->h = h;
    }

    double calculate_volume() override
    {
        this->vol = (double) 1/3 * h * (this->s1 + this->s2 + sqrt(this->s1 * this->s2));
        return this->vol;
    }
};

class prism : public vol_figure {
private:
    double s;
    double h;
public:
    prism(double s, double h)
    {
        this->name = "Prism";

        this->s = s;
        this->h = h;
    }

    double calculate_volume() override
    {
        this->vol = (double) this->s * this->h;
        return this->vol;
    }
};

class hollow_ball : public vol_figure {
private:
    double r;
public:
    hollow_ball(double r)
    {
        this->name = "Hollow ball";
        this->r = r;
    }

    double calculate_volume() override
    {
        this->vol = (double) 4/3 * M_PI * r * r * r;
        return this->vol;
    }
};

int main()
{
    srand(time(0));

    trunc_pyramid tp(1, 2, 3);
    prism p(5, 10);
    hollow_ball hb(4);

    std::vector<vol_figure *> array;
    array.push_back(dynamic_cast<vol_figure*>(&tp));
    array.push_back(dynamic_cast<vol_figure*>(&p));
    array.push_back(dynamic_cast<vol_figure*>(&hb));
    
    uint32_t index = rand() % array.size();
    
    array[index]->print_name();
    std::cout << array[index]->calculate_volume() << std::endl;

    return 0;
}

