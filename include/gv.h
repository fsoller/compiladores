/**
 * @file gv.h
 * @author Lucas Schnorr
 * @date 16 Sep 2013
 * @brief Funções públicas do módulo gv. Verifique a implementação para
 *  maiores detalhes de como utilizar cada uma. 
 */

#ifndef __GV_H__
#define __GV_H__
void gv_init (const char *filename);
void gv_close (void);
void gv_declare (const int tipo, const void *pointer, const char *name);
void gv_connect (const void *p1, const void *p2);
#endif
