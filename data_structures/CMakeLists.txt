file(GLOB SOURCE source/*.cpp)
add_library(data_structures STATIC ${SOURCE})
target_include_directories(data_structures PUBLIC include)
