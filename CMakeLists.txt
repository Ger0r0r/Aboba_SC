### Выставить минимальную версию CMake
cmake_minimum_required(VERSION 2.6)

### Устанавливает переменную
# ${PROJECT_NAME}
project(application_scheme)

### Режим сборки
#set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

### Стандарт языка C++
#set(CMAKE_CXX_STANDART 11)
## то же самое (через флаги компиляции)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

### Стандарт языка C
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=cll")

### Флаги компиляции
#add_definitions(-Wall -O2)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -IC:\SFML-2.6.0\include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network")
# add_definitions(-IC:\SFML-2.6.0\include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network)


### Файлы сборки
#set(SOURCES main.cpp)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

# add_executable(${PROJECT_NAME} main.cpp)
# add_executable(${PROJECT_NAME} SOURCES)
add_executable(${PROJECT_NAME} ${CPPS})


find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(${EXEC_FILE} sfml-graphics sfml-audio sfml-window sfml-system)