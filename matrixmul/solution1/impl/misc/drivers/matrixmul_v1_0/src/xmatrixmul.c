// ==============================================================
// File generated on Tue Nov 17 21:02:07 +0800 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmatrixmul.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMatrixmul_CfgInitialize(XMatrixmul *InstancePtr, XMatrixmul_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMatrixmul_Start(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_AP_CTRL) & 0x80;
    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMatrixmul_IsDone(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMatrixmul_IsIdle(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMatrixmul_IsReady(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMatrixmul_EnableAutoRestart(XMatrixmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XMatrixmul_DisableAutoRestart(XMatrixmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_AP_CTRL, 0);
}

void XMatrixmul_Set_A(XMatrixmul *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_A_DATA, Data);
}

u32 XMatrixmul_Get_A(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_A_DATA);
    return Data;
}

void XMatrixmul_Set_B(XMatrixmul *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_B_DATA, Data);
}

u32 XMatrixmul_Get_B(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_B_DATA);
    return Data;
}

void XMatrixmul_Set_out_r(XMatrixmul *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_OUT_R_DATA, Data);
}

u32 XMatrixmul_Get_out_r(XMatrixmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_OUT_R_DATA);
    return Data;
}

void XMatrixmul_InterruptGlobalEnable(XMatrixmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_GIE, 1);
}

void XMatrixmul_InterruptGlobalDisable(XMatrixmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_GIE, 0);
}

void XMatrixmul_InterruptEnable(XMatrixmul *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_IER);
    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_IER, Register | Mask);
}

void XMatrixmul_InterruptDisable(XMatrixmul *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_IER);
    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_IER, Register & (~Mask));
}

void XMatrixmul_InterruptClear(XMatrixmul *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrixmul_WriteReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_ISR, Mask);
}

u32 XMatrixmul_InterruptGetEnabled(XMatrixmul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_IER);
}

u32 XMatrixmul_InterruptGetStatus(XMatrixmul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMatrixmul_ReadReg(InstancePtr->Axilites_BaseAddress, XMATRIXMUL_AXILITES_ADDR_ISR);
}

