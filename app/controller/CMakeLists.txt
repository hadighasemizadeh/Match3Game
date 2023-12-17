SET (SRCs   src/GameLogic.cpp
            src/NewGame.cpp
            src/InputCtrl.cpp
            src/Run.cpp)
            
ADD_LIBRARY(controller ${SRCs})

TARGET_LINK_LIBRARIES(controller PUBLIC utils model view)

TARGET_INCLUDE_DIRECTORIES(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
