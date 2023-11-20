//
// Created by divan on 11/20/23.
//
// x1 + x2 * y
#include <iostream>

using namespace std;

class XX {
protected:
    int x1, x2;

public:
    // Конструктор с параметрами для создания объектов в динамической области памяти
    XX(int x1_val, int x2_val) : x1(x1_val), x2(x2_val) {
        cout << "XX Constructor with parameters\n";
    }

    // Виртуальный деструктор
    virtual ~XX() {
        cout << "XX Destructor\n";
    }

    // Виртуальные методы просмотра текущего состояния и переустановки объектов
    virtual void display() const {
        cout << "XX: x1 = " << x1 << ", x2 = " << x2 << endl;
    }

    virtual void reset(int new_x1, int new_x2) {
        x1 = new_x1;
        x2 = new_x2;
        cout << "XX Reset: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
};

class YY : public XX {
private:
    int yy;

public:
    // Конструктор с параметрами и списком инициализаторов
    YY(int x1_val, int x2_val, int yy_val) : XX(x1_val, x2_val), yy(yy_val) {
        cout << "YY Constructor with parameters and initializer list\n";
    }

    // Переопределенные методы просмотра текущего состояния объектов
    void display() const override {
        cout << "YY: x1 = " << x1 << ", x2 = " << x2 << ", yy = " << yy << endl;
    }

    // Переопределенные методы переустановки объектов в новое состояние
    void reset(int new_x1, int new_x2, int new_yy) {
        XX::reset(new_x1, new_x2);
        yy = new_yy;
        cout << "YY Reset: x1 = " << x1 << ", x2 = " << x2 << ", yy = " << yy << endl;
    }

    // Метод Run, определяющий значение х1+х2*y
    void Run() {
        int result = x1 + x2 * yy;
        cout << "YY Run: Result = " << result << endl;
    }
};

int main() {
    // Создание объекта производного класса YY
    YY obj(1, 2, 3);

    // Вызов метода display для просмотра текущего состояния
    obj.display();

    // Вызов метода Run
    obj.Run();

    // Переустановка объекта в новое состояние через метод reset
    obj.reset(4, 5, 6);

    return 0;
}
