cmake_minimum_required(VERSION 2.8)

project( DisplayImage )

find_package( OpenCV REQUIRED )

add_executable( DisplayImage testCV.cxx)

target_link_libraries( DisplayImage ${OpenCV_LIBS} )
