#include "ruby/ruby.h"

#define init(func, name) {	\
    extern void func(void);	\
    ruby_init_ext(name".so", func); \
}

void ruby_init_ext(const char *name, void (*init)(void));

void Init_ext(void)
{
    init(Init_strscan, "strscan");
    init(Init_syslog, "syslog");
    init(Init_generator, "json/ext/generator");
    init(Init_parser, "json/ext/parser");
    init(Init_sizeof, "rbconfig/sizeof");
    init(Init_bigdecimal, "bigdecimal");
    init(Init_util, "bigdecimal/util");
    init(Init_cparse, "racc/cparse");
    init(Init_digest, "digest");
    init(Init_bubblebabble, "digest/bubblebabble");
    init(Init_md5, "digest/md5");
    init(Init_rmd160, "digest/rmd160");
    init(Init_sha1, "digest/sha1");
    init(Init_sha2, "digest/sha2");
    init(Init_psych, "psych");
    init(Init_escape, "cgi/escape");
    init(Init_fcntl, "fcntl");
    init(Init_stringio, "stringio");
    init(Init_socket, "socket");
    init(Init_pathname, "pathname");
    init(Init_date_core, "date_core");
    init(Init_pty, "pty");
    init(Init_openssl, "openssl");
    init(Init_fiber, "fiber");
    init(Init_fiddle, "fiddle");
    init(Init_etc, "etc");
    init(Init_continuation, "continuation");
    init(Init_objspace, "objspace");
    init(Init_coverage, "coverage");
    init(Init_console, "io/console");
    init(Init_nonblock, "io/nonblock");
    init(Init_wait, "io/wait");
    init(Init_ripper, "ripper");
    init(Init_nkf, "nkf");
    init(Init_zlib, "zlib");
    init(Init_sdbm, "sdbm");
}
