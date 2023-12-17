SET (SRCs src/Block.cpp
          src/Board.cpp)

ADD_LIBRARY(model ${SRCs})

TARGET_LINK_LIBRARIES (model utils)

TARGET_INCLUDE_DIRECTORIES(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
