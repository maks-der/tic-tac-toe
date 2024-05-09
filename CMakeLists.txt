cmake_minimum_required(VERSION 3.27)

project(tic_tac_toe LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(tic_tac_toe
        main.cpp
        src/FieldRenderer.h
        src/Constants.h
        src/FieldRenderer.cpp
        src/GameController.h
        src/GameController.cpp
        src/DialogRenderer.h
        src/DialogRenderer.cpp
        src/SoundsController.h
        src/SoundsController.cpp
)

set(ASSETS_FILES
        assets/cantarell-regular.ttf
        assets/click-sound.wav
        assets/game-over-sound.wav
)

foreach (asset_file ${ASSETS_FILES})
    configure_file(src/${asset_file} ${CMAKE_BINARY_DIR}/bin/${asset_file} COPYONLY)
endforeach()


target_link_libraries(tic_tac_toe PRIVATE sfml-audio sfml-graphics)
target_compile_features(tic_tac_toe PRIVATE cxx_std_17)

if (WIN32)
    add_custom_command(
            TARGET tic_tac_toe
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:tic_tac_toe>
            VERBATIM)
endif ()

install(TARGETS tic_tac_toe)