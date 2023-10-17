### Выставить минимальную версию CMake
#cmake_miniumum_requried(VERSION 2.6)

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
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++ly")

### Стандарт языка C
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=cll")

### Флаги компиляции
#add_definitions(-Wall -O2)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

### Файлы сборки
#set(SOURCES main.cpp)
file(GLOB
		CPPS "*.cpp")

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME} SOURCES)
add_executable(${PROJECT_NAME} ${CPPS})