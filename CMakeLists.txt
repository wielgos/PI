cmake_minimum_required(VERSION 3.17)
project(Pi C)

set(CMAKE_C_STANDARD 99)

add_executable(Pi main.c)

add_executable(week001.fibo week001/fibo.c)
add_executable(week001.perf week001/perf.c)
add_executable(week001.primes week001/primes.c)
add_executable(week001.warm_up week001/warm_up.c)

add_executable(week002.half week002/half.c)
add_executable(week002.half_natural week002/half_natural.c)
add_executable(week002.narc week002/narc.c)
add_executable(week002.weight week002/weight.c)

add_executable(week003.min week003/min.c)
add_executable(week003.pair week003/pair.c)
add_executable(week003.pair_bad_implementation week003/pair_bad_implementation.c)
add_executable(week003.pri week003/pri.c)

add_executable(week004.fact week004/fact.c)
add_executable(week004.merge week004/merge.c)
add_executable(week004.neigh week004/neigh.c)

add_executable(week005.field week005/field.c)
add_executable(week005.spiral week005/spiral.c)
add_executable(week005.square week005/square.c)

add_executable(week006.rec week006/rec.c)
add_executable(week006.rom week006/rom.c)
add_executable(week006.tri week006/tri.c)

add_executable(week007.bin week007/bin.c)
add_executable(week007.seg week007/seg.c)
add_executable(week007.stamp week007/stamp.c)

add_executable(week008.last week008/last.c)
add_executable(week008.last2 week008/last2.c)
add_executable(week008.odd week008/odd.c)
add_executable(week008.seq week008/seq.c)

add_executable(week009.ring week009/ring.c)
add_executable(week009.semi week009/semi.c)
add_executable(week009.sol week009/sol.c)

add_executable(week010.ban week010/ban.c)
add_executable(week010.jump week010/jump.c)
add_executable(week010.net week010/net.c)

add_executable(week011.1 week011/1.c)
add_executable(week011.2 week011/2.c)
add_executable(week011.3 week011/3.c)