#include "Character.h"
#include "ProtoCharacter.h"

using namespace std;

// Make a new instance of Character given the Prototype (ProtoCharacter)
//
// We take ProtoCharacter as a unique_ptr because we don't want anything else
// pointing to it and once is used it will be deleted.
Character::Character(unique_ptr<ProtoCharacter> protoCharacter) {

  this->level = 0;
  this->activeWeapon = "Stick";

  this->name = protoCharacter->getName();
  this->gender = protoCharacter->getGender();
  this->build = protoCharacter->getBuild();

  auto pointerDeleted = protoCharacter.release();
  delete pointerDeleted;
}

std::string Character::getName() { return this->name; }

BaseCharacter::Gender Character::getGender() { return this->gender; }

BaseCharacter::Build Character::getBuild() { return this->build; }

//Translate enum Build into a string when using the << operator
std::ostream &operator<<(std::ostream &os, const BaseCharacter::Build Token) {
  switch (Token) {
  case BaseCharacter::Build::Archer:
    os << "Archer";
    break;
  case BaseCharacter::Build::Knight:
    os << "Knight";
    break;
  case BaseCharacter::Build::Wizard:
    os << "Wizard";
    break;
  }
  return os;
}

//Translate enum Gender into a string when using the << operator
std::ostream &operator<<(std::ostream &os, const BaseCharacter::Gender Token) {
  switch (Token) {
  case BaseCharacter::Gender::Female:
    os << "Female";
    break;
  case BaseCharacter::Gender::Male:
    os << "Male";
    break;
  }
  return os;
}
