# Ruby for Unikraft
This is the port of Ruby for Unikraft as external library.

## Build
Ruby depends on the following libraries, that need to be added to `Makefile` in
this order:

* `pthreads`, e.g. `pthread-embedded`
* C++ libraries: `compiler-rt`, `libcxx`, `libcxxabi`, `libunwind`
* `libc`, e.g. `newlib`
* network stack, e.g. `lwip`
* optional extensions: `openssl`, `zlib`.

A mandatory build dependency is the Ruby interpreter itself, because it is
needed to properly configure the original sources.  If you want to build the
extensions as well, then you will also need to have them installed on your
build system (e.g. `openssl`, `zlib`).

## Root filesystem
### Creating the filesystem
Ruby interpreter needs a filesystem which should contain its libraries.
Therefore, the filesystem needs to be created before running the VM.  You can
do this by running the following command:

```bash
make ruby-rootfs path=<some directory>
```

It will create the filesystem in the directory you choose where it will install
the Ruby libraries. In order to achieve this, the original code needs to be
configured and build with paths relative to the provided root directory. These
two steps are executed transparently, all you have to do is just running the
above `make` command.

### Using the filesystem
The same steps presented in the same subsection of the Python 3 port README
should be followed.

## Running modes
The next step is to pick a running mode. We currently support the following
running modes:

1. **Ruby script**. You can use any file available in the root filesystem.  You
should use Qemu's `-append` option to pass parameter to Python interpreter,
e.g. `-append "vfs.rootdev=test -- <some file in rootfs>"`.  Please notice that
we are using `test` for the 9pfs mounting tag. For brevity we will skip setting
the mounting tag in the next examples.

2. **Ruby shell**. You can run the interactive Ruby shell, which is just a Ruby
script, with the parameters: `-append "-- /bin/irb"`.

3. **Command line**. You can provide a one line script using the `-e` option,
e,g. `-append "-- -e 'puts \"Hello World\"'"`.

4. **Ruby unit testing (developers only)**. With this mode you can check what
functionality is completely supported by the Ruby port. Please be aware that
this mode is unstable and some of the tests may block. In order to run all the
unit tests you should use the following parameters: `-append "-- /lib/ruby/2.6.0/test/runner.rb --exclude=dtrace --exclude=mkmf --exclude=win32ole --exclude=rdoc"`.

We also provide a configuration option for building `miniruby`, a minimalistic
version of the Ruby interpreter build in the same way as for Linux. `miniruby`
does not have any extension or encoding, therefore its usage is limited. You
can either use it for running simple scripts or simple one liners.

### Memory usage
Some of the unit tests may require a lot of memory to run; for this
reason please allow for at least 1G of memory for unit testing (e.g.,
`-m 1G` in Qemu).

## Further information
Please refer to the `README.md` as well as the documentation in the `doc/`
subdirectory of the main unikraft repository.
