// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XMIN_POOLING_H
#define XMIN_POOLING_H

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
#include "xmin_pooling_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Control_BaseAddress;
} XMin_pooling_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XMin_pooling;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMin_pooling_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMin_pooling_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMin_pooling_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMin_pooling_ReadReg(BaseAddress, RegOffset) \
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
#ifdef SDT
int XMin_pooling_Initialize(XMin_pooling *InstancePtr, UINTPTR BaseAddress);
XMin_pooling_Config* XMin_pooling_LookupConfig(UINTPTR BaseAddress);
#else
int XMin_pooling_Initialize(XMin_pooling *InstancePtr, u16 DeviceId);
XMin_pooling_Config* XMin_pooling_LookupConfig(u16 DeviceId);
#endif
int XMin_pooling_CfgInitialize(XMin_pooling *InstancePtr, XMin_pooling_Config *ConfigPtr);
#else
int XMin_pooling_Initialize(XMin_pooling *InstancePtr, const char* InstanceName);
int XMin_pooling_Release(XMin_pooling *InstancePtr);
#endif

void XMin_pooling_Start(XMin_pooling *InstancePtr);
u32 XMin_pooling_IsDone(XMin_pooling *InstancePtr);
u32 XMin_pooling_IsIdle(XMin_pooling *InstancePtr);
u32 XMin_pooling_IsReady(XMin_pooling *InstancePtr);
void XMin_pooling_EnableAutoRestart(XMin_pooling *InstancePtr);
void XMin_pooling_DisableAutoRestart(XMin_pooling *InstancePtr);

void XMin_pooling_Set_image_r(XMin_pooling *InstancePtr, u64 Data);
u64 XMin_pooling_Get_image_r(XMin_pooling *InstancePtr);
void XMin_pooling_Set_output_r(XMin_pooling *InstancePtr, u64 Data);
u64 XMin_pooling_Get_output_r(XMin_pooling *InstancePtr);
void XMin_pooling_Set_width(XMin_pooling *InstancePtr, u32 Data);
u32 XMin_pooling_Get_width(XMin_pooling *InstancePtr);
void XMin_pooling_Set_height(XMin_pooling *InstancePtr, u32 Data);
u32 XMin_pooling_Get_height(XMin_pooling *InstancePtr);
void XMin_pooling_Set_channels(XMin_pooling *InstancePtr, u32 Data);
u32 XMin_pooling_Get_channels(XMin_pooling *InstancePtr);

void XMin_pooling_InterruptGlobalEnable(XMin_pooling *InstancePtr);
void XMin_pooling_InterruptGlobalDisable(XMin_pooling *InstancePtr);
void XMin_pooling_InterruptEnable(XMin_pooling *InstancePtr, u32 Mask);
void XMin_pooling_InterruptDisable(XMin_pooling *InstancePtr, u32 Mask);
void XMin_pooling_InterruptClear(XMin_pooling *InstancePtr, u32 Mask);
u32 XMin_pooling_InterruptGetEnabled(XMin_pooling *InstancePtr);
u32 XMin_pooling_InterruptGetStatus(XMin_pooling *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
