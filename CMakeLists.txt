cmake_minimum_required(VERSION 3.2)
project(ConsoleAppKohot VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(DEPS_LIBRARY KohotLibrary)
FetchContent_Declare(
	${DEPS_LIBRARY}
	GIT_REPOSITORY https://github.com/EladGil47/${DEPS_LIBRARY}.git
	GIT_TAG master
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/_deps/${DEPS_LIBRARY}
    BINARY_DIR ${PROJECT_SOURCE_DIR}/build/_deps/${DEPS_LIBRARY}
)
FetchContent_MakeAvailable(${DEPS_LIBRARY})

set(CONSOLE_APP_KOHOT_LIB_SOURCES
main.cpp
src/menu.cpp  
src/group_menu.cpp 
src/final_menu.cpp
src/groups_manager_menu.cpp  
src/players_menu.cpp  
include/groups_manager_menu.hpp  
include/group_menu.hpp  
include/final_menu.hpp  
include/menu.hpp  
include/players_menu.hpp  
include/user_interaction.hpp  
)
add_executable(${PROJECT_NAME} ${CONSOLE_APP_KOHOT_LIB_SOURCES})

link_directories(${CMAKE_SOURCE_DIR}/${DEPS_LIBRARY})

target_compile_options(${PROJECT_NAME} PRIVATE
		-Wall
		)

target_link_libraries(${PROJECT_NAME} PRIVATE
    KOHOT_LIB
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)