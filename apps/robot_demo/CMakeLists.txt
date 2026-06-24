add_executable(
    robot_demo

    main.c
    robot_demo.c

    ${PROJECT_SOURCE_DIR}/drivers/imu/imu_sim/imu_sim.c
    ${PROJECT_SOURCE_DIR}/drivers/encoder/encoder_sim/encoder_sim.c
    ${PROJECT_SOURCE_DIR}/drivers/motor/motor_sim/motor_sim.c

    ${PROJECT_SOURCE_DIR}/modules/lipo_battery/lipo_battery.c

    ${PROJECT_SOURCE_DIR}/services/logger/logger.c
    ${PROJECT_SOURCE_DIR}/services/time/time.c
    ${PROJECT_SOURCE_DIR}/services/scheduler/scheduler.c

    ${PROJECT_SOURCE_DIR}/platform/linux/platform_linux.c
)

target_include_directories(
    robot_demo
    PRIVATE

    ${PROJECT_SOURCE_DIR}/drivers/imu/imu_sim
    ${PROJECT_SOURCE_DIR}/drivers/encoder/encoder_sim
    ${PROJECT_SOURCE_DIR}/drivers/motor/motor_sim

    ${PROJECT_SOURCE_DIR}/modules/lipo_battery

    ${PROJECT_SOURCE_DIR}/services/logger
    ${PROJECT_SOURCE_DIR}/services/time
    ${PROJECT_SOURCE_DIR}/services/scheduler

    ${PROJECT_SOURCE_DIR}/platform
    ${PROJECT_SOURCE_DIR}/platform/linux

    ${PROJECT_SOURCE_DIR}/apps/robot_demo

    ${PROJECT_SOURCE_DIR}/core/module_manager
)