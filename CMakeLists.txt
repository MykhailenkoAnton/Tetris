cmake_minimum_required(VERSION 3.13)  # CMake version check
project(tetris)                       # Create project "tetris"
set(CMAKE_CXX_STANDARD 11)            # Enable c++14 standard

# Add sources files.
set(SOURCE_FILES
    main.cpp
    Tetris.cpp
    visual_elements/Field.cpp
    visual_elements/figure/Figure.cpp
    visual_elements/figure/concrete_figure/Stick.cpp
    visual_elements/figure/concrete_figure/Square.cpp
    visual_elements/figure/concrete_figure/HookRight.cpp
    visual_elements/figure/concrete_figure/HookLeft.cpp
    visual_elements/figure/concrete_figure/Piramide.cpp
    visual_elements/figure/concrete_figure/LetterS.cpp
    visual_elements/figure/concrete_figure/LetterS_reverse.cpp
    visual_elements/Menu.cpp)

# Add headers files.
set(HEADER_FILES
    Tetris.h
    visual_elements/Field.h
    visual_elements/figure/Figure.h
    visual_elements/figure/concrete_figure/Stick.h
    visual_elements/figure/concrete_figure/Square.h
    visual_elements/figure/concrete_figure/HookRight.h
    visual_elements/figure/concrete_figure/HookLeft.h
    visual_elements/figure/concrete_figure/Piramide.h
    visual_elements/figure/concrete_figure/LetterS.h
    visual_elements/figure/concrete_figure/LetterS_reverse.h
    visual_elements/Menu.h)

# Add subdirectory.
set(DIRS
    visual_elements
    visual_elements/figure
    visual_elements/figure/concrete_figure)

# Add executable target.
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${DIRS})
