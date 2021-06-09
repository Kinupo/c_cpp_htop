set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(user_lib "")

target_include_directories(
    user_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    user_lib 
    PRIVATE
        user.cpp
        user_repository.cpp
        ${INCLUDE_PATH}/system/user/user.h
        ${INCLUDE_PATH}/system/user/user_repository.h)