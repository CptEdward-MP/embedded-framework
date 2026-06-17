add_executable(
    event_basic

    main.c

    ${PROJECT_SOURCE_DIR}/services/event/event.c

    ${PROJECT_SOURCE_DIR}/services/logger/logger.c

    ${PROJECT_SOURCE_DIR}/platform/linux/platform_linux.c
)

target_include_directories(
    event_basic
    PRIVATE

    ${PROJECT_SOURCE_DIR}/services/event

    ${PROJECT_SOURCE_DIR}/services/logger

    ${PROJECT_SOURCE_DIR}/platform

    ${PROJECT_SOURCE_DIR}/platform/linux
)