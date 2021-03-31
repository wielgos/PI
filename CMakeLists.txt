cmake_minimum_required(VERSION 3.17)
project(Pi C)

set(CMAKE_C_STANDARD 99)

add_executable(Pi main.c)

add_executable(week1.1 week1/1.c)
add_executable(week1.2 week1/2.c)
add_executable(week1.3 week1/3.c)
add_executable(week1.4 week1/4.c)

add_executable(week2.1 week2/1.c)
add_executable(week2.1v2 week2/1v2.c)
add_executable(week2.2 week2/2.c)
add_executable(week2.3 week2/3.c)

add_executable(week3.1 week3/1.c)
add_executable(week3.2 week3/2.c)
add_executable(week3.2v2 week3/2_2.c)
add_executable(week3.3 week3/3.c)

add_executable(week4.1 week4/1.c)
add_executable(week4.2 week4/2.c)
add_executable(week4.3 week4/3.c)