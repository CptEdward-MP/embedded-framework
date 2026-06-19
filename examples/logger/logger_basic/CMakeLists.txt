add_executable(
    logger_basic

    main.c

    ${PROJECT_SOURCE_DIR}/services/logger/logger.c

    ${PROJECT_SOURCE_DIR}/platform/linux/platform_linux.c
)

target_include_directories(
    logger_basic
    PRIVATE

    ${PROJECT_SOURCE_DIR}/services/logger

    ${PROJECT_SOURCE_DIR}/platform
    ${PROJECT_SOURCE_DIR}/platform/linux
)