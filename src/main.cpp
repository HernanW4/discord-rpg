#include "BaseCharacter.h"
#include "Character.h"
#include "ProtoCharacter.h"
#include <dpp/dpp.h>
#include <iostream>
#include <memory>

// const std::string BOT_TOKEN = "add your token here";

/*
  Make sure to make your environment variable named BOT_TOKEN.
  If you do not know how to do this, sucks.
 */

int main() {
  std::unique_ptr<ProtoCharacter> protoCharacter =
      std::unique_ptr<ProtoCharacter>(new ProtoCharacter());

  std::string name;
  std::string genderString;
  BaseCharacter::Gender gender;

  std::string buildString;
  BaseCharacter::Build build;

  std::cout << "Enter Name:" << std::endl;
  std::cin >> name;
  std::cout << "Enter Gender:" << std::endl;
  std::cin >> genderString;
  if (genderString == "F") {
    gender = BaseCharacter::Gender::Female;
  } else {
    gender = BaseCharacter::Gender::Male;
  }
  std::cout << "Enter Build:" << std::endl;
  std::cin >> buildString;

  if (buildString == "Knight") {
    build = BaseCharacter::Build::Knight;
  }

  protoCharacter->setName(name);
  protoCharacter->setGender(gender);
  protoCharacter->setBuild(build);

  Character ch1 = Character(std::move(protoCharacter));

  std::cout << "My Name is: " << ch1.getName() << std::endl;
  std::cout << "My Gender is: " << ch1.getGender() << std::endl;
  std::cout << "My Build is: " << ch1.getBuild() << std::endl;

  std::cout << protoCharacter << std::endl;

  // std::string bot_token;

  // if (const char *env_p = std::getenv("BOT_TOKEN")) {
  //     bot_token = env_p;
  // }
  // dpp::cluster bot(bot_token);

  // bot.on_log(dpp::utility::cout_logger());

  // bot.on_slashcommand([](const dpp::slashcommand_t &event) {
  //   if (event.command.get_command_name() == "ping") {
  //     event.reply("Pong!");
  //   }
  // });

  // bot.on_ready([&bot](const dpp::ready_t &event) {
  //   if (dpp::run_once<struct register_bot_commands>()) {
  //     bot.global_command_create(
  //         dpp::slashcommand("ping", "Ping pong!", bot.me.id));
  //   }
  // });

  // bot.start(dpp::st_wait);
}
