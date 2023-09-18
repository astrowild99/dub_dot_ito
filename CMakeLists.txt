cmake_minimum_required(VERSION 3.26)
project(dub_dot_ito)

set(CMAKE_CXX_STANDARD 17)

add_executable(dub_dot_ito main.cpp
        core/game.cpp
        core/game.h
        core/player/player.cpp
        core/player/player.h
        core/card/card.cpp
        core/card/card.h
        core/player/state/player_state_interface.h
        core/player/state/idle.cpp
        core/player/state/idle.h
        cli/cli.cpp
        cli/cli.h
        core/command/queue.cpp
        core/command/queue.h
        core/command/command_interface.h
        core/command/doubt.cpp
        core/command/doubt.h
        core/command/append_cards.cpp
        core/command/append_cards.h)
