#include <uk/config.h>
#include "ruby/ruby.h"

#define init(func, name) {	\
    extern void func(void);	\
    ruby_init_ext(name".so", func); \
}

void ruby_init_ext(const char *name, void (*init)(void));

void Init_ext(void)
{
#if CONFIG_LIBRUBY_EXT_STRSCAN
    init(Init_strscan, "strscan");
#endif
#if CONFIG_LIBRUBY_EXT_SYSLOG
    init(Init_syslog, "syslog");
#endif
#if CONFIG_LIBRUBY_EXT_JSON
    init(Init_generator, "json/ext/generator");
    init(Init_parser, "json/ext/parser");
#endif
#if CONFIG_LIBRUBY_EXT_RBCONFIG_SIZEOF
    init(Init_sizeof, "rbconfig/sizeof");
#endif
#if CONFIG_LIBRUBY_EXT_BIGDECIMAL
    init(Init_bigdecimal, "bigdecimal");
    init(Init_util, "bigdecimal/util");
#endif
#if CONFIG_LIBRUBY_EXT_RACC_CPARSE
    init(Init_cparse, "racc/cparse");
#endif
#if CONFIG_LIBRUBY_EXT_DIGEST
    init(Init_digest, "digest");
    init(Init_bubblebabble, "digest/bubblebabble");
    init(Init_md5, "digest/md5");
    init(Init_rmd160, "digest/rmd160");
    init(Init_sha1, "digest/sha1");
    init(Init_sha2, "digest/sha2");
#endif
#if CONFIG_LIBRUBY_EXT_PSYCH
    init(Init_psych, "psych");
#endif
#if CONFIG_LIBRUBY_EXT_CGI_ESCAPE
    init(Init_escape, "cgi/escape");
#endif
#if CONFIG_LIBRUBY_EXT_FCNTL
    init(Init_fcntl, "fcntl");
#endif
    init(Init_stringio, "stringio");
#if CONFIG_LIBRUBY_EXT_SOCKET
    init(Init_socket, "socket");
#endif
    init(Init_pathname, "pathname");
#if CONFIG_LIBRUBY_EXT_DATE_CORE
    init(Init_date_core, "date_core");
#endif
#if CONFIG_LIBRUBY_EXT_PTY
    init(Init_pty, "pty");
#endif
#if CONFIG_LIBRUBY_EXT_OPENSSL
    init(Init_openssl, "openssl");
#endif
#if CONFIG_LIBRUBY_EXT_FIBER
    init(Init_fiber, "fiber");
#endif
#if CONFIG_LIBRUBY_EXT_FIDDLE
    init(Init_fiddle, "fiddle");
#endif
#if CONFIG_LIBRUBY_EXT_ETC
    init(Init_etc, "etc");
#endif
#if CONFIG_LIBRUBY_EXT_CONTINUATION
    init(Init_continuation, "continuation");
#endif
#if CONFIG_LIBRUBY_EXT_OBJSPACE
    init(Init_objspace, "objspace");
#endif
#if CONFIG_LIBRUBY_EXT_COVERAGE
    init(Init_coverage, "coverage");
#endif
#if CONFIG_LIBRUBY_EXT_IO_CONSOLE
    init(Init_console, "io/console");
#endif
#if CONFIG_LIBRUBY_EXT_IO_NONBLOCK
    init(Init_nonblock, "io/nonblock");
#endif
#if CONFIG_LIBRUBY_EXT_IO_WAIT
    init(Init_wait, "io/wait");
#endif
#if CONFIG_LIBRUBY_EXT_RIPPER
    init(Init_ripper, "ripper");
#endif
#if CONFIG_LIBRUBY_EXT_NKF
    init(Init_nkf, "nkf");
#endif
#if CONFIG_LIBRUBY_EXT_ZLIB
    init(Init_zlib, "zlib");
#endif
#if CONFIG_LIBRUBY_EXT_SDBM
    init(Init_sdbm, "sdbm");
#endif
}
