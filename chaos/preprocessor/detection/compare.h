# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_DETECTION_COMPARE_H
# define CHAOS_PREPROCESSOR_DETECTION_COMPARE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_COMPARE */
#
# define CHAOS_PP_COMPARE(a, b) CHAOS_PP_PRIMITIVE_COMPARE(a, b)
# define CHAOS_PP_COMPARE_ID() CHAOS_PP_COMPARE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_COMPARE_ CHAOS_PP_LAMBDA(CHAOS_PP_COMPARE)
# endif
#
# /* CHAOS_PP_PRIMITIVE_COMPARE */
#
# define CHAOS_PP_PRIMITIVE_COMPARE(a, b) \
    CHAOS_PP_IIF( \
        CHAOS_PP_BITAND \
            (CHAOS_PP_IS_NULLARY(CHAOS_PP_COMPARE_ ## a(()))) \
            (CHAOS_PP_IS_NULLARY(CHAOS_PP_COMPARE_ ## b(()))) \
    )( \
        CHAOS_PP_COMPL(CHAOS_PP_IS_NULLARY( \
            CHAOS_PP_COMPARE_ ## a( \
                CHAOS_PP_COMPARE_ ## b \
            )(()) \
        )), \
        0 \
    ) \
    /**/
# define CHAOS_PP_PRIMITIVE_COMPARE_ID() CHAOS_PP_PRIMITIVE_COMPARE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PRIMITIVE_COMPARE_ CHAOS_PP_LAMBDA(CHAOS_PP_PRIMITIVE_COMPARE)
# endif
#
# define CHAOS_PP_COMPARE___cplusplus(x) x
# define CHAOS_PP_COMPARE___DATE__(x) x
# define CHAOS_PP_COMPARE___FILE__(x) x
# define CHAOS_PP_COMPARE___LINE__(x) x
# define CHAOS_PP_COMPARE___STDC__(x) x
# define CHAOS_PP_COMPARE___STDC_HOSTED__(x) x
# define CHAOS_PP_COMPARE___STDC_VERSION__(x) x
# define CHAOS_PP_COMPARE___TIME__(x) x
# define CHAOS_PP_COMPARE___STDC_IEC_559__(x) x
# define CHAOS_PP_COMPARE___STDC_IEC_559_COMPLEX__(x) x
# define CHAOS_PP_COMPARE___STDC_ISO_10646__(x) x
# define CHAOS_PP_COMPARE__Bool(x) x
# define CHAOS_PP_COMPARE__Complex(x) x
# define CHAOS_PP_COMPARE__Imaginary(x) x
# define CHAOS_PP_COMPARE__Pragma(x) x
# define CHAOS_PP_COMPARE_asm(x) x
# define CHAOS_PP_COMPARE_and(x) x
# define CHAOS_PP_COMPARE_and_eq(x) x
# define CHAOS_PP_COMPARE_auto(x) x
# define CHAOS_PP_COMPARE_bitand(x) x
# define CHAOS_PP_COMPARE_bitor(x) x
# define CHAOS_PP_COMPARE_bool(x) x
# define CHAOS_PP_COMPARE_break(x) x
# define CHAOS_PP_COMPARE_case(x) x
# define CHAOS_PP_COMPARE_catch(x) x
# define CHAOS_PP_COMPARE_char(x) x
# define CHAOS_PP_COMPARE_class(x) x
# define CHAOS_PP_COMPARE_compl(x) x
# define CHAOS_PP_COMPARE_const(x) x
# define CHAOS_PP_COMPARE_const_cast(x) x
# define CHAOS_PP_COMPARE_continue(x) x
# define CHAOS_PP_COMPARE_default(x) x
# define CHAOS_PP_COMPARE_define(x) x
# define CHAOS_PP_COMPARE_defined(x) x
# define CHAOS_PP_COMPARE_delete(x) x
# define CHAOS_PP_COMPARE_do(x) x
# define CHAOS_PP_COMPARE_double(x) x
# define CHAOS_PP_COMPARE_dynamic_cast(x) x
# define CHAOS_PP_COMPARE_else(x) x
# define CHAOS_PP_COMPARE_elif(x) x
# define CHAOS_PP_COMPARE_endif(x) x
# define CHAOS_PP_COMPARE_enum(x) x
# define CHAOS_PP_COMPARE_error(x) x
# define CHAOS_PP_COMPARE_explicit(x) x
# define CHAOS_PP_COMPARE_export(x) x
# define CHAOS_PP_COMPARE_extern(x) x
# define CHAOS_PP_COMPARE_false(x) x
# define CHAOS_PP_COMPARE_float(x) x
# define CHAOS_PP_COMPARE_for(x) x
# define CHAOS_PP_COMPARE_friend(x) x
# define CHAOS_PP_COMPARE_goto(x) x
# define CHAOS_PP_COMPARE_if(x) x
# define CHAOS_PP_COMPARE_ifdef(x) x
# define CHAOS_PP_COMPARE_ifndef(x) x
# define CHAOS_PP_COMPARE_include(x) x
# define CHAOS_PP_COMPARE_inline(x) x
# define CHAOS_PP_COMPARE_int(x) x
# define CHAOS_PP_COMPARE_line(x) x
# define CHAOS_PP_COMPARE_long(x) x
# define CHAOS_PP_COMPARE_mutable(x) x
# define CHAOS_PP_COMPARE_namespace(x) x
# define CHAOS_PP_COMPARE_new(x) x
# define CHAOS_PP_COMPARE_not(x) x
# define CHAOS_PP_COMPARE_not_eq(x) x
# define CHAOS_PP_COMPARE_operator(x) x
# define CHAOS_PP_COMPARE_or(x) x
# define CHAOS_PP_COMPARE_or_eq(x) x
# define CHAOS_PP_COMPARE_pragma(x) x
# define CHAOS_PP_COMPARE_private(x) x
# define CHAOS_PP_COMPARE_protected(x) x
# define CHAOS_PP_COMPARE_public(x) x
# define CHAOS_PP_COMPARE_register(x) x
# define CHAOS_PP_COMPARE_reinterpret_cast(x) x
# define CHAOS_PP_COMPARE_restrict(x) x
# define CHAOS_PP_COMPARE_return(x) x
# define CHAOS_PP_COMPARE_short(x) x
# define CHAOS_PP_COMPARE_signed(x) x
# define CHAOS_PP_COMPARE_sizeof(x) x
# define CHAOS_PP_COMPARE_static(x) x
# define CHAOS_PP_COMPARE_static_cast(x) x
# define CHAOS_PP_COMPARE_struct(x) x
# define CHAOS_PP_COMPARE_switch(x) x
# define CHAOS_PP_COMPARE_template(x) x
# define CHAOS_PP_COMPARE_this(x) x
# define CHAOS_PP_COMPARE_throw(x) x
# define CHAOS_PP_COMPARE_true(x) x
# define CHAOS_PP_COMPARE_try(x) x
# define CHAOS_PP_COMPARE_typedef(x) x
# define CHAOS_PP_COMPARE_typeid(x) x
# define CHAOS_PP_COMPARE_typename(x) x
# define CHAOS_PP_COMPARE_undef(x) x
# define CHAOS_PP_COMPARE_union(x) x
# define CHAOS_PP_COMPARE_unsigned(x) x
# define CHAOS_PP_COMPARE_using(x) x
# define CHAOS_PP_COMPARE_virtual(x) x
# define CHAOS_PP_COMPARE_void(x) x
# define CHAOS_PP_COMPARE_volatile(x) x
# define CHAOS_PP_COMPARE_wchar_t(x) x
# define CHAOS_PP_COMPARE_while(x) x
# define CHAOS_PP_COMPARE_xor(x) x
# define CHAOS_PP_COMPARE_xor_eq(x) x
#
# endif
