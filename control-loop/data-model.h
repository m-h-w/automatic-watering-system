#ifndef data_model_h
#define data_model_h

#include <stdbool.h>
/* 
    Core data structure  that contains the status of the area being controlled:
    e.g plant pot or area of a flower or veg bed.
    This data structure is displaye on the UI and is initialised by the UI as part
    of the setup of a new controlled area
*/

typedef struct controlled_area_t{
    char name[32];                      /* arbitrary name for the UI */
    unsigned char id;                   /* The ID of the controoled area */
    struct controlled_area_t* next_ptr; /* this data structure is stored as a linked list*/
    float current_moisture;             /* The current moisture reading */
    float water_on;                     /* The moisture level at which the water tuns on */
    float water_off;                    /* the moisture level at which the water tuns off */
    bool water_valve_status;            /* the current status of the water valve */
}controlled_area_t;

/* The following data structures deal with sensor measurements, actuator drivers and remote sensor-driver pairs network locations on the RS-485 Modbus */

/* binds the controlled area to a network address */
typedef struct {
    unsigned char controled_area_id;        /* The id of the controlled area*/
    unsigned char network_adress;           /* The RS-485 Modbus address - 0 means the controlled area is local i.e not on the external bus */
}network_binding_t;

/*  Sensor information - the prototype uses this sensor https://www.amazon.co.uk/dp/B0BTHL6M19?ref=ppx_yo2ov_dt_b_fed_asin_title 
    need to try to make this data structure abstract enough to support different sensors.
*/

typedef struct {
    unsigned char controled_area_id;    /* The id of the controlled area */
    unsigned char adc_number;   
    unsigned char adc_channel;
    void * calibration_data;        /* leaving this abstract for now until calibration data understood better */             

}sensor_binding_t;

/* Actuators are much simpler - just a driver on a gpio pin */
typedef struct {
    unsigned char controled_area_id;    /* The id of the controlled area */
    unsigned char gpio_pin_number;
}actuator_binding_t;


#endif /* data_model_h */
