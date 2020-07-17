;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.2
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv_trm.inc

; Led_A
Led_A__0__DM__MASK EQU 0x7000
Led_A__0__DM__SHIFT EQU 12
Led_A__0__DR EQU CYREG_PRT0_DR
Led_A__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Led_A__0__HSIOM_MASK EQU 0x000F0000
Led_A__0__HSIOM_SHIFT EQU 16
Led_A__0__INTCFG EQU CYREG_PRT0_INTCFG
Led_A__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Led_A__0__MASK EQU 0x10
Led_A__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Led_A__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Led_A__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Led_A__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Led_A__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Led_A__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Led_A__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Led_A__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Led_A__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Led_A__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Led_A__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Led_A__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Led_A__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Led_A__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Led_A__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Led_A__0__PC EQU CYREG_PRT0_PC
Led_A__0__PC2 EQU CYREG_PRT0_PC2
Led_A__0__PORT EQU 0
Led_A__0__PS EQU CYREG_PRT0_PS
Led_A__0__SHIFT EQU 4
Led_A__DR EQU CYREG_PRT0_DR
Led_A__INTCFG EQU CYREG_PRT0_INTCFG
Led_A__INTSTAT EQU CYREG_PRT0_INTSTAT
Led_A__MASK EQU 0x10
Led_A__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Led_A__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Led_A__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Led_A__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Led_A__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Led_A__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Led_A__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Led_A__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Led_A__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Led_A__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Led_A__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Led_A__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Led_A__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Led_A__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Led_A__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Led_A__PC EQU CYREG_PRT0_PC
Led_A__PC2 EQU CYREG_PRT0_PC2
Led_A__PORT EQU 0
Led_A__PS EQU CYREG_PRT0_PS
Led_A__SHIFT EQU 4

; Led_B
Led_B__0__DM__MASK EQU 0x38000
Led_B__0__DM__SHIFT EQU 15
Led_B__0__DR EQU CYREG_PRT0_DR
Led_B__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Led_B__0__HSIOM_MASK EQU 0x00F00000
Led_B__0__HSIOM_SHIFT EQU 20
Led_B__0__INTCFG EQU CYREG_PRT0_INTCFG
Led_B__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Led_B__0__MASK EQU 0x20
Led_B__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Led_B__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Led_B__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Led_B__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Led_B__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Led_B__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Led_B__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Led_B__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Led_B__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Led_B__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Led_B__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Led_B__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Led_B__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Led_B__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Led_B__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Led_B__0__PC EQU CYREG_PRT0_PC
Led_B__0__PC2 EQU CYREG_PRT0_PC2
Led_B__0__PORT EQU 0
Led_B__0__PS EQU CYREG_PRT0_PS
Led_B__0__SHIFT EQU 5
Led_B__DR EQU CYREG_PRT0_DR
Led_B__INTCFG EQU CYREG_PRT0_INTCFG
Led_B__INTSTAT EQU CYREG_PRT0_INTSTAT
Led_B__MASK EQU 0x20
Led_B__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Led_B__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Led_B__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Led_B__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Led_B__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Led_B__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Led_B__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Led_B__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Led_B__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Led_B__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Led_B__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Led_B__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Led_B__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Led_B__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Led_B__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Led_B__PC EQU CYREG_PRT0_PC
Led_B__PC2 EQU CYREG_PRT0_PC2
Led_B__PORT EQU 0
Led_B__PS EQU CYREG_PRT0_PS
Led_B__SHIFT EQU 5

