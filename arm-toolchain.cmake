set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(toolchain /root/buildroot-2017.08/output/host)
set(CMAKE_C_COMPILER ${toolchain}/bin/arm-buildroot-linux-uclibcgnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${toolchain}/bin/arm-buildroot-linux-uclibcgnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH ${toolchain})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_SYSROOT ${toolchain}/arm-buildroot-linux-uclibcgnueabihf/sysroot)
