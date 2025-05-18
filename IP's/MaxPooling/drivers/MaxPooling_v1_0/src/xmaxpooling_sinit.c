// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xmaxpooling.h"

extern XMaxpooling_Config XMaxpooling_ConfigTable[];

#ifdef SDT
XMaxpooling_Config *XMaxpooling_LookupConfig(UINTPTR BaseAddress) {
	XMaxpooling_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XMaxpooling_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XMaxpooling_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XMaxpooling_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMaxpooling_Initialize(XMaxpooling *InstancePtr, UINTPTR BaseAddress) {
	XMaxpooling_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMaxpooling_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMaxpooling_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XMaxpooling_Config *XMaxpooling_LookupConfig(u16 DeviceId) {
	XMaxpooling_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMAXPOOLING_NUM_INSTANCES; Index++) {
		if (XMaxpooling_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMaxpooling_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMaxpooling_Initialize(XMaxpooling *InstancePtr, u16 DeviceId) {
	XMaxpooling_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMaxpooling_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMaxpooling_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

