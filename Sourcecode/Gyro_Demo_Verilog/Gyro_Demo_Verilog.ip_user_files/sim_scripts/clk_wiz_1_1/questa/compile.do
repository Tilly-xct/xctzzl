vlib questa_lib/work
vlib questa_lib/msim

vlib questa_lib/msim/xil_defaultlib
vlib questa_lib/msim/xpm

vmap xil_defaultlib questa_lib/msim/xil_defaultlib
vmap xpm questa_lib/msim/xpm

vlog -work xil_defaultlib -64 -sv "+incdir+../../../ipstatic" \
"D:/Xilinx/Vivado/2018.3/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \

vcom -work xpm -64 -93 \
"D:/Xilinx/Vivado/2018.3/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work xil_defaultlib -64 "+incdir+../../../ipstatic" \
"../../../../Gyro_Demo_Verilog.srcs/sources_1/ip/clk_wiz_1_1/clk_wiz_1_clk_wiz.v" \
"../../../../Gyro_Demo_Verilog.srcs/sources_1/ip/clk_wiz_1_1/clk_wiz_1.v" \

vlog -work xil_defaultlib \
"glbl.v"
