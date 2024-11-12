#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cus.h"
#include <assert.h>
#include <threads.h>
#include <ctype.h>
                                                /*
struct mv_cesa_op_ctx
{
	struct req;

};
*/

int some() {
	 int val;
	 int result; // Declared but not initialized

	 printf("The result is: %d\n", result); // Using uninitialized variable

	 somemeth(&val);

	 int a = 3, b = 2;
	 swap(&a, &b);
	 return 2;
}

void swap(int *px, int *py)
{
	int temp;
	/* interchange *px and *py */
	temp = *px;
	*px = *py;
	*py = temp;
}


void somemeth(int inp) {
}


static int mv_cesa_des_op(struct skcipher_request *req,
		  struct mv_cesa_op_ctx *tmpl)
{
	 struct mv_cesa_des_ctx *ctx = crypto_tfm_ctx(req->base.tfm);

	 mv_cesa_update_op_cfg(tmpl, CESA_SA_DESC_CFG_CRYPTM_DES,
			   CESA_SA_DESC_CFG_CRYPTM_MSK);

	 memcpy(tmpl->ctx.skcipher.key, ctx->key, DES_KEY_SIZE);

	 return mv_cesa_skcipher_queue_req(req, tmpl);
}

static int mv_cesa_ecb_des_encrypt(struct skcipher_request *req)
{
	 struct mv_cesa_op_ctx tmpl;

	 mv_cesa_set_op_cfg(&tmpl,
			   CESA_SA_DESC_CFG_CRYPTCM_ECB |
			   CESA_SA_DESC_CFG_DIR_ENC);

	 return mv_cesa_des_op(req, &tmpl);
}

int main(int argc, char *argv[])
{
	 SharedVar = 6;
	 PrintVar(SharedVar);
	 printf("Print args %d\n", SharedVar);
	 for(int i = 1; i < argc; i++)
	 {
		  printf("Arg %d is %s\n", i, argv[i]);
	 }

	 // fork(PrintVar(SharedVar));

	 assert(SharedVar > 0);

	 int inpNo;
	 printf("Enter the size of array: ");
	 scanf("%d", &inpNo);

	 // int aNos[inpNo];
	 int *aNos = malloc(sizeof(int) * inpNo);
	 int aNos_[inpNo];
	 int inNo;

	 // aNos stores in stack
	 for(int i = 0; i < inpNo; i++)
	 {
		  printf("Enter no:");
		  scanf("%d", &inNo);
		  aNos[i] = inNo;
		  aNos_[i] = inNo;
	 }

	 for(int i = 0; i < inpNo; i++)
	 {
		  printf("No: %d %d\n", *(aNos + i), aNos_[i]); // pointer arith
	 }

	 // *aNos = malloc(sizeof(int) * inpNo);
	 // int *aNos_ = calloc(sizeof(int) * (inpNo + 1), sizeof(aNos));
	 // int *aNos_ = calloc(sizeof(int) * (inpNo + 1), sizeof(aNos));

	 free(*aNos);

	 // printf("try mem");
	 int no[] = { 1, 6, 10 };
	 char *q[3];
	 // char *p = malloc(3 * sizeof(char));
	 // char *p = "string";
	 char p[] = "string";
	 printf("Str :%12.3s: \n",  p);
	 printf("Inttt :%d: \n",  atoi(p));

	 char *a = p;
	 *p = 'a';
	 printf("Str %s \n",  a);
	 //	 free(p);

	 int s[] = { 12, 11, 10, 06, 15 };
	 *s = 66;
	 printf("No is %d", *s);

	 printf("Int arr size - %lu", sizeof(no));

	 int nos[10];
	 memset(nos, 0, 10 * sizeof(int));
	 for(int i = 0; i < 10; i++)
	 {
		  printf("No is %d\n");
	 }

	 // stores in heap, can be freed or ml
	 char *t = malloc(8);
	 strcpy(t, "aaa");
	 printf("%s \n", t);
	 printf("%d \n", &t);
	 free(t);
	 printf("%d \n", &t);
	 t = "New str";
	 printf("%s", t);
}
