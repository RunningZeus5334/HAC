// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XMAXPOOLING_H
#define XMAXPOOLING_H

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
#include "xmaxpooling_hw.h"

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
} XMaxpooling_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XMaxpooling;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMaxpooling_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMaxpooling_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMaxpooling_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMaxpooling_ReadReg(BaseAddress, RegOffset) \
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
int XMaxpooling_Initialize(XMaxpooling *InstancePtr, UINTPTR BaseAddress);
XMaxpooling_Config* XMaxpooling_LookupConfig(UINTPTR BaseAddress);
#else
int XMaxpooling_Initialize(XMaxpooling *InstancePtr, u16 DeviceId);
XMaxpooling_Config* XMaxpooling_LookupConfig(u16 DeviceId);
#endif
int XMaxpooling_CfgInitialize(XMaxpooling *InstancePtr, XMaxpooling_Config *ConfigPtr);
#else
int XMaxpooling_Initialize(XMaxpooling *InstancePtr, const char* InstanceName);
int XMaxpooling_Release(XMaxpooling *InstancePtr);
#endif

void XMaxpooling_Start(XMaxpooling *InstancePtr);
u32 XMaxpooling_IsDone(XMaxpooling *InstancePtr);
u32 XMaxpooling_IsIdle(XMaxpooling *InstancePtr);
u32 XMaxpooling_IsReady(XMaxpooling *InstancePtr);
void XMaxpooling_EnableAutoRestart(XMaxpooling *InstancePtr);
void XMaxpooling_DisableAutoRestart(XMaxpooling *InstancePtr);

void XMaxpooling_Set_image_r(XMaxpooling *InstancePtr, u64 Data);
u64 XMaxpooling_Get_image_r(XMaxpooling *InstancePtr);
void XMaxpooling_Set_output_r(XMaxpooling *InstancePtr, u64 Data);
u64 XMaxpooling_Get_output_r(XMaxpooling *InstancePtr);
void XMaxpooling_Set_width(XMaxpooling *InstancePtr, u32 Data);
u32 XMaxpooling_Get_width(XMaxpooling *InstancePtr);
void XMaxpooling_Set_height(XMaxpooling *InstancePtr, u32 Data);
u32 XMaxpooling_Get_height(XMaxpooling *InstancePtr);
void XMaxpooling_Set_channels(XMaxpooling *InstancePtr, u32 Data);
u32 XMaxpooling_Get_channels(XMaxpooling *InstancePtr);

void XMaxpooling_InterruptGlobalEnable(XMaxpooling *InstancePtr);
void XMaxpooling_InterruptGlobalDisable(XMaxpooling *InstancePtr);
void XMaxpooling_InterruptEnable(XMaxpooling *InstancePtr, u32 Mask);
void XMaxpooling_InterruptDisable(XMaxpooling *InstancePtr, u32 Mask);
void XMaxpooling_InterruptClear(XMaxpooling *InstancePtr, u32 Mask);
u32 XMaxpooling_InterruptGetEnabled(XMaxpooling *InstancePtr);
u32 XMaxpooling_InterruptGetStatus(XMaxpooling *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
