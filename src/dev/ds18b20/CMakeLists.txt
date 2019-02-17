set(DS18B20_SRCS
    ds18b20.cpp
)

add_library(ds18b20 SHARED ${DS18B20_SRCS})
target_link_libraries(ds18b20 Qt5::Core)
