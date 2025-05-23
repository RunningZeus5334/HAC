// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.1 (win64) Build 5076996 Wed May 22 18:37:14 MDT 2024
// Date        : Mon May 12 23:17:49 2025
// Host        : Thomas-Laptop running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_1_Convolution_0_0_stub.v
// Design      : design_1_Convolution_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "Convolution,Vivado 2024.1" *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix(s_axi_control_ARADDR, 
  s_axi_control_ARREADY, s_axi_control_ARVALID, s_axi_control_AWADDR, 
  s_axi_control_AWREADY, s_axi_control_AWVALID, s_axi_control_BREADY, 
  s_axi_control_BRESP, s_axi_control_BVALID, s_axi_control_RDATA, s_axi_control_RREADY, 
  s_axi_control_RRESP, s_axi_control_RVALID, s_axi_control_WDATA, s_axi_control_WREADY, 
  s_axi_control_WSTRB, s_axi_control_WVALID, s_axi_control_r_ARADDR, 
  s_axi_control_r_ARREADY, s_axi_control_r_ARVALID, s_axi_control_r_AWADDR, 
  s_axi_control_r_AWREADY, s_axi_control_r_AWVALID, s_axi_control_r_BREADY, 
  s_axi_control_r_BRESP, s_axi_control_r_BVALID, s_axi_control_r_RDATA, 
  s_axi_control_r_RREADY, s_axi_control_r_RRESP, s_axi_control_r_RVALID, 
  s_axi_control_r_WDATA, s_axi_control_r_WREADY, s_axi_control_r_WSTRB, 
  s_axi_control_r_WVALID, ap_clk, ap_rst_n, interrupt, m_axi_input_r_ARADDR, 
  m_axi_input_r_ARBURST, m_axi_input_r_ARCACHE, m_axi_input_r_ARID, m_axi_input_r_ARLEN, 
  m_axi_input_r_ARLOCK, m_axi_input_r_ARPROT, m_axi_input_r_ARQOS, m_axi_input_r_ARREADY, 
  m_axi_input_r_ARREGION, m_axi_input_r_ARSIZE, m_axi_input_r_ARVALID, 
  m_axi_input_r_AWADDR, m_axi_input_r_AWBURST, m_axi_input_r_AWCACHE, m_axi_input_r_AWID, 
  m_axi_input_r_AWLEN, m_axi_input_r_AWLOCK, m_axi_input_r_AWPROT, m_axi_input_r_AWQOS, 
  m_axi_input_r_AWREADY, m_axi_input_r_AWREGION, m_axi_input_r_AWSIZE, 
  m_axi_input_r_AWVALID, m_axi_input_r_BID, m_axi_input_r_BREADY, m_axi_input_r_BRESP, 
  m_axi_input_r_BVALID, m_axi_input_r_RDATA, m_axi_input_r_RID, m_axi_input_r_RLAST, 
  m_axi_input_r_RREADY, m_axi_input_r_RRESP, m_axi_input_r_RVALID, m_axi_input_r_WDATA, 
  m_axi_input_r_WID, m_axi_input_r_WLAST, m_axi_input_r_WREADY, m_axi_input_r_WSTRB, 
  m_axi_input_r_WVALID, m_axi_output_r_ARADDR, m_axi_output_r_ARBURST, 
  m_axi_output_r_ARCACHE, m_axi_output_r_ARID, m_axi_output_r_ARLEN, 
  m_axi_output_r_ARLOCK, m_axi_output_r_ARPROT, m_axi_output_r_ARQOS, 
  m_axi_output_r_ARREADY, m_axi_output_r_ARREGION, m_axi_output_r_ARSIZE, 
  m_axi_output_r_ARVALID, m_axi_output_r_AWADDR, m_axi_output_r_AWBURST, 
  m_axi_output_r_AWCACHE, m_axi_output_r_AWID, m_axi_output_r_AWLEN, 
  m_axi_output_r_AWLOCK, m_axi_output_r_AWPROT, m_axi_output_r_AWQOS, 
  m_axi_output_r_AWREADY, m_axi_output_r_AWREGION, m_axi_output_r_AWSIZE, 
  m_axi_output_r_AWVALID, m_axi_output_r_BID, m_axi_output_r_BREADY, 
  m_axi_output_r_BRESP, m_axi_output_r_BVALID, m_axi_output_r_RDATA, m_axi_output_r_RID, 
  m_axi_output_r_RLAST, m_axi_output_r_RREADY, m_axi_output_r_RRESP, 
  m_axi_output_r_RVALID, m_axi_output_r_WDATA, m_axi_output_r_WID, m_axi_output_r_WLAST, 
  m_axi_output_r_WREADY, m_axi_output_r_WSTRB, m_axi_output_r_WVALID)
