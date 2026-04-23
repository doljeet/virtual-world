cmake_minimum_required(VERSION 3.10)
project(VirtualWorld)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Windows-only: conio.h is used for _getch() in main.cpp
if(NOT WIN32)
    message(WARNING "This project uses <conio.h> and _getch() which are Windows-only. Build may fail on Linux/macOS.")
endif()

include_directories(.)

add_executable(VirtualWorld
        main.cpp
        Organizm.cpp
        Organizm.h
        Swiat.cpp
        Swiat.h
        Czlowiek.cpp
        Czlowiek.h
        Zwierze.cpp
        Zwierze.h
        Roslina.cpp
        Roslina.h
        Wilk.cpp
        Wilk.h
        Owca.cpp
        Owca.h
        Lis.cpp
        Lis.h
        Zolw.cpp
        Zolw.h
        Antylopa.cpp
        Antylopa.h
        Trawa.cpp
        Trawa.h
        Mlecz.cpp
        Mlecz.h
        Guarana.cpp
        Guarana.h
        WilczeJagody.cpp
        WilczeJagody.h
        BarszczSosnowskiego.cpp
        BarszczSosnowskiego.h
)
