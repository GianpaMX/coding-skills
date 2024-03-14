set(SRC linkedlist.cc)
add_library(DataStructures STATIC ${SRC})
target_include_directories(DataStructures PUBLIC "./")
