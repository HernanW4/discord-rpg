#pragma once
#include <string>

/*

   BaseCharacter consists of what makes a basic character in the game.

   Class can extend from this base class and make various types of characters.




 * */

class BaseCharacter {

public:
  /*
   * Represents the different types of build a character can have.
   *
   * */
  enum class Build {
    Knight,
    Archer,
    Wizard,
  };

  /*
   * Represents the different types of gender for a character to have.
   *
   * */
  enum class Gender {
    Male,
    Female,

  };

protected:
  std::string name; // Name of character cannot be accessed outside of classes
                    // so it's protected
  Build build;      // Builds cannot be accessed by outside classes.
  Gender gender;    // Gender cannot be accessed by outside classes.
};

// For printing enums
//
// Every child class that extends this class should call this two functions to
// be able to print the enums.
std::ostream &operator<<(std::ostream &os, const BaseCharacter::Gender Token);
std::ostream &operator<<(std::ostream &os, const BaseCharacter::Build Token);
