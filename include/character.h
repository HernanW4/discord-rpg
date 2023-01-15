#pragma once
#include <string>


enum class Build{
    Knight,
    Archer,
    Wizard,
};

enum class Gender{
    Male,
    Female,
};

class Character{
    public:
        int level;
        std::string activeWeapon;

        Character(std::string name, Gender gender, Build build);
        std::string getName();
        Gender getGender();
        Build getBuild();

    private:
        std::string name;
        Build build;
        Gender gender;

};

