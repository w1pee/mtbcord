cmake_minimum_required(VERSION 3.25)

project(mtbcord VERSION 0.1
                DESCRIPTION "A terminal based Discord client"
                LANGUAGES C)

add_executable(mtbcord src/main.c)
target_include_directories(mtbcord PUBLIC include)
