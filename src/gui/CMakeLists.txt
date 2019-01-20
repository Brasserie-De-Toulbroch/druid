set(DRUID_GUI_SRCS
    main.cpp
    window.cpp
    central_widget.cpp
)

add_executable(druid ${DRUID_GUI_SRCS} ${PROJECT_SOURCE_DIR}/resources/style.qrc)
target_link_libraries(druid Qt5::Widgets)
