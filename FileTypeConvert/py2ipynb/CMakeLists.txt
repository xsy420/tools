cmake_minimum_required(VERSION 3.10)

# set the project name
project(py2ipynb)

message(STATUS ${PROJECT_NAME}\ Configurating...)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(LIBRARY_DIR ${PROJECT_SOURCE_DIR}/../lib)
set(SRC
  ${LIBRARY_DIR}/cJSON.c
	${SOURCE_DIR}/py2ipynb.c)

include_directories(${LIBRARY_DIR})
LINK_LIBRARIES(m)
# add the executable
add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(
	${PROJECT_NAME}
	PRIVATE
		${PROJECT_SOURCE_DIR}/include
	)

