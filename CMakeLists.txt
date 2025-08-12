cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Projektet måste definieras här innan targets läggs till
project("banksystem")

# Hitta SQLite via vcpkg
find_package(SQLite3 REQUIRED)

# Debug: skriv ut vad CMake hittade
message(STATUS "SQLite3 include dir: ${SQLite3_INCLUDE_DIRS}")
message(STATUS "SQLite3 library: ${SQLite3_LIBRARIES}")

# Lägg till din executable
add_executable(banksystem
    banksystem.cpp
    banksystem.h
    menu.cpp
    menu.h
    show_menu.cpp
    show_menu.h
    clear_console.cpp
    clear_console.h
    menu_components/register.cpp
    menu_components/register.h
)

# Inkludera och länka mot SQLite manuellt
target_include_directories(banksystem PRIVATE ${SQLite3_INCLUDE_DIRS})
target_link_libraries(banksystem PRIVATE ${SQLite3_LIBRARIES})

# Ställ in C++-standard
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET banksystem PROPERTY CXX_STANDARD 20)
endif()
