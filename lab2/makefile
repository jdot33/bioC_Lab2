stats.o: burkertj_stats.cpp 
	g++ -c $^
vectorops.o: burkertj_vector_ops.cpp burkertj_vector_ops.hpp burkertj_stats.cpp
	g++ -c $^
preprocessing.o: burkertj_pre_processing.cpp
	g++ -c $^
preprocessing_exe: burkertj_pre_processing.o burkertj_vector_ops.o burkertj_stats.o
	g++ -o $@ $^
kmeans.o: burkertj_k_means.cpp
	g++ -c $^
kmeans_exe: burkertj_k_means.o burkertj_stats.o burkertj_vector_ops.o
	g++ -o $@ $^
all: burkertj_stats.o burkertj_vector_ops.o burkertj_pre_processing.o preprocessing_exe burkertj_k_means.o kmeans_exe

clean:
	rm -rf *.o
	rm -f *.gch
	rm preprocessing_exe
	rm kmeans_exe