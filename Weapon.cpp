#include "Weapon.h"

Weapon::Weapon(string name, float damage, float weight)
    : name(name), damage(damage), weight(weight) {}

Weapon::Weapon() : Weapon("Оружие по умолчанию", 10, 5) {}

Weapon::~Weapon() {
    std::cout << "Оружие уничтожено: "
              << name << ", урон=" << damage
              << ", вес=" << weight << "\n";
}

string Weapon::getName() const { return name; }
float Weapon::getDamage() const { return damage; }
float Weapon::getWeight() const { return weight; }

void Weapon::setDamage(float damage) {
    if (damage >= 0) this->damage = damage;
}

bool Weapon::canLift(float maxWeight) const {
    return maxWeight < weight;
}

float Weapon::getTotalWeight(float otherWeight) const {
    return weight + otherWeight;
}

float Weapon::getTotalWeight(const Weapon& other) const {
    return getTotalWeight(other.weight);
}
