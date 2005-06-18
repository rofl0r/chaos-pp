# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_STRING_CHARIZE_H
# define CHAOS_PREPROCESSOR_STRING_CHARIZE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_CHARIZE */
#
# define CHAOS_PP_CHARIZE(c) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_CHARIZE_, c)
# define CHAOS_PP_CHARIZE_ID() CHAOS_PP_CHARIZE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CHARIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_CHARIZE)
# endif
#
# define CHAOS_IP_CHARIZE__ '_'
# define CHAOS_IP_CHARIZE_0 '0'
# define CHAOS_IP_CHARIZE_1 '1'
# define CHAOS_IP_CHARIZE_2 '2'
# define CHAOS_IP_CHARIZE_3 '3'
# define CHAOS_IP_CHARIZE_4 '4'
# define CHAOS_IP_CHARIZE_5 '5'
# define CHAOS_IP_CHARIZE_6 '6'
# define CHAOS_IP_CHARIZE_7 '7'
# define CHAOS_IP_CHARIZE_8 '8'
# define CHAOS_IP_CHARIZE_9 '9'
# define CHAOS_IP_CHARIZE_a 'a'
# define CHAOS_IP_CHARIZE_b 'b'
# define CHAOS_IP_CHARIZE_c 'c'
# define CHAOS_IP_CHARIZE_d 'd'
# define CHAOS_IP_CHARIZE_e 'e'
# define CHAOS_IP_CHARIZE_f 'f'
# define CHAOS_IP_CHARIZE_g 'g'
# define CHAOS_IP_CHARIZE_h 'h'
# define CHAOS_IP_CHARIZE_i 'i'
# define CHAOS_IP_CHARIZE_j 'j'
# define CHAOS_IP_CHARIZE_k 'k'
# define CHAOS_IP_CHARIZE_l 'l'
# define CHAOS_IP_CHARIZE_m 'm'
# define CHAOS_IP_CHARIZE_n 'n'
# define CHAOS_IP_CHARIZE_o 'o'
# define CHAOS_IP_CHARIZE_p 'p'
# define CHAOS_IP_CHARIZE_q 'q'
# define CHAOS_IP_CHARIZE_r 'r'
# define CHAOS_IP_CHARIZE_s 's'
# define CHAOS_IP_CHARIZE_t 't'
# define CHAOS_IP_CHARIZE_u 'u'
# define CHAOS_IP_CHARIZE_v 'v'
# define CHAOS_IP_CHARIZE_w 'w'
# define CHAOS_IP_CHARIZE_x 'x'
# define CHAOS_IP_CHARIZE_y 'y'
# define CHAOS_IP_CHARIZE_z 'z'
# define CHAOS_IP_CHARIZE_A 'A'
# define CHAOS_IP_CHARIZE_B 'B'
# define CHAOS_IP_CHARIZE_C 'C'
# define CHAOS_IP_CHARIZE_D 'D'
# define CHAOS_IP_CHARIZE_E 'E'
# define CHAOS_IP_CHARIZE_F 'F'
# define CHAOS_IP_CHARIZE_G 'G'
# define CHAOS_IP_CHARIZE_H 'H'
# define CHAOS_IP_CHARIZE_I 'I'
# define CHAOS_IP_CHARIZE_J 'J'
# define CHAOS_IP_CHARIZE_K 'K'
# define CHAOS_IP_CHARIZE_L 'L'
# define CHAOS_IP_CHARIZE_M 'M'
# define CHAOS_IP_CHARIZE_N 'N'
# define CHAOS_IP_CHARIZE_O 'O'
# define CHAOS_IP_CHARIZE_P 'P'
# define CHAOS_IP_CHARIZE_Q 'Q'
# define CHAOS_IP_CHARIZE_R 'R'
# define CHAOS_IP_CHARIZE_S 'S'
# define CHAOS_IP_CHARIZE_T 'T'
# define CHAOS_IP_CHARIZE_U 'U'
# define CHAOS_IP_CHARIZE_V 'V'
# define CHAOS_IP_CHARIZE_W 'W'
# define CHAOS_IP_CHARIZE_X 'X'
# define CHAOS_IP_CHARIZE_Y 'Y'
# define CHAOS_IP_CHARIZE_Z 'Z'
#
# endif
