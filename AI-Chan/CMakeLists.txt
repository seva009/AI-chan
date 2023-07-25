cmake_minimum_required(VERSION 3.5)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

include_directories( ${OpenCV_INCLUDE_DIRS} )
find_package( OpenCV REQUIRED )

project(AI-Chan LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DGMPXX_USE_CXX11_ABI=1)
add_definitions(-DGMP_USE_DEPRECATED=0)

add_executable(AI-Chan main.cpp)

install(TARGETS AI-Chan
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

target_link_libraries( AI-Chan ${OpenCV_LIBS} gmpxx gmp)


