set(SRC linkedlist.cc)
add_library(DataStructures STATIC ${SRC})
target_include_directories(DataStructures PUBLIC "./")

add_executable(linkedlisttest linkedlisttest.cc)
target_include_directories(linkedlisttest PUBLIC "./")
target_link_libraries(linkedlisttest PUBLIC DataStructures Catch2::Catch2)
