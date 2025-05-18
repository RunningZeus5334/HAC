// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xmin_pooling.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMin_pooling_CfgInitialize(XMin_pooling *InstancePtr, XMin_pooling_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMin_pooling_Start(XMin_pooling *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMin_pooling_IsDone(XMin_pooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMin_pooling_IsIdle(XMin_pooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMin_pooling_IsReady(XMin_pooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMin_pooling_EnableAutoRestart(XMin_pooling *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMin_pooling_DisableAutoRestart(XMin_pooling *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_AP_CTRL, 0);
}

void XMin_pooling_Set_image_r(XMin_pooling *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_IMAGE_R_DATA, (u32)(Data));
    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_IMAGE_R_DATA + 4, (u32)(Data >> 32));
}

u64 XMin_pooling_Get_image_r(XMin_pooling *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_IMAGE_R_DATA);
    Data += (u64)XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_IMAGE_R_DATA + 4) << 32;
    return Data;
}

void XMin_pooling_Set_output_r(XMin_pooling *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_OUTPUT_R_DATA, (u32)(Data));
    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_OUTPUT_R_DATA + 4, (u32)(Data >> 32));
}

u64 XMin_pooling_Get_output_r(XMin_pooling *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_OUTPUT_R_DATA);
    Data += (u64)XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_OUTPUT_R_DATA + 4) << 32;
    return Data;
}

void XMin_pooling_Set_width(XMin_pooling *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_WIDTH_DATA, Data);
}

u32 XMin_pooling_Get_width(XMin_pooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_WIDTH_DATA);
    return Data;
}

void XMin_pooling_Set_height(XMin_pooling *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_HEIGHT_DATA, Data);
}

u32 XMin_pooling_Get_height(XMin_pooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_HEIGHT_DATA);
    return Data;
}

void XMin_pooling_Set_channels(XMin_pooling *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_CHANNELS_DATA, Data);
}

u32 XMin_pooling_Get_channels(XMin_pooling *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_CHANNELS_DATA);
    return Data;
}

void XMin_pooling_InterruptGlobalEnable(XMin_pooling *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_GIE, 1);
}

void XMin_pooling_InterruptGlobalDisable(XMin_pooling *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_GIE, 0);
}

void XMin_pooling_InterruptEnable(XMin_pooling *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_IER);
    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_IER, Register | Mask);
}

void XMin_pooling_InterruptDisable(XMin_pooling *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_IER);
    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMin_pooling_InterruptClear(XMin_pooling *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMin_pooling_WriteReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_ISR, Mask);
}

u32 XMin_pooling_InterruptGetEnabled(XMin_pooling *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_IER);
}

u32 XMin_pooling_InterruptGetStatus(XMin_pooling *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMin_pooling_ReadReg(InstancePtr->Control_BaseAddress, XMIN_POOLING_CONTROL_ADDR_ISR);
}

