mljs_ann:
	emcc src/embind/ann.cpp resources/mljs_linalg.o -o build/mljs.js -s ALLOW_MEMORY_GROWTH -O3 -s ENVIRONMENT='web' -s SINGLE_FILE=1 \
		--bind -s MODULARIZE=1 -I includes/mlpack/src -I includes/mljs_armadillo/include -I includes/cereal/include \
		-I includes/ensmallen/include resources/blas_*.a resources/liblapack.a resources/libf2c.a;
	cp build/mljs.js resources/