; Led_C
Led_C__0__DM__MASK EQU 0xE00000
Led_C__0__DM__SHIFT EQU 21
Led_C__0__DR EQU CYREG_PRT0_DR
Led_C__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Led_C__0__HSIOM_MASK EQU 0xF0000000
Led_C__0__HSIOM_SHIFT EQU 28
Led_C__0__INTCFG EQU CYREG_PRT0_INTCFG
Led_C__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Led_C__0__MASK EQU 0x80
Led_C__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Led_C__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Led_C__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Led_C__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Led_C__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Led_C__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Led_C__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Led_C__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Led_C__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Led_C__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Led_C__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Led_C__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Led_C__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Led_C__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Led_C__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Led_C__0__PC EQU CYREG_PRT0_PC
Led_C__0__PC2 EQU CYREG_PRT0_PC2
Led_C__0__PORT EQU 0
Led_C__0__PS EQU CYREG_PRT0_PS
Led_C__0__SHIFT EQU 7
Led_C__DR EQU CYREG_PRT0_DR
Led_C__INTCFG EQU CYREG_PRT0_INTCFG
Led_C__INTSTAT EQU CYREG_PRT0_INTSTAT
Led_C__MASK EQU 0x80
Led_C__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Led_C__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Led_C__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Led_C__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Led_C__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Led_C__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Led_C__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Led_C__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Led_C__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Led_C__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Led_C__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Led_C__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Led_C__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Led_C__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Led_C__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Led_C__PC EQU CYREG_PRT0_PC
Led_C__PC2 EQU CYREG_PRT0_PC2
Led_C__PORT EQU 0
Led_C__PS EQU CYREG_PRT0_PS
Led_C__SHIFT EQU 7

; Led_D
Led_D__0__DM__MASK EQU 0xE00000
Led_D__0__DM__SHIFT EQU 21
Led_D__0__DR EQU CYREG_PRT3_DR
Led_D__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
Led_D__0__HSIOM_MASK EQU 0xF0000000
Led_D__0__HSIOM_SHIFT EQU 28
Led_D__0__INTCFG EQU CYREG_PRT3_INTCFG
Led_D__0__INTSTAT EQU CYREG_PRT3_INTSTAT
Led_D__0__MASK EQU 0x80
Led_D__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
Led_D__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
Led_D__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
Led_D__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
Led_D__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
Led_D__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
Led_D__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
Led_D__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
Led_D__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
Led_D__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
Led_D__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
Led_D__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
Led_D__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
Led_D__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
Led_D__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
Led_D__0__PC EQU CYREG_PRT3_PC
Led_D__0__PC2 EQU CYREG_PRT3_PC2
Led_D__0__PORT EQU 3
Led_D__0__PS EQU CYREG_PRT3_PS
Led_D__0__SHIFT EQU 7
Led_D__DR EQU CYREG_PRT3_DR
Led_D__INTCFG EQU CYREG_PRT3_INTCFG
Led_D__INTSTAT EQU CYREG_PRT3_INTSTAT
Led_D__MASK EQU 0x80
Led_D__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
Led_D__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
Led_D__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
Led_D__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
Led_D__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
Led_D__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
Led_D__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
Led_D__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
Led_D__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
Led_D__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
Led_D__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
Led_D__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
Led_D__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
Led_D__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
Led_D__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
Led_D__PC EQU CYREG_PRT3_PC
Led_D__PC2 EQU CYREG_PRT3_PC2
Led_D__PORT EQU 3
Led_D__PS EQU CYREG_PRT3_PS
Led_D__SHIFT EQU 7

