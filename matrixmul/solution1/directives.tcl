############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_interface -mode s_axilite "matrixmul"
set_directive_interface -mode m_axi -depth 1024 -offset slave "matrixmul" A
set_directive_interface -mode m_axi -depth 1024 -offset slave "matrixmul" B
set_directive_interface -mode m_axi -depth 1024 -offset slave "matrixmul" out
set_directive_pipeline -II 1 "matrixmul/Col"
