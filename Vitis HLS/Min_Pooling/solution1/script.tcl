############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
open_project Min_Pooling
set_top min_pooling
add_files Min_Pooling/source/Minpooling.c
add_files Min_Pooling/source/Minpooling.h
open_solution "solution1" -flow_target vivado
set_part {xc7z020clg400-1}
create_clock -period 8 -name default
config_export -library V -output C:/Vitis/Vitis_HLS/IP_repo_export -vendor Thomas -version 1.0
#source "./Min_Pooling/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog -output C:/Vitis/Vitis_HLS/IP_repo_export
