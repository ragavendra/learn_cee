/*
 * =====================================================================================
 *
 *       Filename:  goto.c
 *
 *    Description:  Learn structs
 *
 *        Version:  1.0
 *        Created:  2024-11-18 12:28:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ragavendra N (rn), ragavendra.bn@gmail.com
 *        Company:  Garden Systems, Vancouver
 *
 * =====================================================================================
 */

#include	<stdio.h>
#include	<string.h>

struct es_em_ctxt;
void some_func(struct es_em_ctxt *ctxt);

struct es_fault_info {
	 unsigned long vector;
	 unsigned long error_code;
	 unsigned long cr2;
};

struct pt_regs;

/* ES instruction emulation context */
struct es_em_ctxt {
	 struct pt_regs *regs;
	 // struct insn insn;
	 struct es_fault_info fi;
};


int main() {

	struct es_em_ctxt ctxt;
	// = {};
	some_func(&ctxt);
}

void some_func(struct es_em_ctxt *ctxt){

	 // bool flag;
	// printf("Comp result %s %s \n", !3 ? "capture" : "false", flag);
	printf("Comp result %s \n", !3 ? "capture" : "false");
	printf("Ctxt fi vector %lu \n", ctxt->fi.cr2);
	memset(&ctxt->fi, 0, sizeof(ctxt->fi));
	printf("fi error code %lu \n", ctxt->fi.cr2);

	// memset(ctxt, 0, sizeof(struct es_fault_info));
}

