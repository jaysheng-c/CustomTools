# 指引导航窗口，通过框选强调窗口组件

add_library(guide SHARED)
target_sources(guide PRIVATE guide_widget.cpp)
target_link_libraries(guide PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
)