; PWM_0
PWM_0_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT0_CC
PWM_0_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT0_CC_BUFF
PWM_0_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT0_COUNTER
PWM_0_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT0_CTRL
PWM_0_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT0_INTR
PWM_0_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT0_INTR_MASK
PWM_0_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT0_INTR_MASKED
PWM_0_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT0_INTR_SET
PWM_0_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT0_PERIOD
PWM_0_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT0_PERIOD_BUFF
PWM_0_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT0_STATUS
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x01
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 0
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x100
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 8
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x1000000
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 24
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x10000
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 16
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x01
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 0
PWM_0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x01
PWM_0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 0
PWM_0_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 0
PWM_0_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT0_TR_CTRL0
PWM_0_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT0_TR_CTRL1
PWM_0_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT0_TR_CTRL2
PWM_0_Int__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
PWM_0_Int__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
PWM_0_Int__INTC_MASK EQU 0x10000
PWM_0_Int__INTC_NUMBER EQU 16
PWM_0_Int__INTC_PRIOR_MASK EQU 0xC0
PWM_0_Int__INTC_PRIOR_NUM EQU 3
PWM_0_Int__INTC_PRIOR_REG EQU CYREG_CM0_IPR4
PWM_0_Int__INTC_SET_EN_REG EQU CYREG_CM0_ISER
PWM_0_Int__INTC_SET_PD_REG EQU CYREG_CM0_ISPR
PWM_0_Out__0__DM__MASK EQU 0x7000
PWM_0_Out__0__DM__SHIFT EQU 12
PWM_0_Out__0__DR EQU CYREG_PRT2_DR
PWM_0_Out__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
PWM_0_Out__0__HSIOM_MASK EQU 0x000F0000
PWM_0_Out__0__HSIOM_SHIFT EQU 16
PWM_0_Out__0__INTCFG EQU CYREG_PRT2_INTCFG
PWM_0_Out__0__INTSTAT EQU CYREG_PRT2_INTSTAT
PWM_0_Out__0__MASK EQU 0x10
PWM_0_Out__0__OUT_SEL EQU CYREG_UDB_PA2_CFG10
PWM_0_Out__0__OUT_SEL_SHIFT EQU 8
PWM_0_Out__0__OUT_SEL_VAL EQU -1
PWM_0_Out__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
PWM_0_Out__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
PWM_0_Out__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
PWM_0_Out__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
PWM_0_Out__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
PWM_0_Out__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
PWM_0_Out__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
PWM_0_Out__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
PWM_0_Out__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
PWM_0_Out__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
PWM_0_Out__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
PWM_0_Out__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
PWM_0_Out__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
PWM_0_Out__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
PWM_0_Out__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
PWM_0_Out__0__PC EQU CYREG_PRT2_PC
PWM_0_Out__0__PC2 EQU CYREG_PRT2_PC2
PWM_0_Out__0__PORT EQU 2
PWM_0_Out__0__PS EQU CYREG_PRT2_PS
PWM_0_Out__0__SHIFT EQU 4
PWM_0_Out__DR EQU CYREG_PRT2_DR
PWM_0_Out__INTCFG EQU CYREG_PRT2_INTCFG
PWM_0_Out__INTSTAT EQU CYREG_PRT2_INTSTAT
PWM_0_Out__MASK EQU 0x10
PWM_0_Out__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
PWM_0_Out__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
PWM_0_Out__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
PWM_0_Out__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
PWM_0_Out__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
PWM_0_Out__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
PWM_0_Out__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
PWM_0_Out__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
PWM_0_Out__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
PWM_0_Out__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
PWM_0_Out__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
PWM_0_Out__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
PWM_0_Out__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
PWM_0_Out__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
PWM_0_Out__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
PWM_0_Out__PC EQU CYREG_PRT2_PC
PWM_0_Out__PC2 EQU CYREG_PRT2_PC2
PWM_0_Out__PORT EQU 2
PWM_0_Out__PS EQU CYREG_PRT2_PS
PWM_0_Out__SHIFT EQU 4

