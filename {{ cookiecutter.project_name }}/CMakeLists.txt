# TODO: tests

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Name of the project
project({{ cookiecutter.project_name }})

# Set default build type to Debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type (Debug or Release)" FORCE)
endif()

message(STATUS "CMake build type: " ${CMAKE_BUILD_TYPE})

# Version of the project
set(PROJECT_VERSION "1.0.0")

# If build type is Debug, generate debugging information and don't optimise
if (CMAKE_BUILD_TYPE STREQUAL Debug)
  add_definitions(-O0)
  set(CMAKE_C_FLAGS "-g -Wall -pedantic")
else()
  add_definitions(-O3)
  set(CMAKE_C_FLAGS "-Wall -pedantic")
endif()

{% if cookiecutter.use_cpack == 'y' -%}
# CPack

set(CPACK_PACKAGE_CONTACT "<your email>")
set(CPACK_GENERATOR "DEB;RPM;ZIP;TGZ")
set(CPACK_PACKAGE_DESCRIPTION, "{{ cookiecutter.project_short_description }}")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

# DEB package
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "<project website>")

# DEB package dependencies e.g. libncurses5 (>= 5.0), libglib2.0-0 (>= 2.0)
# List of dependencies for a DEB package
# E.g.: libncurses5 (>= 5.0), libglib2.0-0 (>= 2.0)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")

# RPM package
set(CPACK_RPM_PACKAGE_LICENSE "{{ cookiecutter.license}}")
set(CPACK_RPM_PACKAGE_URL "<project website>")
set(CPACK_RPM_PACKAGE_DESCRIPTION "{{ cookiecutter.project_short_description }}")

# List of dependencies for an RPM package
# E.g.: ncurses >= 5.0, glib2 >= 2.0
set(CPACK_RPM_PACKAGE_REQUIRES "")

include(CPack)

# End CPack
{% endif -%}

# C standard for the compiler to use
set(CMAKE_C_STANDARD {{ cookiecutter.c_standard }})

# Source code files, all .h and .c files from src/ directory are included
file(GLOB SOURCES "src/*.h" "src/*.c")

# Executable name
add_executable(${PROJECT_NAME} ${SOURCES})


############################################
#                                          #
#              Dependencies                #
#                                          #
############################################

find_package(PkgConfig)

pkg_check_modules(PKG_CONFIG "pkg-config")

{% if cookiecutter.add_glib == 'y' -%}
pkg_check_modules(GLIB "glib-2.0")
{% endif -%}

{% if cookiecutter.add_curses == 'y' -%}
pkg_check_modules(CURSES "ncurses")
{% endif -%}


include_directories(
  {% if cookiecutter.add_glib == 'y' -%}
  ${GLIB_INCLUDE_DIRS}
  {% endif -%}

  {% if cookiecutter.add_curses == 'y' -%}
  ${CURSES_INCLUDE_DIRS}
  {% endif -%}
  )

link_directories(
  {% if cookiecutter.add_glib == 'y' -%}
  ${GLIB_LIBRARY_DIRS}
  {% endif -%}

  {% if cookiecutter.add_curses == 'y' -%}
  ${CURSES_LIBRARY_DIRS}
  {% endif -%}
  )

add_definitions(
  {% if cookiecutter.add_glib == 'y' -%}
  ${GLIB_CFLAGS_OTHER}
  {% endif -%}

  {% if cookiecutter.add_curses == 'y' -%}
  ${CURSES_CFLAGS_OTHER}
  {% endif -%}
  )

target_link_libraries(${PROJECT_NAME}
  {% if cookiecutter.add_glib == 'y' -%}
  ${GLIB_LIBRARIES}
  {% endif -%}

  {% if cookiecutter.add_curses == 'y' -%}
  ${CURSES_LIBRARIES}
  {% endif -%}
  )


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
