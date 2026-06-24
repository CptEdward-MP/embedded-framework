#include "logger.h"
#include "scheduler.h"

#include "platform.h"

#include "imu_sim.h"
#include "encoder_sim.h"
#include "motor_sim.h"

#include "robot_demo.h"

static void IMUTask(
    void *context)
{
//============  Debug ===================//
    Log_Info("IMU Task");
//=======================================//

    robot_demo_t *robot =
        context;

    IMUSim_Update();

    robot->yaw =
        IMUSim_GetYaw();
}


static void EncoderTask(
    void *context)
{

    //=============== Debug ===============//
    Log_Info("Encoder Task");
    //=====================================//


    robot_demo_t *robot =
        context;

    EncoderSim_Update();

    robot->left_encoder =
        EncoderSim_GetLeft();

    robot->right_encoder =
        EncoderSim_GetRight();
}


static void ControlTask(
    void *context)
{

    //================  Debug =============//
    Log_Info("Control Task");
    //=====================================//


    robot_demo_t *robot =
        context;

    robot->left_motor =
        robot->yaw * 0.1f;

    robot->right_motor =
        robot->yaw * 0.1f;

    MotorSim_SetLeft(
        robot->left_motor);

    MotorSim_SetRight(
        robot->right_motor);
}


static void BatteryTask(
    void *context)
{

    //===================== debug ===============//
    Log_Info("Battery Task");
    //===========================================//


    static float voltage =
        13.5f;

    robot_demo_t *robot =
        context;

    voltage -= 0.05f;

    if (voltage < 9.0f)
    {
        voltage = 13.5f;
    }

    Platform_ADC_SetValue(
        0,
        voltage);

    LipoBattery_Update(
        &robot->battery);
}



static void TelemetryTask(
    void *context)
{

    //================== debug =====================//
    Log_Info("Telemetry Task");
    //==============================================//


    robot_demo_t *robot =
        context;

    lipo_battery_data_t battery =
        LipoBattery_GetData(
            &robot->battery);

    Log_Info(
        "Yaw=%.2f EncL=%d EncR=%d MotorL=%.2f MotorR=%.2f Battery=%.2fV",
        robot->yaw,
        robot->left_encoder,
        robot->right_encoder,
        robot->left_motor,
        robot->right_motor,
        battery.voltage);
}


int main(void)
{
    robot_demo_t robot;

    IMUSim_Init();
    EncoderSim_Init();
    MotorSim_Init();

    RobotDemo_Init(
        &robot);

    Scheduler_Init();

   Scheduler_RegisterTask(
    IMUTask,
    &robot,
    100);

Scheduler_RegisterTask(
    EncoderTask,
    &robot,
    200);

Scheduler_RegisterTask(
    ControlTask,
    &robot,
    500);

Scheduler_RegisterTask(
    BatteryTask,
    &robot,
    1000);

Scheduler_RegisterTask(
    TelemetryTask,
    &robot,
    2000);

    Log_Info(
        "=========== Robot Demo Started ============");

    float test = 13.5f;

Log_Info(
    "TEST FLOAT = %.2f",
    test);

    while (1)
    {
        Scheduler_Run();
    }

    return 0;
}