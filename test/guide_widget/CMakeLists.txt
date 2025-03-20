
include_directories(${CMAKE_SOURCE_DIR}/src/modules)
link_directories(${CMAKE_BINARY_DIR}/src)

add_executable(testGuide main.cpp)
target_link_directories(testGuide PRIVATE ${CMAKE_BINARY_DIR}/src)
target_link_libraries(testGuide PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        guide
)

# 复制 guide 库到当前路径
add_custom_command(TARGET testGuide POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_BINARY_DIR}/src/${CMAKE_SHARED_LIBRARY_PREFIX}guide${CMAKE_SHARED_LIBRARY_SUFFIX}
        $<TARGET_FILE_DIR:testGuide>
)