; PWM_1
PWM_1_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT1_CC
PWM_1_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT1_CC_BUFF
PWM_1_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT1_COUNTER
PWM_1_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT1_CTRL
PWM_1_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT1_INTR
PWM_1_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT1_INTR_MASK
PWM_1_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT1_INTR_MASKED
PWM_1_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT1_INTR_SET
PWM_1_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT1_PERIOD
PWM_1_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT1_PERIOD_BUFF
PWM_1_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT1_STATUS
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x02
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 1
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x200
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 9
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x2000000
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 25
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x20000
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 17
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x02
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 1
PWM_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x02
PWM_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 1
PWM_1_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 1
PWM_1_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT1_TR_CTRL0
PWM_1_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT1_TR_CTRL1
PWM_1_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT1_TR_CTRL2
PWM_1_Out__0__DM__MASK EQU 0x1C0000
PWM_1_Out__0__DM__SHIFT EQU 18
PWM_1_Out__0__DR EQU CYREG_PRT2_DR
PWM_1_Out__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
PWM_1_Out__0__HSIOM_MASK EQU 0x0F000000
PWM_1_Out__0__HSIOM_SHIFT EQU 24
PWM_1_Out__0__INTCFG EQU CYREG_PRT2_INTCFG
PWM_1_Out__0__INTSTAT EQU CYREG_PRT2_INTSTAT
PWM_1_Out__0__MASK EQU 0x40
PWM_1_Out__0__OUT_SEL EQU CYREG_UDB_PA2_CFG10
PWM_1_Out__0__OUT_SEL_SHIFT EQU 12
PWM_1_Out__0__OUT_SEL_VAL EQU -1
PWM_1_Out__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
PWM_1_Out__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
PWM_1_Out__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
PWM_1_Out__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
PWM_1_Out__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
PWM_1_Out__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
PWM_1_Out__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
PWM_1_Out__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
PWM_1_Out__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
PWM_1_Out__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
PWM_1_Out__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
PWM_1_Out__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
PWM_1_Out__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
PWM_1_Out__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
PWM_1_Out__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
PWM_1_Out__0__PC EQU CYREG_PRT2_PC
PWM_1_Out__0__PC2 EQU CYREG_PRT2_PC2
PWM_1_Out__0__PORT EQU 2
PWM_1_Out__0__PS EQU CYREG_PRT2_PS
PWM_1_Out__0__SHIFT EQU 6
PWM_1_Out__DR EQU CYREG_PRT2_DR
PWM_1_Out__INTCFG EQU CYREG_PRT2_INTCFG
PWM_1_Out__INTSTAT EQU CYREG_PRT2_INTSTAT
PWM_1_Out__MASK EQU 0x40
PWM_1_Out__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
PWM_1_Out__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
PWM_1_Out__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
PWM_1_Out__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
PWM_1_Out__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
PWM_1_Out__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
PWM_1_Out__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
PWM_1_Out__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
PWM_1_Out__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
PWM_1_Out__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
PWM_1_Out__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
PWM_1_Out__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
PWM_1_Out__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
PWM_1_Out__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
PWM_1_Out__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
PWM_1_Out__PC EQU CYREG_PRT2_PC
PWM_1_Out__PC2 EQU CYREG_PRT2_PC2
PWM_1_Out__PORT EQU 2
PWM_1_Out__PS EQU CYREG_PRT2_PS
PWM_1_Out__SHIFT EQU 6

