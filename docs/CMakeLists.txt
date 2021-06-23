cmake_minimum_required(VERSION 3.10)

project(Light2D_Doc)

##### Utils package
find_package(Doxygen)

set(DOXYGEN_EXCLUDE_PATTERNS "*/third_party/*")

if(DOXYGEN_FOUND)
    doxygen_add_docs(   docs ${CMAKE_CURRENT_SOURCE_DIR}/../src
                        COMMENT "Generating Doxygen documentation")
endif()
