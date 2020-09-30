/*
 * FreeRTOS+TCP Labs Build 160112 (C) 2016 Real Time Engineers ltd.
 * Authors include Hein Tibosch and Richard Barry
 *
 *******************************************************************************
 ***** NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ***
 ***                                                                         ***
 ***                                                                         ***
 ***   FREERTOS+TCP IS STILL IN THE LAB (mainly because the FTP and HTTP     ***
 ***   demos have a dependency on FreeRTOS+FAT, which is only in the Labs    ***
 ***   download):                                                            ***
 ***                                                                         ***
 ***   FreeRTOS+TCP is functional and has been used in commercial products   ***
 ***   for some time.  Be aware however that we are still refining its       ***
 ***   design, the source code does not yet quite conform to the strict      ***
 ***   coding and style standards mandated by Real Time Engineers ltd., and  ***
 ***   the documentation and testing is not necessarily complete.            ***
 ***                                                                         ***
 ***   PLEASE REPORT EXPERIENCES USING THE SUPPORT RESOURCES FOUND ON THE    ***
 ***   URL: http://www.FreeRTOS.org/contact  Active early adopters may, at   ***
 ***   the sole discretion of Real Time Engineers Ltd., be offered versions  ***
 ***   under a license other than that described below.                      ***
 ***                                                                         ***
 ***                                                                         ***
 ***** NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ***
 *******************************************************************************
 *
 * FreeRTOS+TCP can be used under two different free open source licenses.  The
 * license that applies is dependent on the processor on which FreeRTOS+TCP is
 * executed, as follows:
 *
 * If FreeRTOS+TCP is executed on one of the processors listed under the Special 
 * License Arrangements heading of the FreeRTOS+TCP license information web 
 * page, then it can be used under the terms of the FreeRTOS Open Source 
 * License.  If FreeRTOS+TCP is used on any other processor, then it can be used
 * under the terms of the GNU General Public License V2.  Links to the relevant
 * licenses follow:
 * 
 * The FreeRTOS+TCP License Information Page: http://www.FreeRTOS.org/tcp_license 
 * The FreeRTOS Open Source License: http://www.FreeRTOS.org/license
 * The GNU General Public License Version 2: http://www.FreeRTOS.org/gpl-2.0.txt
 *
 * FreeRTOS+TCP is distributed in the hope that it will be useful.  You cannot
 * use FreeRTOS+TCP unless you agree that you use the software 'as is'.
 * FreeRTOS+TCP is provided WITHOUT ANY WARRANTY; without even the implied
 * warranties of NON-INFRINGEMENT, MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. Real Time Engineers Ltd. disclaims all conditions and terms, be they
 * implied, expressed, or statutory.
 *
 * 1 tab == 4 spaces!
 *
 * http://www.FreeRTOS.org
 * http://www.FreeRTOS.org/plus
 * http://www.FreeRTOS.org/labs
 *
 */

#ifndef FREERTOS_DHCP_H
#define FREERTOS_DHCP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Application level configuration options. */
#include "FreeRTOSIPConfig.h"
#include "IPTraceMacroDefaults.h"

#if( ipconfigDHCP_USES_USER_HOOK != 0 )
	typedef enum eDHCP_QUESTIONS
	{
		eDHCPOffer,			/* Driver is about to ask for a DHCP offer. */
		eDHCPRequest,		/* Driver is about to request DHCP an IP address. */
	} eDHCPCallbackQuestion_t;

	typedef enum eDHCP_ANSWERS
	{
		eDHCPContinue,			/* Continue the DHCP process */
		eDHCPUseDefaults,		/* Stop DHCP and use the static defaults. */
		eDHCPStopNoChanges,		/* Stop DHCP and continue with current settings. */
	} eDHCPCallbackAnswer_t;
#endif	/* ipconfigDHCP_USES_USER_HOOK */

/*
 * NOT A PUBLIC API FUNCTION.
 */
void vDHCPProcess( portBASE_TYPE xReset );

/* Internal call: returns true if socket is the current DHCP socket */
portBASE_TYPE xIsDHCPSocket( Socket_t xSocket );

#if( ipconfigDHCP_USES_USER_HOOK != 0 )
	/* The following function must be provided by the user.
	The user may decide to continue or stop, after receiving a DHCP offer. */
	portBASE_TYPE xApplicationDHCPUserHook( eDHCPCallbackQuestion_t eQuestion,
		unsigned int ulIPAddress, unsigned int ulNetMask );
#endif	/* ipconfigDHCP_USES_USER_HOOK */

#ifdef __cplusplus
}	/* extern "C" */
#endif

#endif /* FREERTOS_DHCP_H */













