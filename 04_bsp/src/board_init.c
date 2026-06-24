#include "board_device.h"
#include "device.h"

device_t *board_device_table[DEV_ID_MAX];

void board_init(void) 
{
    const device_reg_entry_t *start = (const device_reg_entry_t *)&__device_reg_start;
    const device_reg_entry_t *end   = (const device_reg_entry_t *)&__device_reg_end;

    for (const device_reg_entry_t *entry = start; entry < end; entry++) 
    {
        if (entry->init) 
        {
            entry->init();
        }
    }
}
