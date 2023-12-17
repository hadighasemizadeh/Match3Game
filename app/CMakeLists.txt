
ADD_EXECUTABLE(${EXECUTABLE_NAME} main.cpp)
SET(RESOURCE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)

# Add additional src subdirectories
ADD_SUBDIRECTORY(utils)
ADD_SUBDIRECTORY(model)
ADD_SUBDIRECTORY(view)
ADD_SUBDIRECTORY(controller)

SET(PROJECT_LIBRARIES model view controller utils)
TARGET_INCLUDE_DIRECTORIES( ${EXECUTABLE_NAME} PUBLIC
                            ${FREETYPE_INCLUDE_DIRS}
                            ${SDL2_INCLUDE_DIRS}
                            ${SDL2_IMAGE_INCLUDE_DIRS}
                            ${SDL2_TTF_INCLUDE_DIRS}
)

TARGET_LINK_DIRECTORIES(${EXECUTABLE_NAME}  PUBLIC 
                        ${EXTERNAL_DEPENDENCIES}/SDL2-install/lib/
                        ${EXTERNAL_DEPENDENCIES}/SDL2_image-install/lib/
                        ${EXTERNAL_DEPENDENCIES}/FreeType-install/lib/
                        ${EXTERNAL_DEPENDENCIES}/SDL2_ttf-install/lib/
)

TARGET_LINK_LIBRARIES(  ${EXECUTABLE_NAME} PUBLIC 
                        freetype${STATIC_LIB_EXTENSION}
                        SDL2${STATIC_LIB_EXTENSION}
                        SDL2_image${STATIC_LIB_EXTENSION}
                        SDL2_ttf${CMAKE_STATIC_LIBRARY_SUFFIX}
                        ${PROJECT_LIBRARIES}
)

# Install all dynamic libraries
FILE(GLOB RESOURCES "${CMAKE_CURRENT_SOURCE_DIR}/res/")
INSTALL(FILES 
            ${EXTERNAL_DEPENDENCIES}/SDL2-install/bin/SDL2${DYNAMIC_LIB_EXTENSION}
            ${EXTERNAL_DEPENDENCIES}/SDL2_image-install/bin/SDL2_image${DYNAMIC_LIB_EXTENSION}
            ${EXTERNAL_DEPENDENCIES}/SDL2_ttf-install/bin/SDL2_ttf${CMAKE_SHARED_LIBRARY_SUFFIX}
        DESTINATION 
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}
)

# Install resource directory
install(DIRECTORY 
            ${RESOURCE_SOURCE_DIR}
        DESTINATION 
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}
)
