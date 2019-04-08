add_definitions(-std=c++11)
file(GLOB SRC_LIST
    "*.hpp",
    "*.cpp")
file(GLOB HEADER_LIST "*.hpp")
add_executable(WordLists ${SRC_LIST})

add_library(IO STATIC trie.cpp IO.cpp)
add_library(alg STATIC algorithm.cpp)
add_library(trie STATIC trie.cpp)
add_library(interface STATIC interface.cpp)

target_link_libraries(interface PRIVATE trie IO alg)

if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    target_compile_options(IO PRIVATE --coverage)
    target_link_libraries(IO PRIVATE gcov)
    target_compile_options(alg PRIVATE --coverage)
    target_link_libraries(alg PRIVATE gcov)
    target_compile_options(interface PRIVATE --coverage)
    target_link_libraries(interface PRIVATE gcov)
endif()
#install(TARGETS WordLists DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/")

install(FILES type.hpp IO.hpp algorithm.hpp IO.cpp algorithm.cpp trie.hpp trie.cpp
        DESTINATION 
        "${CMAKE_SOURCE_DIR}/GUI/WordListsGui/WordLists/")