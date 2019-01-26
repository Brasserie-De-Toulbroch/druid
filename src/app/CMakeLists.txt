set(DRUID_GUI_SRCS
    main.cpp
    window.cpp
    central_widget.cpp
    timer.cpp
    volume.cpp
    notes.cpp
    menu.cpp
)

add_executable(druid ${DRUID_GUI_SRCS} ${PROJECT_SOURCE_DIR}/resources/style.qrc)
include_directories(${PROJECT_SOURCE_DIR}/src/)
target_link_libraries(druid Qt5::Widgets druid_db)
