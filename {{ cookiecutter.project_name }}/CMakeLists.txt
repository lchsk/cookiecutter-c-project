# TODO: tests, libs, format

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project({{ cookiecutter.project_name }})

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type (Debug or Release)" FORCE)
endif()

set(PROJECT_VERSION "1.0.0")

if (CMAKE_BUILD_TYPE STREQUAL Debug)
  set(CMAKE_C_FLAGS "-g -Wall -pedantic -O0")
else()
  set(CMAKE_C_FLAGS "-Wall -pedantic -O3")
endif()

# CPack

{% if cookiecutter.use_cpack == 'y' -%}

set(CPACK_PACKAGE_CONTACT "")
set(CPACK_GENERATOR "DEB;RPM;ZIP;TGZ")
set(CPACK_PACKAGE_DESCRIPTION, "{{ cookiecutter.project_short_description }}")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

# DEB package
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "http://xstarter.org")

# DEB package dependencies e.g. libncurses5 (>= 5.0), libglib2.0-0 (>= 2.0)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libncurses5 (>= 5.0), libglib2.0-0 (>= 2.0)")

# RPM package
set(CPACK_RPM_PACKAGE_LICENSE "{{ cookiecutter.license}}")
set(CPACK_RPM_PACKAGE_URL "")
set(CPACK_RPM_PACKAGE_DESCRIPTION "{{ cookiecutter.project_short_description }}")

# RPM package dependencies e.g. ncurses >= 5.0, glib2 >= 2.0
set(CPACK_RPM_PACKAGE_REQUIRES "")

include(CPack)

{% endif -%}

# End CPack

set(CMAKE_C_STANDARD {{ cookiecutter.c_standard }})

# find_package(Curses REQUIRED)
# find_package(Glib REQUIRED)

message(STATUS "CMake build type: " ${CMAKE_BUILD_TYPE})

# include_directories(
  # ${Glib_INCLUDE_DIRS}
  # ${CURSES_INCLUDE_DIR}
# )

file(GLOB SOURCES "src/*.h" "src/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})

# target_link_libraries(xstarter
  # ${Glib_LIBRARIES}
  # ${CURSES_LIBRARIES}
  # -lncurses
  # -pthread
# )

# install(TARGETS xstarter DESTINATION bin)

# install(FILES xstarter.1 DESTINATION share/man/man1)

# uninstall target
# configure_file(
  # "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  # "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  # IMMEDIATE @ONLY
# )

# add_custom_target(uninstall
  # COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake
# )

# add_custom_target(check ./tests/xstarter_tests ${CMAKE_CTEST_COMMAND})
