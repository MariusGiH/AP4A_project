cmake_minimum_required(VERSION 3.29)
project(projet_badges_ap4a)

set(CMAKE_CXX_STANDARD 17)

add_executable(projet_badges_ap4a main.cpp
        Scheduler.cpp
        Scheduler.h
        Server.cpp
        Server.h
        LecteurBadge.cpp
        LecteurBadge.h
        Badge.cpp
        Badge.h
        Cpp/Badge.cpp
)
