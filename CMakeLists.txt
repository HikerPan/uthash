# 设置 CMake 最低版本和项目名称
cmake_minimum_required(VERSION 3.10)
project(MyCProject C)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# 设置编译选项，添加调试信息并禁用优化
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")
set(CMAKE_BUILD_TYPE Debug)


# 指定源文件
set(SOURCES src/moves_hashmap.c)

# 创建主项目的可执行文件
add_executable(MyExecutable ${SOURCES} src/main.c)
target_include_directories(MyExecutable PRIVATE src)

# 添加 Unity 测试可执行文件
add_executable(UnitTests src/unity.c tests/test_moves_hashmap.c src/moves_hashmap.c)
target_include_directories(UnitTests PRIVATE src)

# 启用测试
enable_testing()
add_test(NAME MovesHashmapTests COMMAND UnitTests)

# 添加一个自定义 clean 目标
add_custom_target(clean-all
    COMMAND ${CMAKE_BUILD_TOOL} clean
    COMMAND rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake Makefile
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Cleaning all generated files..."
)
