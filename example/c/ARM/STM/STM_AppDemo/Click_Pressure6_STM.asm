_systemInit:
;Click_Pressure6_STM.c,34 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Pressure6_STM.c,36 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #7
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Pressure6_STM.c,37 :: 		mikrobus_i2cInit( _MIKROBUS1, &_PRESSURE6_I2C_CFG[0] );
MOVW	R0, #lo_addr(__PRESSURE6_I2C_CFG+0)
MOVT	R0, #hi_addr(__PRESSURE6_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Pressure6_STM.c,38 :: 		mikrobus_logInit( _LOG_USBUART_A, 115200 );
MOV	R1, #115200
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Pressure6_STM.c,39 :: 		mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_Pressure6_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_Pressure6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Pressure6_STM.c,40 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Pressure6_STM.c,41 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Pressure6_STM.c,43 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Pressure6_STM.c,45 :: 		pressure6_i2cDriverInit( (T_PRESSURE6_P)&_MIKROBUS1_GPIO, (T_PRESSURE6_P)&_MIKROBUS1_I2C, _PRESSURE6_DEF_SLAVE_ADDRESS );
MOVS	R2, __PRESSURE6_DEF_SLAVE_ADDRESS
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_pressure6_i2cDriverInit+0
;Click_Pressure6_STM.c,46 :: 		pressure6_powerON();
BL	_pressure6_powerON+0
;Click_Pressure6_STM.c,47 :: 		Delay_1sec();
BL	_Delay_1sec+0
;Click_Pressure6_STM.c,50 :: 		_PRESSURE6_MC_DATA_READY_ENABLED |
MOVS	R0, __PRESSURE6_MC_AVE_NUM_SINGLE
ORR	R0, R0, __PRESSURE6_MC_DATA_READY_ENABLED
UXTB	R0, R0
;Click_Pressure6_STM.c,51 :: 		_PRESSURE6_MC_FULL_DATA_ENABLED |
ORR	R0, R0, __PRESSURE6_MC_FULL_DATA_ENABLED
UXTB	R0, R0
;Click_Pressure6_STM.c,52 :: 		_PRESSURE6_MC_WATER_MARK_ENABLED |
ORR	R0, R0, __PRESSURE6_MC_WATER_MARK_ENABLED
UXTB	R0, R0
;Click_Pressure6_STM.c,53 :: 		_PRESSURE6_MC_MODE_CONTINUOUS);
ORR	R0, R0, __PRESSURE6_MC_MODE_CONTINUOUS
UXTB	R1, R0
;Click_Pressure6_STM.c,48 :: 		pressure6_writeByte(_PRESSURE6_REG_MODE_CONTROL,
MOVS	R0, __PRESSURE6_REG_MODE_CONTROL
;Click_Pressure6_STM.c,53 :: 		_PRESSURE6_MC_MODE_CONTINUOUS);
BL	_pressure6_writeByte+0
;Click_Pressure6_STM.c,55 :: 		mikrobus_logWrite(" --- Start measurement --- ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr2_Click_Pressure6_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_Pressure6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Pressure6_STM.c,56 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Pressure6_STM.c,58 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Pressure6_STM.c,60 :: 		pressure6_waitingForNewData();
BL	_pressure6_waitingForNewData+0
;Click_Pressure6_STM.c,61 :: 		Pressure = pressure6_getPressure();
BL	_pressure6_getPressure+0
MOVW	R1, #lo_addr(_Pressure+0)
MOVT	R1, #hi_addr(_Pressure+0)
STRH	R0, [R1, #0]
;Click_Pressure6_STM.c,62 :: 		Temperature = pressure6_getTemperatre();
BL	_pressure6_getTemperatre+0
MOVW	R1, #lo_addr(_Temperature+0)
MOVT	R1, #hi_addr(_Temperature+0)
STRB	R0, [R1, #0]
;Click_Pressure6_STM.c,65 :: 		IntToStr(Pressure, demoText);
MOVW	R0, #lo_addr(_Pressure+0)
MOVT	R0, #hi_addr(_Pressure+0)
LDRH	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_IntToStr+0
;Click_Pressure6_STM.c,66 :: 		mikrobus_logWrite(" Pressure : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr3_Click_Pressure6_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_Pressure6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Pressure6_STM.c,67 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Pressure6_STM.c,69 :: 		IntToStr(Temperature, demoText);
MOVW	R0, #lo_addr(_Temperature+0)
MOVT	R0, #hi_addr(_Temperature+0)
LDRB	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_IntToStr+0
;Click_Pressure6_STM.c,70 :: 		mikrobus_logWrite(" Temperature : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr4_Click_Pressure6_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_Pressure6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Pressure6_STM.c,71 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Pressure6_STM.c,73 :: 		mikrobus_logWrite("  ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr5_Click_Pressure6_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_Pressure6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Pressure6_STM.c,74 :: 		Delay_ms( 1000 );
MOVW	R7, #6911
MOVT	R7, #183
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_Pressure6_STM.c,75 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Pressure6_STM.c,77 :: 		void main()
;Click_Pressure6_STM.c,79 :: 		systemInit();
BL	_systemInit+0
;Click_Pressure6_STM.c,80 :: 		applicationInit();
BL	_applicationInit+0
;Click_Pressure6_STM.c,82 :: 		while (1)
L_main4:
;Click_Pressure6_STM.c,84 :: 		applicationTask();
BL	_applicationTask+0
;Click_Pressure6_STM.c,85 :: 		}
IT	AL
BAL	L_main4
;Click_Pressure6_STM.c,86 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
