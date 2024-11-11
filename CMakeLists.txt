# 设置 CMake 最低版本和项目名称
cmake_minimum_required(VERSION 3.10)
project(MyCppProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定源文件
set(SOURCES src/moves_hashmap.cpp main.cpp)

# 创建可执行文件
add_executable(MyExecutable ${SOURCES})

# 包含头文件目录
target_include_directories(MyExecutable PRIVATE src)

# 添加一个自定义 clean 目标
add_custom_target(clean-all
    COMMAND ${CMAKE_BUILD_TOOL} clean
    COMMAND rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake Makefile
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Cleaning all generated files..."
)

