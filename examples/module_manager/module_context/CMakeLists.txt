add_executable(
    module_context

    main.c

    # Core
    ${PROJECT_SOURCE_DIR}/core/module_manager/module_manager.c

    # Services
    ${PROJECT_SOURCE_DIR}/services/logger/logger.c

    # Platform
    ${PROJECT_SOURCE_DIR}/platform/linux/platform_linux.c
)

target_include_directories(
    module_context
    PRIVATE

    # Core
    ${PROJECT_SOURCE_DIR}/core/module_manager

    # Services
    ${PROJECT_SOURCE_DIR}/services/logger

    # Platform
    ${PROJECT_SOURCE_DIR}/platform
    ${PROJECT_SOURCE_DIR}/platform/linux
)