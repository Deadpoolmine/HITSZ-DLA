// ==============================================================
// File generated on Tue Nov 17 21:03:28 +0800 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "gmem"
#define AUTOTB_TVIN_gmem  "../tv/cdatafile/c.matrixmul.autotvin_gmem.dat"
#define AUTOTB_TVOUT_gmem  "../tv/cdatafile/c.matrixmul.autotvout_gmem.dat"
// wrapc file define: "A"
#define AUTOTB_TVIN_A  "../tv/cdatafile/c.matrixmul.autotvin_A.dat"
// wrapc file define: "B"
#define AUTOTB_TVIN_B  "../tv/cdatafile/c.matrixmul.autotvin_B.dat"
// wrapc file define: "out_r"
#define AUTOTB_TVIN_out_r  "../tv/cdatafile/c.matrixmul.autotvin_out_r.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "gmem"
#define AUTOTB_TVOUT_PC_gmem  "../tv/rtldatafile/rtl.matrixmul.autotvout_gmem.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			gmem_depth = 0;
			A_depth = 0;
			B_depth = 0;
			out_r_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{gmem " << gmem_depth << "}\n";
			total_list << "{A " << A_depth << "}\n";
			total_list << "{B " << B_depth << "}\n";
			total_list << "{out_r " << out_r_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int gmem_depth;
		int A_depth;
		int B_depth;
		int out_r_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void matrixmul (
int A[3][4],
int B[4][5],
int out[3][5]);

