#pragma once
#include <string>
#include <iostream>
using std::string;

class Characteristic;

class Weapon {
    friend class Characteristic;
private:
    string name;
    float damage;
    float weight;
public:
    Weapon(string name, float damage, float weight);
    Weapon();
    ~Weapon();

    string getName() const;
    float getDamage() const;
    float getWeight() const;

    void setDamage(float damage);

    bool canLift(float maxWeight) const;
    float getTotalWeight(const Weapon& other) const;
    float getTotalWeight(float otherWeight) const;
};
