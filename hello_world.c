/*
#include <stdio.h>
#include "io.h"
#include "alt_types.h"
#include "system.h"
#include "altera_avalon_jtag_uart_regs.h"
#include "include\timer.h"
#include "sys/alt_irq.h"


void led_flash_v0(alt_u32 led_base){
	static alt_u8 led_pattern = 0x01;
	static alt_u8 dir = 0;

	if(dir){
		led_pattern >>=0x01;
		if(led_pattern == 0x01){
			dir = 0;
		}
	}else{
		led_pattern <<=0x01;
		if(led_pattern == 0x80){
			dir = 1;
		}
	}
	IOWR(led_base, 0, led_pattern);
}

// write your ISR that handles hardware interrupts for a specific device

static void isr_func(void* context){
	struct Timer* t_ptr = context;
	// clear peripheral interrupt
	t_ptr->clrTO(t_ptr);
	// do something
	led_flash_v0(LED_BASE);
}

int main()
{


	printf("Hello from NIOS II! AGAINNN\n");

	// new Timer instance
	struct Timer t_0 = Timer.new(TIMER_0_BASE);
	// ensure that your program registers the ISR with the HAL by calling the alt_ic_isr_register()
	// alt_ic_isr_register() enables interrupts
	alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ, &isr_func, &t_0, (alt_u8*) 0x0);

	// continuous,
	t_0.init(&t_0, 1, 1, 1, 0x0000FFFF);


//	int prd = 0;
//	while(1){
//	  led_flash_v0(LED_BASE);
//	  while(prd < 50000){
//		  prd++;
//	  }
//	  prd = 0;
//	}

	return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include "sys/alt_dma.h"
#include "system.h"

static volatile int rx_done = 0;

/* Callback function that obtains notification that the data is received */
static void done(void* handle, void* data){
	rx_done++;
}

int main(){
	int rc;
	alt_dma_txchan txchan;
	alt_dma_rxchan rxchan;

	void* tx_data = (void*) 0x0000A000; /* pointer to data to send */
	void* rx_buffer = (void*) 0x0000B000; /* pointer to rx buffer */

	/* Create the transmit channel */
	if((txchan = alt_dma_txchan_open("/dev/dma")) == NULL){
		printf("Failed to open transmit channel\n");
		exit(1);
	}
	/* Create the receive channel */
	if((rxchan = alt_dma_rxchan_open("/dev/dma")) == NULL){
		printf("Failed to open receive channel\n");
		exit(1);
	}

	/* Post the transmit request */
	if((rc = alt_dma_txchan_send(txchan, tx_data, 128, NULL, NULL)) < 0){
		printf("Failed to open transmit request, reason = %i\n", rc);
		exit(1);
	}

	/* Post the receive request */
	if((rc = alt_dma_rxchan_prepare(rxchan, rx_buffer, 128, done, NULL)) < 0){
		printf("Failed to open read request, reason = %i\n", rc);
		exit(1);
	}

	/* wait for transfer to complete */
	while(!rx_done);
	printf("Transfer successful!\n");

	return 0;
}
