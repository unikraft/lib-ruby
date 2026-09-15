#include <stdlib.h>

#define RUBY_LIB_DIR "/lib/ruby/" LIBRUBY_RUBY_VERSION
#define RUBY_GEM_DIR "/lib/ruby/gems/" LIBRUBY_RUBY_VERSION

extern int ruby_main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	setenv("GEM_HOME", RUBY_GEM_DIR, 0);
	setenv("GEM_PATH", RUBY_GEM_DIR, 0);
	setenv("RUBYGEMS_GEMDEPS", RUBY_LIB_DIR "/Gemfile", 0);
	setenv("RUBYLIB",
	       RUBY_LIB_DIR ":"
	       RUBY_LIB_DIR "/x86_64-linux:"
	       RUBY_LIB_DIR "/.ext", 0);

	return ruby_main(argc, argv);
}