; PWM_2
PWM_2_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT2_CC
PWM_2_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT2_CC_BUFF
PWM_2_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT2_COUNTER
PWM_2_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT2_CTRL
PWM_2_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT2_INTR
PWM_2_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT2_INTR_MASK
PWM_2_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT2_INTR_MASKED
PWM_2_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT2_INTR_SET
PWM_2_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT2_PERIOD
PWM_2_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT2_PERIOD_BUFF
PWM_2_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT2_STATUS
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x04
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 2
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x400
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 10
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x4000000
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 26
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x40000
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 18
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x04
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 2
PWM_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x04
PWM_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 2
PWM_2_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 2
PWM_2_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT2_TR_CTRL0
PWM_2_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT2_TR_CTRL1
PWM_2_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT2_TR_CTRL2
PWM_2_Out__0__DM__MASK EQU 0x07
PWM_2_Out__0__DM__SHIFT EQU 0
PWM_2_Out__0__DR EQU CYREG_PRT1_DR
PWM_2_Out__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
PWM_2_Out__0__HSIOM_MASK EQU 0x0000000F
PWM_2_Out__0__HSIOM_SHIFT EQU 0
PWM_2_Out__0__INTCFG EQU CYREG_PRT1_INTCFG
PWM_2_Out__0__INTSTAT EQU CYREG_PRT1_INTSTAT
PWM_2_Out__0__MASK EQU 0x01
PWM_2_Out__0__OUT_SEL EQU CYREG_UDB_PA1_CFG10
PWM_2_Out__0__OUT_SEL_SHIFT EQU 0
PWM_2_Out__0__OUT_SEL_VAL EQU -1
PWM_2_Out__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
PWM_2_Out__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
PWM_2_Out__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
PWM_2_Out__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
PWM_2_Out__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
PWM_2_Out__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
PWM_2_Out__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
PWM_2_Out__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
PWM_2_Out__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
PWM_2_Out__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
PWM_2_Out__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
PWM_2_Out__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
PWM_2_Out__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
PWM_2_Out__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
PWM_2_Out__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
PWM_2_Out__0__PC EQU CYREG_PRT1_PC
PWM_2_Out__0__PC2 EQU CYREG_PRT1_PC2
PWM_2_Out__0__PORT EQU 1
PWM_2_Out__0__PS EQU CYREG_PRT1_PS
PWM_2_Out__0__SHIFT EQU 0
PWM_2_Out__DR EQU CYREG_PRT1_DR
PWM_2_Out__INTCFG EQU CYREG_PRT1_INTCFG
PWM_2_Out__INTSTAT EQU CYREG_PRT1_INTSTAT
PWM_2_Out__MASK EQU 0x01
PWM_2_Out__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
PWM_2_Out__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
PWM_2_Out__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
PWM_2_Out__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
PWM_2_Out__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
PWM_2_Out__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
PWM_2_Out__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
PWM_2_Out__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
PWM_2_Out__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
PWM_2_Out__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
PWM_2_Out__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
PWM_2_Out__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
PWM_2_Out__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
PWM_2_Out__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
PWM_2_Out__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
PWM_2_Out__PC EQU CYREG_PRT1_PC
PWM_2_Out__PC2 EQU CYREG_PRT1_PC2
PWM_2_Out__PORT EQU 1
PWM_2_Out__PS EQU CYREG_PRT1_PS
PWM_2_Out__SHIFT EQU 0

; Clock_1MHz
Clock_1MHz__DIVIDER_MASK EQU 0x0000FFFF
Clock_1MHz__ENABLE EQU CYREG_CLK_DIVIDER_A00
Clock_1MHz__ENABLE_MASK EQU 0x80000000
Clock_1MHz__MASK EQU 0x80000000
Clock_1MHz__REGISTER EQU CYREG_CLK_DIVIDER_A00

; Miscellaneous
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 18
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04C81193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 18
CYDEV_CHIP_MEMBER_4D EQU 13
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 19
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 17
CYDEV_CHIP_MEMBER_4I EQU 23
CYDEV_CHIP_MEMBER_4J EQU 14
CYDEV_CHIP_MEMBER_4K EQU 15
CYDEV_CHIP_MEMBER_4L EQU 22
CYDEV_CHIP_MEMBER_4M EQU 21
CYDEV_CHIP_MEMBER_4N EQU 10
CYDEV_CHIP_MEMBER_4O EQU 7
CYDEV_CHIP_MEMBER_4P EQU 20
CYDEV_CHIP_MEMBER_4Q EQU 12
CYDEV_CHIP_MEMBER_4R EQU 8
CYDEV_CHIP_MEMBER_4S EQU 11
CYDEV_CHIP_MEMBER_4T EQU 9
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 16
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 24
CYDEV_CHIP_MEMBER_FM3 EQU 28
CYDEV_CHIP_MEMBER_FM4 EQU 29
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 26
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 27
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_Disallowed
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 1
CYDEV_DFT_SELECT_CLK1 EQU 2
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 1
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END