void AESL_WRAP_matrixmul (
int A[3][4],
int B[4][5],
int out[3][5])
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;


		// output port post check: "gmem"
		aesl_fh.read(AUTOTB_TVOUT_PC_gmem, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_gmem, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_gmem, AESL_token); // data

			sc_bv<32> *gmem_pc_buffer = new sc_bv<32>[47];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'gmem', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'gmem', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					gmem_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_gmem, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_gmem))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: gmem
				{
					// bitslice(31, 0)
					// {
						// celement: A(31, 0)
						// {
							sc_lv<32>* A_lv0_0_2_1_lv1_0_3_1 = new sc_lv<32>[47];
						// }
						// celement: B(31, 0)
						// {
							sc_lv<32>* B_lv0_0_3_1_lv1_0_4_1 = new sc_lv<32>[47];
						// }
						// celement: out(31, 0)
						// {
							sc_lv<32>* out_lv0_0_2_1_lv1_0_4_1 = new sc_lv<32>[47];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: A(31, 0)
						{
							// carray: (0) => (2) @ (1)
							for (int i_0 = 0; i_0 <= 2; i_0 += 1)
							{
								// carray: (0) => (3) @ (1)
								for (int i_1 = 0; i_1 <= 3; i_1 += 1)
								{
									hls_map_index++;
								}
							}
						}
						// celement: B(31, 0)
						{
							// carray: (0) => (3) @ (1)
							for (int i_0 = 0; i_0 <= 3; i_0 += 1)
							{
								// carray: (0) => (4) @ (1)
								for (int i_1 = 0; i_1 <= 4; i_1 += 1)
								{
									hls_map_index++;
								}
							}
						}
						// celement: out(31, 0)
						{
							// carray: (0) => (2) @ (1)
							for (int i_0 = 0; i_0 <= 2; i_0 += 1)
							{
								// carray: (0) => (4) @ (1)
								for (int i_1 = 0; i_1 <= 4; i_1 += 1)
								{
									if (&(out[0][0]) != NULL) // check the null address if the c port is array or others
									{
										out_lv0_0_2_1_lv1_0_4_1[hls_map_index].range(31, 0) = sc_bv<32>(gmem_pc_buffer[hls_map_index].range(31, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: A(31, 0)
						{
							// carray: (0) => (2) @ (1)
							for (int i_0 = 0; i_0 <= 2; i_0 += 1)
							{
								// carray: (0) => (3) @ (1)
								for (int i_1 = 0; i_1 <= 3; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : A[i_0][i_1]
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : A[0][0]
									// output_left_conversion : A[i_0][i_1]
									// output_type_conversion : (A_lv0_0_2_1_lv1_0_3_1[hls_map_index]).to_uint64()
									hls_map_index++;
								}
							}
						}
						// celement: B(31, 0)
						{
							// carray: (0) => (3) @ (1)
							for (int i_0 = 0; i_0 <= 3; i_0 += 1)
							{
								// carray: (0) => (4) @ (1)
								for (int i_1 = 0; i_1 <= 4; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : B[i_0][i_1]
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : B[0][0]
									// output_left_conversion : B[i_0][i_1]
									// output_type_conversion : (B_lv0_0_3_1_lv1_0_4_1[hls_map_index]).to_uint64()
									hls_map_index++;
								}
							}
						}
						// celement: out(31, 0)
						{
							// carray: (0) => (2) @ (1)
							for (int i_0 = 0; i_0 <= 2; i_0 += 1)
							{
								// carray: (0) => (4) @ (1)
								for (int i_1 = 0; i_1 <= 4; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : out[i_0][i_1]
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : out[0][0]
									// output_left_conversion : out[i_0][i_1]
									// output_type_conversion : (out_lv0_0_2_1_lv1_0_4_1[hls_map_index]).to_uint64()
									if (&(out[0][0]) != NULL) // check the null address if the c port is array or others
									{
										out[i_0][i_1] = (out_lv0_0_2_1_lv1_0_4_1[hls_map_index]).to_uint64();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] gmem_pc_buffer;
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "gmem"
		char* tvin_gmem = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_gmem);
		char* tvout_gmem = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_gmem);

		// "A"
		char* tvin_A = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_A);

		// "B"
		char* tvin_B = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_B);

		// "out_r"
		char* tvin_out_r = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_out_r);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_gmem, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_gmem, tvin_gmem);

		sc_bv<32>* gmem_tvin_wrapc_buffer = new sc_bv<32>[47];

		// RTL Name: gmem
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: A(31, 0)
				{
					// carray: (0) => (2) @ (1)
					for (int i_0 = 0; i_0 <= 2; i_0 += 1)
					{
						// carray: (0) => (3) @ (1)
						for (int i_1 = 0; i_1 <= 3; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : A[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : A[0][0]
							// regulate_c_name       : A
							// input_type_conversion : A[i_0][i_1]
							if (&(A[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> A_tmp_mem;
								A_tmp_mem = A[i_0][i_1];
								gmem_tvin_wrapc_buffer[hls_map_index].range(31, 0) = A_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
				// celement: B(31, 0)
				{
					// carray: (0) => (3) @ (1)
					for (int i_0 = 0; i_0 <= 3; i_0 += 1)
					{
						// carray: (0) => (4) @ (1)
						for (int i_1 = 0; i_1 <= 4; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : B[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : B[0][0]
							// regulate_c_name       : B
							// input_type_conversion : B[i_0][i_1]
							if (&(B[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> B_tmp_mem;
								B_tmp_mem = B[i_0][i_1];
								gmem_tvin_wrapc_buffer[hls_map_index].range(31, 0) = B_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
				// celement: out(31, 0)
				{
					// carray: (0) => (2) @ (1)
					for (int i_0 = 0; i_0 <= 2; i_0 += 1)
					{
						// carray: (0) => (4) @ (1)
						for (int i_1 = 0; i_1 <= 4; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : out[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : out[0][0]
							// regulate_c_name       : out
							// input_type_conversion : out[i_0][i_1]
							if (&(out[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> out_tmp_mem;
								out_tmp_mem = out[i_0][i_1];
								gmem_tvin_wrapc_buffer[hls_map_index].range(31, 0) = out_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 47; i++)
		{
			sprintf(tvin_gmem, "%s\n", (gmem_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_gmem, tvin_gmem);
		}

		tcl_file.set_num(47, &tcl_file.gmem_depth);
		sprintf(tvin_gmem, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_gmem, tvin_gmem);

		// release memory allocation
		delete [] gmem_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_A, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_A, tvin_A);

		sc_bv<32> A_tvin_wrapc_buffer;

		// RTL Name: A
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_A, "%s\n", (A_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_A, tvin_A);
		}

		tcl_file.set_num(1, &tcl_file.A_depth);
		sprintf(tvin_A, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_A, tvin_A);

		// [[transaction]]
		sprintf(tvin_B, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_B, tvin_B);

		sc_bv<32> B_tvin_wrapc_buffer;

		// RTL Name: B
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_B, "%s\n", (B_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_B, tvin_B);
		}

		tcl_file.set_num(1, &tcl_file.B_depth);
		sprintf(tvin_B, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_B, tvin_B);

		// [[transaction]]
		sprintf(tvin_out_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_out_r, tvin_out_r);

		sc_bv<32> out_r_tvin_wrapc_buffer;

		// RTL Name: out_r
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_out_r, "%s\n", (out_r_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_out_r, tvin_out_r);
		}

		tcl_file.set_num(1, &tcl_file.out_r_depth);
		sprintf(tvin_out_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_out_r, tvin_out_r);

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		matrixmul(A, B, out);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_gmem, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_gmem, tvout_gmem);

		sc_bv<32>* gmem_tvout_wrapc_buffer = new sc_bv<32>[47];

		// RTL Name: gmem
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: A(31, 0)
				{
					// carray: (0) => (2) @ (1)
					for (int i_0 = 0; i_0 <= 2; i_0 += 1)
					{
						// carray: (0) => (3) @ (1)
						for (int i_1 = 0; i_1 <= 3; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : A[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : A[0][0]
							// regulate_c_name       : A
							// input_type_conversion : A[i_0][i_1]
							if (&(A[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> A_tmp_mem;
								A_tmp_mem = A[i_0][i_1];
								gmem_tvout_wrapc_buffer[hls_map_index].range(31, 0) = A_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
				// celement: B(31, 0)
				{
					// carray: (0) => (3) @ (1)
					for (int i_0 = 0; i_0 <= 3; i_0 += 1)
					{
						// carray: (0) => (4) @ (1)
						for (int i_1 = 0; i_1 <= 4; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : B[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : B[0][0]
							// regulate_c_name       : B
							// input_type_conversion : B[i_0][i_1]
							if (&(B[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> B_tmp_mem;
								B_tmp_mem = B[i_0][i_1];
								gmem_tvout_wrapc_buffer[hls_map_index].range(31, 0) = B_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
				// celement: out(31, 0)
				{
					// carray: (0) => (2) @ (1)
					for (int i_0 = 0; i_0 <= 2; i_0 += 1)
					{
						// carray: (0) => (4) @ (1)
						for (int i_1 = 0; i_1 <= 4; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : out[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : out[0][0]
							// regulate_c_name       : out
							// input_type_conversion : out[i_0][i_1]
							if (&(out[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> out_tmp_mem;
								out_tmp_mem = out[i_0][i_1];
								gmem_tvout_wrapc_buffer[hls_map_index].range(31, 0) = out_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 47; i++)
		{
			sprintf(tvout_gmem, "%s\n", (gmem_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_gmem, tvout_gmem);
		}

		tcl_file.set_num(47, &tcl_file.gmem_depth);
		sprintf(tvout_gmem, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_gmem, tvout_gmem);

		// release memory allocation
		delete [] gmem_tvout_wrapc_buffer;

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "gmem"
		delete [] tvin_gmem;
		delete [] tvout_gmem;
		// release memory allocation: "A"
		delete [] tvin_A;
		// release memory allocation: "B"
		delete [] tvin_B;
		// release memory allocation: "out_r"
		delete [] tvin_out_r;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

