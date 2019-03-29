add_definitions(-std=c++11)
file(GLOB SRC_LIST
    "*.hpp",
    "*.cpp")
file(GLOB HEADER_LIST "*.hpp")
add_executable(WordLists ${SRC_LIST})

add_library(IO trie.cpp IO.cpp)
add_library(alg algorithm.cpp)
add_library(trie trie.cpp)

#install(TARGETS WordLists DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/")

install(FILES type.hpp IO.hpp algorithm.hpp IO.cpp algorithm.cpp trie.hpp trie.cpp
        DESTINATION 
        "${CMAKE_SOURCE_DIR}/GUI/WordListsGui/WordLists/")