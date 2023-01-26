#pragma once

#include "BaseCharacter.h"
#include <string>

/*
    This class will be used for the process of making the character.

    So in simple terms while a Character is being made, this class will hold the
 temporary attributes.


 * */
class ProtoCharacter : virtual private BaseCharacter {

public:
  // Setters
  void setName(std::string name);
  void setGender(BaseCharacter::Gender gender);
  void setBuild(BaseCharacter::Build build);

  // Getters
  std::string getName();
  BaseCharacter::Gender getGender();
  BaseCharacter::Build getBuild();
};
