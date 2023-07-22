cmake_minimum_required(VERSION 3.25)

project(mtbcord VERSION 0.1
                DESCRIPTION "A terminal based Discord client"
                LANGUAGES C)



find_package(Curses REQUIRED)

set(DEBUG_OPTIONS "-Wall;-Wextra;-pedantic")
set(RELEASE_OPTIONS "-Werror;-Wall;-Wextra;-pedantic")

set(SOURCE_FILES   "src/main.c"
                    "src/ui/events.c"
                    "src/ui/ui.c")

# Main executable
add_executable(mtbcord ${SOURCE_FILES})

target_compile_features(mtbcord PUBLIC c_std_99)

target_compile_options(mtbcord PUBLIC "$<$<CONFIG:Debug>:${DEBUG_OPTIONS}>")
target_compile_options(mtbcord PUBLIC "$<$<CONFIG:Release>:${RELEASE_OPTIONS}>")

# Include dirs
target_include_directories(mtbcord PUBLIC
    include
    ${CURSES_INCLUDE_DIR})

# Libraries
target_link_libraries(mtbcord PUBLIC
    ${CURSES_LIBRARIES})
