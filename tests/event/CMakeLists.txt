add_executable(
    event_test

    main.c

    # Services
    ${PROJECT_SOURCE_DIR}/services/event/event.c
    ${PROJECT_SOURCE_DIR}/services/logger/logger.c

    # Platform
    ${PROJECT_SOURCE_DIR}/platform/linux/platform_linux.c
)

target_include_directories(
    event_test
    PRIVATE

    # Services
    ${PROJECT_SOURCE_DIR}/services/event
    ${PROJECT_SOURCE_DIR}/services/logger

    # Platform
    ${PROJECT_SOURCE_DIR}/platform
    ${PROJECT_SOURCE_DIR}/platform/linux
)