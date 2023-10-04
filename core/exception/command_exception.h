//
// Created by donato on 04/10/23.
//

#ifndef DUB_DOT_ITO_COMMAND_EXCEPTION_H
#define DUB_DOT_ITO_COMMAND_EXCEPTION_H

#include <exception>
#include <string>

namespace Core {

    class CommandException : public std::exception {
    private:
        std::string message;
    public:
        explicit CommandException(std::string p_message);
        const char *what();
    };

} // Core

#endif //DUB_DOT_ITO_COMMAND_EXCEPTION_H
