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

class regular_pyramid : public vol_figure {
private:
    double a;
    double h;
public:
    regular_pyramid(double a, double h)
    {
        this->name = "Regular pyramid";

        this->a = a;
        this->h = h;
    }

    double calculate_volume() override
    {
        this->vol = (double) 1/3 * h * a * a * sqrt(3)/4;
        return this->vol;
    }
};

class cuboid : public vol_figure {
private:
    double a;
    double b;
    double c;
public:
    cuboid(double a, double b, double c)
    {
        this->name = "Cuboid";

        this->a = a;
        this->b = b;
        this->c = c;
    }

    double calculate_volume() override
    {
        this->vol = a * b * c;
        return this->vol;
    }
};

class hollow_cylinder : public vol_figure {
private:
    double r;
    double h;
public:
    hollow_cylinder(double r, double h)
    {
        this->name = "Hollow cylinder";
        this->r = r;
    }

    double calculate_volume() override
    {
        this->vol = (double) M_PI * r * r * h;
        return this->vol;
    }
};

int main()
{
    srand(time(0));

    cuboid tp(1, 2, 3);
    regular_pyramid p(5, 10);
    hollow_cylinder hb(4, 6);

    std::vector<vol_figure *> array;
    array.push_back(dynamic_cast<vol_figure*>(&tp));
    array.push_back(dynamic_cast<vol_figure*>(&p));
    array.push_back(dynamic_cast<vol_figure*>(&hb));
    
    uint32_t index = rand() % array.size();
    
    array[index]->print_name();
    std::cout << array[index]->calculate_volume() << std::endl;

    return 0;
}

