#include "event.h"
#include "logger.h"

#include <stddef.h>

/* Application-defined event identifier */
#define EVENT_BUTTON_PRESSED  1

/* Callback executed when button press event occurs */
void ButtonHandler(
    const event_t *event,
    void *context)
{
    (void)event;
    (void)context;

    Log_Info(
        "Button Event Received");
}

int main(void)
{
    /* Create event object */
    event_t button_event =
    {
        .id = EVENT_BUTTON_PRESSED
    };

    /* Register callback for button press event */
    Event_Subscribe(
        EVENT_BUTTON_PRESSED,
        ButtonHandler,
        NULL);

    /* Publish event and notify subscribers */
    int subscribers_notified =
        Event_Publish(
            &button_event);

    (void)subscribers_notified;

    return 0;
}