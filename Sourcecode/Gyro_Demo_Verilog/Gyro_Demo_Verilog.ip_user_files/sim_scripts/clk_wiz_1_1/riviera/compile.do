vlib work
vlib riviera

vlib riviera/xil_defaultlib
vlib riviera/xpm

vmap xil_defaultlib riviera/xil_defaultlib
vmap xpm riviera/xpm

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../ipstatic" \
"D:/Xilinx/Vivado/2018.3/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \

vcom -work xpm -93 \
"D:/Xilinx/Vivado/2018.3/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../ipstatic" \
"../../../../Gyro_Demo_Verilog.srcs/sources_1/ip/clk_wiz_1_1/clk_wiz_1_clk_wiz.v" \
"../../../../Gyro_Demo_Verilog.srcs/sources_1/ip/clk_wiz_1_1/clk_wiz_1.v" \

vlog -work xil_defaultlib \
"glbl.v"

