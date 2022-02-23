cmake_minimum_required(VERSION 3.21)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)
#set(SDL_DIR /usr/local/localib) # 这个SDL开发包的路径，可以通过brew info sdl2查出来
include_directories(/usr/local/include/SDL2/) # 添加SDL头文件搜索路径
link_libraries(/usr/local/lib/libSDL2.dylib /usr/local/lib/libSDL2_image.dylib) # 增加SDL链接库目录
#find_package(SDL2 REQUIRED)
#add_executable(PlaySDL main.cpp)



add_executable(leetcode diagram.cpp)
#target_link_libraries(leetcode ${SDL2_LIBRARY}) # 链接目标库
