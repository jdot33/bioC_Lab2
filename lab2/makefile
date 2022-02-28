vectorops.o: burkertj_vector_ops.cpp burkertj_vector_ops.hpp burkertj_stats.cpp burkertj_stats.hpp
	g++ -c $^
vectorops_exe: burkertj_vector_ops.o
	g++ -o $@ $^
preprocessing.o: burkertj_pre_processing.cpp burkertj_pre_processing.hpp burkertj_vector_ops.cpp burkertj_vector_ops.hpp burkertj_stats.cpp burkertj_stats.hpp
	g++ -c $^
preprocessing_exe: burkertj_pre_processing.o
	g++ -o $@ $^
all: vectorops.o burkertj_vector_ops.o burkertj_pre_processing.o vectorops_exe

clean:
	rm -rf *.o
	rm -f *.gch