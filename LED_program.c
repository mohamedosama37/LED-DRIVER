/***************************************************************************************************************************************************/
/*AUTHOR   : MOHAMED OSAMA                                                                                                                          */
/*DATE     : 4 FEB 2019                                                                                                                             */
/*VERSION  : V01                                                                                                                                    */
/***************************************************************************************************************************************************/
/* DESCRIPTION                                                                                                                                       */
/*------------                                                                                                                                       */
/* this filedefines the implementation of both private and public functions                                                                          */
/*****************************************************************************************************************************************************/

#include "../04-LIB/01-STD_TYPES/STD_TYPES.h"

#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "DIO_interface.h"

/* comment : function used to turn on the led                                                                                                      */
u8 LED_u8Enable (void)
{
	u8 Locacl_u8ErrorState = 0;
	#if (  LED_u8CONNECTION_TYPE ==  LED_u8_FORWARD_CONNECTION)
	{
	  Locacl_u8ErrorState= u8 DIO_u8SetPinValue (LED_u8ConnectedPin , INPUT_HIGH);	
	}	
	#elif (LED_u8CONNECTION_TYPE == LED_u8_REVERSE_CONNECTION)
	{
	  Locacl_u8ErrorState= u8 DIO_u8SetPinValue (LED_u8ConnectedPin , INPUT_LOW);
	}
	#else
	{ Locacl_u8ErrorState = 1;
        
	}
	
 return 	Locacl_u8ErrorState;
}	

/* comment : function used to trun off the led                                                                                                     */
u8 LED_u8Disable (void)
{
	u8 Locacl_u8ErrorState = 0;
	#if (  LED_u8CONNECTION_TYPE ==  LED_u8_FORWARD_CONNECTION)
	{
	  Locacl_u8ErrorState= u8 DIO_u8SetPinValue (LED_u8ConnectedPin , INPUT_LOW);	
	}	
	#elif (LED_u8CONNECTION_TYPE == LED_u8_REVERSE_CONNECTION)
	{
	  Locacl_u8ErrorState= u8 DIO_u8SetPinValue (LED_u8ConnectedPin , INPUT_HIGH);
	}
	#else
	{ Locacl_u8ErrorState = 1;
        
	}
	
 return 	Locacl_u8ErrorState;
	
	
	
	
}	