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
# if !defined CHAOS_PP_VALUE
#    define CHAOS_PP_VALUE 0
# elif (CHAOS_PP_VALUE) < 0
#    undef CHAOS_PP_VALUE
#    define CHAOS_PP_VALUE 0
# endif
#
# undef CHAOS_IP_SLOT_TEMP_0
# undef CHAOS_IP_SLOT_TEMP_1
# undef CHAOS_IP_SLOT_TEMP_2
# undef CHAOS_IP_SLOT_TEMP_3
# undef CHAOS_IP_SLOT_TEMP_4
# undef CHAOS_IP_SLOT_TEMP_5
# undef CHAOS_IP_SLOT_TEMP_6
# undef CHAOS_IP_SLOT_TEMP_7
# undef CHAOS_IP_SLOT_TEMP_8
# undef CHAOS_IP_SLOT_TEMP_9
#
# if (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(9) == 0
#    define CHAOS_IP_SLOT_TEMP_9 0
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(9) == 1
#    define CHAOS_IP_SLOT_TEMP_9 1
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(9) == 2
#    define CHAOS_IP_SLOT_TEMP_9 2
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(9) == 3
#    define CHAOS_IP_SLOT_TEMP_9 3
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(9) == 4
#    define CHAOS_IP_SLOT_TEMP_9 4
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(9) == 5
#    define CHAOS_IP_SLOT_TEMP_9 5
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(9) == 6
#    define CHAOS_IP_SLOT_TEMP_9 6
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(9) == 7
#    define CHAOS_IP_SLOT_TEMP_9 7
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(9) == 8
#    define CHAOS_IP_SLOT_TEMP_9 8
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(9) == 9
#    define CHAOS_IP_SLOT_TEMP_9 9
# endif
#
# if (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(8) == 0
#    define CHAOS_IP_SLOT_TEMP_8 0
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(8) == 1
#    define CHAOS_IP_SLOT_TEMP_8 1
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(8) == 2
#    define CHAOS_IP_SLOT_TEMP_8 2
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(8) == 3
#    define CHAOS_IP_SLOT_TEMP_8 3
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(8) == 4
#    define CHAOS_IP_SLOT_TEMP_8 4
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(8) == 5
#    define CHAOS_IP_SLOT_TEMP_8 5
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(8) == 6
#    define CHAOS_IP_SLOT_TEMP_8 6
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(8) == 7
#    define CHAOS_IP_SLOT_TEMP_8 7
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(8) == 8
#    define CHAOS_IP_SLOT_TEMP_8 8
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(8) == 9
#    define CHAOS_IP_SLOT_TEMP_8 9
# endif
#
# if (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(7) == 0
#    define CHAOS_IP_SLOT_TEMP_7 0
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(7) == 1
#    define CHAOS_IP_SLOT_TEMP_7 1
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(7) == 2
#    define CHAOS_IP_SLOT_TEMP_7 2
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(7) == 3
#    define CHAOS_IP_SLOT_TEMP_7 3
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(7) == 4
#    define CHAOS_IP_SLOT_TEMP_7 4
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(7) == 5
#    define CHAOS_IP_SLOT_TEMP_7 5
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(7) == 6
#    define CHAOS_IP_SLOT_TEMP_7 6
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(7) == 7
#    define CHAOS_IP_SLOT_TEMP_7 7
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(7) == 8
#    define CHAOS_IP_SLOT_TEMP_7 8
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(7) == 9
#    define CHAOS_IP_SLOT_TEMP_7 9
# endif
#
# if (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(6) == 0
#    define CHAOS_IP_SLOT_TEMP_6 0
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(6) == 1
#    define CHAOS_IP_SLOT_TEMP_6 1
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(6) == 2
#    define CHAOS_IP_SLOT_TEMP_6 2
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(6) == 3
#    define CHAOS_IP_SLOT_TEMP_6 3
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(6) == 4
#    define CHAOS_IP_SLOT_TEMP_6 4
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(6) == 5
#    define CHAOS_IP_SLOT_TEMP_6 5
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(6) == 6
#    define CHAOS_IP_SLOT_TEMP_6 6
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(6) == 7
#    define CHAOS_IP_SLOT_TEMP_6 7
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(6) == 8
#    define CHAOS_IP_SLOT_TEMP_6 8
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(6) == 9
#    define CHAOS_IP_SLOT_TEMP_6 9
# endif
#
# if (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(5) == 0
#    define CHAOS_IP_SLOT_TEMP_5 0
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(5) == 1
#    define CHAOS_IP_SLOT_TEMP_5 1
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(5) == 2
#    define CHAOS_IP_SLOT_TEMP_5 2
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(5) == 3
#    define CHAOS_IP_SLOT_TEMP_5 3
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(5) == 4
#    define CHAOS_IP_SLOT_TEMP_5 4
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(5) == 5
#    define CHAOS_IP_SLOT_TEMP_5 5
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(5) == 6
#    define CHAOS_IP_SLOT_TEMP_5 6
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(5) == 7
#    define CHAOS_IP_SLOT_TEMP_5 7
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(5) == 8
#    define CHAOS_IP_SLOT_TEMP_5 8
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(5) == 9
#    define CHAOS_IP_SLOT_TEMP_5 9
# endif
#
# if (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(4) == 0
#    define CHAOS_IP_SLOT_TEMP_4 0
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(4) == 1
#    define CHAOS_IP_SLOT_TEMP_4 1
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(4) == 2
#    define CHAOS_IP_SLOT_TEMP_4 2
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(4) == 3
#    define CHAOS_IP_SLOT_TEMP_4 3
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(4) == 4
#    define CHAOS_IP_SLOT_TEMP_4 4
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(4) == 5
#    define CHAOS_IP_SLOT_TEMP_4 5
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(4) == 6
#    define CHAOS_IP_SLOT_TEMP_4 6
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(4) == 7
#    define CHAOS_IP_SLOT_TEMP_4 7
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(4) == 8
#    define CHAOS_IP_SLOT_TEMP_4 8
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(4) == 9
#    define CHAOS_IP_SLOT_TEMP_4 9
# endif
#
# if (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(3) == 0
#    define CHAOS_IP_SLOT_TEMP_3 0
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(3) == 1
#    define CHAOS_IP_SLOT_TEMP_3 1
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(3) == 2
#    define CHAOS_IP_SLOT_TEMP_3 2
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(3) == 3
#    define CHAOS_IP_SLOT_TEMP_3 3
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(3) == 4
#    define CHAOS_IP_SLOT_TEMP_3 4
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(3) == 5
#    define CHAOS_IP_SLOT_TEMP_3 5
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(3) == 6
#    define CHAOS_IP_SLOT_TEMP_3 6
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(3) == 7
#    define CHAOS_IP_SLOT_TEMP_3 7
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(3) == 8
#    define CHAOS_IP_SLOT_TEMP_3 8
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(3) == 9
#    define CHAOS_IP_SLOT_TEMP_3 9
# endif
#
# if (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(2) == 0
#    define CHAOS_IP_SLOT_TEMP_2 0
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(2) == 1
#    define CHAOS_IP_SLOT_TEMP_2 1
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(2) == 2
#    define CHAOS_IP_SLOT_TEMP_2 2
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(2) == 3
#    define CHAOS_IP_SLOT_TEMP_2 3
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(2) == 4
#    define CHAOS_IP_SLOT_TEMP_2 4
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(2) == 5
#    define CHAOS_IP_SLOT_TEMP_2 5
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(2) == 6
#    define CHAOS_IP_SLOT_TEMP_2 6
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(2) == 7
#    define CHAOS_IP_SLOT_TEMP_2 7
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(2) == 8
#    define CHAOS_IP_SLOT_TEMP_2 8
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(2) == 9
#    define CHAOS_IP_SLOT_TEMP_2 9
# endif
#
# if (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(1) == 0
#    define CHAOS_IP_SLOT_TEMP_1 0
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(1) == 1
#    define CHAOS_IP_SLOT_TEMP_1 1
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(1) == 2
#    define CHAOS_IP_SLOT_TEMP_1 2
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(1) == 3
#    define CHAOS_IP_SLOT_TEMP_1 3
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(1) == 4
#    define CHAOS_IP_SLOT_TEMP_1 4
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(1) == 5
#    define CHAOS_IP_SLOT_TEMP_1 5
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(1) == 6
#    define CHAOS_IP_SLOT_TEMP_1 6
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(1) == 7
#    define CHAOS_IP_SLOT_TEMP_1 7
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(1) == 8
#    define CHAOS_IP_SLOT_TEMP_1 8
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(1) == 9
#    define CHAOS_IP_SLOT_TEMP_1 9
# endif
#
# if (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(0) == 0
#    define CHAOS_IP_SLOT_TEMP_0 0
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(0) == 1
#    define CHAOS_IP_SLOT_TEMP_0 1
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(0) == 2
#    define CHAOS_IP_SLOT_TEMP_0 2
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(0) == 3
#    define CHAOS_IP_SLOT_TEMP_0 3
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(0) == 4
#    define CHAOS_IP_SLOT_TEMP_0 4
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(0) == 5
#    define CHAOS_IP_SLOT_TEMP_0 5
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(0) == 6
#    define CHAOS_IP_SLOT_TEMP_0 6
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(0) == 7
#    define CHAOS_IP_SLOT_TEMP_0 7
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(0) == 8
#    define CHAOS_IP_SLOT_TEMP_0 8
# elif (CHAOS_PP_VALUE) CHAOS_IP_SLOT_DIGIT(0) == 9
#    define CHAOS_IP_SLOT_TEMP_0 9
# endif
#
# undef CHAOS_PP_VALUE
