# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_RECURSION_PHASE_H
# define CHAOS_PREPROCESSOR_RECURSION_PHASE_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
#
# /* CHAOS_PP_PHASE */
#
# define CHAOS_PP_PHASE(offset) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_PHASE_, offset)
# define CHAOS_PP_PHASE_ID() CHAOS_PP_PHASE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PHASE_ CHAOS_PP_LAMBDA(CHAOS_PP_PHASE)
# endif
#
# define CHAOS_IP_PHASE_0(n, macro) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_PHASE_I_, n)(macro)
# define CHAOS_IP_PHASE_1(n, macro) CHAOS_IP_PHASE_0(CHAOS_PP_INC(n), macro)
# define CHAOS_IP_PHASE_2(n, macro) CHAOS_IP_PHASE_1(CHAOS_PP_INC(n), macro)
# define CHAOS_IP_PHASE_3(n, macro) CHAOS_IP_PHASE_2(CHAOS_PP_INC(n), macro)
# define CHAOS_IP_PHASE_4(n, macro) CHAOS_IP_PHASE_3(CHAOS_PP_INC(n), macro)
# define CHAOS_IP_PHASE_5(n, macro) CHAOS_IP_PHASE_4(CHAOS_PP_INC(n), macro)
#
# define CHAOS_IP_PHASE_I_0(macro) macro
# define CHAOS_IP_PHASE_I_1(macro) CHAOS_PP_DEFER(macro)
# define CHAOS_IP_PHASE_I_2(macro) macro CHAOS_PP_OBSTRUCT()
# define CHAOS_IP_PHASE_I_3(macro) CHAOS_PP_DEFER(CHAOS_IP_PHASE_I_2)(macro)
# define CHAOS_IP_PHASE_I_4(macro) CHAOS_PP_DEFER(CHAOS_IP_PHASE_I_3)(macro)
# define CHAOS_IP_PHASE_I_5(macro) CHAOS_PP_DEFER(CHAOS_IP_PHASE_I_4)(macro)
#
# endif
