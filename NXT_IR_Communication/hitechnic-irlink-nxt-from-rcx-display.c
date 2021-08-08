#pragma config(Sensor, S3,     HTRCX,          sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * hitechnic-irlink-rcx.h provides an API for the HiTechnic IR Link Sensor to allow
 * communication between the NXT and RCX.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 * - Big thanks to Thorsten Benter for giving me one of his RCXs to work with!
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 16 September 2010
 * version 0.1
 *
 * DESCRIPTION:
 * This code waits to receive an IR signal from an RCX and displays the value.
 * Index 8 of the message (i.e. "msg[6]"), can be used to identify simple numeric messages sent from teh RCX.
 */

#include "hitechnic-irlink-rcx.h"

int newValue;
int lastValue;

task main () {
  tByteArray msg;
  eraseDisplay();
  displayCenteredBigTextLine(2, "RCX IR");
  displayCenteredBigTextLine(4, "Receiver");
  sleep(3000);
  eraseDisplay();
  while(true) {
  	// Read the message from the RCX and display
  	HTRCXreadResp(HTRCX, msg);
  	newValue =
  				msg[0] +
					msg[1] +
					msg[2] +
					msg[3] +
					msg[4] +
					msg[5] +
					msg[6] +
					msg[7] +
					msg[8] +
					msg[9] +
					msg[10] +
					msg[11] +
					msg[12] +
					msg[13] +
					msg[14] +
					msg[15]
					;
		if (newValue == lastValue) {
			//do nothing
		}
		else if (newValue != 0) {
			if(msg[6] != 0 && msg[6] < 100) {
				lastValue = newValue;
	  		eraseDisplay();
		  	playSound(soundBlip);
			  displayCenteredBigTextLine(4, "%d", msg[6]);
			}
			else {
				eraseDisplay();
		  	playSound(soundBlip);
				displayCenteredTextLine(4, "Bad Message");
			}
  	}
  	sleep(200);
  }
}
