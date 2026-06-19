#include <stddef.h>

#include "event.h"
#include "logger.h"

/* Test event identifier */
#define EVENT_TEST  1

/* Test callback counter */
static int callback_count = 0;

/* Test callback */
static void TestHandler(
    const event_t *event,
    void *context)
{
    (void)event;
    (void)context;

    callback_count++;
}

/* Test successful subscription */
static void Test_SubscribeSuccess(void)
{
    int result =
        Event_Subscribe(
            EVENT_TEST,
            TestHandler,
            NULL);

    if (result == EVENT_OK)
    {
        Log_Info(
            "PASS: Subscribe Success");
    }
    else
    {
        Log_Error(
            "FAIL: Subscribe Success");
    }
}

/* Test duplicate subscription detection */
static void Test_DuplicateSubscribe(void)
{
    int result =
        Event_Subscribe(
            EVENT_TEST,
            TestHandler,
            NULL);

    if (result == EVENT_DUPLICATE)
    {
        Log_Info(
            "PASS: Duplicate Detection");
    }
    else
    {
        Log_Error(
            "FAIL: Duplicate Detection");
    }
}

/* Test NULL callback handling */
static void Test_NullCallback(void)
{
    int result =
        Event_Subscribe(
            EVENT_TEST,
            NULL,
            NULL);

    if (result == EVENT_NULL)
    {
        Log_Info(
            "PASS: NULL Callback");
    }
    else
    {
        Log_Error(
            "FAIL: NULL Callback");
    }
}

/* Test event publication */
static void Test_PublishEvent(void)
{
    callback_count = 0;

    event_t event =
    {
        .id = EVENT_TEST
    };

    int notified =
        Event_Publish(
            &event);

    if ((notified == 1) &&
        (callback_count == 1))
    {
        Log_Info(
            "PASS: Publish Event");
    }
    else
    {
        Log_Error(
            "FAIL: Publish Event");
    }
}

int main(void)
{
    Log_Info(
        "Starting Event Tests");

    Test_SubscribeSuccess();

    Test_DuplicateSubscribe();

    Test_NullCallback();

    Test_PublishEvent();

    Log_Info(
        "Event Tests Complete");

    return 0;
}