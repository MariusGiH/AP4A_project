cmake_minimum_required(VERSION 3.29)
project(AP4A_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(AP4A_project main.cpp
        Scheduler.cpp
        Scheduler.h
        Serveur.cpp
        Serveur.h
        LecteurBadge.cpp
        LecteurBadge.h
        Badge.cpp
        Badge.h
)
