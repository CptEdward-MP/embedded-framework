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

add_subdirectory(
    tests/event)







add_subdirectory(
    examples/logger/logger_basic)

add_subdirectory(
    tests/logger)







add_subdirectory(
    examples/module_manager/module_registration)

add_subdirectory(
    examples/module_manager/module_context)

add_subdirectory(
    tests/module_manager)








add_subdirectory(
    examples/lipo_battery/lipo_battery_basic)

add_subdirectory(
    tests/lipo_battery)






add_subdirectory(
    examples/time/time_basic)

add_subdirectory(
    tests/time)






add_subdirectory(
    examples/scheduler/scheduler_basic)

add_subdirectory(
    tests/scheduler)