/**********************************************************************/
/* Author			: Badr Mohamed									  */
/* Date				: 20 May 2022									  */
/* Version 			: V01											  */
/**********************************************************************/



/*  
    Disable systick and systick interrupt 
    Determine Clock (AHB | AHB/8)
*/
void MSTK_voidInit(void);
/* Delay for number of ticks */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
/* Execute func (Copy_Ptr) after interval of ticks for single time */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_Ptr) (void));
/* Execute func (Copy_Ptr) after interval of ticks periodically */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_Ptr) (void));
/* Stop Interval and Timer */
void MSTK_voidStopInterval(void);
/* Get Remainig Ticks */
u32 MSTK_u32GetRemainingTicks(void);
/* Get Elapsed Ticks */
u32 MSTK_u32GetElapsedTicks(void);
