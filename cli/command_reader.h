//
// Created by donato on 01/10/23.
//

#ifndef DUB_DOT_ITO_COMMAND_READER_H
#define DUB_DOT_ITO_COMMAND_READER_H

#include <string>
#include <vector>
#include "../core/command/command.h"

namespace Cli {
    /**
     * a static class helper to read the commands
     */
    class CommandReader {
    public:
        // region string utils
        static std::vector<std::string> explode(const std::string& p_command, const char& p_needle);
        static bool is_numeric(const std::string& p_argument);
        // endregion string utils
        static Core::Command *read(Core::Player *p_player, std::string p_command);
        static Core::CardValue read_card_value(std::string p_card_name);
    };

} // Cli

#endif //DUB_DOT_ITO_COMMAND_READER_H
