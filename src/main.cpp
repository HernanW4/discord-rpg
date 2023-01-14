#include <dpp/dpp.h>
#include <iostream>

//const std::string BOT_TOKEN = "add your token here";

/*
  Make sure to make your environment variable named BOT_TOKEN.
  If you do not know how to do this, sucks.
 */

int main() {

  std::string bot_token;

  if (const char *env_p = std::getenv("BOT_TOKEN")) {
      bot_token = env_p;
  }
  dpp::cluster bot(bot_token);

  bot.on_log(dpp::utility::cout_logger());

  bot.on_slashcommand([](const dpp::slashcommand_t &event) {
    if (event.command.get_command_name() == "ping") {
      event.reply("Pong!");
    }
  });

  bot.on_ready([&bot](const dpp::ready_t &event) {
    if (dpp::run_once<struct register_bot_commands>()) {
      bot.global_command_create(
          dpp::slashcommand("ping", "Ping pong!", bot.me.id));
    }
  });

  bot.start(dpp::st_wait);
}
