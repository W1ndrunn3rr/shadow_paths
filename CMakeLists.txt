cmake_minimum_required (VERSION 3.1)

project (Shadow_Paths)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "C:/lib/SFML-2.5.1/lib/cmake/SFML")
    # Link sfml statically (Optional)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Shadow_Paths main.cpp src/Entity.cpp lib/Entity.h src/Quest.cpp lib/Quest.h lib/Merchant.h src/Merchant.cpp src/CombatController.cpp lib/CombatController.h src/GameController.cpp lib/GameController.h src/GameView.cpp lib/GameView.h src/Boss.cpp lib/Boss.h src/Music.cpp lib/Music.h)
target_link_libraries(Shadow_Paths sfml-graphics sfml-audio)
