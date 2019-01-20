set(DRUID_GUI_SRCS
    main.cpp
    window.cpp
    central_widget.cpp
)

add_executable(druid ${DRUID_GUI_SRCS})
target_link_libraries(druid Qt5::Widgets)
