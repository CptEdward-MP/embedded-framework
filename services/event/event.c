#include "event.h"

#include <stddef.h>

#define MAX_SUBSCRIPTIONS 20

/* Subscription entry */
typedef struct
{
    event_id_t id;

    event_callback_t callback;

    void *context;

} event_subscription_t;

/* Subscription registry */
static event_subscription_t
    subscriptions[MAX_SUBSCRIPTIONS];

static int subscription_count = 0;

/* Subscribe callback to event */
int Event_Subscribe(
    event_id_t id,
    event_callback_t callback,
    void *context)
{
    if (callback == NULL)
    {
        return EVENT_NULL;
    }

    /* Duplicate check */
    for (int i = 0;
         i < subscription_count;
         i++)
    {
        if ((subscriptions[i].id == id) &&
            (subscriptions[i].callback ==
             callback) &&
            (subscriptions[i].context ==
             context))
        {
            return EVENT_DUPLICATE;
        }
    }

    if (subscription_count >=
        MAX_SUBSCRIPTIONS)
    {
        return EVENT_FULL;
    }

    subscriptions[subscription_count].id =
        id;

    subscriptions[subscription_count]
        .callback = callback;

    subscriptions[subscription_count]
        .context = context;

    subscription_count++;

    return EVENT_OK;
}

/* Publish event */
int Event_Publish(
    const event_t *event)
{
    int notified = 0;

    if (event == NULL)
    {
        return EVENT_NULL;
    }

    for (int i = 0;
         i < subscription_count;
         i++)
    {
        if (subscriptions[i].id ==
            event->id)
        {
            subscriptions[i].callback(
                event,
                subscriptions[i].context);

            notified++;
        }
    }

    return notified;
}