/* synthesis syn_black_box black_box_pad_pin="s_axi_control_ARADDR[5:0],s_axi_control_ARREADY,s_axi_control_ARVALID,s_axi_control_AWADDR[5:0],s_axi_control_AWREADY,s_axi_control_AWVALID,s_axi_control_BREADY,s_axi_control_BRESP[1:0],s_axi_control_BVALID,s_axi_control_RDATA[31:0],s_axi_control_RREADY,s_axi_control_RRESP[1:0],s_axi_control_RVALID,s_axi_control_WDATA[31:0],s_axi_control_WREADY,s_axi_control_WSTRB[3:0],s_axi_control_WVALID,s_axi_control_r_ARADDR[5:0],s_axi_control_r_ARREADY,s_axi_control_r_ARVALID,s_axi_control_r_AWADDR[5:0],s_axi_control_r_AWREADY,s_axi_control_r_AWVALID,s_axi_control_r_BREADY,s_axi_control_r_BRESP[1:0],s_axi_control_r_BVALID,s_axi_control_r_RDATA[31:0],s_axi_control_r_RREADY,s_axi_control_r_RRESP[1:0],s_axi_control_r_RVALID,s_axi_control_r_WDATA[31:0],s_axi_control_r_WREADY,s_axi_control_r_WSTRB[3:0],s_axi_control_r_WVALID,ap_rst_n,interrupt,m_axi_input_r_ARADDR[63:0],m_axi_input_r_ARBURST[1:0],m_axi_input_r_ARCACHE[3:0],m_axi_input_r_ARID[0:0],m_axi_input_r_ARLEN[7:0],m_axi_input_r_ARLOCK[1:0],m_axi_input_r_ARPROT[2:0],m_axi_input_r_ARQOS[3:0],m_axi_input_r_ARREADY,m_axi_input_r_ARREGION[3:0],m_axi_input_r_ARSIZE[2:0],m_axi_input_r_ARVALID,m_axi_input_r_AWADDR[63:0],m_axi_input_r_AWBURST[1:0],m_axi_input_r_AWCACHE[3:0],m_axi_input_r_AWID[0:0],m_axi_input_r_AWLEN[7:0],m_axi_input_r_AWLOCK[1:0],m_axi_input_r_AWPROT[2:0],m_axi_input_r_AWQOS[3:0],m_axi_input_r_AWREADY,m_axi_input_r_AWREGION[3:0],m_axi_input_r_AWSIZE[2:0],m_axi_input_r_AWVALID,m_axi_input_r_BID[0:0],m_axi_input_r_BREADY,m_axi_input_r_BRESP[1:0],m_axi_input_r_BVALID,m_axi_input_r_RDATA[31:0],m_axi_input_r_RID[0:0],m_axi_input_r_RLAST,m_axi_input_r_RREADY,m_axi_input_r_RRESP[1:0],m_axi_input_r_RVALID,m_axi_input_r_WDATA[31:0],m_axi_input_r_WID[0:0],m_axi_input_r_WLAST,m_axi_input_r_WREADY,m_axi_input_r_WSTRB[3:0],m_axi_input_r_WVALID,m_axi_output_r_ARADDR[63:0],m_axi_output_r_ARBURST[1:0],m_axi_output_r_ARCACHE[3:0],m_axi_output_r_ARID[0:0],m_axi_output_r_ARLEN[7:0],m_axi_output_r_ARLOCK[1:0],m_axi_output_r_ARPROT[2:0],m_axi_output_r_ARQOS[3:0],m_axi_output_r_ARREADY,m_axi_output_r_ARREGION[3:0],m_axi_output_r_ARSIZE[2:0],m_axi_output_r_ARVALID,m_axi_output_r_AWADDR[63:0],m_axi_output_r_AWBURST[1:0],m_axi_output_r_AWCACHE[3:0],m_axi_output_r_AWID[0:0],m_axi_output_r_AWLEN[7:0],m_axi_output_r_AWLOCK[1:0],m_axi_output_r_AWPROT[2:0],m_axi_output_r_AWQOS[3:0],m_axi_output_r_AWREADY,m_axi_output_r_AWREGION[3:0],m_axi_output_r_AWSIZE[2:0],m_axi_output_r_AWVALID,m_axi_output_r_BID[0:0],m_axi_output_r_BREADY,m_axi_output_r_BRESP[1:0],m_axi_output_r_BVALID,m_axi_output_r_RDATA[31:0],m_axi_output_r_RID[0:0],m_axi_output_r_RLAST,m_axi_output_r_RREADY,m_axi_output_r_RRESP[1:0],m_axi_output_r_RVALID,m_axi_output_r_WDATA[31:0],m_axi_output_r_WID[0:0],m_axi_output_r_WLAST,m_axi_output_r_WREADY,m_axi_output_r_WSTRB[3:0],m_axi_output_r_WVALID" */
/* synthesis syn_force_seq_prim="ap_clk" */;
  input [5:0]s_axi_control_ARADDR;
  output s_axi_control_ARREADY;
  input s_axi_control_ARVALID;
  input [5:0]s_axi_control_AWADDR;
  output s_axi_control_AWREADY;
  input s_axi_control_AWVALID;
  input s_axi_control_BREADY;
  output [1:0]s_axi_control_BRESP;
  output s_axi_control_BVALID;
  output [31:0]s_axi_control_RDATA;
  input s_axi_control_RREADY;
  output [1:0]s_axi_control_RRESP;
  output s_axi_control_RVALID;
  input [31:0]s_axi_control_WDATA;
  output s_axi_control_WREADY;
  input [3:0]s_axi_control_WSTRB;
  input s_axi_control_WVALID;
  input [5:0]s_axi_control_r_ARADDR;
  output s_axi_control_r_ARREADY;
  input s_axi_control_r_ARVALID;
  input [5:0]s_axi_control_r_AWADDR;
  output s_axi_control_r_AWREADY;
  input s_axi_control_r_AWVALID;
  input s_axi_control_r_BREADY;
  output [1:0]s_axi_control_r_BRESP;
  output s_axi_control_r_BVALID;
  output [31:0]s_axi_control_r_RDATA;
  input s_axi_control_r_RREADY;
  output [1:0]s_axi_control_r_RRESP;
  output s_axi_control_r_RVALID;
  input [31:0]s_axi_control_r_WDATA;
  output s_axi_control_r_WREADY;
  input [3:0]s_axi_control_r_WSTRB;
  input s_axi_control_r_WVALID;
  input ap_clk /* synthesis syn_isclock = 1 */;
  input ap_rst_n;
  output interrupt;
  output [63:0]m_axi_input_r_ARADDR;
  output [1:0]m_axi_input_r_ARBURST;
  output [3:0]m_axi_input_r_ARCACHE;
  output [0:0]m_axi_input_r_ARID;
  output [7:0]m_axi_input_r_ARLEN;
  output [1:0]m_axi_input_r_ARLOCK;
  output [2:0]m_axi_input_r_ARPROT;
  output [3:0]m_axi_input_r_ARQOS;
  input m_axi_input_r_ARREADY;
  output [3:0]m_axi_input_r_ARREGION;
  output [2:0]m_axi_input_r_ARSIZE;
  output m_axi_input_r_ARVALID;
  output [63:0]m_axi_input_r_AWADDR;
  output [1:0]m_axi_input_r_AWBURST;
  output [3:0]m_axi_input_r_AWCACHE;
  output [0:0]m_axi_input_r_AWID;
  output [7:0]m_axi_input_r_AWLEN;
  output [1:0]m_axi_input_r_AWLOCK;
  output [2:0]m_axi_input_r_AWPROT;
  output [3:0]m_axi_input_r_AWQOS;
  input m_axi_input_r_AWREADY;
  output [3:0]m_axi_input_r_AWREGION;
  output [2:0]m_axi_input_r_AWSIZE;
  output m_axi_input_r_AWVALID;
  input [0:0]m_axi_input_r_BID;
  output m_axi_input_r_BREADY;
  input [1:0]m_axi_input_r_BRESP;
  input m_axi_input_r_BVALID;
  input [31:0]m_axi_input_r_RDATA;
  input [0:0]m_axi_input_r_RID;
  input m_axi_input_r_RLAST;
  output m_axi_input_r_RREADY;
  input [1:0]m_axi_input_r_RRESP;
  input m_axi_input_r_RVALID;
  output [31:0]m_axi_input_r_WDATA;
  output [0:0]m_axi_input_r_WID;
  output m_axi_input_r_WLAST;
  input m_axi_input_r_WREADY;
  output [3:0]m_axi_input_r_WSTRB;
  output m_axi_input_r_WVALID;
  output [63:0]m_axi_output_r_ARADDR;
  output [1:0]m_axi_output_r_ARBURST;
  output [3:0]m_axi_output_r_ARCACHE;
  output [0:0]m_axi_output_r_ARID;
  output [7:0]m_axi_output_r_ARLEN;
  output [1:0]m_axi_output_r_ARLOCK;
  output [2:0]m_axi_output_r_ARPROT;
  output [3:0]m_axi_output_r_ARQOS;
  input m_axi_output_r_ARREADY;
  output [3:0]m_axi_output_r_ARREGION;
  output [2:0]m_axi_output_r_ARSIZE;
  output m_axi_output_r_ARVALID;
  output [63:0]m_axi_output_r_AWADDR;
  output [1:0]m_axi_output_r_AWBURST;
  output [3:0]m_axi_output_r_AWCACHE;
  output [0:0]m_axi_output_r_AWID;
  output [7:0]m_axi_output_r_AWLEN;
  output [1:0]m_axi_output_r_AWLOCK;
  output [2:0]m_axi_output_r_AWPROT;
  output [3:0]m_axi_output_r_AWQOS;
  input m_axi_output_r_AWREADY;
  output [3:0]m_axi_output_r_AWREGION;
  output [2:0]m_axi_output_r_AWSIZE;
  output m_axi_output_r_AWVALID;
  input [0:0]m_axi_output_r_BID;
  output m_axi_output_r_BREADY;
  input [1:0]m_axi_output_r_BRESP;
  input m_axi_output_r_BVALID;
  input [31:0]m_axi_output_r_RDATA;
  input [0:0]m_axi_output_r_RID;
  input m_axi_output_r_RLAST;
  output m_axi_output_r_RREADY;
  input [1:0]m_axi_output_r_RRESP;
  input m_axi_output_r_RVALID;
  output [31:0]m_axi_output_r_WDATA;
  output [0:0]m_axi_output_r_WID;
  output m_axi_output_r_WLAST;
  input m_axi_output_r_WREADY;
  output [3:0]m_axi_output_r_WSTRB;
  output m_axi_output_r_WVALID;
endmodule
