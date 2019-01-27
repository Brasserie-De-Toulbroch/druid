set(DRUID_DB_SRCS
    db.cpp
    recipe.cpp
)

add_library(druid_db ${DRUID_DB_SRCS})
target_link_libraries(druid_db Qt5::Core sqlite3)
