#include <iostream>
#include "Weapon.h"
#include "Characteristic.h"
#include "MyMath.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 25, 7);
    Weapon axe;

    std::cout << sword.getName() << " " << sword.getDamage() << " " << sword.getWeight() << "\n";
    std::cout << axe.getName() << " " << axe.getDamage() << " " << axe.getWeight() << "\n";

    Weapon* bow = new Weapon("Лук", 15, 3);
    std::cout << bow->getName() << " " << bow->getDamage() << " " << bow->getWeight() << "\n";
    delete bow;

    Characteristic hero(10);
    std::cout << "Суммарный урон: " << hero.GetDamage(sword) << "\n";

    std::cout << MyMath::Add(2, 3) << "\n";
    std::cout << MyMath::Sub(5, 1) << "\n";
    std::cout << MyMath::Mult(4, 3) << "\n";
    std::cout << MyMath::Div(10, 2) << "\n";

    std::cout << "Кол-во вызовов: " << MyMath::counter << "\n";
    return 0;
}
