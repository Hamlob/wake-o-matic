cmake_minimum_required(VERSION 3.16)
include(ExternalProject)

project(Wake-o-matic-tests)


ExternalProject_Add(project_cppunit
  URL http://dev-www.libreoffice.org/src/cppunit-1.15.1.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/lib/cppunit-1.15.1
  CONFIGURE_COMMAND ""
  # BUILD_COMMAND make
  # INSTALL_COMMAND make install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/lib/cppunit-1.15.1
)

ExternalProject_Get_Property(project_cppunit install_dir)

add_library(cppunit STATIC IMPORTED)
set_property(TARGET cppunit PROPERTY IMPORTED_LOCATION ${install_dir}/lib/libcppunit)
add_dependencies(cppunit project_cppunit)

add_subdirectory(src)
include_directories(${install_dir}/include/cppunit-1.15.1)

target_link_libraries(wake-o-matic-tester LINK_PUBLIC cppunit)