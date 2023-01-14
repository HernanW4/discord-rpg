#pragma once


#include <string>

class Character{
    public:
        int level;
        std::string active_weapon;

        Character(std::string name, Gender gender, Build build);
        std::string get_name();
        Gender get_gender();
        Build get_build();

    private:
        std::string name;
        Build build;
        Gender gender;

};

enum class Build{
    Knight,
    Archer,
    Wizard
};

enum class Gender{
    Male,
    Female,
};