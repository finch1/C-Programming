/*
 * timer.c
 *
 *  Created on: 27 May 2018
 *      Author: GOKU
 */

#include "timer.h"
#include <altera_avalon_timer_regs.h>

	static void clrTO(struct Timer *this){
		IOWR_ALTERA_AVALON_TIMER_STATUS(this->timer_base, 0x0000);
	}

#ifdef FULL_PERIPH
	/*
	 * Read Status Register
	 */
	static alt_u16 getSR(struct Timer *this){
		return IORD_ALTERA_AVALON_TIMER_STATUS(this->timer_base);
	}

	/*
	 * Clear Control Register
	 */
	static void clrCR(struct Timer *this){
		IOWR_ALTERA_AVALON_TIMER_CONTROL(this->timer_base, 0x0000);
	}

	/*
	 * Control Register bit 0 - RW
	 * If the ITO bit is 1, the interval timer core generates an IRQ when the status register’s TO
	 * bit is 1. When the ITO bit is 0, the timer does not generate IRQs.
	*/
	static void setITO(struct Timer *this){
		//alt_u16 data = (1 << ALTERA_AVALON_TIMER_CONTROL_ITO_OFST) | ALTERA_AVALON_TIMER_CONTROL_ITO_MSK;
		alt_u16 data |= IORD_ALTERA_AVALON_TIMER_CONTROL(this->timer_base);
		IOWR_ALTERA_AVALON_TIMER_CONTROL(this->timer_base, (data | ALTERA_AVALON_TIMER_CONTROL_ITO_MSK));
	}

	static void clrITO(struct Timer *this){
		alt_u16 data = (0 << ALTERA_AVALON_TIMER_CONTROL_ITO_OFST) | ALTERA_AVALON_TIMER_CONTROL_ITO_MSK;
		data |= IORD_ALTERA_AVALON_TIMER_CONTROL(this->timer_base);
		IOWR_ALTERA_AVALON_TIMER_CONTROL(this->timer_base, data);
	}

	/*
	 * Control Register bit 1 - RW
	 * The CONT (continuous) bit determines how the internal counter behaves when it reaches zero. If the
	 * CONT bit is 1, the counter runs continuously until it is stopped by the STOP bit. If CONT
	 * is 0, the counter stops after it reaches zero. When the counter reaches zero, it reloads with the
	 * value stored in the period registers, regardless of the CONT bit
	*/
	static void setContinuous(struct Timer *this){
		alt_u16 data = (1 << ALTERA_AVALON_TIMER_CONTROL_CONT_OFST) | ALTERA_AVALON_TIMER_CONTROL_CONT_MSK;
		data |= IORD_ALTERA_AVALON_TIMER_CONTROL(this->timer_base);
		IOWR_ALTERA_AVALON_TIMER_CONTROL(this->timer_base, data);
	}

	static void clrContinuous(struct Timer *this){
		alt_u16 data = (0 << ALTERA_AVALON_TIMER_CONTROL_CONT_OFST) | ALTERA_AVALON_TIMER_CONTROL_CONT_MSK;
		data |= IORD_ALTERA_AVALON_TIMER_CONTROL(this->timer_base);
		IOWR_ALTERA_AVALON_TIMER_CONTROL(this->timer_base, data);
	}

	/*
	 * Control Register bit 2 - W
	 * Writing a 1 to the START bit starts the internal counter running(counting down). The START
	 * bit is an event bit that enables the counter when a write operation is performed. If the timer
	 * is stopped, writing a 1 to the START bit causes the timer to restart counting from the number
	 * currently stored in its counter. If the timer is already running, writing a 1 to START has no
	 * effect. Writing 0 to the START bit has no effect
	*/
	static void setStart(struct Timer *this){
		// shift the set bit by offset, then set bit
		alt_u16 data = (1 << ALTERA_AVALON_TIMER_CONTROL_START_OFST) | ALTERA_AVALON_TIMER_CONTROL_START_MSK;
		data |= IORD_ALTERA_AVALON_TIMER_CONTROL(this->timer_base);
		IOWR_ALTERA_AVALON_TIMER_CONTROL(this->timer_base, data);
	}

	/*
	 * Control Register bit 3 - W
	 * Writing a 1 to the STOP bit stops the internal counter. The STOP bit is an event bit that causes
	 * the counter to stop when a write operation is performed. If the timer is already stopped, writing
	 * a 1 to STOP has no effect. Writing a 0 to the stop bit has no effect. If the timer hardware is
	 * configured with Start/Stop control bits off,writing the STOP bit has no effect.
	*/
	static void setStop(struct Timer *this){
		alt_u16 data = (1 << ALTERA_AVALON_TIMER_CONTROL_STOP_OFST) | ALTERA_AVALON_TIMER_CONTROL_STOP_MSK;
		data |= IORD_ALTERA_AVALON_TIMER_CONTROL(this->timer_base);
		IOWR_ALTERA_AVALON_TIMER_CONTROL(this->timer_base, data);
	}

	/*
	 * Status Register bit 0 - RC
	 * The TO (timeout) bit is set to 1 when the internal counter reaches zero. Once set by a timeout event,
	 * the TO bit stays set until explicitly cleared by a master peripheral. Write zero to the status
	 * register to clear the TO bit.
	*/
	static alt_u16 getTO(struct Timer *this){
		alt_u16 data = IORD_ALTERA_AVALON_TIMER_STATUS(this->timer_base) & ALTERA_AVALON_TIMER_STATUS_TO_MSK;
		data = (data >> ALTERA_AVALON_TIMER_STATUS_TO_OFST);
		return data;
	}



	/*
	 * Status Register bit 1 - R
	 * The RUN bit reads as 1 when the internal counter is running; otherwise this bit reads as 0. The
	 * RUN bit is not changed by a write operation to the status register.
	*/
	static alt_u16 getRUN(struct Timer *this){
		alt_u16 data = IORD_ALTERA_AVALON_TIMER_STATUS(this->timer_base) & ALTERA_AVALON_TIMER_STATUS_RUN_MSK;
		data = (data >> ALTERA_AVALON_TIMER_STATUS_RUN_OFST);
		return data;
	}

	/*
	 * Period Registers - W
	 * The period_n registers together store the timeout period value.
	*/
	static void setPeriod(struct Timer *this, alt_u32 period){

		alt_u16 data = (alt_u16)(period & 0x0000FFFF);
		IOWR_ALTERA_AVALON_TIMER_PERIODL(this->timer_base, data);
		data =  (alt_u16)(period & 0xFFFF0000) >> 16;
		IOWR_ALTERA_AVALON_TIMER_PERIODH(this->timer_base, data);
	}

	/*
	 * Snap Register bit 1 - R
	 * A master peripheral may request a coherent snapshot of the current internal counter by performing a
	 * write operation (write-data ignored) to one of the snap_n registers. When a write occurs, the
	 * value of the counter is copied to snap_n registers. The snapshot occurs whether or not the counter
	 * is running. Requesting a snapshot does not change the internal counter's operation.
	*/
	static alt_u32 getSnap(struct Timer *this){
	alt_u16 data_h = IORD_ALTERA_AVALON_TIMER_SNAPH(this->timer_base);
	alt_u16 data_l = IORD_ALTERA_AVALON_TIMER_SNAPL(this->timer_base);
	return 	(data_h << 16) | data_l;
}
#else
	static void init(struct Timer *this, alt_u8 start, alt_u8 cont, alt_u8 ito, alt_u32 period){

		alt_u16 data = (alt_u16)(period & 0x0000FFFF);
		IOWR_ALTERA_AVALON_TIMER_PERIODL(this->timer_base, data);
		data =  (alt_u16)(period & 0xFFFF0000) >> 16;
		IOWR_ALTERA_AVALON_TIMER_PERIODH(this->timer_base, data);

		data = 0;

		data = (cont << ALTERA_AVALON_TIMER_CONTROL_CONT_OFST) | ALTERA_AVALON_TIMER_CONTROL_CONT_MSK;
		data = (ito << ALTERA_AVALON_TIMER_CONTROL_ITO_OFST) | ALTERA_AVALON_TIMER_CONTROL_ITO_MSK;
		data = (1 << ALTERA_AVALON_TIMER_CONTROL_START_OFST) | ALTERA_AVALON_TIMER_CONTROL_START_MSK;
		IOWR_ALTERA_AVALON_TIMER_CONTROL(this->timer_base, data);
	}
#endif
/*
 * New Timer Instance
 * Returns a struct instance for a timer with variables and methods.
*/
static struct Timer new(alt_u32 base){
										return(struct Timer){
																					.timer_base = base,
																					.clrTO = &clrTO,
																#ifdef FULL_PERIPH
																					.getSR = &getSR,
																					.clrCR = &clrCR,
																					.setITO = &setITO,
																					.clrITO = &clrITO,
																					.setContinuous = &setContinuous,
																					.clrContinuous = &clrContinuous,
																					.setStart = &setStart,
																					.setStop = &setStop,
																					.getTO = &getTO,
																					.getRUN = &getRUN,
																					.setPeriod = &setPeriod,
																					.getSnap = &getSnap};
																#else
																					.init = &init};
																#endif
}

const struct TimerClass Timer = {.new = &new};

