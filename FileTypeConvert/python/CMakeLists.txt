cmake_minimum_required(VERSION 3.10)

# set the project name
project(ft)

message(STATUS ${PROJECT_NAME}\ Configurating...)

set(SRC
        pythonFT.c
        ft.c)

LINK_LIBRARIES(m)
# add the executable
add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

