add_executable(levelup-13-pairs 13-pairs.cc)
target_include_directories(levelup-13-pairs PUBLIC "./")
target_link_libraries(levelup-13-pairs PUBLIC Catch2::Catch2)

add_executable(levelup-15-triplets 15-triplets.cc)
target_include_directories(levelup-15-triplets PUBLIC "./")
target_link_libraries(levelup-15-triplets PUBLIC Catch2::Catch2)

add_executable(levelup-17-mountain 17-mountain.cc)
target_include_directories(levelup-17-mountain PUBLIC "./")
target_link_libraries(levelup-17-mountain PUBLIC Catch2::Catch2)

add_executable(levelup-19-longestband 19-longestband.cc)
target_include_directories(levelup-19-longestband PUBLIC "./")
target_link_libraries(levelup-19-longestband PUBLIC Catch2::Catch2)
