// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xmaxpooling.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMaxpooling_CfgInitialize(XMaxpooling *InstancePtr, XMaxpooling_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMaxpooling_Start(XMaxpooling *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMaxpooling_IsDone(XMaxpooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMaxpooling_IsIdle(XMaxpooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMaxpooling_IsReady(XMaxpooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMaxpooling_EnableAutoRestart(XMaxpooling *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMaxpooling_DisableAutoRestart(XMaxpooling *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_AP_CTRL, 0);
}

void XMaxpooling_Set_image_r(XMaxpooling *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_IMAGE_R_DATA, (u32)(Data));
    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_IMAGE_R_DATA + 4, (u32)(Data >> 32));
}

u64 XMaxpooling_Get_image_r(XMaxpooling *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_IMAGE_R_DATA);
    Data += (u64)XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_IMAGE_R_DATA + 4) << 32;
    return Data;
}

void XMaxpooling_Set_output_r(XMaxpooling *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_OUTPUT_R_DATA, (u32)(Data));
    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_OUTPUT_R_DATA + 4, (u32)(Data >> 32));
}

u64 XMaxpooling_Get_output_r(XMaxpooling *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_OUTPUT_R_DATA);
    Data += (u64)XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_OUTPUT_R_DATA + 4) << 32;
    return Data;
}

void XMaxpooling_Set_width(XMaxpooling *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_WIDTH_DATA, Data);
}

u32 XMaxpooling_Get_width(XMaxpooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_WIDTH_DATA);
    return Data;
}

void XMaxpooling_Set_height(XMaxpooling *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_HEIGHT_DATA, Data);
}

u32 XMaxpooling_Get_height(XMaxpooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_HEIGHT_DATA);
    return Data;
}

void XMaxpooling_Set_channels(XMaxpooling *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_CHANNELS_DATA, Data);
}

u32 XMaxpooling_Get_channels(XMaxpooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_CHANNELS_DATA);
    return Data;
}

void XMaxpooling_InterruptGlobalEnable(XMaxpooling *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_GIE, 1);
}

void XMaxpooling_InterruptGlobalDisable(XMaxpooling *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_GIE, 0);
}

void XMaxpooling_InterruptEnable(XMaxpooling *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_IER);
    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_IER, Register | Mask);
}

void XMaxpooling_InterruptDisable(XMaxpooling *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_IER);
    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMaxpooling_InterruptClear(XMaxpooling *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpooling_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_ISR, Mask);
}

u32 XMaxpooling_InterruptGetEnabled(XMaxpooling *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_IER);
}

u32 XMaxpooling_InterruptGetStatus(XMaxpooling *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMaxpooling_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOLING_CONTROL_ADDR_ISR);
}

