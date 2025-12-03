// CLab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;
class Characteristic;
class MyMath;

class Weapon {
private:
    string name;
    int damage;
    float weight;

public:
    Weapon(string n, int d, float w) : name(n), damage(d), weight(w) {// Конструктор с параметрами
        cout << "Создано оружие: " << name << endl;
    }

    Weapon() : Weapon("Меч", 45, 10.5) {}// Конструктор без параметров

    
    ~Weapon() {// Деструктор
        cout << "Удаляется оружие: " << name << " (Урон: " << damage 
            << ", Вес: " << weight << ")" << endl;
    }

    bool isTooHeavy(float maxWeight) {
        return weight > maxWeight;
    }

    float getTotalWeight(const Weapon& other) {
        return getTotalWeight(other.weight);
    }

    float getTotalWeight(float otherWeight) {
        return weight + otherWeight;
    }

    string getName() const { return name; }
    int getDamage() const { return damage; }
    float getWeight() const { return weight; }

    void setDamage(int newDamage) {
        damage = newDamage;
    }

    friend class Characteristic;
};

class Characteristic {
private:
    int strength;

public:
    Characteristic(int str) : strength(str) {}

    int GetDamage(const Weapon& weapon) {
        return strength + weapon.damage;
    }
};
class MyMath {
private:
    static int methodCallCount;

public:
    static int Add(int a, int b) {// Статические методы
        methodCallCount++;
        return a + b;
    }

    static int Sub(int a, int b) {
        methodCallCount++;
        return a - b;
    }

    static int Mult(int a, int b) {
        methodCallCount++;
        return a * b;
    }

    static double Div(double a, double b) {
        methodCallCount++;
        if (b != 0) {
            return a / b;
        }
        return 0;
    }
  
    static int getMethodCallCount() {// Статический метод для получения счетчика вызовов
        return methodCallCount;
    }
};

int MyMath::methodCallCount = 0;

void program1() {
    cout << "=== ПРОГРАММА 1 ===" << endl;

    Weapon weapon1("Лук", 25, 8.7f);  // Конструктор с параметрами
    Weapon weapon2;                   // Конструктор без параметров

    cout << "Оружие 1: " << weapon1.getName() << ", Урон: " << weapon1.getDamage()
        << ", Вес: " << weapon1.getWeight() << endl;
    cout << "Оружие 2: " << weapon2.getName() << ", Урон: " << weapon2.getDamage()
        << ", Вес: " << weapon2.getWeight() << endl;

    cout << endl;
}

void program2() {
    cout << "=== ПРОГРАММА 2 ===" << endl;

    Weapon weapon3("Топор", 35, 12.3f);
    cout << "Обычный объект: " << weapon3.getName() << ", Урон: " << weapon3.getDamage()
        << ", Вес: " << weapon3.getWeight() << endl;

    Weapon* dynamicWeapon = new Weapon("Кинжал", 15, 5.2f);
    cout << "Динамический объект: " << dynamicWeapon->getName() << ", Урон: " << dynamicWeapon->getDamage()
        << ", Вес: " << dynamicWeapon->getWeight() << endl;

    cout << "Проверка веса топора (макс. 10 кг): " << (weapon3.isTooHeavy(10.0f) ? "Слишком тяжелый" : "Можно поднять") << endl;
    cout << "Проверка веса кинжала (макс. 10 кг): " << (dynamicWeapon->isTooHeavy(10.0f) ? "Слишком тяжелый" : "Можно поднять") << endl;

    cout << "Суммарный вес топора и кинжала: " << weapon3.getTotalWeight(*dynamicWeapon) << endl;
    cout << "Суммарный вес топора и 5 кг: " << weapon3.getTotalWeight(5.0f) << endl;

    delete dynamicWeapon;
    cout << endl;
}

void program3() {
    cout << "=== ПРОГРАММА 3 ===" << endl;

    Weapon weapon4("Посох", 20, 7.8f);
    cout << "Исходное оружие: " << weapon4.getName() << ", Урон: " << weapon4.getDamage()
        << ", Вес: " << weapon4.getWeight() << endl;

    weapon4.setDamage(30);
    cout << "После изменения урона: " << weapon4.getName() << ", Урон: " << weapon4.getDamage()
        << ", Вес: " << weapon4.getWeight() << endl;

    Characteristic character(15); // Персонаж с силой 15
    int totalDamage = character.GetDamage(weapon4);
    cout << "Суммарный урон героя с оружием: " << totalDamage << endl;

    cout << "Проверка MyMath:" << endl;
    cout << "Add(10, 5) = " << MyMath::Add(10, 5) << endl;
    cout << "Sub(10, 5) = " << MyMath::Sub(10, 5) << endl;
    cout << "Mult(10, 5) = " << MyMath::Mult(10, 5) << endl;
    cout << "Div(10.0, 5.0) = " << MyMath::Div(10.0, 5.0) << endl;
    cout << "Количество вызовов методов MyMath: " << MyMath::getMethodCallCount() << endl;

    cout << endl;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    program1();
    program2();
    program3();

    return 0;
}