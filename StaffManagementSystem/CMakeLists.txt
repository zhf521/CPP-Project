cmake_minimum_required(VERSION 3.25.1)

project(workManager)

aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)
add_executable(workManager ${SRC_SUB} ${SRC_CUR})
include_directories(include)
