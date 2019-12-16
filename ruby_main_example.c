#include <stdlib.h>

extern int ruby_main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	setenv("GEM_HOME", "/lib/ruby/gems/"LIBRUBY_VERSION_LONG, 0);
	setenv("GEM_PATH", "/lib/ruby/gems/"LIBRUBY_VERSION_LONG, 0);
	setenv("RUBYGEMS_GEMDEPS", "/lib/ruby/"LIBRUBY_VERSION_LONG"/Gemfile", 0);
	setenv("RUBYLIB", "/lib/ruby/"LIBRUBY_VERSION_LONG":"
		"/lib/ruby/"LIBRUBY_VERSION_LONG"/x86_64-linux:"
		"/lib/ruby/"LIBRUBY_VERSION_LONG"/.ext", 0);

	return ruby_main(argc, argv);
}
