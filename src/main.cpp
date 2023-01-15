#include <dpp/dpp.h>
#include <iostream>

/*
  Make sure to make your environment variable named BOT_TOKEN.
  If you do not know how to do this, sucks.
 */

typedef unsigned long int character_creation_id_t;

std::atomic<character_creation_id_t> next_character_creation_id(0);

std::map<character_creation_id_t, dpp::snowflake> character_creations;
std::mutex character_creations_mutex;

dpp::snowflake get_user_for_character_creation_id(character_creation_id_t id) {
    std::scoped_lock lock(character_creations_mutex);

    return character_creations.at(id);
}

bool is_character_being_created(character_creation_id_t id) {
    std::scoped_lock lock(character_creations_mutex);

    return character_creations.contains(id);
}

void new_character_creation(dpp::snowflake userId, character_creation_id_t creationId) {
    std::scoped_lock lock(character_creations_mutex);

    character_creations.insert(std::pair(creationId, userId));
}

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

    if (event.command.get_command_name() == "embed") {
        dpp::embed embed = dpp::embed()
                .set_color(dpp::colors::cadmium_green)
                .set_title("Cheese")
                .set_image("https://upload.wikimedia.org/wikipedia/commons/thumb/d/d5/Rust_programming_language_black_logo.svg/1024px-Rust_programming_language_black_logo.svg.png");

        std::string buttonId = std::string("your_mom-") + std::to_string(next_character_creation_id.load());

        event.reply(dpp::message(event.command.channel_id, embed).add_component(dpp::component().add_component(
                dpp::component().set_label(buttonId).set_type(dpp::cot_button).set_style(dpp::cos_primary).set_id(buttonId)
                )));

        new_character_creation(event.command.get_issuing_user().id, next_character_creation_id.load());

        next_character_creation_id++;
    }
  });

  bot.on_button_click([&bot](const dpp::button_click_t& event) {
      std::string buttonType;
      std::string characterCreationId;

      bool isAfterSeparator = false;

      for (char i : event.custom_id) {
        if (i == '-') {
            isAfterSeparator = true;
            continue;
        }

        if (isAfterSeparator) {
            characterCreationId.push_back(i);
        } else {
            buttonType.push_back(i);
        }
      }

      character_creation_id_t creationId = std::stoi(characterCreationId);

      if (!is_character_being_created(creationId)) {
          event.reply("What the heck: " + characterCreationId);
      }

      if (event.command.get_issuing_user().id == get_user_for_character_creation_id(creationId)) {
          event.reply("About time");
      } else {
          event.reply(dpp::message(event.command.channel_id, "You stink").set_flags(dpp::message_flags::m_ephemeral));
      }
  });

  bot.on_ready([&bot](const dpp::ready_t &event) {
    if (dpp::run_once<struct register_bot_commands>()) {
      bot.global_command_create(
          dpp::slashcommand("ping", "Ping pong!", bot.me.id));
      bot.global_command_create(
          dpp::slashcommand("embed", "No!", bot.me.id));
    }
  });

  bot.start(dpp::st_wait);
}

