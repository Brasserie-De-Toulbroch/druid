set(DRUID_GUI_SRCS
    main.cpp
    window.cpp
    central_widget.cpp
    timer.cpp
    volume.cpp
    temperature.cpp
)

add_executable(druid ${DRUID_GUI_SRCS} ${PROJECT_SOURCE_DIR}/resources/style.qrc)
include_directories(${PROJECT_SOURCE_DIR}/src/ ${QWT_INCLUDE_DIR})
target_link_libraries(druid Qt5::Widgets)
