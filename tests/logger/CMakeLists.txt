add_executable(
    logger_test

    main.c

    # Services
    ${PROJECT_SOURCE_DIR}/services/logger/logger.c

    # Platform
    ${PROJECT_SOURCE_DIR}/platform/linux/platform_linux.c
)

target_include_directories(
    logger_test
    PRIVATE

    # Services
    ${PROJECT_SOURCE_DIR}/services/logger

    # Platform
    ${PROJECT_SOURCE_DIR}/platform
    ${PROJECT_SOURCE_DIR}/platform/linux
)