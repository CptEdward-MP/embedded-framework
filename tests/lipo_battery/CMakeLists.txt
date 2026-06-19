add_executable(
    lipo_battery_test

    main.c

    # Modules
    ${PROJECT_SOURCE_DIR}/modules/lipo_battery/lipo_battery.c

    # Services
    ${PROJECT_SOURCE_DIR}/services/logger/logger.c

    # Platform
    ${PROJECT_SOURCE_DIR}/platform/linux/platform_linux.c
)

target_include_directories(
    lipo_battery_test
    PRIVATE

    # Core
    ${PROJECT_SOURCE_DIR}/core/module_manager

    # Modules
    ${PROJECT_SOURCE_DIR}/modules/lipo_battery

    # Services
    ${PROJECT_SOURCE_DIR}/services/logger

    # Platform
    ${PROJECT_SOURCE_DIR}/platform
    ${PROJECT_SOURCE_DIR}/platform/linux
)