
set PATH=
call G:/Vivado/Vivado/Vivado/2018.3/bin/xelab xil_defaultlib.apatb_matrixmul_top glbl -prj matrixmul.prj -L smartconnect_v1_0 -L axi_protocol_checker_v1_1_12 -L axi_protocol_checker_v1_1_13 -L axis_protocol_checker_v1_1_11 -L axis_protocol_checker_v1_1_12 -L xil_defaultlib -L unisims_ver -L xpm --initfile "G:/Vivado/Vivado/Vivado/2018.3/data/xsim/ip/xsim_ip.ini" --lib "ieee_proposed=./ieee_proposed" -s matrixmul -debug wave
call G:/Vivado/Vivado/Vivado/2018.3/bin/xsim --noieeewarnings matrixmul -tclbatch matrixmul.tcl

