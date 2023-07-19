import os

env = Environment(CC='gcc', CCFLAGS='-std=c99 -O3 -ftree-vectorize -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wcast-align -Wstrict-prototypes -Wswitch-enum -Wunreachable-code -Wformat=2')

env.StaticLibrary('http', Glob('src/http/*.c'))
env.StaticLibrary('api', Glob('src/api/*.c'))
env.Program('mtbcord', Glob('src/*.c'), LIBS=['http', 'api'], LIBPATH='.', CPPPATH=['src/http/', 'src/api/', 'deps/termbox2/']) 
