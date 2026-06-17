cmake_minimum_required(VERSION 3.16)

project(EmbeddedFramework C)

set(CMAKE_C_STANDARD 99)

add_executable(health_monitor

    # Application
    apps/health_monitor/main.c

    # Core
    core/module_manager/module_manager.c

    # Modules
    modules/lipo_battery/lipo_battery.c

    # Services
    services/logger/logger.c

    # Platform
    platform/linux/platform_linux.c

    # OSAL
    osal/posix/osal_posix.c
)

target_include_directories(health_monitor PRIVATE

    # Core
    core/module_manager

    # Modules
    modules/lipo_battery

    # Services
    services/logger

    # Platform
    platform
    platform/linux

    # OSAL
    osal
    osal/posix
)

add_subdirectory(
    examples/event_basic)