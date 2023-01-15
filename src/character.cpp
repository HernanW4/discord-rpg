//
// Created by walter, caca on 1/14/23.
//
#include "character.h"

#include <utility>

Character::Character(std::string name, Gender gender, Build build) {
    this->name = std::move(name);
    this->gender = gender;
    this->build = build;
    this->activeWeapon = "Stick";
    this->level = 0;
}

std::string Character::getName() {
    return this->name;
}

Build Character::getBuild() {
    return this->build;
}

Gender Character::getGender() {
    return this->gender;
}