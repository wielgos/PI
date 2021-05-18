cmake_minimum_required(VERSION 3.17)
project(Pi C)

set(CMAKE_C_STANDARD 99)

add_executable(Pi main.c)

add_executable(week1.fibo week1/fibo.c)
add_executable(week1.perf week1/perf.c)
add_executable(week1.primes week1/primes.c)
add_executable(week1.warm_up week1/warm_up.c)

add_executable(week2.half week2/half.c)
add_executable(week2.half_natural week2/half_natural.c)
add_executable(week2.narc week2/narc.c)
add_executable(week2.weight week2/weight.c)

add_executable(week3.min week3/min.c)
add_executable(week3.pair week3/pair.c)
add_executable(week3.pair_bad_implementation week3/pair_bad_implementation.c)
add_executable(week3.pri week3/pri.c)

add_executable(week4.fact week4/fact.c)
add_executable(week4.merge week4/merge.c)
add_executable(week4.neigh week4/neigh.c)

add_executable(week5.field week5/field.c)
add_executable(week5.spiral week5/spiral.c)
add_executable(week5.square week5/square.c)

add_executable(week6.rec week6/rec.c)
add_executable(week6.rom week6/rom.c)
add_executable(week6.tri week6/tri.c)

add_executable(week7.bin week7/bin.c)
add_executable(week7.seg week7/seg.c)
add_executable(week7.stamp week7/stamp.c)

add_executable(week8.last week8/last.c)
add_executable(week8.last2 week8/last2.c)
add_executable(week8.odd week8/odd.c)
add_executable(week8.seq week8/seq.c)

add_executable(week9.ring week9/ring.c)
add_executable(week9.semi week9/semi.c)
add_executable(week9.sol week9/sol.c)