#include "Characteristic.h"

Characteristic::Characteristic(float strength)
    : strength(strength) {}

float Characteristic::GetDamage(const Weapon& weapon) {
    return strength + weapon.damage;
}
