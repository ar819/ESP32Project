#include "altera_up_avalon_accelerometer_spi.h"
#include "altera_avalon_pio_regs.h"
#include <stdio.h>
#include <unistd.h>
#include "system.h"

int main() {
	alt_printf("Hello world\n");
    alt_32 x_read;
    alt_u16 button_read;
    alt_up_accelerometer_spi_dev * acc_dev;
    acc_dev = alt_up_accelerometer_spi_open_dev("/dev/accelerometer_spi_0");
    if (acc_dev == NULL) { // if return 1, check if the spi ip name is "accelerometer_spi"
    	return 1;
    }

    while (1) {
		alt_up_accelerometer_spi_read_x_axis(acc_dev, & x_read);
		button_read = IORD(SW_BASE,0);
		alt_printf("%x",button_read);
		alt_printf(" %x\n", x_read);
		usleep(5000);

    }

    return 0;
}

