add_executable(
    scheduler_test

    main.c

    ${PROJECT_SOURCE_DIR}/services/scheduler/scheduler.c
    ${PROJECT_SOURCE_DIR}/services/time/time.c
    ${PROJECT_SOURCE_DIR}/services/logger/logger.c

    ${PROJECT_SOURCE_DIR}/platform/linux/platform_linux.c
)

target_include_directories(
    scheduler_test
    PRIVATE

    ${PROJECT_SOURCE_DIR}/services/scheduler
    ${PROJECT_SOURCE_DIR}/services/time
    ${PROJECT_SOURCE_DIR}/services/logger

    ${PROJECT_SOURCE_DIR}/platform
    ${PROJECT_SOURCE_DIR}/platform/linux
)