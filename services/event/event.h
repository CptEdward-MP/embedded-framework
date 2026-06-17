#ifndef EVENT_H
#define EVENT_H

#include <stdint.h>

/* Event return codes */
#define EVENT_OK          0
#define EVENT_FULL       -1
#define EVENT_NULL       -2
#define EVENT_DUPLICATE  -3

/* Application-defined event identifier */
typedef uint32_t event_id_t;

/* Event object */
typedef struct
{
    event_id_t id;

} event_t;

/* Event callback */
typedef void (*event_callback_t)(
    const event_t *event,
    void *context);

/* Subscribe to event */
int Event_Subscribe(
    event_id_t id,
    event_callback_t callback,
    void *context);

/* Publish event
 *
 * Returns:
 * Number of subscribers notified
 */
int Event_Publish(
    const event_t *event);

#endif /* EVENT_H */