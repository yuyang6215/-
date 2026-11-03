cmake_minimum_required(VERSION 3.20)

project(BookManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BookManager
	main.cpp
	BookManager.cpp
	FileStorage.cpp
	Book.cpp
)
