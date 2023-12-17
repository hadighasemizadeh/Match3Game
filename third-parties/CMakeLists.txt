INCLUDE(ExternalProject)

SET(ExternalDependencies Freetype SDL2 SDL2_image SDL2_ttf)
SET(FREETYPE_LIBRARY freetype${STATIC_LIB_EXTENSION})

SET(FREETYPE_INCLUDE_DIRS ${EXTERNAL_DEPENDENCIES}/Freetype-install/include/freetype2 CACHE PATH "Path to FreeType include directory")
SET(SDL2_INCLUDE_DIRS ${EXTERNAL_DEPENDENCIES}/SDL2-install/include/SDL2 CACHE PATH "Path to SDL2 include directory")
SET(SDL2_IMAGE_INCLUDE_DIRS ${EXTERNAL_DEPENDENCIES}/SDL2_image-install/include/SDL2 CACHE PATH "Path to SDL2 image include directory")
SET(SDL2_TTF_INCLUDE_DIRS ${EXTERNAL_DEPENDENCIES}/SDL2_ttf-install/include/SDL2 CACHE PATH "Path to SDL2 ttf include directory")

# Download and build FreeType (required by SDL2_ttf)
ExternalProject_Add(
    Freetype
    URL https://download.savannah.gnu.org/releases/freetype/freetype-2.13.2.tar.gz
    PREFIX ${CMAKE_BINARY_DIR}/Freetype
    CMAKE_ARGS 
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX=${EXTERNAL_DEPENDENCIES}/Freetype-install
        -DFREETYPE_LIBRARY=Freetype${STATIC_LIB_EXTENSION}
)

# Download and build SDL2
ExternalProject_Add(
    SDL2
    PREFIX ${CMAKE_BINARY_DIR}/SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.28.5  # SDL2 release version
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX=${EXTERNAL_DEPENDENCIES}/SDL2-install
)

# Download and build SDL2 Image
ExternalProject_Add(
    SDL2_image
    PREFIX ${CMAKE_BINARY_DIR}/SDL2_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG  release-2.8.0 # SDL2 image release version
    CMAKE_ARGS 
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX=${EXTERNAL_DEPENDENCIES}/SDL2_image-install
        -DSDL2_DIR=${EXTERNAL_DEPENDENCIES}/SDL2-install/cmake 
        -DSDL2_INCLUDE_DIR=${SDL2_INCLUDE_DIRS} 
        -DSDL2_LIBRARY=SDL2${STATIC_LIB_EXTENSION}
)

# Download and build SDL2_ttf
ExternalProject_Add(
    SDL2_ttf
    URL https://libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.20.2.zip
    PREFIX ${CMAKE_BINARY_DIR}/SDL2_ttf
    CMAKE_ARGS 
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX=${EXTERNAL_DEPENDENCIES}/SDL2_ttf-install
        -DSDL2_DIR=${EXTERNAL_DEPENDENCIES}/SDL2-install/cmake 
        -DSDL2_image_DIR=${EXTERNAL_DEPENDENCIES}/SDL2_image-install/cmake
        -DFreetype_DIR=${EXTERNAL_DEPENDENCIES}/Freetype-install/cmake
        -DSDL2_LIBRARY=SDL2_ttf${CMAKE_STATIC_LIBRARY_SUFFIX}
)
