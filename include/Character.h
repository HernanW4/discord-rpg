
#include "BaseCharacter.h"
#include "ProtoCharacter.h"
#include <memory>
#include <string.h>

/*

   This class represents what is a Character in the game.

   New attributes are added for customization purposes such as level and active
 weapon.

   ProtoCharacter will become a Character once it has reached the final state.
 After Character is made no attributes can be changed other than the level and
 activeWeapon. For future maybe the Build may be subject to change.

 * */

class Character : virtual private BaseCharacter {

public:
  // Make a new instance of Character given a ProtoCharacter
  Character(std::unique_ptr<ProtoCharacter> protoCharacter);

  // Keeps track of Character's level
  int level;

  // Keeps track of weapong being used by character.
  std::string activeWeapon;

  // Getters
  std::string getName();
  Gender getGender();
  Build getBuild();
};
