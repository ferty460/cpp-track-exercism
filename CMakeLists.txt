cmake_minimum_required(VERSION 3.31)
project(exercism)

set(CMAKE_CXX_STANDARD 20)

add_executable(exercism 1_hello_world.cpp
        2_log_levels.cpp
        3_lasagna.cpp
        4_freelancer_rates.cpp
        5_last_will.cpp
        6_pacman_rules.cpp
        7_vehicle_purchase.cpp
        vehicle_purchase.h
        hello_world.h
        8_making_the_grade.cpp
        9_interest_is_interesting.cpp
        10_ellens_alien_game.cpp
        11_election_day.cpp
        12_troll_the_trolls.cpp
)
