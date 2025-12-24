#pragma once
#include "Weapon.h"

class Characteristic {
private:
    float strength;
public:
    Characteristic(float strength);
    float GetDamage(const Weapon& weapon);
};
