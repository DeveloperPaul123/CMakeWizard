cmake_minimum_required(VERSION 3.0)

project(CMakeWizard LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(ApplicationVersion)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(project_ui_forms ui/mainwindow.ui)

qt5_wrap_ui(ui_wrap ${project_ui_forms})
qt5_wrap_cpp(moc_sources src/mainwindow.h)

set(project_sources 
	src/mainwindow.cpp 
	src/main.cpp
	src/cmakeproject.cpp
	src/cmakeoption.cpp
	src/cmakepackage.cpp
	src/cmakelibrary.cpp)

set(project_headers 
	src/mainwindow.h
	src/cmakeproject.h
	src/cmakeoption.h
	src/cmakepackage.h
	src/cmakelibrary.h)

add_library(GUI STATIC ${ui_wrap} ${moc_sources})
target_link_libraries(GUI Qt5::Gui Qt5::Widgets Qt5::Core)
set_target_properties(GUI PROPERTIES LINKER_LANGUAGE "CXX")

add_executable(${PROJECT_NAME} ${project_sources} ${project_headers})

target_link_libraries(${PROJECT_NAME} GUI Qt5::Gui Qt5::Widgets Qt5::Core)

if (MSVC) 
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:${PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:${PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:${PROJECT_NAME}>
		)
endif(MSVC)