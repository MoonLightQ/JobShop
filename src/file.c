/**
 * @brief Implementation of file.h
 * 
 * @file file.c
 * @author Celery Meng
 * @date 2018-05-03
 */

#include "file.h"
#include <stdio.h>

#define MAX_JOBS_SIZE 100

order_t *new_order() {
	return (order_t*)malloc(sizeof(order_t));
}

int change_from_char_to_num() {
	char ch;
	ch = getchar();
	int num = 0;
	while (ch >= '0' && ch <= '9') {
		num = num * 10 + (ch - '0');
		ch = getchar();
	}
	printf("%d ", num);
	return num;
}

void read_from_console(order_t *input_order) {
	char ch;
<<<<<<< HEAD
	int index;                 /*Ñ­»·±äÁ¿*/
	int num_of_precedure;
	scanf("%d", &(test_order->num_of_jobs));       /*ÊäÈë²úÆ·²ÎÊı*/
	scanf("%d", &(test_order->num_of_machines));  /*ÊäÈë»úÆ÷ÊıÄ¿*/
	test_order->operations = (operation_t**)malloc(sizeof(operation_t*) * test_order->num_of_jobs);  //ÎªÖ¸ÕëÊı×é¶¯Ì¬·ÖÅä¿Õ¼ä 
	for (index = 0; index < test_order->num_of_jobs; index++) {
		test_order->operations[index] = (operation_t*)malloc(sizeof(operation_t) * 10);  //ÎªÊı×éÖĞµÄÔªËØ·ÖÅä¿Õ¼ä 
		if (test_order->operations[index] == NULL) {
			printf("·ÖÅäÊ§°Ü\n");
		}
	}
	for (index = 0; index < test_order->num_of_jobs; index++) {
		num_of_precedure = 0;
		scanf("%d", &((test_order->operations[index][num_of_precedure]).period));   //²úÆ·ĞòºÅ 
		ch = getchar();
		while (1) {
			if (ch == '(') {
				(test_order->operations[index][num_of_precedure]).period = change_from_char_to_num(getchar());
				(test_order->operations[index][num_of_precedure]).machine = change_from_char_to_num(getchar());
				num_of_precedure++;
=======
	int i;                 /*å¾ªç¯å˜é‡*/
	int a;
	scanf("%d", &(input_order->num_of_jobs));       /*è¾“å…¥äº§å“å‚æ•°*/
	scanf("%d", &(input_order->num_of_machines));  /*è¾“å…¥æœºå™¨æ•°ç›®*/
	input_order->operations = (operation_t**)malloc(sizeof(operation_t*) * input_order->num_of_jobs);  //ä¸ºæŒ‡é’ˆæ•°ç»„åŠ¨æ€åˆ†é…ç©ºé—´ 
	for (i = 0; i < input_order->num_of_jobs; i++) {
		input_order->operations[i] = (operation_t*)malloc(sizeof(operation_t) * MAX_JOBS_SIZE);  //ä¸ºæ•°ç»„ä¸­çš„å…ƒç´ åˆ†é…ç©ºé—´ 
	}
	for (i = 0; i < input_order->num_of_jobs; i++) {
		a = 0;
		int b;
		scanf("%d", &b);
		ch = getchar();
		while (1) {
			if (ch == '(') {
				(input_order->operations[i][a]).period = change_from_char_to_num(getchar());
				(input_order->operations[i][a]).machine = change_from_char_to_num(getchar());
				a++;
				ch = getchar();
>>>>>>> 7c08cd0e481e4cf8eb76a994b7167dca3dc190de
			}
			if (ch == '\n') {
				break;
			}
			ch = getchar();
		}
		printf("\n");
	}
}

void read_from_file(order_t *input_order, const char *path) {
	FILE *fp = fopen(path, "r");
	if (fp == NULL) {
		printf("Open files failed!\n");
	}
	rewind(fp);
	char ch;
	int index;                 /*å¾ªç¯å˜é‡*/
	int num_of_precedure;
	input_order->num_of_jobs = file_change_from_char_to_num(fp);       /*è¾“å…¥äº§å“å‚æ•°*/
	input_order->num_of_machines = file_change_from_char_to_num(fp);  /*è¾“å…¥æœºå™¨æ•°ç›®*/
	input_order->operations = (operation_t**)malloc(sizeof(operation_t*) * input_order->num_of_jobs);  //ä¸ºæŒ‡é’ˆæ•°ç»„åŠ¨æ€åˆ†é…ç©ºé—´ 
	for (index = 0; index <input_order->num_of_jobs; index++) {
		input_order->operations[index] = (operation_t*)malloc(sizeof(operation_t) * 10);  //ä¸ºæ•°ç»„ä¸­çš„å…ƒç´ åˆ†é…ç©ºé—´ 
		if (input_order->operations[index] == NULL) {
			printf("åˆ†é…å¤±è´¥\n");
		}
	}
	for (index = 0; index < input_order->num_of_jobs; index++) {
		num_of_precedure = 0;
		(input_order->operations[index][num_of_precedure]).job = file_change_from_char_to_num(fp);   //äº§å“åºå· 
		ch = fgetc(fp);
		while (1) {
			if (ch == '(') {
				(input_order->operations[index][num_of_precedure]).period = file_change_from_char_to_num(fp);
				(input_order->operations[index][num_of_precedure]).machine = file_change_from_char_to_num(fp);
				num_of_precedure++;
			}
			if (ch == '\n') {
				break;
			}
			ch = fgetc(fp);
		}
		printf("\n");
	}
	fclose(fp);
}

int file_change_from_char_to_num(FILE *fp) {
	char ch = fgetc(fp);
	int num = 0;
	if (ch > '9' || ch < '0') {
		ch = fgetc(fp);
	}
	if (ch >= '0' && ch <= '9') {
		while (ch >= '0' && ch <= '9') {
			num = num * 10 + (ch - '0');
			ch = fgetc(fp);
		}
	}
	return num;
}

void delete_order(order_t *to_be_deleted)
{
	for (int i = 0; i < to_be_deleted->num_of_jobs; i++) {
		free(to_be_deleted->operations[i]);
	}
    free(to_be_deleted->operations);
	free(to_be_deleted);
}
