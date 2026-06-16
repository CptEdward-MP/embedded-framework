cmake_minimum_required(VERSION 3.16)

project(EmbeddedFramework C)

set(CMAKE_C_STANDARD 99)

add_executable(health_monitor
    apps/health_monitor/main.c

    platform/linux/platform_linux.c

    osal/posix/osal_posix.c

    services/logger/logger.c

    modules/lipo_battery/lipo_battery.c

    core/module_manager/module_manager.c
)


target_include_directories(health_monitor PRIVATE
    platform
    platform/linux

    osal

    services/logger

    modules/lipo_battery

    core/module_manager
)
