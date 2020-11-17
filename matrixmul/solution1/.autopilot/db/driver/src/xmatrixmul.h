// ==============================================================
// File generated on Tue Nov 17 21:02:07 +0800 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMATRIXMUL_H
#define XMATRIXMUL_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmatrixmul_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XMatrixmul_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XMatrixmul;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMatrixmul_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMatrixmul_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMatrixmul_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMatrixmul_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XMatrixmul_Initialize(XMatrixmul *InstancePtr, u16 DeviceId);
XMatrixmul_Config* XMatrixmul_LookupConfig(u16 DeviceId);
int XMatrixmul_CfgInitialize(XMatrixmul *InstancePtr, XMatrixmul_Config *ConfigPtr);
#else
int XMatrixmul_Initialize(XMatrixmul *InstancePtr, const char* InstanceName);
int XMatrixmul_Release(XMatrixmul *InstancePtr);
#endif

void XMatrixmul_Start(XMatrixmul *InstancePtr);
u32 XMatrixmul_IsDone(XMatrixmul *InstancePtr);
u32 XMatrixmul_IsIdle(XMatrixmul *InstancePtr);
u32 XMatrixmul_IsReady(XMatrixmul *InstancePtr);
void XMatrixmul_EnableAutoRestart(XMatrixmul *InstancePtr);
void XMatrixmul_DisableAutoRestart(XMatrixmul *InstancePtr);

void XMatrixmul_Set_A(XMatrixmul *InstancePtr, u32 Data);
u32 XMatrixmul_Get_A(XMatrixmul *InstancePtr);
void XMatrixmul_Set_B(XMatrixmul *InstancePtr, u32 Data);
u32 XMatrixmul_Get_B(XMatrixmul *InstancePtr);
void XMatrixmul_Set_out_r(XMatrixmul *InstancePtr, u32 Data);
u32 XMatrixmul_Get_out_r(XMatrixmul *InstancePtr);

void XMatrixmul_InterruptGlobalEnable(XMatrixmul *InstancePtr);
void XMatrixmul_InterruptGlobalDisable(XMatrixmul *InstancePtr);
void XMatrixmul_InterruptEnable(XMatrixmul *InstancePtr, u32 Mask);
void XMatrixmul_InterruptDisable(XMatrixmul *InstancePtr, u32 Mask);
void XMatrixmul_InterruptClear(XMatrixmul *InstancePtr, u32 Mask);
u32 XMatrixmul_InterruptGetEnabled(XMatrixmul *InstancePtr);
u32 XMatrixmul_InterruptGetStatus(XMatrixmul *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
