#ifndef EXTCONF_H
#define EXTCONF_H
#define HAVE_RB_ENC_INTERNED_STR 1
#define HAVE_RB_STR_TO_INTERNED_STR 1
#define HAVE_RB_HASH_NEW_CAPA 1
#define HAVE_RB_HASH_BULK_INSERT 1
/* SIMD disabled: <x86intrin.h> and <cpuid.h> are compiler headers, not on
 * the -nostdinc include path.
 */
/*#define HAVE_X86INTRIN_H 1*/
/*#define JSON_ENABLE_SIMD 1*/
/*#define HAVE_CPUID_H 1*/
#define Init_parser Init_json_ext_parser
#define InitVM_parser InitVM_json_ext_parser
#define RUBY_EXPORT 1
#endif
