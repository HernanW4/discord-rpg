
#include "ProtoCharacter.h"

void ProtoCharacter::setName(std::string name) { this->name = name; }

void ProtoCharacter::setBuild(Build build) { this->build = build; }

void ProtoCharacter::setGender(Gender gender) { this->gender = gender; }

std::string ProtoCharacter::getName() { return this->name; }

BaseCharacter::Gender ProtoCharacter::getGender() { return this->gender; }

BaseCharacter::Build ProtoCharacter::getBuild() { return this->build; }
