#include <stdio.h>



/* 
To DO 
1. Set up the freertos environment
2. Setup freertos and test
3. setup a webserver UI free rtos process to initialise the controlled area data structure and view the relevant data on the UI
4. setup a free rtos process for the main control loop to:
    a. use littleFS to store a linked list of all the controlled areas - setup via te webUI
    b. at startup read the linked list into RAM - if there is 1 or more controlled area setup go to the main loop. Otherwise os sleep and poll until a contolled area is present in littlefs
    c. in the main loop traverse the linked list, reading the moisture levels and turning on and off the water based on the water_on and water_of thresholds
    d. os sleep 30 second


*/