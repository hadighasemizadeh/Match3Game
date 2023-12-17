SET (SRCs   src/Renderer.cpp
            src/View.cpp)

ADD_LIBRARY(view    ${SRCs})

TARGET_LINK_LIBRARIES(  view  PUBLIC
                        utils
                        model
                        SDL2${STATIC_LIB_EXTENSION}
                        SDL2_image${STATIC_LIB_EXTENSION}
                        SDL2_ttf${CMAKE_STATIC_LIBRARY_SUFFIX}
)
TARGET_INCLUDE_DIRECTORIES(view PUBLIC
                                ${CMAKE_CURRENT_SOURCE_DIR}/include
                                ${FREETYPE_INCLUDE_DIRS}
                                ${SDL2_INCLUDE_DIRS}
                                ${SDL2_IMAGE_INCLUDE_DIRS}
                                ${SDL2_TTF_INCLUDE_DIRS}
)
