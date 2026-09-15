#ifndef EXTCONF_H
#define EXTCONF_H
#define JSON_GENERATOR 1
/* SIMD disabled: <x86intrin.h> and <cpuid.h> are compiler headers, not on
 * the -nostdinc include path.
 */
/*#define HAVE_X86INTRIN_H 1*/
/*#define JSON_ENABLE_SIMD 1*/
/*#define HAVE_CPUID_H 1*/
#define Init_generator Init_json_ext_generator
#define InitVM_generator InitVM_json_ext_generator
#define RUBY_EXPORT 1
#endif
