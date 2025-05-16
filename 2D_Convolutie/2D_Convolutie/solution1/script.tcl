############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
open_project 2D_Convolutie
set_top Convolution
add_files 2D_Convolutie/source/2D_Convolutie.c
add_files 2D_Convolutie/source/2D_Convolutie.h
add_files -tb 2D_Convolutie/source/2D_Convolutie_tb.c
open_solution "solution1" -flow_target vivado
set_part {xc7z020-clg400-1}
create_clock -period 8 -name default
config_export -format ip_catalog -library V -output C:/Vitis/Vitis_HLS/IP_repo_export -rtl verilog -vendor Thomas -version 1.3
source "./2D_Convolutie/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog -output C:/Vitis/Vitis_HLS/IP_repo_export
