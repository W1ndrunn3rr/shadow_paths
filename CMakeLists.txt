cmake_minimum_required (VERSION 3.1)

# Tu wstawcie nazwę swojego projektu
project (Shadow_Paths)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

# Windows specific config
# To możecie zmienić jeśli zainstalujecie SFML-a w innym miejscu
IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "C:/lib/SFML-2.5.1/lib/cmake/SFML")
    # Link sfml statically (Optional)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# tu ustawiacie nazwę pliku wykonywalnego - możecie zmienić choinka na coś innego
add_executable(Shadow_Paths main.cpp Entity.cpp Entity.h Quest.cpp Quest.h Merchant.h Merchant.cpp CombatController.cpp CombatController.h GameController.cpp GameController.h GameView.cpp GameView.h Boss.cpp Boss.h Music.cpp Music.h)
target_link_libraries(Shadow_Paths sfml-graphics sfml-audio)